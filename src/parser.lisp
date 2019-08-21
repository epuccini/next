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
(defvar *paranteses* 0)
(defvar *variables* nil)
(defvar *functions* nil)
(defvar *arguments* 0)
(defvar *def-template* nil)
(defvar *impl-template* nil)
(defvar *is-main-defined* nil)
(defvar *infinite-arguments* 10000)
(defvar *block* 0)

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
  (print-stack)
  (sb-ext:quit))


(defun error-no-type-def ()
  (format t "Error no variable and type defined!~%")
  (print-stack)
  (sb-ext:quit))

(defun error-function-not-defined ()
  (format t "Error function not defined!~%")
  (print-stack)
  (sb-ext:quit))

(defun error-missing-expression ()
  (format t "Error missing expression!~%")
  (print-stack)
  (sb-ext:quit))

(defun error-type-unkown ()
  (format t "Error type unkown!~%")
  (print-stack)
  (sb-ext:quit))

(defun error-syntax-error ()
  (format t "Error syntax error!~%")
  (print-stack)
  (sb-ext:quit))

(defun preprocess (expression)
  (let* ((new-expr1 (regex-replace-all "\\(" expression "°(°"))
         (new-expr2 (regex-replace-all "\\)" new-expr1 "°)°"))
         (new-expr3 (regex-replace-all "\"" new-expr2 "°\"°"))
         (new-expr4 (regex-replace-all (format nil "~a" #\return) new-expr3
                                       (format nil "°\n°")))
         (new-expr5 (regex-replace-all "\\[" new-expr4 "°[°"))
         (new-expr6 (regex-replace-all "\\]" new-expr5 "°]°"))
         (new-expr7 (regex-replace-all (format nil "~a" #\newline) new-expr6
                                       (format nil "°\n°")))
         (new-expr8 (regex-replace-all (format nil "~a" #\tab) new-expr7
                                       (format nil " ")))
         (new-expr9 (regex-replace-all "\\," new-expr8 "°,°"))
         (expr-list (split " |°" new-expr9)))
    (remove-if #'(lambda(x) (= (length x) 0)) expr-list)))

(defun emit-code-call (call)
  (if call
      (format t "~%~a~{~a~}~%" (car call) (cdr call)))
  (if (not (is-main-defined-p))
      (setf *code* (format nil "int main () {"))) 
  (if call
      (setf *code*
            (format nil "~a~%~a~{~a~}~%" *code* (car call) (cdr call))))
  (if (not (is-main-defined-p))
      (setf *code* (format nil "~a}" *code*))) 
  *code*)

(defun skip-expr-or-value (expr p)
  (cond  ((equal (car expr) "(")
          (setq p (1+ p))
          (skip-expr-or-value (cdr expr) p))
         ((equal (car expr) ")")
         (progn
           (setq p (1- p))
           (if (= p 0)
               (return-from skip-expr-or-value (cdr expr))
               (skip-expr-or-value (cdr expr) p))))
         ((and (not (equal (car expr) "(")) (not (equal (car expr) ")")))
          (if (> p 0)
              (skip-expr-or-value (cdr expr) p)
              (return-from skip-expr-or-value (cdr expr))))))

(defun skip-expression (expr p)
  (cond  ((or (equal (car expr) "(") (equal (car expr) ";|"))
          (setq p (1+ p))
          (skip-expression (cdr expr) p))
         ((or (equal (car expr) ")") (equal (car expr) "|;"))
         (progn
           (setq p (1- p))
           (if (= p 0)
               (return-from skip-expression (cdr expr))
               (skip-expression (cdr expr) p))))
        ((or (equal (car expr) "(") (not (equal (car expr) ")")))
         (skip-expression (cdr expr) p))))

(defun get-variable-name (name)
  (format nil "~a_~a" name *block*))

(defun get-function-name (name)
  (format nil "~a_~a" name *block*))

(defun inc-parens ()
  (setf *paranteses* (1+ *paranteses*)))

(defun dec-parens ()
  (setf *paranteses* (1- *paranteses*)))

(defun inc-block ()
  (setf *block* (1+ *block*)))

(defun dec-block ()
  (setf *block* (1- *block*)))

(defun zero-parens ()
  (setf *paranteses* 0))

(defun zero-block ()
  (setf *block* 0))

(defun dec-arg ()
  (if (>= *paranteses* 0)
      (setf (gethash *paranteses* *arguments*)
            (1- (gethash *paranteses* *arguments*)))
      (if (not (gethash *paranteses* *arguments*))
          (setf (gethash *paranteses* *arguments*) 0))))

(defun inc-arg ()
  (if (not (gethash *paranteses* *arguments*))
      (setf (gethash *paranteses* *arguments*) 0))
  (setf (gethash *paranteses* *arguments*)
        (1+ (gethash *paranteses* *arguments*))))

(defun zero-arg ()
  (setf (gethash *paranteses* *arguments*) 0))

(defun type-of-number-string (numstr)
  (cond ((and (typep (parse-integer numstr :junk-allowed t) 'integer)
              (not (find #\. numstr)))
         'integer)
        ((typep (parse-float numstr
                             :junk-allowed t
                             :type 'double-float) 'double-float)
         'double-float)
        ((typep (parse-float numstr
                             :junk-allowed t
                             :type 'single-float) 'float)
         'float)
        ((typep numstr 'string)
         'string)))

(defun parse-argument (expr-list)
  (cond ((find #\: (car expr-list))
         (let ((def (split ":" (car expr-list))))
           (dbg "parse-argument: DEFINE " (car expr-list))
           (inc-arg)
           (cond ((equal "int16" (cadr def))
                  (setf *call* (append *call* (list "short")))
                  (setf (gethash (get-variable-name (car def)) *variables*) 'integer))
                 ((equal "int32" (cadr def))
                  (setf *call* (append *call* (list "int")))
                  (setf (gethash (get-variable-name (car def)) *variables*) 'integer))
                 ((equal "int64" (cadr def))
                  (setf *call* (append *call* (list "long")))
                  (setf (gethash (get-variable-name (car def)) *variables*) 'bigint))
                 ((equal "float32" (cadr def))
                  (setf *call* (append *call* (list "float")))
                  (setf (gethash (get-variable-name (car def)) *variables*) 'single-float))
                 ((equal "float64" (cadr def))
                  (setf *call* (append *call* (list "double")))
                  (setf (gethash (get-variable-name (car def)) *variables*) 'double-float))
                 ((equal "bool" (cadr def))
                  (setf *call* (append *call* (list "bool")))
                  (setf (gethash (get-variable-name (car def)) *variables*) 'boolean))
                 ((equal "byte" (cadr def))
                  (setf *call* (append *call* (list "char")))
                  (setf (gethash (get-variable-name (car def)) *variables*) 'char))
                 ((equal "string" (cadr def))
                  (setf *call* (append *call* (list "char*")))
                  (setf (gethash (get-variable-name (car def)) *variables*) 'string)))
           (setf *call* (append *call* (list " ")))
           (setf *call* (append *call* (list (get-variable-name (car def)))))
           (dbg "parse-argument: OPEN ARG")
           (if (find #\: (cadr expr-list))
               (setf *call* (append *call* (list ","))))
           (setf expr-list (parse-argument (cdr expr-list))))))
  expr-list)

(defun parse-argument-vector (expr-list)
  (cond ((equal "[" (car expr-list))
         (dbg "parse-argument-vector: OPEN VEC")
         (dbg "parse-argument-vector: FIRST VAR " expr-list)
         (zero-arg)
         (setf *call* (append *call* (list "(")))
         (setf expr-list (parse-argument (cdr expr-list)))
         (setf expr-list (parse-argument-vector expr-list)))
        ((equal "]" (car expr-list))
         (dbg "parse-argument-vector: CLOSE VEC")
         (dbg "parse-argument-vector: OPEN INNER")
         (setf *call* (append *call* (list ")")))
         (setf *call* (append *call* (list (format nil "~%{~%"))))
         (setf expr-list (parse-inner-block (cdr expr-list)))
         (return-from parse-argument-vector expr-list))
        ((equal "(" (car expr-list))
         (inc-parens)
         (dbg "parse-argument-vector: ( Block " *block*)
         (setf expr-list (cdr expr-list)))
        ((equal ")" (car expr-list))
         (dbg "parse-argument-vector: ) Block " *block*)
         (setf expr-list (cdr expr-list)))
        ((equal "\n" (car expr-list))
         (dbg "parse-argument-vector: RET " (cdr expr-list))
         (setf expr-list (parse-argument-vector (cdr expr-list))))
        ((stringp (car expr-list))
         (setf expr-list (parse-argument expr-list))
         (dbg "parse-argument-vector: NEXT VAR " expr-list)
         (setf *call* (append *call* (list ", ")))
         (setf expr-list (parse-argument-vector expr-list))))
  expr-list)

(defun parse-type (expr-list)
  (let ((type (cadr (split ":" (car expr-list)))))
    (cond ((equal "int16" type)
           (setf *call* (append *call* (list "short")))
           (setf expr-list (cdr expr-list)))
          ((equal "int32" type)
           (setf *call* (append *call* (list "int")))
           (setf expr-list (cdr expr-list)))
          ((equal "int64" type)
           (setf *call* (append *call* (list "long")))
           (setf expr-list (cdr expr-list)))
          ((equal "float32" type)
           (setf *call* (append *call* (list "float")))
           (setf expr-list (cdr expr-list)))
          ((equal "float64" type)
           (setf *call* (append *call* (list "double")))
           (setf expr-list (cdr expr-list)))
          ((equal "byte" type)
           (setf *call* (append *call* (list "char")))
           (setf expr-list (cdr expr-list)))
          ((equal "bool" type)
           (setf *call* (append *call* (list "bool")))
           (setf expr-list (cdr expr-list)))
          ((equal "void" type)
           (setf *call* (append *call* (list "void")))
           (setf expr-list (cdr expr-list)))
          ((equal "[" type)
           (setf *call* (append *call* (list "void")))))
    (setf *call* (append *call* (list " ")))
    (dbg "parse-type: Type " type))
  expr-list)

(defun parse-function (expr-list)
  (cond ((stringp (car expr-list))
         (let ((fn-name (car (split ":" (car expr-list)))))
           (dbg "parse-function: Functionname " fn-name)
           (setf expr-list (parse-type expr-list))
           (setf (gethash (get-function-name fn-name) *functions*) (car *call*))
           (setf *call* (append *call* (list (get-function-name fn-name))))
           (inc-block)
           (setf expr-list (parse-argument-vector expr-list)))))
  (setf *call* (append *call* (list (format nil "}~%"))))
  (dec-block)
  expr-list)

(defun parse-inner-block (expr-list)
  (cond ((equal "(" (car expr-list))
         (progn
           (inc-parens)
           (dbg "parse-inner-block: OPEN INNER Block " *block*)
           (setf expr-list (parse-call (cdr expr-list)))))
        ((equal ")" (car expr-list))
         (progn
           (dec-parens)
           (if (= (- *paranteses* *block*) 0)
               (progn
                 (dbg "parse-inner-block: RET INNER ) Block " *block*)
                 (return-from parse-inner-block expr-list))
               (progn
                 (dbg "parse-inner-block: CLOSE INNER ) Block " *block*)
                 (setf expr-list (parse-inner-block (cdr expr-list)))))))
        ((equal "\n" (car expr-list))
         (dbg "parse-inner-block: RET INNER " (cadr expr-list))
         (setf expr-list (parse-inner-block (cdr expr-list))))
        ((equal ";|" (car expr-list))
         (dbg "parse-inner-block: MultiComment")
         (setf expr-list (parse-multiline-comment (cdr expr-list))))
        ((equal ";" (car expr-list))
         (dbg "parse-inner-block: Comment")
         (setf expr-list (parse-single-line-comment (cdr expr-list))))
        ((not (car expr-list))
         (dbg "parse-inner-block: NIL"))
        ((> (length expr-list) 0)
         (dbg "parse-inner-block: PARSE INNER " (cdr expr-list) " Block " *block*)
         (setf expr-list (parse-inner-block (cdr expr-list)))))
  (if (equal "(" (car expr-list))
      (setf expr-list (parse-inner-block expr-list)))
  expr-list)
  
(defun parse-variable (expr-list)
  (cond ((find #\: (car expr-list))
         (let ((def (split ":" (car expr-list))))
           (dbg "parse-variable: DEFINE " (car expr-list))
           (cond ((equal "int16" (cadr def))
                  (setf *call* (append *call* (list "short")))
                  (setf (gethash (get-variable-name (car def)) *variables*) 'integer))
                 ((equal "int32" (cadr def))
                  (setf *call* (append *call* (list "int")))
                  (setf (gethash (get-variable-name (car def)) *variables*) 'integer))
                 ((equal "int64" (cadr def))
                  (setf *call* (append *call* (list "long")))
                  (setf (gethash (get-variable-name (car def)) *variables*) 'bigint))
                 ((equal "float32" (cadr def))
                  (setf *call* (append *call* (list "float")))
                  (setf (gethash (get-variable-name (car def)) *variables*) 'single-float))
                 ((equal "float64" (cadr def))
                  (setf *call* (append *call* (list "double")))
                  (setf (gethash (get-variable-name (car def)) *variables*) 'double-float))
                 ((equal "bool" (cadr def))
                  (setf *call* (append *call* (list "bool")))
                  (setf (gethash (get-variable-name (car def)) *variables*) 'boolean))
                 ((equal "byte" (cadr def))
                  (setf *call* (append *call* (list "char")))
                  (setf (gethash (get-variable-name (car def)) *variables*) 'char))
                 ((equal "string" (cadr def))
                  (setf *call* (append *call* (list "char*")))
                  (setf (gethash (get-variable-name (car def)) *variables*) 'string)))
           (setf *call* (append *call* (list " ")))
           (setf *call* (append *call* (list (get-variable-name (car def)))))
           (setf *call* (append *call* (list "=")))
           (dbg "parse-variable: OPEN ARG")
           (if (equal (cadr expr-list) "]")
               (error-missing-expression))
           (setf expr-list (parse-expression (cdr expr-list))))))
  expr-list)
          
(defun parse-parameter-vector (expr-list)
  (cond ((equal "[" (car expr-list))
         (dbg "parse-parameter-vector: OPEN VEC")
         (dbg "parse-parameter-vector: FIRST VAR " expr-list)
         (setf expr-list (parse-variable (cdr expr-list)))
         (setf expr-list (parse-parameter-vector expr-list)))
        ((equal "]" (car expr-list))
         (dbg "parse-parameter-vector: CLOSE VEC")
         (dbg "parse-parameter-vector: OPEN INNER")
         (setf expr-list (parse-inner-block (cdr expr-list)))
         (setf *call* (append *call* (list (format nil "}~%"))))
         (dec-block)
         (return-from parse-parameter-vector expr-list))
        ((equal "(" (car expr-list))
         (inc-parens)
         (dbg "parse-parameter-vector: ( Block " *block*)
         (setf expr-list (cdr expr-list)))
        ((equal ")" (car expr-list))
         (dbg "parse-parameter-vector: ) Block " *block*)
         (setf expr-list (cdr expr-list)))
        ((equal "\n" (car expr-list))
         (dbg "parse-parameter-vector: RET " (cdr expr-list))
         (setf expr-list (parse-parameter-vector (cdr expr-list))))
        ((stringp (car expr-list))
         (setf expr-list (parse-variable expr-list))
         (dbg "parse-parameter-vector: NEXT VAR " expr-list)
         (setf expr-list (parse-parameter-vector expr-list))))
  expr-list)

(defun parse-multiline-comment (expr-list)
  (cond ((equal "|;" (car expr-list))
         (dbg "parse-multiline-comment: OPEN")
         (setf expr-list (parse-expression (cdr expr-list))))
        ((stringp (car expr-list))
         (dbg "parse-multiline-comment: COMMENT " (car expr-list))
         (setf expr-list (parse-multiline-comment (cdr expr-list)))))
  expr-list)

(defun parse-single-line-comment (expr-list)
  (cond ((not (equal "\n" (car expr-list)))
         (dbg "parse-singleline-comment: COMMENT " (car expr-list))
         (setf expr-list (parse-single-line-comment (cdr expr-list)))))
  expr-list)

(defun parse-cstr (expr-list)
  (cond ((equal "\"" (car expr-list))
         (setf *call* (append *call* (list "\"")))
         (setf expr-list (parse-arguments (cdr expr-list) *infinite-arguments*)))
        ((stringp (car expr-list))
         (setf *call* (append *call* (list (car expr-list))))
         (setf expr-list (parse-cstr (cdr expr-list)))))
  expr-list)

(defun parse-arguments (expr-list max)
  (cond ((equal "(" (car expr-list))
         (progn
           (inc-arg)
           (inc-parens)
           (if (and *paranteses* (not (equal "(" (car (last *call*)))))
               (setf *call* (append *call* (list ","))))
           (dbg "parse-arguments: OPEN ARG ( Block " *block*)
           (setf expr-list (parse-call (cdr expr-list)))))
        ((equal "\"" (car expr-list))
         (if (and *paranteses*
                  (not (equal "(" (car (last *call*)))))
             (setf *call* (append *call* (list ","))))
         (setf *call* (append *call* (list "\"")))
         (setf expr-list (parse-cstr (cdr expr-list))))
        ((equal ")" (car expr-list))
         (progn
           (dec-arg)
           (dec-parens)
           (dbg "parse-arguments: ARG CLOSE ) Block " *block*)
           (setf *call* (append *call* (list ")")))
           (if (= (- *paranteses* *block*) 0)
               (setf *call* (append *call* (list (format nil ";~%")))))
           (dec-arg)
           (setf expr-list (parse-call (cdr expr-list)))))
        ((equal "," (car expr-list))
         (error-syntax-error))
        ((numberp (parse-integer (car expr-list) :junk-allowed t))
         (progn
           (inc-arg)
           (if (and (gethash *paranteses* *arguments*)
                    (not (equal "(" (car (last *call*)))))
               (setf *call* (append *call* (list ","))))
           (if (> (gethash *paranteses* *arguments*) max)
               (error-parameter-max (gethash *paranteses* *arguments*)
                                    max))
           (progn
             ; convert lisp double-float to c double
             (setf (car expr-list) (regex-replace-all "d0" (car expr-list) "f"))
             (setf *call* (append *call* (list (car expr-list))))
             (setf expr-list (parse-arguments (cdr expr-list) max)))))
        ((remove-if-not #'(lambda (x)
                            (equal x (get-variable-name (car expr-list))))
                        (hash-table-keys *variables*))
         (progn
           (inc-arg)
           (if (and (gethash *paranteses* *arguments*)
                    (not (equal "(" (car (last *call*)))))
               (setf *call* (append *call* (list ","))))
           (if (> (gethash *paranteses* *arguments*) max)
               (error-parameter-max (gethash *paranteses* *arguments*)
                                    max))
           (dbg "parse-arguments: VARIABLE " (get-variable-name (car expr-list)))
           (setf *call* (append *call* (list (get-variable-name (car expr-list)))))
           (setf expr-list (parse-arguments (cdr expr-list) max)))))
  expr-list)

(defun parse-call (expr-list)
   (cond ((equal "(" (car expr-list))
          (progn
            (inc-parens)
            (dbg "parse-call: CALL OPEN ( Block " *block*)
            (setf expr-list (parse-call (cdr expr-list)))))
         ((equal ")" (car expr-list))
         (progn
           (dec-parens)
           (dbg "parse-call: CALL CLOSE ) Block " *block*)
           (if (> (- *paranteses* *block*) 0)
               (setf *call* (append *call* (list ")"))))
           (if (= (- *paranteses* *block*) 0)
               (setf *call* (append *call* (list (format nil ");~%")))))
           (dec-arg)
           (return-from parse-call (cdr expr-list))))
         ((equal "," (car expr-list))
          (error-syntax-error))
        ((equal "\n" (car expr-list))
         (dbg "parse-call: RET")
         (setf expr-list (parse-call (cdr expr-list))))
        ((equal "print-format" (car expr-list))
         (progn
           (setf *call* (append *call* (list "print_format")))
           (setf *call* (append *call* (list "(")))
           (zero-arg)
           (setf expr-list (parse-arguments (cdr expr-list) *infinite-arguments*))))
        ((equal "println" (car expr-list))
         (let ((tp1 (gethash (get-variable-name (cadr expr-list)) *variables*))
               (tp2 (type-of-number-string (cadr expr-list)))
               (tp nil))
           (if (remove-if-not #'(lambda (x)
                                  (equal x (get-variable-name (cadr expr-list))))
                            (hash-table-keys *variables*))
             (setf tp tp1)
             (setf tp tp2))
         (cond ((equal tp 'integer)
                (setf *call* (append *call* (list "println_int32"))))
               ((equal tp 'bigint)
                (setf *call* (append *call* (list "println_int64"))))
               ((equal tp 'double-float)
                (setf *call* (append *call* (list "println_float64"))))
               ((equal tp 'single-float)
                (setf *call* (append *call* (list "println_float32"))))
               ((equal tp 'string)
                (setf *call* (append *call* (list "println_str")))))
         (setf *call* (append *call* (list "(")))
         (zero-arg)
         (dbg "parse-arguments: println = " (cdr expr-list))
         (setf expr-list (parse-arguments (cdr expr-list) 1))))
        ((equal "print" (car expr-list))
         (let ((tp1 (gethash (get-variable-name (cadr expr-list)) *variables*))
               (tp2 (type-of-number-string (cadr expr-list)))
               (tp nil))
           (if (remove-if-not #'(lambda (x)
                                  (equal x (get-variable-name (cadr expr-list))))
                              (hash-table-keys *variables*))
               (setf tp tp1)
               (setf tp tp2))
           (cond ((equal tp 'integer)
                  (setf *call* (append *call* (list "print_int32"))))
                 ((equal tp 'bigint)
                  (setf *call* (append *call* (list "print_int65"))))
                 ((equal tp 'double-float)
                  (setf *call* (append *call* (list "print_float64"))))
                 ((equal tp 'single-float)
                  (setf *call* (append *call* (list "print_float32"))))
                 ((equal tp 'string)
                  (setf *call* (append *call* (list "print_str")))))
           (setf *call* (append *call* (list "(")))
           (zero-arg)
           (setf expr-list (parse-arguments (cdr expr-list) 1))))
        ((equal "let" (car expr-list))
         (progn
           (zero-arg)
           (inc-block)
           (dbg "parse-call: LET")
           (setf *call* (append *call* (list (format nil "{~%"))))
           (setf expr-list (parse-parameter-vector (cdr expr-list)))))
        ((or (equal "mod" (car expr-list))
             (equal "%" (car expr-list)))
         (progn
           (setf *call* (append *call* (list "mod")))
           (setf *call* (append *call* (list "(")))
           (zero-arg)
           (setf expr-list (parse-arguments (cdr expr-list) 2))))
        ((equal "defn" (car expr-list))
         (setf expr-list (parse-function (cdr expr-list))))
        ((remove-if-not #'(lambda (x)
                            (equal x (get-function-name (car expr-list))))
                        (hash-table-keys *functions*))
         (progn
           (setf *call* (append *call* (list (get-function-name (car expr-list)))))
           (setf *call* (append *call* (list "(")))
           (zero-arg)
           (setf expr-list (parse-arguments (cdr expr-list) *infinite-arguments*))))
        ((stringp (car expr-list))
         (dbg "parse-call: FN not defined: " (car expr-list))
         (error-function-not-defined)))
   expr-list)


(defun parse-expression (expr-list)
  (cond ((equal "(" (car expr-list))
         (progn
           (inc-arg)
           (inc-parens)
           (dbg "parse-expression: OPEN EXPR ( Block " *block*)
           (setf expr-list (parse-call (cdr expr-list)))))
        ((not (car expr-list))
         (dbg "parse-expression: NIL"))
        ((equal ")" (car expr-list))
         (dec-parens)
         (dbg "parse-expression: CLOSE EXPR ) Block " *block*)
         (if (= (- *paranteses* *block*) 0)
             (setf *call* (append *call* (list (format t ";~%")))))
         (setf expr-list (cdr expr-list)))
        ((equal "," (car expr-list))
         (error-syntax-error))        
        ((equal (format nil "~a" #\Tab) (car expr-list))
         (setf expr-list (cdr expr-list)))
        ((numberp (parse-integer (car expr-list) :junk-allowed t))
         (dbg "parse-expression: NUM Block " *block*)
         (setf *call* (append *call* (list (car expr-list))))
         (setf *call* (append *call* (list (format nil ";~%"))))
         (setf expr-list (cdr expr-list)))
        ((equal "\"" (car expr-list))
         (dbg "parse-expression: STRING Block " *block*)
         (setf *call* (append *call* (list "\"")))
         (setf expr-list (parse-cstr (cdr expr-list)))
         (dbg "parse-expression: STRING END " expr-list)
         (setf *call* (append *call* (list (format nil ";~%")))))
        ((equal ";|" (car expr-list))
         (dbg "parse-expression: parse multiline comment")
         (setf expr-list (parse-multiline-comment (cdr expr-list))))
        ((equal ";" (car expr-list))
         (dbg "parse-expression: parse singleiline comment")
         (setf expr-list (parse-single-line-comment (cdr expr-list))))
        ((> (length (cdr expr-list)) 0)
         (setf expr-list (parse-expression (cdr expr-list)))))
  expr-list)

(defun parse (expression)
  "Parse expression."
  (let ((expr-list (preprocess expression)))
    (setf *call* '("    "))
    (setf *paranteses* 0)
    (setf  *block* 0)
    (setf *arguments* (make-hash-table))
    (setf *variables* (make-hash-table :test 'equal))
    (setf *functions* (make-hash-table :test 'equal))
    (setf (gethash *paranteses* *arguments*) 0)
    (setf expr-list (parse-expression expr-list))
    (loop while (and (find "(" expr-list :test #'equal)
                     (> (length expr-list) 0)) do
           (setf expr-list (parse-expression expr-list)))
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
