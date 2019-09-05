;;; -----------------------------------------------------
;;; next
;;; -----------------------------------------------------
;;; File:     /Users/edward/Documents/Code/common-lisp/projects/next/src/next.lisp
;;; Date:     09:29:15 of Wednesday, 8/14/2019 (GMT+1)
;;; Author:   Edward Puccini
;;; -----------------------------------------------------

(in-package :next)

(defun setup-signatures ()
  (setf (gethash "elt" *signatures*) '("pointer" "pointer" "value"))
  (setf (gethash "set" *signatures*) '("void" "pointer" "value"))
  (setf (gethash "#" *signatures*) '("pointer" "pointer" "value"))
  (setf (gethash "::" *signatures*) '("void" "pointer" "value"))
  (setf (gethash "prn" *signatures*) '("void" "value"))
  (setf (gethash "prnl" *signatures*) '("void" "value"))
  (setf (gethash "prnfmt" *signatures*) '("void" "value" "value"))
  (setf (gethash "mod" *signatures*) '("value" "value" "value"))
  (setf (gethash "add" *signatures*) '("value" "value" "value"))
  (setf (gethash "sub" *signatures*) '("value" "value" "value"))
  (setf (gethash "mul" *signatures*) '("value" "value" "value"))
  (setf (gethash "div" *signatures*) '("value" "value" "value"))
  (setf (gethash "sqrt" *signatures*) '("value" "value" "value"))
  (setf (gethash "power" *signatures*) '("value" "value" "value"))
  (setf (gethash "max" *signatures*) '("value" "value" "value"))
  (setf (gethash "min" *signatures*) '("value" "value" "value"))
  (setf (gethash "map" *signatures*) '("pointer" "function" "pointer"))
  (setf (gethash "mapn" *signatures*) '("pointer" "function" "pointer"))
  (setf (gethash "size" *signatures*) '("void" "pointer"))
  (setf (gethash "@" *signatures*) '("void" "pointer"))
  (setf (gethash "new_bool" *signatures*) '("pointer" "value"))
  (setf (gethash "new_b8" *signatures*) '("pointer" "value"))
  (setf (gethash "new_c8" *signatures*) '("pointer" "value"))
  (setf (gethash "new_i16" *signatures*) '("pointer" "value"))
  (setf (gethash "new_i32" *signatures*) '("pointer" "value"))
  (setf (gethash "new_i64" *signatures*) '("pointer" "value"))
  (setf (gethash "new_f32" *signatures*) '("pointer" "value"))
  (setf (gethash "new_f64" *signatures*) '("pointer" "value"))
  (setf (gethash "push" *signatures*) '("void" "pointer" "value"))
  (setf (gethash "append" *signatures*) '("void" "value" "pointer"))  
  (setf (gethash "car" *signatures*) '("value" "pointer"))
  (setf (gethash "cdr" *signatures*) '("pointer" "pointer"))
  (setf (gethash "bool" *signatures*) '("value" "void"))
  (setf (gethash "b8" *signatures*) '("value" "void"))
  (setf (gethash "c8" *signatures*) '("value" "void"))
  (setf (gethash "i16" *signatures*) '("value" "value"))
  (setf (gethash "i32" *signatures*) '("value" "value"))
  (setf (gethash "i64" *signatures*) '("value" "value"))
  (setf (gethash "f32" *signatures*) '("value" "value"))
  (setf (gethash "f64" *signatures*) '("value" "value"))  
  (setf (gethash "bool>" *signatures*) '("pointer" "value"))
  (setf (gethash "b8>" *signatures*) '("pointer" "pointer"))
  (setf (gethash "c8>" *signatures*) '("pointer" "pointer"))
  (setf (gethash "i16>" *signatures*) '("pointer" "pointer"))
  (setf (gethash "i32>" *signatures*) '("pointer" "pointer"))
  (setf (gethash "i64>" *signatures*) '("pointer" "pointer"))
  (setf (gethash "f32>" *signatures*) '("pointer" "pointer"))
  (setf (gethash "f64>" *signatures*) '("pointer" "pointer"))  
  (setf (gethash "reduce" *signatures*) '("pointer" "function" "pointer"))
  (setf (gethash "lt" *signatures*) '("value" "value" "value"))
  (setf (gethash "leqt" *signatures*) '("value" "value" "value"))
  (setf (gethash "gt" *signatures*) '("value" "value" "value"))
  (setf (gethash "geqt" *signatures*) '("value" "value" "value"))
  (setf (gethash "eq" *signatures*) '("value" "value" "value"))
  (setf (gethash "neq" *signatures*) '("value" "value" "value"))
  (set-function-type "elt" 'integer)
  (set-function-type "set" 'integer)
  (set-function-type "#" 'integer)
  (set-function-type "->" 'integer)
  (set-function-type "@" 'integer)
  (set-function-type "bool" 'boolean)
  (set-function-type "elt_b8" 'char)
  (set-function-type "elt_i16" 'short-integer)
  (set-function-type "elt_i32" 'integer)
  (set-function-type "elt_i64" 'bigint)
  (set-function-type "elt_f32" 'single-float)
  (set-function-type "elt_f64" 'double-float)
  (set-function-type "set_b8" 'char)
  (set-function-type "set_i16" 'short-integer)
  (set-function-type "set_i32" 'integer)
  (set-function-type "set_i64" 'bigint)
  (set-function-type "set_f32" 'single-float)
  (set-function-type "set_f64" 'double-float)
  (set-function-type "b8" 'byte)
  (set-function-type "c8" 'char)
  (set-function-type "i16" 'short-integer)
  (set-function-type "i32" 'integer)
  (set-function-type "i64" 'bigint)
  (set-function-type "f32" 'single-float)
  (set-function-type "f64" 'double-float)
  (set-function-type "b8>" 'byte-pointer)
  (set-function-type "c8>" 'char-pointer)
  (set-function-type "i16>" 'short-integer-pointer)
  (set-function-type "i32>" 'integer-pointer)
  (set-function-type "i64>" 'bigint-pointer)
  (set-function-type "f32>" 'single-float-pointer)
  (set-function-type "f64>" 'double-float-pointer)
  (set-function-type "add" 'double-float)
  (set-function-type "sub" 'double-float)
  (set-function-type "mul" 'double-float)
  (set-function-type "div" 'double-float)
  (set-function-type "sqrt" 'single-float)
  (set-function-type "power" 'single-float)
  (set-function-type "size" 'integer)
  (set-function-type "+" 'double-float)
  (set-function-type "-" 'double-float)
  (set-function-type "*" 'double-float)
  (set-function-type "/" 'double-float)
  (set-function-type "√" 'single-float)
  (set-function-type "^" 'single-float)
  (set-function-type "max" 'integer)
  (set-function-type "min" 'integer))

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
        (inf "Save definition to " outfile)
        (save-binary-data (concatenate 'string
                                          outfilepath
                                          outfilename ".h") definition-data)
        (inf "Save implementation to " outfile)
        (save-binary-data (concatenate 'string
                                       outfilepath
                                       outfilename ".c") outfile-data)))))

