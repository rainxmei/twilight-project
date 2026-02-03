
(cl:in-package :asdf)

(defsystem "robot_soccer-msg"
  :depends-on (:roslisp-msg-protocol :roslisp-utils :actionlib_msgs-msg
               :std_msgs-msg
)
  :components ((:file "_package")
    (:file "MotionAction" :depends-on ("_package_MotionAction"))
    (:file "_package_MotionAction" :depends-on ("_package"))
    (:file "MotionActionFeedback" :depends-on ("_package_MotionActionFeedback"))
    (:file "_package_MotionActionFeedback" :depends-on ("_package"))
    (:file "MotionActionGoal" :depends-on ("_package_MotionActionGoal"))
    (:file "_package_MotionActionGoal" :depends-on ("_package"))
    (:file "MotionActionResult" :depends-on ("_package_MotionActionResult"))
    (:file "_package_MotionActionResult" :depends-on ("_package"))
    (:file "MotionFeedback" :depends-on ("_package_MotionFeedback"))
    (:file "_package_MotionFeedback" :depends-on ("_package"))
    (:file "MotionGoal" :depends-on ("_package_MotionGoal"))
    (:file "_package_MotionGoal" :depends-on ("_package"))
    (:file "MotionResult" :depends-on ("_package_MotionResult"))
    (:file "_package_MotionResult" :depends-on ("_package"))
  ))