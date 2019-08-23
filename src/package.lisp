;;; -----------------------------------------------------
;;; next - package file
;;; -----------------------------------------------------
;;; File:     /Users/edward/Documents/Code/common-lisp/projects/next/src/package.lisp
;;; Date:     09:29:15 of Wednesday, 8/14/2019 (GMT+1)
;;; Author:   Edward Puccini
;;; -----------------------------------------------------

(defpackage :next
    (:use "COMMON-LISP" #:flood #:cl-ppcre #:parse-float #:alexandria)
    (:export
     #:parse
     #:parse-expression
     #:parse-function
     #:parse-variable
     #:parse-call
     #:load-data
     #:save-data
     #:load-binary-data
     #:repl
     #:evaluate
     #:compile-next
     #:*call*
     #:*code*
     #:*def-template*
     #:*impl-template*
))

