;;; -----------------------------------------------------
;;; next - application main file
;;; -----------------------------------------------------
;;; File:     src/main.lisp
;;; Date:     09:29:15 of Wednesday, 8/14/2019 (GMT+1)
;;; Author:   Edward Puccini
;;; -----------------------------------------------------

(require 'next)
(require 'flood)
(require 'argparse)

(eval-when (:load-toplevel :compile-toplevel :execute)
  (use-package :argparse))

(defun main()
    (let ((param
           (with-arguments-hash-table
               "next"
             "Next programming languge compiler, repl and evaluatior."
             "v1.0.0.0"
             '(:argument "--compile"
               :description "Compile file"
               :group "Compilation"
               :type 'string)
             '(:argument "--repl"
               :description "Read-eval-print-loop flag"
               :group "Read-eval-print-loop"
               :type 'flag)
	     '(:argument "--eval"
               :description "Evaluate expression"
               :group "Evaluation"
               :type 'string))))
      (handle-unknown-arguments param)
      (handle-missing-arguments param)
      (print (get-argument-value param "--eval"))))

(defun build ()
  "Save executable with necessary options."
  (save-lisp-and-die "next"
                     :executable t
                     :toplevel 'main
                     :save-runtime-options t))
