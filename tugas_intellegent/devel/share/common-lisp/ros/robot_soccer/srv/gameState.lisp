; Auto-generated. Do not edit!


(cl:in-package robot_soccer-srv)


;//! \htmlinclude gameState-request.msg.html

(cl:defclass <gameState-request> (roslisp-msg-protocol:ros-message)
  ((state
    :reader state
    :initarg :state
    :type cl:fixnum
    :initform 0))
)

(cl:defclass gameState-request (<gameState-request>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <gameState-request>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'gameState-request)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name robot_soccer-srv:<gameState-request> is deprecated: use robot_soccer-srv:gameState-request instead.")))

(cl:ensure-generic-function 'state-val :lambda-list '(m))
(cl:defmethod state-val ((m <gameState-request>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader robot_soccer-srv:state-val is deprecated.  Use robot_soccer-srv:state instead.")
  (state m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <gameState-request>) ostream)
  "Serializes a message object of type '<gameState-request>"
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'state)) ostream)
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <gameState-request>) istream)
  "Deserializes a message object of type '<gameState-request>"
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'state)) (cl:read-byte istream))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<gameState-request>)))
  "Returns string type for a service object of type '<gameState-request>"
  "robot_soccer/gameStateRequest")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'gameState-request)))
  "Returns string type for a service object of type 'gameState-request"
  "robot_soccer/gameStateRequest")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<gameState-request>)))
  "Returns md5sum for a message object of type '<gameState-request>"
  "f362d485cfee2365e9883ed5f96ae587")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'gameState-request)))
  "Returns md5sum for a message object of type 'gameState-request"
  "f362d485cfee2365e9883ed5f96ae587")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<gameState-request>)))
  "Returns full string definition for message of type '<gameState-request>"
  (cl:format cl:nil "uint8 state~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'gameState-request)))
  "Returns full string definition for message of type 'gameState-request"
  (cl:format cl:nil "uint8 state~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <gameState-request>))
  (cl:+ 0
     1
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <gameState-request>))
  "Converts a ROS message object to a list"
  (cl:list 'gameState-request
    (cl:cons ':state (state msg))
))
;//! \htmlinclude gameState-response.msg.html

(cl:defclass <gameState-response> (roslisp-msg-protocol:ros-message)
  ((success
    :reader success
    :initarg :success
    :type cl:boolean
    :initform cl:nil)
   (message
    :reader message
    :initarg :message
    :type cl:string
    :initform ""))
)

(cl:defclass gameState-response (<gameState-response>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <gameState-response>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'gameState-response)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name robot_soccer-srv:<gameState-response> is deprecated: use robot_soccer-srv:gameState-response instead.")))

(cl:ensure-generic-function 'success-val :lambda-list '(m))
(cl:defmethod success-val ((m <gameState-response>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader robot_soccer-srv:success-val is deprecated.  Use robot_soccer-srv:success instead.")
  (success m))

(cl:ensure-generic-function 'message-val :lambda-list '(m))
(cl:defmethod message-val ((m <gameState-response>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader robot_soccer-srv:message-val is deprecated.  Use robot_soccer-srv:message instead.")
  (message m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <gameState-response>) ostream)
  "Serializes a message object of type '<gameState-response>"
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:if (cl:slot-value msg 'success) 1 0)) ostream)
  (cl:let ((__ros_str_len (cl:length (cl:slot-value msg 'message))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) __ros_str_len) ostream))
  (cl:map cl:nil #'(cl:lambda (c) (cl:write-byte (cl:char-code c) ostream)) (cl:slot-value msg 'message))
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <gameState-response>) istream)
  "Deserializes a message object of type '<gameState-response>"
    (cl:setf (cl:slot-value msg 'success) (cl:not (cl:zerop (cl:read-byte istream))))
    (cl:let ((__ros_str_len 0))
      (cl:setf (cl:ldb (cl:byte 8 0) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'message) (cl:make-string __ros_str_len))
      (cl:dotimes (__ros_str_idx __ros_str_len msg)
        (cl:setf (cl:char (cl:slot-value msg 'message) __ros_str_idx) (cl:code-char (cl:read-byte istream)))))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<gameState-response>)))
  "Returns string type for a service object of type '<gameState-response>"
  "robot_soccer/gameStateResponse")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'gameState-response)))
  "Returns string type for a service object of type 'gameState-response"
  "robot_soccer/gameStateResponse")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<gameState-response>)))
  "Returns md5sum for a message object of type '<gameState-response>"
  "f362d485cfee2365e9883ed5f96ae587")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'gameState-response)))
  "Returns md5sum for a message object of type 'gameState-response"
  "f362d485cfee2365e9883ed5f96ae587")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<gameState-response>)))
  "Returns full string definition for message of type '<gameState-response>"
  (cl:format cl:nil "bool success~%string message~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'gameState-response)))
  "Returns full string definition for message of type 'gameState-response"
  (cl:format cl:nil "bool success~%string message~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <gameState-response>))
  (cl:+ 0
     1
     4 (cl:length (cl:slot-value msg 'message))
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <gameState-response>))
  "Converts a ROS message object to a list"
  (cl:list 'gameState-response
    (cl:cons ':success (success msg))
    (cl:cons ':message (message msg))
))
(cl:defmethod roslisp-msg-protocol:service-request-type ((msg (cl:eql 'gameState)))
  'gameState-request)
(cl:defmethod roslisp-msg-protocol:service-response-type ((msg (cl:eql 'gameState)))
  'gameState-response)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'gameState)))
  "Returns string type for a service object of type '<gameState>"
  "robot_soccer/gameState")