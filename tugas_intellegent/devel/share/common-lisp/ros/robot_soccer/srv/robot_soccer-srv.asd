
(cl:in-package :asdf)

(defsystem "robot_soccer-srv"
  :depends-on (:roslisp-msg-protocol :roslisp-utils )
  :components ((:file "_package")
    (:file "gameState" :depends-on ("_package_gameState"))
    (:file "_package_gameState" :depends-on ("_package"))
  ))