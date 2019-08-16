;;; -----------------------------------------------------
;;; next - parser file
;;; -----------------------------------------------------
;;; File:     src/parser.lisp
;;; Date:     09:29:15 of Wednesday, 8/14/2019 (GMT+1)
;;; Author:   Edward Puccini
;;; -----------------------------------------------------

(in-package :next)

(defparameter *grammar*
  '((expressions -> () (expression expressions))
    (expression -> (open-bracket call close-bracket))
    (call -> print mul div sub plus mod)
    (print -> (princ arguments))
    (mul -> (mulsym nums expressions))
    (div -> (divsym nums expressions))
    (sub -> (subsym nums expressions))
    (div -> (divsym nums expressions))
    (plus -> (plussym nums expressions))
    (mod -> (modsym nums expressions))
    (mulsym -> () "mul" "*")
    (divsym -> () "div" "/")
    (subsym -> () "sub" "-")
    (plussym -> () "plus" "+")
    (modsym -> () "mod" "%")
    (open-bracket -> "(")
    (close-bracket -> ")")
    (arguments -> () (argument arguments))
    (argument -> () (num) (str) (expression))
    (nums -> () (num) (nums))
    (num -> () (ziffer num))
    (ziffer -> 0 1 2 3 4 5 6 7 8 9)
    (str -> () (letter str))
    (strs -> () (str) (strs))
    (letter -> a b c d e f g h i j k l m n o p q r s t u v w x y z)))

