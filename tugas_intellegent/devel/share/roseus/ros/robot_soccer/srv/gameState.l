;; Auto-generated. Do not edit!


(when (boundp 'robot_soccer::gameState)
  (if (not (find-package "ROBOT_SOCCER"))
    (make-package "ROBOT_SOCCER"))
  (shadow 'gameState (find-package "ROBOT_SOCCER")))
(unless (find-package "ROBOT_SOCCER::GAMESTATE")
  (make-package "ROBOT_SOCCER::GAMESTATE"))
(unless (find-package "ROBOT_SOCCER::GAMESTATEREQUEST")
  (make-package "ROBOT_SOCCER::GAMESTATEREQUEST"))
(unless (find-package "ROBOT_SOCCER::GAMESTATERESPONSE")
  (make-package "ROBOT_SOCCER::GAMESTATERESPONSE"))

(in-package "ROS")





(defclass robot_soccer::gameStateRequest
  :super ros::object
  :slots (_state ))

(defmethod robot_soccer::gameStateRequest
  (:init
   (&key
    ((:state __state) 0)
    )
   (send-super :init)
   (setq _state (round __state))
   self)
  (:state
   (&optional __state)
   (if __state (setq _state __state)) _state)
  (:serialization-length
   ()
   (+
    ;; uint8 _state
    1
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; uint8 _state
       (write-byte _state s)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; uint8 _state
     (setq _state (sys::peek buf ptr- :char)) (incf ptr- 1)
   ;;
   self)
  )

(defclass robot_soccer::gameStateResponse
  :super ros::object
  :slots (_success _message ))

(defmethod robot_soccer::gameStateResponse
  (:init
   (&key
    ((:success __success) nil)
    ((:message __message) "")
    )
   (send-super :init)
   (setq _success __success)
   (setq _message (string __message))
   self)
  (:success
   (&optional (__success :null))
   (if (not (eq __success :null)) (setq _success __success)) _success)
  (:message
   (&optional __message)
   (if __message (setq _message __message)) _message)
  (:serialization-length
   ()
   (+
    ;; bool _success
    1
    ;; string _message
    4 (length _message)
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; bool _success
       (if _success (write-byte -1 s) (write-byte 0 s))
     ;; string _message
       (write-long (length _message) s) (princ _message s)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; bool _success
     (setq _success (not (= 0 (sys::peek buf ptr- :char)))) (incf ptr- 1)
   ;; string _message
     (let (n) (setq n (sys::peek buf ptr- :integer)) (incf ptr- 4) (setq _message (subseq buf ptr- (+ ptr- n))) (incf ptr- n))
   ;;
   self)
  )

(defclass robot_soccer::gameState
  :super ros::object
  :slots ())

(setf (get robot_soccer::gameState :md5sum-) "f362d485cfee2365e9883ed5f96ae587")
(setf (get robot_soccer::gameState :datatype-) "robot_soccer/gameState")
(setf (get robot_soccer::gameState :request) robot_soccer::gameStateRequest)
(setf (get robot_soccer::gameState :response) robot_soccer::gameStateResponse)

(defmethod robot_soccer::gameStateRequest
  (:response () (instance robot_soccer::gameStateResponse :init)))

(setf (get robot_soccer::gameStateRequest :md5sum-) "f362d485cfee2365e9883ed5f96ae587")
(setf (get robot_soccer::gameStateRequest :datatype-) "robot_soccer/gameStateRequest")
(setf (get robot_soccer::gameStateRequest :definition-)
      "uint8 state
---
bool success
string message
")

(setf (get robot_soccer::gameStateResponse :md5sum-) "f362d485cfee2365e9883ed5f96ae587")
(setf (get robot_soccer::gameStateResponse :datatype-) "robot_soccer/gameStateResponse")
(setf (get robot_soccer::gameStateResponse :definition-)
      "uint8 state
---
bool success
string message
")



(provide :robot_soccer/gameState "f362d485cfee2365e9883ed5f96ae587")


