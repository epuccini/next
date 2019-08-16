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

(defun split-expr (expression)
  (let* ((new-expr1 (regex-replace-all "\\(" expression ";(;"))
         (new-expr2 (regex-replace-all "\\)" new-expr1 ";);"))
         (expr-list (split " |;" new-expr2)))
    (remove-if #'(lambda(x) (= (length x) 0)) expr-list)))

(defun emit-code-call (call)
  (format t "~a~{~a~};" (car call) (cdr call))
  (setf *code*
        (format nil "~a~{~a~};" (car call) (cdr call))))

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

(defun parse-arguments (expr-list max)
  (cond ((equal "(" (car expr-list))
         (progn
           (inc-arg)
           (setf *paranthese* (1+ *paranthese*))
           (if (and *paranthese* (not (equal "(" (car (last *call*)))))
               (setf *call* (append *call* (list ","))))
           (parse-call (cdr expr-list))))
        ((equal ")" (car expr-list))
         (progn
           (setf *paranthese* (1- *paranthese*))
           (setf *call* (append *call* (list ")")))
           (dec-arg)))
        ((numberp (parse-integer (car expr-list)))
         (progn
           (inc-arg)
           (if (and (gethash *paranthese* *arguments*)
                    (not (equal "(" (car (last *call*)))))
               (setf *call* (append *call* (list ","))))
           (if (> (gethash *paranthese* *arguments*) max)
               (progn
                 (format t "Error too many parameter to function (~a). Only ~a parameter expected!~%" (gethash *paranthese* *arguments*) max))
                    (progn
                      (setf *call* (append *call* (list (car expr-list))))
                      (parse-arguments (cdr expr-list) max)))))))

(defun parse-call (expr-list)
  (cond ((equal "(" (car expr-list))
         (progn
           (setf *paranthese* (1+ *paranthese*))
           (parse-call (cdr expr-list))))
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
           (parse-call (cdr expr-list))))))

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
