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
  (setf (gethash "ixx" *signatures*) '("value" "value"))  
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
  (set-function-type "trunc" "f32")
  (set-function-type "string-to-i32" "i32")
  (set-function-type "string-to-f32" "f32")
  (set-function-type "len" "i32")
  (set-function-type "elt" "i32")
  (set-function-type "set" "i32")
  (set-function-type "#" "i32")
  (set-function-type "->" "i32")
  (set-function-type "@" "i32")
  (set-function-type "bool" "bool")
  (set-function-type "push" "i32'")
  (set-function-type "open" "file")
  (set-function-type "close" "i16")
  (set-function-type "read-line" "string")
  (set-function-type "write-line" "i32")
  (set-function-type "read-binary" "ui64")
  (set-function-type "write-binary" "ui64")
  (set-function-type "elt_b8" "c8")
  (set-function-type "elt_i16" "i16")
  (set-function-type "elt_i32" "i32")
  (set-function-type "elt_i64" "i64")
  (set-function-type "elt_f32" "f32")
  (set-function-type "elt_f64" "f64")
  (set-function-type "elt_f80" "f80")
  (set-function-type "elt_ixx" "ixx")
  (set-function-type "set_b8" "c8")
  (set-function-type "set_i16" "i16")
  (set-function-type "set_i32" "i32")
  (set-function-type "set_i64" "i64")
  (set-function-type "set_f32" "f32")
  (set-function-type "set_f64" "f64")
  (set-function-type "set_f80" "f80")
  (set-function-type "set_ixx" "ixx")
  (set-function-type "bool" "bool")
  (set-function-type "string" "string")
  (set-function-type "cstring" "cstring")
  (set-function-type "file" "file")
  (set-function-type "b8" "c8")
  (set-function-type "c8" "c8")
  (set-function-type "i16" "i16")
  (set-function-type "i32" "i32")
  (set-function-type "i64" "i64")
  (set-function-type "ui16" "ui16")
  (set-function-type "ui32" "ui32")
  (set-function-type "ui64" "ui64")
  (set-function-type "f32" "f32")
  (set-function-type "f64" "f64")
  (set-function-type "f80" "f80")
  (set-function-type "ixx" "ixx")
  (set-function-type "bool>" "bool>")
  (set-function-type "string>" "string>")
  (set-function-type "cstring>" "cstring>")
  (set-function-type "file>" "file>")
  (set-function-type "b8>" "b8>")
  (set-function-type "c8>" "c8>")
  (set-function-type "i16>" "i16>")
  (set-function-type "i32>" "i32>")
  (set-function-type "i64>" "i64>")
  (set-function-type "ui16>" "ui16>")
  (set-function-type "ui32>" "ui32>")
  (set-function-type "ui64>" "ui64>")
  (set-function-type "f32>" "f32>")
  (set-function-type "f64>" "f64>")
  (set-function-type "f80>" "f80>")
  (set-function-type "ixx>" "ixx>")
  (set-function-type "bool>>" "bool>>")
  (set-function-type "string>>" "string>>")
  (set-function-type "cstring>>" "cstring>>")
  (set-function-type "file>>" "file>>")
  (set-function-type "b8>>" "b8>>")
  (set-function-type "c8>>" "c8>>")
  (set-function-type "i16>>" "i16>>")
  (set-function-type "i32>>" "i32>>")
  (set-function-type "i64>>" "i64>>" )
  (set-function-type "ui16>>" "ui16>>")
  (set-function-type "ui32>>" "ui32>>")
  (set-function-type "ui64>>" "ui64>>")
  (set-function-type "f32>>" "f32>>")
  (set-function-type "f64>>" "f64>>")
  (set-function-type "f80>>" "f80>>")
  (set-function-type "ixx>>" "ixx>>")
  (set-function-type "add" "f64")
  (set-function-type "sub" "f64")
  (set-function-type "mul" "f64")
  (set-function-type "div" "f64")
  (set-function-type "sqrt" "f32")
  (set-function-type "power" "f32")
  (set-function-type "size" "i32")
  (set-function-type "fabs" "f64")
  (set-function-type "atan" "f64")
  (set-function-type "acos" "f64")
  (set-function-type "asin" "f64")
  (set-function-type "asin2" "f64")
  (set-function-type "cos" "f64")
  (set-function-type "cosh" "f64")
  (set-function-type "sin" "f64")
  (set-function-type "sinh" "f64")
  (set-function-type "tanh" "f64")
  (set-function-type "exp" "f64")
  (set-function-type "log" "f64")
  (set-function-type "log10" "f64")
  (set-function-type "floor" "f64")
  (set-function-type "ceil" "f64")
  (set-function-type "round" "f64")
  (set-function-type "fmod" "f64")
  (set-function-type "shiftl" "i32")
  (set-function-type "shiftr" "i32")
  (set-function-type ">>" "i32")
  (set-function-type "<<" "i32")
  (set-function-type "or" "bool")
  (set-function-type "not" "bool")
  (set-function-type "and" "bool")
  (set-function-type "==" "bool")
  (set-function-type "!=" "bool")
  (set-function-type ">=" "bool")
  (set-function-type "<=" "bool")
  (set-function-type "equal" "bool")
  (set-function-type "eq" "bool")
  (set-function-type "neq" "bool")
  (set-function-type "geqt" "bool")
  (set-function-type "leqt" "bool")
  (set-function-type "gt" "bool")
  (set-function-type "lt" "bool")
  (set-function-type "√" "f32")
  (set-function-type "^" "f32")
  (set-function-type "+" "f64")
  (set-function-type "-" "f64")
  (set-function-type "*" "f64")
  (set-function-type "/" "f64")
  (set-function-type "add" "f64")
  (set-function-type "sub" "f64")
  (set-function-type "mul" "f64")
  (set-function-type "div" "f64")
  (set-function-type "badd" "ixx")
  (set-function-type "bsub" "ixx")
  (set-function-type "bmul" "ixx")
  (set-function-type "bdiv" "ixx")
  (set-function-type "append" ">")
  (set-function-type "reverse" ">")
  (set-function-type "max" "i32")
  (set-function-type "min" "i32"))

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
    ;(remove-definition-macro)
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