(defvar *call* '("    "))
(defvar *code* nil)
(defvar *paranthese* 0)
(defvar *arguments* 0)
(defvar *def-template* (load-binary-data "../templates/code.h"))
(defvar *impl-template* (load-binary-data "../templates/code.c"))
(defvar *is-main-defined* nil)

(defun is-main-defined-p ()
  *is-main-defined*)

(defun print-stack ()
  "Use swank to log a stack-trace."
  (let ((trace ""))
    (let* ((msg-lst (remove-if #'null
                               (swank-backend:call-with-debugging-environment
                                (lambda () (swank:backtrace 0 5)))))
           (stack-msg 
            (progn
              (mapcar (lambda (msg)
                        (setf trace (concatenate 'string trace 
                                                   (format nil "~{~A ~}~%" msg))))
                      msg-lst) trace)))
      (print stack-msg))))

(defun error-parameter-max (cnt max)
  (format t "Error too many parameter to function (~a). Only ~a parameter expected!~%" cnt max)
  (print-stack))

(defun split-expr (expression)
  (let* ((new-expr1 (regex-replace-all "\\(" expression "°(°"))
         (new-expr2 (regex-replace-all "\\)" new-expr1 "°)°"))
         (new-expr3 (regex-replace-all "\"" new-expr2 "°\"°"))
         (new-expr4 (regex-replace-all (format nil "~a" #\newline) new-expr3 ""))
         (expr-list (split " |°" new-expr4)))
    (remove-if #'(lambda(x) (= (length x) 0)) expr-list)))

(defun emit-code-call (call)
  (if call
      (format t "~a~{~a~};~%" (car call) (cdr call)))
  (if (not (is-main-defined-p))
      (setf *code* (format nil "int main () {"))) 
  (if call
      (setf *code*
            (format nil "~a~%~a~{~a~}~%" *code* (car call) (cdr call))))
  (if (not (is-main-defined-p))
      (setf *code* (format nil "~a}" *code*))) 
  *code*)

(defun dec-arg ()
  (setf (gethash *paranthese* *arguments*)
        (1- (gethash *paranthese* *arguments*)))
  (if (not (gethash *paranthese* *arguments*))
      (setf (gethash *paranthese* *arguments*) 0)))

(defun inc-arg ()
  (if (not (gethash *paranthese* *arguments*))
      (setf (gethash *paranthese* *arguments*) 0))
  (setf (gethash *paranthese* *arguments*)
        (1+ (gethash *paranthese* *arguments*))))

(defun parse-multiline-comment (expr-list)
  (cond ((equal "|;" (car expr-list))
         (parse-expression (cdr expr-list)))
        ((stringp (car expr-list))
         (parse-multiline-comment (cdr expr-list)))))

(defun parse-cstr (expr-list)
  (cond ((equal "\"" (car expr-list))
         (setf *call* (append *call* (list "\"")))
         (parse-arguments (cdr expr-list) 1))
        ((stringp (car expr-list))
         (setf *call* (append *call* (list (car expr-list))))
         (parse-cstr (cdr expr-list)))))

(defun parse-arguments (expr-list max)
  (cond ((equal "(" (car expr-list))
         (progn
           (inc-arg)
           (setf *paranthese* (1+ *paranthese*))
           (if (and *paranthese* (not (equal "(" (car (last *call*)))))
               (setf *call* (append *call* (list ","))))
           (parse-call (cdr expr-list))))
        ((equal "\"" (car expr-list))
         (setf *call* (append *call* (list "\"")))
         (parse-cstr (cdr expr-list)))
        ((equal ")" (car expr-list))
         (progn
           (setf *paranthese* (1- *paranthese*))
           (setf *call* (append *call* (list ")")))
           (if (= *paranthese* 0)
               (setf *call* (append *call* (list (format nil ";~%")))))
           (dec-arg)
           (parse-call (cdr expr-list))))
        ((numberp (parse-integer (car expr-list) :junk-allowed t))
         (progn
           (inc-arg)
           (if (and (gethash *paranthese* *arguments*)
                    (not (equal "(" (car (last *call*)))))
               (setf *call* (append *call* (list ","))))
           (if (> (gethash *paranthese* *arguments*) max)
               (error-parameter-max (gethash *paranthese* *arguments*)
                                    max))
           (progn
             (setf *call* (append *call* (list (car expr-list))))
             (parse-arguments (cdr expr-list) max)))))
  nil)

(defun parse-call (expr-list)
  (cond ((equal "(" (car expr-list))
         (progn
           (setf *paranthese* (1+ *paranthese*))
           (parse-call (cdr expr-list))))
        ((equal ")" (car expr-list))
         (progn
           (setf *paranthese* (1- *paranthese*))
           (setf *call* (append *call* (list ")")))
           (dec-arg)))
        ((equal "println" (car expr-list))
         (progn
           (if (numberp (parse-integer (cadr expr-list) :junk-allowed t))
               (setf *call* (append *call* (list "println_int")))
               (setf *call* (append *call* (list "println_str"))))
           (setf *call* (append *call* (list "(")))
           (parse-arguments (cdr expr-list) 1)))
        ((equal "print" (car expr-list))
         (progn
           (if (numberp (parse-integer (cadr expr-list) :junk-allowed t))
               (setf *call* (append *call* (list "println_int")))
               (setf *call* (append *call* (list "print_str"))))
           (setf *call* (append *call* (list "(")))
           (parse-arguments (cdr expr-list) 1)))
        ((or (equal "mod" (car expr-list))
             (equal "%" (car expr-list)))
         (progn
           (setf *call* (append *call* (list "mod")))
           (setf *call* (append *call* (list "(")))
           (parse-arguments (cdr expr-list) 2)))))

(defun parse-expression (expr-list)
  (cond ((equal "(" (car expr-list))
         (progn
           (inc-arg)
           (setf *paranthese* (1+ *paranthese*))
           (parse-call (cdr expr-list))))
        ((equal ";|" (car expr-list))
         (parse-multiline-comment (cdr expr-list)))
        ((> (length (cdr expr-list)) 0)
         (parse-expression (cdr expr-list)))))

(defun parse (expression)
  "Parse expression."
  (let ((expr-list (split-expr expression)))
    (setf *call* '("    "))
    (setf *paranthese* 0)
    (setf *arguments* (make-hash-table))
    (setf (gethash *paranthese* *arguments*) 0)
    (parse-expression expr-list)
    (setf *code* (emit-code-call *call*))
    *code*))

(defun repl ()
  (format t "~%>")
  (loop for input = (read-line)
       while input do
       (parse input)
       (format t "~%>")))

(defun evaluate (expression)
  (parse expression))


(defun compile-next (infile outfile)
  (let* ((infile-data (load-binary-data infile))
         (code (parse infile-data))
         (outfile-data (concatenate 'string *impl-template* code))
         (outfilename (pathname-name outfile))
         (outfilepath (directory-namestring outfile)))
    (setf outfile-data (regex-replace-all "\\$\\(OUTPUT_H\\)"
                                          outfile-data
                                          (concatenate 'string
                                                       outfilename ".h")))
    (save-binary-data (concatenate 'string
                                   outfilepath
                                   outfilename ".h") *def-template*)
    (save-binary-data (concatenate 'string
                                   outfilepath
                                   outfilename ".c") outfile-data)))
