; -------------------------------------------------------------
; Edward Alan Puccini 24.05.2013
; -------------------------------------------------------------
; Feedforward Artificial Neural Network lib and main program.
; with backpropagation learning-, offline algorithm 
; -------------------------------------------------------------
; nn-io.lisp - Input, output data
; Function load and save to file, to add data to a stack
; -------------------------------------------------------------

(in-package :next)

(require 'cl-binary)

(defun load-binary-data (path)
  "Load binary file from path."
  (let ((store))
    (cl-binary:with-open-binary-file (in path)
      (loop for line = (cl-binary:read-u8 in)
         while line do
           (setf store (concatenate 'string store
                                    (format nil "~a" (code-char line))))))
	store))


(defun save-binary-data (path data)
  "Load binary file from path."
  (cl-binary:with-open-binary-file (out path :direction :output)
    (loop for x from 0 to (1- (length data)) do
         (cl-binary:write-u8 out (char-code (elt data x))))))


