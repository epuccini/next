;;; -----------------------------------------------------
;;; next - parser file
;;; -----------------------------------------------------
;;; File:     src/parser.lisp
;;; Date:     09:29:15 of Wednesday, 8/14/2019 (GMT+1)
;;; Author:   Edward Puccini
;;; -----------------------------------------------------

(in-package :next)

(require 'parse-float)

(defvar *code_list* '(""))
(defvar *definition_list* '(""))
(defvar *implementation_list* '(""))
(defvar *target* 'code)
(defvar *paranteses* 0)
(defvar *variables* nil)
(defvar *functions* nil)
(defvar *arguments* 0)
(defvar *block* 0)
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

(defun error-missing-open-square-bracket ()
  (format t "Error missing square bracket!~%")
  (print-stack)
  (sb-ext:quit))

(defun error-missing-open-parens ()
  (format t "Error missing open parens!~%")
  (print-stack)
  (sb-ext:quit))

(defun error-missing-close-square-bracket ()
  (format t "Error missing square bracket!~%")
  (print-stack)
  (sb-ext:quit))

(defun error-missing-close-parens ()
  (format t "Error missing close parens!~%")
  (print-stack)
  (sb-ext:quit))

(defun error-variable-not-defined ()
  (format t "Error variable not defined!~%")
  (print-stack)
  (sb-ext:quit))

(defun error-function-vector-malformed ()
  (format t "Error function vector malformed!~%")
  (print-stack)
  (sb-ext:quit))

(defun error-let-vector-malformed ()
  (format t "Error let vector malformed!~%")
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

(defun emit-code-call ()
  (let ((code '(""))
        (definition '(""))
        (implementation '("")))
    (if *implementation_list*
        (format t "~%~{~a~}~%" *implementation_list*))
    (if *code_list*
        (format t "~%~{~a~}~%" *code_list*))
    (if *implementation_list*
        (setf implementation
              (format nil "~%~{~a~}~%" *implementation_list*)))
    (if *code_list*
        (if (not (is-main-defined-p))
            (setf code (format nil "int main () ~%{~%~{~a~}~%" *code_list*))
            (setf code (format nil "~{~a~}~%" *code_list*))))
    (if (not (is-main-defined-p))
        (setf code (format nil "~a}" code)))
    (values code definition implementation)))

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
  (setq *paranteses* (1+ *paranteses*)))

(defun dec-parens ()
  (setq *paranteses* (1- *paranteses*)))

(defun inc-block ()
  (setq *block* (+ 1 *block*))
  (zero-hash-variables))

(defun dec-block ()
  (zero-hash-variables)
  (setq *block* (- *block* 1)))

(defun zero-parens ()
  (setq *paranteses* 0))

(defun zero-block ()
  (setq *block* 0))

(defun zero-hash-variables ()
  (mapcar #'(lambda (var) (setf (gethash (get-variable-name var) *variables*) nil) var)
          (hash-table-keys *variables*)))

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

(defun add-code (expression)
  (if expression
      (cond ((equal *target* 'code)
             (setf *code_list* (append *code_list* (list expression))))
            ((equal *target* 'implementation)
             (setf *implementation_list* (append *implementation_list* (list expression))))
            ((equal *target* 'definition)
             (setf *definition_list* (append *definition_list* (list expression)))))))

(defun get-last-code ()
  (cond ((equal *target* 'code)
         (car (reverse *code_list*)))
        ((equal *target* 'implementation)
         (car (reverse  *implementation_list*)))
        ((equal *target* 'definition)
         (car (reverse *definition_list*)))))

(defun get-previous-last-code ()
  (cond ((equal *target* 'code)
         (cadr (reverse *code_list*)))
        ((equal *target* 'implementation)
         (cadr (reverse  *implementation_list*)))
        ((equal *target* 'definition)
         (cadr (reverse *definition_list*)))))

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

(defun inspect-function-type(expr-list)
  (if (equal "(" (car expr-list))
      (cond ((remove-if-not #'(lambda (x)
                                (equal x (get-function-name (cadr expr-list))))
                            (hash-table-keys *functions*))
             (return-from inspect-function-type (gethash (get-function-name (cadr expr-list)) *functions*))))))

(defun parse-argument (expr-list)
  (cond ((find #\: (car expr-list))
         (let ((def (split ":" (car expr-list))))
           (dbg "parse-argument: DEFINE " (car expr-list))
           (inc-arg)
           (cond ((equal "int16" (cadr def))
                  (add-code "short")
                  (setf (gethash (get-variable-name (car def)) *variables*) 'integer))
                 ((equal "int32" (cadr def))
                  (add-code "int")
                  (setf (gethash (get-variable-name (car def)) *variables*) 'integer))
                 ((equal "int64" (cadr def))
                  (add-code "long")
                  (setf (gethash (get-variable-name (car def)) *variables*) 'bigint))
                 ((equal "float32" (cadr def))
                  (add-code "float")
                  (setf (gethash (get-variable-name (car def)) *variables*) 'single-float))
                 ((equal "float64" (cadr def))
                  (add-code "double")
                  (setf (gethash (get-variable-name (car def)) *variables*) 'double-float))
                 ((equal "bool" (cadr def))
                  (add-code "bool")
                  (setf (gethash (get-variable-name (car def)) *variables*) 'boolean))
                 ((equal "byte" (cadr def))
                  (add-code "char")
                  (setf (gethash (get-variable-name (car def)) *variables*) 'char))
                 ((equal "string" (cadr def))
                  (add-code "char*")
                  (setf (gethash (get-variable-name (car def)) *variables*) 'string)))
           (add-code " ")
           (add-code (get-variable-name (car def)))
           (dbg "parse-argument: OPEN ARG")
           (if (find #\: (cadr expr-list))
               (add-code ","))
           (setf expr-list (parse-argument (cdr expr-list))))))
  expr-list)

(defun parse-type (expr-list)
  (let ((fn-name (car (split ":" (car expr-list))))
        (type (cadr (split ":" (car expr-list)))))
    (cond ((equal "int16" type)
           (add-code "short")
           (setf (gethash (get-function-name fn-name) *functions*) 'integer)
           (setf expr-list (cdr expr-list)))
          ((equal "int32" type)
           (add-code "int")
           (setf (gethash (get-function-name fn-name) *functions*) 'integer)
           (setf expr-list (cdr expr-list)))
          ((equal "int64" type)
           (add-code "long")
           (setf (gethash (get-function-name fn-name) *functions*) 'bigint)
           (setf expr-list (cdr expr-list)))
          ((equal "float32" type)
           (add-code "float")
           (setf (gethash (get-function-name fn-name) *functions*) 'single-float)
           (setf expr-list (cdr expr-list)))
          ((equal "float64" type)
           (add-code "double")
           (setf (gethash (get-function-name fn-name) *functions*) 'double-float)
           (setf expr-list (cdr expr-list)))
          ((equal "byte" type)
           (add-code "char")
           (setf (gethash (get-function-name fn-name) *functions*) 'char)
           (setf expr-list (cdr expr-list)))
          ((equal "bool" type)
           (add-code "bool")
           (setf (gethash (get-function-name fn-name) *functions*) 'boolean)
           (setf expr-list (cdr expr-list)))
          ((equal "void" type)
           (add-code "void")
           (setf (gethash (get-function-name fn-name) *functions*) 'void)
           (setf expr-list (cdr expr-list)))
          ((equal "[" type)
           (add-code "void")
           (setf (gethash (get-function-name fn-name) *functions*) 'void)))
    (dbg "parse-type: Type " type))
  expr-list)

(defun parse-function-name-and-type (expr-list)
  (cond ((stringp (car expr-list))
         (let ((fn-name (car (split ":" (car expr-list)))))
           (dbg "parse-function-name-and-type: Functionname " fn-name)
           (setf expr-list (parse-type expr-list))
           (add-code " ")
           (cond ((equal fn-name "main")
                  (setf *is-main-defined* t)
                  (add-code fn-name))
                 ((not (equal fn-name "main"))
                  (add-code (get-function-name fn-name)))))))
  (dbg "parse-function-name-and-type: EXIT Rest. " expr-list)
  expr-list)
  
(defun parse-variable (expr-list)
  (dbg "parse-variable: " (car expr-list))
  (cond ((equal "\n" (car expr-list))
         (dbg "parse-variable: RET")
         (setf expr-list (parse-variable expr-list)))
        ((find #\: (car expr-list))
         (let ((def (split ":" (car expr-list))))
           (dbg "parse-variable: DEFINE " (car expr-list))
           (cond ((equal "int16" (cadr def))
                  (add-code "short")
                  (setf (gethash (get-variable-name (car def)) *variables*) 'integer))
                 ((equal "int32" (cadr def))
                  (add-code "int")
                  (setf (gethash (get-variable-name (car def)) *variables*) 'integer))
                 ((equal "int64" (cadr def))
                  (add-code "long")
                  (setf (gethash (get-variable-name (car def)) *variables*) 'bigint))
                 ((equal "float32" (cadr def))
                  (add-code "float")
                  (setf (gethash (get-variable-name (car def)) *variables*) 'single-float))
                 ((equal "float64" (cadr def))
                  (add-code "double")
                  (setf (gethash (get-variable-name (car def)) *variables*) 'double-float))
                 ((equal "bool" (cadr def))
                  (add-code "bool")
                  (setf (gethash (get-variable-name (car def)) *variables*) 'boolean))
                 ((equal "byte" (cadr def))
                  (add-code "char")
                  (setf (gethash (get-variable-name (car def)) *variables*) 'char))
                 ((equal "string" (cadr def))
                  (add-code "char*")
                  (setf (gethash (get-variable-name (car def)) *variables*) 'string))
                 ((not (cadr def))
                  (error-no-type-def)))
           (if (or (equal "\n" (cadr expr-list)) (equal "]" (cadr expr-list)))
                  (error-no-type-def))
           (add-code " ")
           (add-code (get-variable-name (car def)))
           (add-code "=")
           (dbg "parse-variable: OPEN ARG")
           (if (equal (cadr expr-list) "]")
               (error-missing-expression))
           (dbg "parse-variable: next " (cdr expr-list))
           (setf expr-list (parse-expression (cdr expr-list)))
           (dbg "parse-variable: rest " expr-list)))
        ((not (find #\: (car expr-list)))
         (error-syntax-error)))
  expr-list)

(defun get-iter-variable-name-x (name cnt)
  (let ((hash  ""))
    (if (>= cnt 0)
        (progn
          (setf hash (format nil "~a_~a" name cnt))
          (if (gethash hash *variables*)
              (progn
                (return-from get-iter-variable-name-x hash))
              (progn
                (setf cnt (- cnt 1))
                (get-iter-variable-name-x name cnt)))))))

(defun get-iter-variable-name (name)
  (get-iter-variable-name-x name *block*))

(defun parse-block (expr-list)
  (dbg "parse-block " (car expr-list))
  (if (equal "(" (car expr-list))
      (progn
        (dbg "parse-block before expression " expr-list)
        (setf expr-list (parse-expression expr-list))
        (dbg "parse-block after expression " expr-list)
        (setf expr-list (parse-block expr-list))))
  (if (not expr-list)
      (return-from parse-block expr-list))
  (if (equal "\"" (car expr-list))
      (progn
        (dbg "parse-expression: STRING block " *block*)
        (add-code "\"")
        (setf expr-list (parse-cstr (cdr expr-list)))
        (dbg "parse-expression: STRING END " expr-list)
        (add-code (format nil ";~%"))
        (return-from parse-block expr-list)))
  (if (equal ";|" (car expr-list))
      (progn
        (dbg "parse-expression: parse multiline comment")
        (setf expr-list (parse-multiline-comment (cdr expr-list)))
        (return-from parse-block expr-list)))
  (if (equal ";" (car expr-list))
      (progn
        (dbg "parse-expression: parse singleiline comment")
        (setf expr-list (parse-single-line-comment (cdr expr-list)))
        (return-from parse-block expr-list)))
  (if (equal "\n" (car expr-list))
      (setf expr-list (parse-block (cdr expr-list))))
  (if (equal ")" (car expr-list))
      (progn
        (dbg "parse-block: CLOSE" expr-list)
        (return-from parse-block expr-list)))
  (if (not (equal ")" (car expr-list)))
      (progn
        (dbg "parse-block " (car expr-list))
        (setf expr-list (parse-block (cdr expr-list))))))

;;(defun parse-block-old (expr-list)
  ;(setf expr-list (iterate-inner-block expr-list))
  ;(cdr expr-list))
  
(defun parse-function-vector (expr-list)
  (dbg "parse-function-vector: parse variable")  
  (setf expr-list (parse-argument expr-list))
  (if (equal "]" (car expr-list))
      (return-from parse-function-vector expr-list))
  (if (equal "\n" (car expr-list))
      (setf expr-list (parse-function-vector (cdr expr-list))))
  (if (and (not (find #\: (cadr expr-list))) (not (equal "]" (cadr expr-list))))
      (error-function-vector-malformed))
  (if (not (equal "]" (car expr-list)))
      (progn
        (dbg "parse-function-vector: next variable")  
        (setf expr-list (parse-function-vector expr-list))))
  (dbg "parse-function-vector: exit")
  expr-list)

(defun parse-let-vector (expr-list)
  (dbg "parse-let-vector: parse variable")  
  (setf expr-list (parse-variable expr-list))
  (if (equal "]" (car expr-list))
      (return-from parse-let-vector expr-list))
  (if (equal "\n" (car expr-list))
      (setf expr-list (parse-let-vector (cdr expr-list))))
  (if (not (equal "]" (car expr-list)))
      (progn
        (dbg "parse-let-vector: next variable")  
        (setf expr-list (parse-let-vector expr-list))))
  (dbg "parse-let-vector: exit" (car expr-list))
  expr-list)

(defun parse-open-square-bracket (expr-list)
  (dbg "parse-open-square-bracket")  
  (if (equal "[" (car expr-list))
      (return-from parse-open-square-bracket (cdr expr-list))
      (error-missing-open-square-bracket)))

(defun parse-close-square-bracket (expr-list)
  (dbg "parse-close-square-bracket")  
  (if (equal "]" (car expr-list))
      (return-from parse-close-square-bracket (cdr expr-list))
      (error-missing-close-square-bracket)))

(defun parse-open-parens (expr-list)
  (dbg "parse-open-parens")  
  (if (equal "(" (car expr-list))
      (return-from parse-open-parens (cdr expr-list))
      (error-missing-open-parens)))

(defun parse-close-parens (expr-list)
  (dbg "parse-close-parens")  
  (if (equal ")" (car expr-list))
      (return-from parse-close-parens (cdr expr-list))
      (error-missing-close-parens)))

(defun parse-let (expr-list)
  (zero-arg)
  (inc-block)
  (dbg "parse-let: open square block " *block* " parens " *paranteses*)
  (setf expr-list (parse-open-square-bracket expr-list))
  (add-code (format nil "{~%"))
  (setf expr-list (parse-let-vector expr-list))
  (setf expr-list (parse-close-square-bracket expr-list))
  (setf expr-list (parse-block expr-list))
  (dec-block)
  (dec-parens)
  (add-code (format nil "}~%"))
  (dbg "parse-let BLOCK END  block " *block* " parens " *paranteses*)
  (dbg "parse-let " expr-list)
  expr-list)

(defun parse-def-function (expr-list)
  (zero-arg)
  (inc-block)
  (dbg "parse-def-function: name and type block " *block* " parens " *paranteses*)
  (setf expr-list (parse-function-name-and-type expr-list))
  (dbg "parse-def-function: open square")
  (add-code "(")
  (setf expr-list (parse-open-square-bracket expr-list))
  (setf expr-list (parse-function-vector expr-list))
  (setf expr-list (parse-close-square-bracket expr-list))
  (add-code ")")
  (add-code (format nil "~%{~%"))
  (setf expr-list (parse-block expr-list))
  (add-code (format nil "}~%"))
  (dec-block)
  (dec-parens)
  (dbg "parse-def-function BLOCK END block " *block* " parens " *paranteses*)
  (dbg "parse-def-function " (car expr-list))
  expr-list)

  (defun parse-multiline-comment (expr-list)
  (cond ((equal "|;" (car expr-list))
         (dbg "parse-multiline-comment: CLOSE")
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
         (add-code "\"")
         (setf expr-list (parse-arguments (cdr expr-list) *infinite-arguments*)))
        ((stringp (car expr-list))
         (add-code (car expr-list))
         (setf expr-list (parse-cstr (cdr expr-list)))))
  expr-list)

(defvar *count-parens* 0)

(defun count-elements-x (element count)
  (flood:dbg "count-elements-x: ELEMENT " element)
  (if (not (gethash (format nil "~a" *count-parens*) count))
          (setf (gethash (format nil "~a" *count-parens*) count) 0))
  (if (equal "(" element)
      (progn
        (setf (gethash (format nil "~a" *count-parens*) count)
              (1+ (gethash (format nil "~a" *count-parens*) count)))
        (flood:dbg "(")
        (flood:dbg "hash " (gethash (format nil "~a" *count-parens*) count))
        (setf *count-parens* (1+ *count-parens*))))
  (if (and (stringp element)
           (not (equal "(" element))
           (not (equal ")" element)))
      (progn
        (setf (gethash (format nil "~a" *count-parens*) count)
              (1+ (gethash (format nil "~a" *count-parens*) count)))
        (flood:dbg "TOKEN")
        (flood:dbg "hash " (gethash (format nil "~a" *count-parens*) count))
        (flood:dbg "*count-parens* " *count-parens*)))
  (if (equal ")" element)
      (progn
        (flood:dbg ")")
        (flood:dbg "hash " (gethash (format nil "~a" *count-parens*) count))
        (setf *count-parens* (1- *count-parens*))))
  (if (not (gethash (format nil "~a" *count-parens*) count))
      (setf (gethash (format nil "~a" *count-parens*) count) 0))
  count)
      
(defun count-elements (expr-list)
  (let ((count (make-hash-table :test 'equal)))
    (setf *count-parens* 1)
    (dolist (element expr-list)
      (if (not (= *count-parens* 0))
          (setf count (count-elements-x element count))))
    (gethash "1" count)))

(defun parse-arguments (expr-list max)
  (cond ((equal "(" (car expr-list))
         (progn
           (inc-arg)
           (inc-parens)
           (if (and *paranteses* (not (equal "(" (get-last-code))))
               (add-code ","))
           (dbg "parse-arguments: OPEN ARG ( block " *block* " Parens " *paranteses*)
           (setf expr-list (parse-call (cdr expr-list)))))
        ((equal "\"" (car expr-list))
         (if (and *paranteses*
                  (not (equal "(" (get-last-code))))
             (add-code ","))
         (add-code "\"")
         (setf expr-list (parse-cstr (cdr expr-list))))
        ((equal ")" (car expr-list))
         (progn
           (dec-arg)
           (if (> (- *paranteses* *block*) 0)
               (dec-parens))
           (dbg "parse-arguments: block " *block* " Parens " *paranteses*)
           (cond ((> (- *paranteses* *block*) 0)
                  (progn
                    (add-code ")")
                    (setf expr-list (cdr expr-list))
                    (setf expr-list (parse-arguments expr-list max))))
                 ((<= (- *paranteses* *block*) 0)
                  (progn
                    (add-code (format nil ");~%"))
                    (dbg "parse-arguments: ende " expr-list)
                    (return-from parse-arguments expr-list))))))
        ((equal "," (car expr-list))
         (error-syntax-error))
        ((numberp (parse-integer (car expr-list) :junk-allowed t))
         (progn
           (dbg "parse-arguments: NUMBERP " expr-list)
           (inc-arg)
           (if (and (gethash *paranteses* *arguments*)
                    (not (equal "(" (get-last-code))))
               (add-code ","))
           (if (> (gethash *paranteses* *arguments*) max)
               (error-parameter-max (gethash *paranteses* *arguments*)
                                    max))
           (progn
             ; convert lisp double-float to c double
             (setf (car expr-list) (regex-replace-all "d0" (car expr-list) "f"))
             (add-code (car expr-list))
             (setf expr-list (parse-arguments (cdr expr-list) max)))))
        ((remove-if-not #'(lambda (x)
                             (equal x (get-iter-variable-name (car expr-list))))
                         (hash-table-keys *variables*))
         (progn
           (PRINT (hash-table-keys *variables*))
           (inc-arg)
           (if (and (gethash *paranteses* *arguments*)
                        (not (equal "(" (get-last-code))))
               (add-code ","))
           (if (> (gethash *paranteses* *arguments*) max)
               (error-parameter-max (gethash *paranteses* *arguments*)
                                    max))
           (dbg "parse-arguments: VARIABLE " (get-iter-variable-name (car expr-list)))
           (add-code (get-iter-variable-name (car expr-list)))
           (setf expr-list (parse-arguments (cdr expr-list) max))))
        ((stringp (car expr-list))
         (dbg "parse-call: VARIABLE not defined: " (car expr-list))
         (error-variable-not-defined)))
  expr-list)

(defun parse-call (expr-list)
  (cond ((equal "(" (car expr-list))
         (progn
           (inc-parens)
           (dbg "parse-call: CALL OPEN ( block " *block* " Parens " *paranteses*)
           (setf expr-list (parse-call (cdr expr-list)))))
        ((equal ")" (car expr-list))
         (progn
           (setf expr-list (parse-arguments expr-list *infinite-arguments*))
           (return-from parse-call (cdr expr-list))))
        ((equal "," (car expr-list))
         (error-syntax-error))
        ((equal "\n" (car expr-list))
         (dbg "parse-call: RET")
         (setf expr-list (parse-call (cdr expr-list))))
        ((equal "set" (car expr-list))
         (add-code (get-iter-variable-name (cadr expr-list)))
         (add-code "=")
         (add-code "(")
         (zero-arg)
         (setf expr-list (parse-arguments (cddr expr-list) *infinite-arguments*))
         (return-from parse-call expr-list))
        ((or (equal "add" (car expr-list)) (equal "+" (car expr-list)))
         (let ((variable-type (gethash (get-iter-variable-name (cadr expr-list)) *variables*))
               (number-type (type-of-number-string (cadr expr-list)))
               (function-type (inspect-function-type (cdr expr-list)))
               (tp nil))
           (dbg "parse-call: println BLOCK " *block* " Parens " *paranteses*)
           (cond ((remove-if-not #'(lambda (x)
                                     (equal x (get-iter-variable-name (cadr expr-list))))
                                 (hash-table-keys *variables*))
                  (setf tp variable-type))
                 (function-type
                  (setf tp function-type))
                 (number-type
                  (setf tp number-type)))
           (cond ((equal tp 'integer)
                  (add-code "add_int32"))
                 ((equal tp 'bigint)
                  (add-code "add_int64"))
                 ((equal tp 'double-float)
                  (add-code "add_float64"))
                 ((equal tp 'single-float)
                  (add-code "add_float32")))
           (add-code "(")
           (add-code (format nil "~a" (1- (count-elements expr-list))))
           (inc-arg)
           (zero-arg)
           (dbg "parse-call: println Next arg " (cdr expr-list))
           (setf expr-list (parse-arguments (cdr expr-list) (1- (count-elements expr-list))))))
        ((equal "print-format" (car expr-list))
         (progn
           (add-code "print_format")
           (add-code "(")
           (zero-arg)
           (setf expr-list (parse-arguments (cdr expr-list) *infinite-arguments*))))
        ((equal "println" (car expr-list))
         (let ((variable-type (gethash (get-iter-variable-name (cadr expr-list)) *variables*))
               (number-type (type-of-number-string (cadr expr-list)))
               (function-type (inspect-function-type (cdr expr-list)))
               (tp nil))
           (dbg "parse-call: println BLOCK " *block* " Parens " *paranteses*)
           (cond ((remove-if-not #'(lambda (x)
                                     (equal x (get-iter-variable-name (cadr expr-list))))
                                 (hash-table-keys *variables*))
                  (setf tp variable-type))
                 (function-type
                  (setf tp function-type))
                 (number-type
                  (setf tp number-type)))
           (cond ((equal tp 'integer)
                  (add-code "println_int32"))
                 ((equal tp 'bigint)
                  (add-code "println_int64"))
                 ((equal tp 'double-float)
                  (add-code "println_float64"))
                 ((equal tp 'single-float)
                  (add-code "println_float32"))
                 ((equal tp 'string)
                  (add-code "println_str")))
         (add-code "(")
         (zero-arg)
         (dbg "parse-call: println Next arg " (cdr expr-list))
         (setf expr-list (parse-arguments (cdr expr-list) 1))))
        ((equal "print" (car expr-list))
         (let ((variable-type (gethash (get-iter-variable-name (cadr expr-list)) *variables*))
               (number-type (type-of-number-string (cadr expr-list)))
               (function-type (inspect-function-type (cdr expr-list)))
               (tp nil))
           (cond ((remove-if-not #'(lambda (x)
                                     (equal x (get-iter-variable-name (cadr expr-list))))
                                 (hash-table-keys *variables*))
                  (setf tp variable-type))
                 (function-type
                  (setf tp function-type))
                 (number-type
                  (setf tp number-type)))
           (cond ((equal tp 'integer)
                  (add-code "print_int32"))
                 ((equal tp 'bigint)
                  (add-code "print_int65"))
                 ((equal tp 'double-float)
                  (add-code "print_float64"))
                 ((equal tp 'single-float)
                  (add-code "print_float32"))
                 ((equal tp 'string)
                  (add-code "print_str")))
           (add-code "(")
           (zero-arg)
           (dbg "parse-call: print Next arg " (cdr expr-list))
           (setf expr-list (parse-arguments (cdr expr-list) 1))))
        ((equal "let" (car expr-list))
         (progn
           (zero-arg)
           (dbg "parse-call: LET INC BLOCK " *block* " PARENS " *paranteses*)
           (setf expr-list (parse-let (cdr expr-list)))))
        ((or (equal "mod" (car expr-list))
             (equal "%" (car expr-list)))
         (progn
           (add-code "mod")
           (add-code "(")
           (zero-arg)
           (dbg "parse-call: MOD block " *block* " PARENS " *paranteses*)
           (setf expr-list (parse-arguments (cdr expr-list) 2))))
        ((equal "defn" (car expr-list))
         (zero-arg)
         (setf *target* 'implementation)
         (dbg "parse-call: DEFN INC BLOCK " (cdr expr-list))
         (setf expr-list (parse-def-function (cdr expr-list)))
         (setf *target* 'code))
        ((equal "return" (car expr-list))
         (add-code "return")
         (add-code "(")
         (zero-arg)
         (setf expr-list (parse-arguments (cdr expr-list) 1))
         (return-from parse-call expr-list))
        ((remove-if-not #'(lambda (x)
                            (equal x (get-function-name (car expr-list))))
                        (hash-table-keys *functions*))
         (progn
           (add-code (get-function-name (car expr-list)))
           (add-code "(")
           (zero-arg)
           (setf expr-list (parse-arguments (cdr expr-list) *infinite-arguments*))))
        ((stringp (car expr-list))
         (dbg "parse-call: FN not defined: " (car expr-list))
         (error-function-not-defined)))
   expr-list)


(defun parse-expression (expr-list)
  (if (car expr-list)
      (progn
        (if (equal "," (car expr-list))
            (error-syntax-error))        
        (if (equal "\n" (car expr-list))
            (progn
              (setf expr-list (cdr expr-list))
              (dbg "parse-expression: caught \n")
              (return-from parse-expression expr-list)))
        (if (equal "\"" (car expr-list))
            (progn
              (dbg "parse-expression: STRING block " *block*)
              (add-code "\"")
              (setf expr-list (parse-cstr (cdr expr-list)))
              (dbg "parse-expression: STRING END " expr-list)
              (add-code (format nil ";~%"))
              (return-from parse-expression expr-list)))
        (if (equal ";|" (car expr-list))
            (progn
              (dbg "parse-expression: parse multiline comment")
              (setf expr-list (parse-multiline-comment (cdr expr-list)))
              (return-from parse-expression expr-list)))
        (if (equal ";" (car expr-list))
            (progn
              (dbg "parse-expression: parse singleiline comment")
              (setf expr-list (parse-single-line-comment (cdr expr-list)))
              (return-from parse-expression expr-list)))
        (if (numberp (parse-integer (car expr-list) :junk-allowed t))
            (progn
              (dbg "parse-expression: NUM block " *block* " number " (car expr-list))
              (add-code (car expr-list))
              (add-code (format nil ";~%"))
              (return-from parse-expression (cdr expr-list))))
        (if (not (or (equal "," (car expr-list))
                     (equal "\n" (car expr-list))
                     (equal "(" (car expr-list))
                     (equal ")" (car expr-list))
                     (equal "[" (car expr-list))
                     (equal "]" (car expr-list))
                     (equal "\"" (car expr-list))
                     (equal ";|" (car expr-list))
                     (equal "|;" (car expr-list))
                     (equal ";" (car expr-list))
                     (numberp (parse-integer (car expr-list) :junk-allowed t))))
            (progn
              (dbg "parse-expression: SYMBOL " (car expr-list))
              (setf expr-list (cdr expr-list))
              (return-from parse-expression expr-list)))
        (if (equal "(" (car expr-list))
            (progn
              (setf expr-list (parse-open-parens expr-list))
              (inc-arg)
              (inc-parens)
              (dbg "parse-expression: OPEN parens " *paranteses* " block " *block*)
              (setf expr-list (parse-call expr-list))
              (dbg "parse-expression: CALL END rest " expr-list " parens " *paranteses* " block " *block*)
              (if (car expr-list)
                  (setf expr-list (parse-close-parens expr-list)))
              ;(dec-parens)
              (dbg "parse-expression: CLOSE parens " *paranteses* " block " *block*)
              (zero-arg)
              (return-from parse-expression expr-list))))))

(defun parse (expression)
  "Parse expression."
  (let ((expr-list (preprocess expression)))
    (setf *code_list* '(""))
    (setf *implementation_list* '(""))
    (setf *definition_list* '(""))
    (setf *paranteses* 0)
    (setf  *block* 0)
    (setf *arguments* (make-hash-table))
    (setf *variables* (make-hash-table :test 'equal))
    (setf *functions* (make-hash-table :test 'equal))
    (setf (gethash *paranteses* *arguments*) 0)
    (loop while (and (find "(" expr-list :test #'equal)
                     (> (length expr-list) 0)) do
         (setf expr-list (parse-expression expr-list))))
  (emit-code-call))

(defun repl ()
  (format t "~%>")
  (loop for input = (read-line)
       while input do
       (parse input)
       (format t "~%>")))

(defun evaluate (expression)
  (parse expression))

(defun compile-next (infile outfile)
  (let ((infile-data (load-binary-data infile)))
    (load-templates)
    (multiple-value-bind (code definition implementation) (parse infile-data)
      (declare (ignore definition))
      (let* ((outfile-data (concatenate 'string *impl-template* code))
             (outfilename (pathname-name outfile))
             (outfilepath (directory-namestring outfile)))
        (setf outfile-data (regex-replace-all "\\$\\(OUTPUT_H\\)"
                                                 outfile-data
                                                 (concatenate 'string
                                                              outfilename ".h")))
        (setf outfile-data (regex-replace-all "\\$\\(IMPLEMENTATION\\)"
                                              outfile-data
                                              implementation))
        (save-binary-data (concatenate 'string
                                          outfilepath
                                          outfilename ".h") *def-template*)
        (save-binary-data (concatenate 'string
                                       outfilepath
                                       outfilename ".c") outfile-data)))))

