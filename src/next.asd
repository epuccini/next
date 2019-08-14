;;; -----------------------------------------------------
;;; next - system asd file 
;;; -----------------------------------------------------
;;; File:     /Users/edward/Documents/Code/common-lisp/projects/next/src/next.asd
;;; Date:     09:29:15 of Wednesday, 8/14/2019 (GMT+1)
;;; Author:   Edward Puccini
;;; -----------------------------------------------------

(require 'asdf)

(defsystem "next"
    :version "0.0.0"
    :maintainer "Edward Puccini"
    :licence "BSD"
    :description "Generated by pm 2019."
    :depends-on ( "flood" "argparse" "cl-ppcre" )
    :components ((:file "package")
		 (:file "file")
		 (:file "parser")
                 (:file "next")))
