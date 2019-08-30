;;; -----------------------------------------------------
;;; next
;;; -----------------------------------------------------
;;; File:     /Users/edward/Documents/Code/common-lisp/projects/next/src/next.lisp
;;; Date:     09:29:15 of Wednesday, 8/14/2019 (GMT+1)
;;; Author:   Edward Puccini
;;; -----------------------------------------------------

(in-package :next)

(defun setup-signatures ()
  (setf (gethash "elt" *signatures*) '("array" "array" "value"))
  (setf (gethash "set" *signatures*) '("void" "array" "value"))
  (setf (gethash "#" *signatures*) '("array" "array" "value"))
  (setf (gethash "->" *signatures*) '("void" "array" "value"))
  (setf (gethash "print" *signatures*) '("void" "value"))
  (setf (gethash "println" *signatures*) '("void" "value"))
  (setf (gethash "print-format" *signatures*) '("void" "value" "value"))
  (setf (gethash "mod" *signatures*) '("value" "value" "value"))
  (setf (gethash "add" *signatures*) '("value" "value" "value"))
  (setf (gethash "sub" *signatures*) '("value" "value" "value"))
  (setf (gethash "mul" *signatures*) '("value" "value" "value"))
  (setf (gethash "div" *signatures*) '("value" "value" "value"))
  (setf (gethash "sqrt" *signatures*) '("value" "value" "value"))
  (setf (gethash "power" *signatures*) '("value" "value" "value"))
  (setf (gethash "max" *signatures*) '("value" "value" "value"))
  (setf (gethash "min" *signatures*) '("value" "value" "value"))
  (setf (gethash "map" *signatures*) '("array" "function" "array"))
  (setf (gethash "reduce" *signatures*) '("array" "function" "array"))
  (setf (gethash "lt" *signatures*) '("value" "value" "value"))
  (setf (gethash "leqt" *signatures*) '("value" "value" "value"))
  (setf (gethash "gt" *signatures*) '("value" "value" "value"))
  (setf (gethash "geqt" *signatures*) '("value" "value" "value"))
  (setf (gethash "eq" *signatures*) '("value" "value" "value"))
  (setf (gethash "neq" *signatures*) '("value" "value" "value"))
  (set-function-type "bool" 'boolean)
  (set-function-type "byte" 'char)
  (set-function-type "int16" 'integer)
  (set-function-type "int32" 'integer)
  (set-function-type "int64" 'bigint)
  (set-function-type "float32" 'single-float)
  (set-function-type "float64" 'double-float)
  (set-function-type "add" 'double-float)
  (set-function-type "sub" 'double-float)
  (set-function-type "mul" 'double-float)
  (set-function-type "div" 'double-float)
  (set-function-type "sqrt" 'single-float)
  (set-function-type "power" 'single-float)
  (set-function-type "+" 'double-float)
  (set-function-type "-" 'double-float)
  (set-function-type "*" 'double-float)
  (set-function-type "/" 'double-float)
  (set-function-type "√" 'single-float)
  (set-function-type "^" 'single-float)
  (set-function-type "max" 'integer)
  (set-function-type "min" 'integer))

(defun get-current-function ()
  (gethash (1- *paranteses*) *current-function*))

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
      (let* ((outfile-data (concatenate 'string *impl-template* code))
             (outfilename (pathname-name outfile))
             (outfilepath (directory-namestring outfile))
             (definition-data (concatenate 'string *def-template*
                                           (format nil "~a" definition))))
        (setf outfile-data (regex-replace-all "\\$\\(OUTPUT_H\\)"
                                                 outfile-data
                                                 (concatenate 'string
                                                              outfilename ".h")))
        (setf outfile-data (regex-replace-all "\\$\\(IMPLEMENTATION\\)"
                                              outfile-data
                                              implementation))
        (save-binary-data (concatenate 'string
                                          outfilepath
                                          outfilename ".h") definition-data)
        (save-binary-data (concatenate 'string
                                       outfilepath
                                       outfilename ".c") outfile-data)))))

