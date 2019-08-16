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

(defun load-data (path)
  "Load ascii file from path."
  (let ((store))
	(with-open-file (stream path 
				            :direction :input
                            :external-format :utf-8)
	  (with-standard-io-syntax
		(setf store (read stream))))
	store))

(defun save-data (path store)
  "Save ascii data to path from store."
  (with-open-file (stream path 
			              :direction :output
                          :external-format :utf-8
			              :if-exists :supersede)
    (with-standard-io-syntax
	  (print store stream))))

