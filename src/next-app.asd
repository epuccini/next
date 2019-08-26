;;; -----------------------------------------------------
;;; next - application asd-file
;;; -----------------------------------------------------
;;; File:     /Users/edward/Documents/Code/common-lisp/projects/next/src/next-app.asd
;;; Date:     09:29:15 of Wednesday, 8/14/2019 (GMT+1)
;;; Author:   Edward Puccini
;;; -----------------------------------------------------

(require 'asdf)

(defsystem "next-app"
    :version "0.0.0"
    :maintainer "Edward Puccini"
    :licence "BSD"
    :description "Generated by pm 2017."
    :depends-on ( "flood" "argparse" "parse-float" "cl-ppcre" "ieee-floats"
                          "cl-binary" "alexandria")
    :components ((:file "package")
		 (:file "file")
		 (:file "parser")
                 (:file "next")
                 (:file "main")))
