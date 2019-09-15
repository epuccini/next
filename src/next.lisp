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
  (setf (gethash "len" *signatures*) '("value" "pointer"))
  (setf (gethash "prnstr" *signatures*) '("void" "pointer" "value"))
  (setf (gethash "prn" *signatures*) '("void" "value"))
  (setf (gethash "prnl" *signatures*) '("void" "value"))
  (setf (gethash "prnfmt" *signatures*) '("void" "value" "value"))
  (setf (gethash "open" *signatures*) '("value" "value" "value"))
  (setf (gethash "close" *signatures*) '("value" "value"))
  (setf (gethash "read-line" *signatures*) '("value" "value" "pointer"))
  (setf (gethash "write-line" *signatures*) '("value" "value" "value"))
  (setf (gethash "read-binary" *signatures*) '("value" "pointer" "value" "value" "value"))
  (setf (gethash "write-binary" *signatures*) '("value" "pointer" "value" "value" "value"))
  (setf (gethash "mod" *signatures*) '("value" "value" "value"))
  (setf (gethash "add" *signatures*) '("value" "value" "value"))
  (setf (gethash "sub" *signatures*) '("value" "value" "value"))
  (setf (gethash "mul" *signatures*) '("value" "value" "value"))
  (setf (gethash "div" *signatures*) '("value" "value" "value"))
  (setf (gethash "sqrt" *signatures*) '("value" "value" "value"))
  (setf (gethash "power" *signatures*) '("value" "value" "value"))
  (setf (gethash "max" *signatures*) '("value" "value" "value"))
  (setf (gethash "min" *signatures*) '("value" "value" "value"))
  (setf (gethash "fabs" *signatures*) '("value" "value" "value"))
  (setf (gethash "atan" *signatures*) '("value" "value" "value"))
  (setf (gethash "acos" *signatures*) '("value" "value" "value"))
  (setf (gethash "asin" *signatures*) '("value" "value" "value"))
  (setf (gethash "asin2" *signatures*) '("value" "value" "value"))
  (setf (gethash "cos" *signatures*) '("value" "value" "value"))
  (setf (gethash "cosh" *signatures*) '("value" "value" "value"))
  (setf (gethash "sin" *signatures*) '("value" "value" "value"))
  (setf (gethash "sinh" *signatures*) '("value" "value" "value"))
  (setf (gethash "tanh" *signatures*) '("value" "value" "value"))
  (setf (gethash "exp" *signatures*) '("value" "value" "value"))
  (setf (gethash "log" *signatures*) '("value" "value" "value"))
  (setf (gethash "log10" *signatures*) '("value" "value" "value"))
  (setf (gethash "floor" *signatures*) '("value" "value" "value"))
  (setf (gethash "ceil" *signatures*) '("value" "value" "value"))
  (setf (gethash "round" *signatures*) '("value" "value" "value"))
  (setf (gethash "fmod" *signatures*) '("value" "value" "value"))
  (setf (gethash "map" *signatures*) '("pointer" "function" "pointer"))
  (setf (gethash "mapn" *signatures*) '("pointer" "function" "pointer"))
  (setf (gethash "size" *signatures*) '("void" "pointer"))
  (setf (gethash "@" *signatures*) '("void" "pointer"))
  (setf (gethash "destroy" *signatures*) '("void" "void"))
  (setf (gethash "del" *signatures*) '("void" "pointer"))
  (setf (gethash "new" *signatures*) '("pointer" "value"))
  (setf (gethash "new_bool" *signatures*) '("pointer" "value"))
  (setf (gethash "new_b8" *signatures*) '("pointer" "value"))
  (setf (gethash "new_c8" *signatures*) '("pointer" "value"))
  (setf (gethash "new_i16" *signatures*) '("pointer" "value"))
  (setf (gethash "new_i32" *signatures*) '("pointer" "value"))
  (setf (gethash "new_i64" *signatures*) '("pointer" "value"))
  (setf (gethash "new_f32" *signatures*) '("pointer" "value"))
  (setf (gethash "new_f64" *signatures*) '("pointer" "value"))
  (setf (gethash "new_f80" *signatures*) '("pointer" "value"))
  (setf (gethash "push" *signatures*) '("pointer" "handle" "value"))
  (setf (gethash "append" *signatures*) '("void" "value" "pointer"))  
  (setf (gethash "remove" *signatures*) '("pointer" "pointer" "value"))  
  (setf (gethash "car" *signatures*) '("value" "pointer"))
  (setf (gethash "cdr" *signatures*) '("pointer" "pointer"))
  (setf (gethash "cdrn" *signatures*) '("pointer" "pointer"))
  (setf (gethash "bool" *signatures*) '("value" "void"))
  (setf (gethash "b8" *signatures*) '("value" "void"))
  (setf (gethash "c8" *signatures*) '("value" "void"))
  (setf (gethash "i16" *signatures*) '("value" "value"))
  (setf (gethash "i32" *signatures*) '("value" "value"))
  (setf (gethash "i64" *signatures*) '("value" "value"))
  (setf (gethash "f32" *signatures*) '("value" "value"))
  (setf (gethash "f64" *signatures*) '("value" "value"))
  (setf (gethash "f80" *signatures*) '("value" "value"))  
  (setf (gethash "bool>" *signatures*) '("pointer" "value"))
  (setf (gethash "b8>" *signatures*) '("pointer" "pointer"))
  (setf (gethash "c8>" *signatures*) '("pointer" "pointer"))
  (setf (gethash "i16>" *signatures*) '("pointer" "pointer"))
  (setf (gethash "i32>" *signatures*) '("pointer" "pointer"))
  (setf (gethash "i64>" *signatures*) '("pointer" "pointer"))
  (setf (gethash "f32>" *signatures*) '("pointer" "pointer"))
  (setf (gethash "f64>" *signatures*) '("pointer" "pointer"))
  (setf (gethash "f80>" *signatures*) '("pointer" "pointer"))
  (setf (gethash "defp" *signatures*) '("void" "value" "value"))
  (setf (gethash "deref" *signatures*) '("value" "pointer"))
  (setf (gethash "?" *signatures*) '("value" "pointer"))
  (setf (gethash "ref" *signatures*) '("pointer" "value"))
  (setf (gethash "&" *signatures*) '("pointer" "value"))  
  (setf (gethash "reduce" *signatures*) '("pointer" "function" "pointer"))
  (setf (gethash "lt" *signatures*) '("value" "value" "value"))
  (setf (gethash "leqt" *signatures*) '("value" "value" "value"))
  (setf (gethash "gt" *signatures*) '("value" "value" "value"))
  (setf (gethash "geqt" *signatures*) '("value" "value" "value"))
  (setf (gethash "eq" *signatures*) '("value" "value" "value"))
  (setf (gethash "neq" *signatures*) '("value" "value" "value"))
  (setf (gethash "trunc" *signatures*) '("value" "value"))
  (setf (gethash ">>" *signatures*) '("value" "value"))
  (setf (gethash "<<" *signatures*) '("value" "value"))  
  (setf (gethash "shiftr" *signatures*) '("value" "value"))
  (setf (gethash "shiftr" *signatures*) '("value" "value"))  
  (set-function-type "trunc" 'single-float)
  (set-function-type "string-to-i32" 'integer)
  (set-function-type "string-to-f32" 'single-float)
  (set-function-type "len" 'integer)
  (set-function-type "elt" 'integer)
  (set-function-type "set" 'integer)
  (set-function-type "#" 'integer)
  (set-function-type "->" 'integer)
  (set-function-type "@" 'integer)
  (set-function-type "bool" 'boolean)
  (set-function-type "push" 'integer-list)
  (set-function-type "open" 'file)
  (set-function-type "close" 'short-integer)
  (set-function-type "read-line" 'string)
  (set-function-type "write-line" 'integer)
  (set-function-type "read-binary" 'unsigned-long-integer)
  (set-function-type "write-binary" 'unsigned-long-integer)
  (set-function-type "elt_b8" 'char)
  (set-function-type "elt_i16" 'short-integer)
  (set-function-type "elt_i32" 'integer)
  (set-function-type "elt_i64" 'bigint)
  (set-function-type "elt_f32" 'single-float)
  (set-function-type "elt_f64" 'double-float)
  (set-function-type "elt_f80" 'long-double-float)
  (set-function-type "set_b8" 'char)
  (set-function-type "set_i16" 'short-integer)
  (set-function-type "set_i32" 'integer)
  (set-function-type "set_i64" 'bigint)
  (set-function-type "set_f32" 'single-float)
  (set-function-type "set_f64" 'double-float)
  (set-function-type "set_f80" 'long-double-float)
  (set-function-type "bool" 'boolean)
  (set-function-type "string" 'string)
  (set-function-type "cstring" 'const-string)
  (set-function-type "file" 'file)
  (set-function-type "b8" 'byte)
  (set-function-type "c8" 'char)
  (set-function-type "i16" 'short-integer)
  (set-function-type "i32" 'integer)
  (set-function-type "i64" 'bigint)
  (set-function-type "ui16" 'unsigned-short-integer)
  (set-function-type "ui32" 'unsigned-integer)
  (set-function-type "ui64" 'unsigned-bigint)
  (set-function-type "f32" 'single-float)
  (set-function-type "f64" 'double-float)
  (set-function-type "f80" 'long-double-float)
  (set-function-type "bool>" 'boolean-pointer)
  (set-function-type "string>" 'string-pointer)
  (set-function-type "cstring>" 'const-string-pointer)
  (set-function-type "file>" 'file-pointer)
  (set-function-type "b8>" 'byte-pointer)
  (set-function-type "c8>" 'char-pointer)
  (set-function-type "i16>" 'short-integer-pointer)
  (set-function-type "i32>" 'integer-pointer)
  (set-function-type "i64>" 'bigint-pointer)
  (set-function-type "ui16>" 'unsigned-short-integer-pointer)
  (set-function-type "ui32>" 'unsigned-integer-pointer)
  (set-function-type "ui64>" 'unsigned-bigint-pointer)
  (set-function-type "f32>" 'single-float-pointer)
  (set-function-type "f64>" 'double-float-pointer)
  (set-function-type "f80>" 'long-double-float-pointer)
  (set-function-type "bool>>" 'boolean-handle)
  (set-function-type "string>>" 'string-handle)
  (set-function-type "cstring>>" 'const-string-handle)
  (set-function-type "file>>" 'file-handle)
  (set-function-type "b8>>" 'byte-handle)
  (set-function-type "c8>>" 'char-handle)
  (set-function-type "i16>>" 'short-integer-handle)
  (set-function-type "i32>>" 'integer-handle)
  (set-function-type "i64>>" 'bigint-handle)
  (set-function-type "ui16>>" 'unsigned-short-integer-handle)
  (set-function-type "ui32>>" 'unsigned-integer-handle)
  (set-function-type "ui64>>" 'unsigned-bigint-handle)
  (set-function-type "f32>>" 'single-float-handle)
  (set-function-type "f64>>" 'double-float-handle)
  (set-function-type "f80>>" 'long-double-float-handle)
  (set-function-type "add" 'double-float)
  (set-function-type "sub" 'double-float)
  (set-function-type "mul" 'double-float)
  (set-function-type "div" 'double-float)
  (set-function-type "sqrt" 'single-float)
  (set-function-type "power" 'single-float)
  (set-function-type "size" 'integer)
  (set-function-type "fabs" 'double-float)
  (set-function-type "atan" 'double-float)
  (set-function-type "acos" 'double-float)
  (set-function-type "asin" 'double-float)
  (set-function-type "asin2" 'double-float)
  (set-function-type "cos" 'double-float)
  (set-function-type "cosh" 'double-float)
  (set-function-type "sin" 'double-float)
  (set-function-type "sinh" 'double-float)
  (set-function-type "tanh" 'double-float)
  (set-function-type "exp" 'double-float)
  (set-function-type "log" 'double-float)
  (set-function-type "log10" 'double-float)
  (set-function-type "floor" 'double-float)
  (set-function-type "ceil" 'double-float)
  (set-function-type "round" 'double-float)
  (set-function-type "fmod" 'double-float)
  (setf (gethash "shiftr" *signatures*) '("value" "value"))
  (setf (gethash "shiftr" *signatures*) '("value" "value"))  
  (set-function-type "trunc" 'single-float)
  (set-function-type "string-to-i32" 'integer)
  (set-function-type "string-to-f32" 'single-float)
  (set-function-type "len" 'integer)
  (set-function-type "elt" 'integer)
  (set-function-type "set" 'integer)
  (set-function-type "#" 'integer)
  (set-function-type "->" 'integer)
  (set-function-type "@" 'integer)
  (set-function-type "bool" 'boolean)
  (set-function-type "push" 'integer-list)
  (set-function-type "open" 'file)
  (set-function-type "close" 'short-integer)
  (set-function-type "read-line" 'string)
  (set-function-type "write-line" 'integer)
  (set-function-type "read-binary" 'unsigned-long-integer)
  (set-function-type "write-binary" 'unsigned-long-integer)
  (set-function-type "elt_b8" 'char)
  (set-function-type "elt_i16" 'short-integer)
  (set-function-type "elt_i32" 'integer)
  (set-function-type "elt_i64" 'bigint)
  (set-function-type "elt_f32" 'single-float)
  (set-function-type "elt_f64" 'double-float)
  (set-function-type "elt_f80" 'long-double-float)
  (set-function-type "set_b8" 'char)
  (set-function-type "set_i16" 'short-integer)
  (set-function-type "set_i32" 'integer)
  (set-function-type "set_i64" 'bigint)
  (set-function-type "set_f32" 'single-float)
  (set-function-type "set_f64" 'double-float)
  (set-function-type "set_f80" 'long-double-float)
  (set-function-type "bool" 'boolean)
  (set-function-type "string" 'string)
  (set-function-type "cstring" 'const-string)
  (set-function-type "file" 'file)
  (set-function-type "b8" 'byte)
  (set-function-type "c8" 'char)
  (set-function-type "i16" 'short-integer)
  (set-function-type "i32" 'integer)
  (set-function-type "i64" 'bigint)
  (set-function-type "ui16" 'unsigned-short-integer)
  (set-function-type "ui32" 'unsigned-integer)
  (set-function-type "ui64" 'unsigned-bigint)
  (set-function-type "f32" 'single-float)
  (set-function-type "f64" 'double-float)
  (set-function-type "f80" 'long-double-float)
  (set-function-type "bool>" 'boolean-pointer)
  (set-function-type "string>" 'string-pointer)
  (set-function-type "cstring>" 'const-string-pointer)
  (set-function-type "file>" 'file-pointer)
  (set-function-type "b8>" 'byte-pointer)
  (set-function-type "c8>" 'char-pointer)
  (set-function-type "i16>" 'short-integer-pointer)
  (set-function-type "i32>" 'integer-pointer)
  (set-function-type "i64>" 'bigint-pointer)
  (set-function-type "ui16>" 'unsigned-short-integer-pointer)
  (set-function-type "ui32>" 'unsigned-integer-pointer)
  (set-function-type "ui64>" 'unsigned-bigint-pointer)
  (set-function-type "f32>" 'single-float-pointer)
  (set-function-type "f64>" 'double-float-pointer)
  (set-function-type "f80>" 'long-double-float-pointer)
  (set-function-type "bool>>" 'boolean-handle)
  (set-function-type "string>>" 'string-handle)
  (set-function-type "cstring>>" 'const-string-handle)
  (set-function-type "file>>" 'file-handle)
  (set-function-type "b8>>" 'byte-handle)
  (set-function-type "c8>>" 'char-handle)
  (set-function-type "i16>>" 'short-integer-handle)
  (set-function-type "i32>>" 'integer-handle)
  (set-function-type "i64>>" 'bigint-handle)
  (set-function-type "ui16>>" 'unsigned-short-integer-handle)
  (set-function-type "ui32>>" 'unsigned-integer-handle)
  (set-function-type "ui64>>" 'unsigned-bigint-handle)
  (set-function-type "f32>>" 'single-float-handle)
  (set-function-type "f64>>" 'double-float-handle)
  (set-function-type "f80>>" 'long-double-float-handle)
  (set-function-type "add" 'double-float)
  (set-function-type "sub" 'double-float)
  (set-function-type "mul" 'double-float)
  (set-function-type "div" 'double-float)
  (set-function-type "sqrt" 'single-float)
  (set-function-type "power" 'single-float)
  (set-function-type "size" 'integer)
  (set-function-type "fabs" 'double-float)
  (set-function-type "atan" 'double-float)
  (set-function-type "acos" 'double-float)
  (set-function-type "asin" 'double-float)
  (set-function-type "asin2" 'double-float)
  (set-function-type "cos" 'double-float)
  (set-function-type "cosh" 'double-float)
  (set-function-type "sin" 'double-float)
  (set-function-type "sinh" 'double-float)
  (set-function-type "tanh" 'double-float)
  (set-function-type "exp" 'double-float)
  (set-function-type "log" 'double-float)
  (set-function-type "log10" 'double-float)
  (set-function-type "floor" 'double-float)
  (set-function-type "ceil" 'double-float)
  (set-function-type "round" 'double-float)
  (set-function-type "fmod" 'double-float)
  (set-function-type "shiftl" 'integer)
  (set-function-type "shiftr" 'integer)
  (set-function-type ">>" 'integer)
  (set-function-type "<<" 'integer)
  (set-function-type "or" 'boolean)
  (set-function-type "not" 'boolean)
  (set-function-type "and" 'boolean)
  (set-function-type "==" 'boolean)
  (set-function-type "!=" 'boolean)
  (set-function-type ">=" 'boolean)
  (set-function-type "<=" 'boolean)
  (set-function-type "equal" 'boolean)
  (set-function-type "eq" 'boolean)
  (set-function-type "neq" 'boolean)
  (set-function-type "geqt" 'boolean)
  (set-function-type "leqt" 'boolean)
  (set-function-type "gt" 'boolean)
  (set-function-type "lt" 'boolean)
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
  (dbg "compile-next: load-binary")
  (let ((infile-data (load-binary-data infile)))
    (load-templates)
    (multiple-value-bind (code definition implementation) (parse infile-data)
      (if *error*
          (progn
            (print-stack)
            (sb-ext:quit)
            (return-from compile-next)))
      (let* ((outfile-data (concatenate 'string *impl-template* code))
             (outfilename (pathname-name outfile))
             (outfilepath (directory-namestring outfile))
             (definition-data (concatenate 'string *def-template*
                                           (format nil "~a" definition))))
        (dbg "compile-next: setup data")
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

