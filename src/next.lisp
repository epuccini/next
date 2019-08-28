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
  (setf (gethash "print" *signatures*) '("void" "value"))
  (setf (gethash "println" *signatures*) '("void" "value"))
  (setf (gethash "print-format" *signatures*) '("void" "value" "value"))
  (setf (gethash "mod" *signatures*) '("value" "value" "value"))
  (setf (gethash "plus" *signatures*) '("value" "value" "value")))

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

