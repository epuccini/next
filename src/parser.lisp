;;; -----------------------------------------------------
;;; next - parser file
;;; -----------------------------------------------------
;;; File:     src/parser.lisp
;;; Date:     09:29:15 of Wednesday, 8/14/2019 (GMT+1)
;;; Author:   Edward Puccini
;;; -----------------------------------------------------

(in-package :next)

(require 'parse-float)

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
(defvar *block* 0)
(defvar *arguments* 0)
(defvar *def-template* nil)
(defvar *impl-template* nil)
(defvar *is-main-defined* nil)
(defvar *infinite-arguments* 10000)

(defun load-templates ()
  (setf *def-template* (load-binary-data "../templates/code.h"))
  (setf *impl-template* (load-binary-data "../templates/code.c")))

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
         (new-expr4 (regex-replace-all (format nil "~a" #\return) new-expr3 (format nil "°\n°")))
         (expr-list (split " |°" new-expr4)))
    (remove-if #'(lambda(x) (= (length x) 0)) expr-list)))

(defun emit-code-call (call)
  (if call
      (format t "~a~{~a~}~%" (car call) (cdr call)))
  (if (not (is-main-defined-p))
      (setf *code* (format nil "int main () {"))) 
  (if call
      (setf *code*
            (format nil "~a~%~a~{~a~}~%" *code* (car call) (cdr call))))
  (if (not (is-main-defined-p))
      (setf *code* (format nil "~a}" *code*))) 
  *code*)

(defun inc-block ()
  (setf *block* (1+ *block*)))

(defun dec-block ()
  (setf *block* (1- *block*)))

(defun zero-block ()
  (setf *block* 0))

(defun dec-arg ()
  (setf (gethash *block* *arguments*)
        (1- (gethash *block* *arguments*)))
  (if (not (gethash *block* *arguments*))
      (setf (gethash *block* *arguments*) 0)))

(defun inc-arg ()
  (if (not (gethash *block* *arguments*))
      (setf (gethash *block* *arguments*) 0))
  (setf (gethash *block* *arguments*)
        (1+ (gethash *block* *arguments*))))

(defun zero-arg ()
  (setf (gethash *block* *arguments*) 0))

(defun parse-multiline-comment (expr-list)
  (cond ((equal "|;" (car expr-list))
         (parse-expression (cdr expr-list)))
        ((stringp (car expr-list))
         (parse-multiline-comment (cdr expr-list)))))

(defun parse-single-line-comment (expr-list)
  (cond ((equal "\n" (car expr-list))
         (parse-expression (cdr expr-list)))
        ((stringp (car expr-list))
         (parse-single-line-comment (cdr expr-list)))))

(defun parse-cstr (expr-list)
  (cond ((equal "\"" (car expr-list))
         (setf *call* (append *call* (list "\"")))
         (parse-arguments (cdr expr-list) *infinite-arguments*))
        ((stringp (car expr-list))
         (setf *call* (append *call* (list (car expr-list))))
         (parse-cstr (cdr expr-list)))))

(defun parse-arguments (expr-list max)
  (cond ((equal "(" (car expr-list))
         (progn
           (inc-arg)
           (inc-block)
           (if (and *block* (not (equal "(" (car (last *call*)))))
               (setf *call* (append *call* (list ","))))
           (parse-call (cdr expr-list))))
        ((equal "\"" (car expr-list))
         (if (and *block*
                  (not (equal "(" (car (last *call*)))))
             (setf *call* (append *call* (list ","))))
         (setf *call* (append *call* (list "\"")))
         (parse-cstr (cdr expr-list)))
        ((equal ")" (car expr-list))
         (progn
           (dec-block)
           (setf *call* (append *call* (list ")")))
           (if (= *block* 0)
               (setf *call* (append *call* (list (format nil ";~%")))))
           (dec-arg)
           (parse-call (cdr expr-list))))
        ((numberp (parse-integer (car expr-list) :junk-allowed t))
         (progn
           (inc-arg)
           (if (and (gethash *block* *arguments*)
                    (not (equal "(" (car (last *call*)))))
               (setf *call* (append *call* (list ","))))
           (if (> (gethash *block* *arguments*) max)
               (error-parameter-max (gethash *block* *arguments*)
                                    max))
           (progn
             ; convert lisp double-float to c double
             (setf (car expr-list) (regex-replace-all "d0" (car expr-list) "f"))
             (setf *call* (append *call* (list (car expr-list))))
             (parse-arguments (cdr expr-list) max)))))
  nil)

(defun parse-call (expr-list)
  (cond ((equal "(" (car expr-list))
         (progn
           (inc-block)
           (parse-call (cdr expr-list))))
        ((equal ")" (car expr-list))
         (progn
           (dec-block)
           (setf *call* (append *call* (list ")")))
           (if (= *block* 0)
               (setf *call* (append *call* (list (format nil ";~%")))))
           (dec-arg)))
        ((equal "\n" (car expr-list))
         (parse-expression (cdr expr-list)))
        ((equal "print-format" (car expr-list))
         (progn
           (setf *call* (append *call* (list "print_format")))
           (setf *call* (append *call* (list "(")))
           (zero-arg)
           (parse-arguments (cdr expr-list) *infinite-arguments*)))
        ((equal "println" (car expr-list))
         (progn
           (cond ((and (typep (parse-integer (cadr expr-list) :junk-allowed t) 'integer)
                       (not (find #\. (cadr expr-list)))) 
                  (setf *call* (append *call* (list "println_int32"))))
                 ((typep (parse-float (cadr expr-list)
                                      :junk-allowed t
                                      :type 'double-float) 'double-float)
                  (setf *call* (append *call* (list "println_float64"))))
                 ((typep (parse-float (cadr expr-list)
                                      :junk-allowed t
                                      :type 'single-float) 'float)
                  (setf *call* (append *call* (list "println_float32"))))
                 ((stringp (cadr expr-list))
                  (setf *call* (append *call* (list "println_str")))))
           (setf *call* (append *call* (list "(")))
           (zero-arg)
           (parse-arguments (cdr expr-list) 1)))
        ((equal "print" (car expr-list))
         (progn
           (cond ((and (typep (parse-integer (cadr expr-list) :junk-allowed t) 'integer)
                       (not (find #\. (cadr expr-list))))
                  (setf *call* (append *call* (list "println_int32"))))
                 ((typep (parse-float (cadr expr-list)
                                      :junk-allowed t
                                      :type 'double-float) 'double-float)
                  (setf *call* (append *call* (list "print_float64"))))
                 ((typep (parse-float (cadr expr-list)
                                      :junk-allowed t
                                      :type 'single-float) 'float)
                  (setf *call* (append *call* (list "print_float32"))))
                 ((stringp (cadr expr-list))
                  (setf *call* (append *call* (list "print_str")))))
           (setf *call* (append *call* (list "(")))
           (zero-arg)
           (parse-arguments (cdr expr-list) 1)))
        ((or (equal "mod" (car expr-list))
             (equal "%" (car expr-list)))
         (progn
           (setf *call* (append *call* (list "mod")))
           (setf *call* (append *call* (list "(")))
           (zero-arg)
           (parse-arguments (cdr expr-list) 2)))))

(defun parse-expression (expr-list)
  (cond ((equal "(" (car expr-list))
         (progn
           (inc-arg)
           (inc-block)
           (parse-call (cdr expr-list))))
        ((equal ";|" (car expr-list))
         (parse-multiline-comment (cdr expr-list)))
        ((equal ";" (car expr-list))
         (parse-single-line-comment (cdr expr-list)))
        ((> (length (cdr expr-list)) 0)
         (parse-expression (cdr expr-list)))))

(defun parse (expression)
  "Parse expression."
  (let ((expr-list (split-expr expression)))
    (setf *call* '("    "))
    (setf *block* 0)
    (setf *arguments* (make-hash-table))
    (setf (gethash *block* *arguments*) 0)
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
  (load-templates)
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
