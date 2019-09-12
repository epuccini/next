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

(eval-when (:compile-toplevel)
  (declaim (optimize (speed 1) (safety 1) (space 3) (debug 0))))

(defun main()
  (flood:dbg "main: setup param")
    (let ((param
           (argparse:with-arguments-hash-table
               "next"
             "Next programming languge compiler, repl and evaluatior."
             "v1.0.0.0"
             '(:argument "--compile"
               :description "Compile file"
               :group "Compilation"
               :type 'string)
             '(:argument "--output"
               :description "Output file"
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
      (flood:dbg "main: handle arguments")
      (argparse:handle-unknown-arguments param)
      (argparse:handle-missing-arguments param)
      (flood:dbg "main: eval arguments")
      (cond ((argparse:get-argument-value param "--repl")
             (next:repl))
            ((argparse:get-argument-value param "--eval")
             (next:evaluate (argparse:get-argument-value param "--eval")))
            ((argparse:get-argument-value param "--compile")
             (next:compile-next (argparse:get-argument-value param "--compile")
                                (argparse:get-argument-value param "--output"))))))

(defun build ()
  "Save executable with necessary options."
  #+windows
  (save-lisp-and-die "next.exe"
                     :executable t
                     :toplevel 'main
                     :save-runtime-options t)
  #+linux
  (save-lisp-and-die "next"
                     :executable t
                     :toplevel 'main
                     :save-runtime-options t)
  #+darwin
  (save-lisp-and-die "next"
                     :executable t
                     :toplevel 'main
                     :save-runtime-options t))

(defun release ()
  (let ((last-mode (flood:get-log-level)))
    (flood:set-log-level :prd)
    (build)
    (flood:set-log-level last-mode)))
