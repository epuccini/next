;;; -----------------------------------------------------
;;; next - package file
;;; -----------------------------------------------------
;;; File:     /Users/edward/Documents/Code/common-lisp/projects/next/src/package.lisp
;;; Date:     09:29:15 of Wednesday, 8/14/2019 (GMT+1)
;;; Author:   Edward Puccini
;;; -----------------------------------------------------

(defpackage :next
    (:use "COMMON-LISP" #:flood #:argparse #:cl-ppcre)
    (:export
     #:parse
     #:parse-expression
     #:parse-call
     #:parse-arguments
     #:load-data
     #:save-data
     #:*call*
     #:*code*
     #:*def-template*
     #:*impl-template*
))

