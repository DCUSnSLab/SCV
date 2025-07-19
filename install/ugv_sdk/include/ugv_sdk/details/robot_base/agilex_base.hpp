/*
 * agilex_base.hpp
 *
 * Created on: Dec 22, 2020 17:14
 * Description:
 *
 * Each robot class derived from this base class should provide implementation
 * for the following two functions:
 *
 * - virtual void Connect(std::string dev_name) = 0;
 * - virtual void ParseCANFrame(can_frame *rx_frame) = 0;
 *
 * Copyright (c) 2020 Ruixiang Du (rdu)
 */

#ifndef AGILEX_BASE_HPP
#define AGILEX_BASE_HPP

#include <string>
#include <cstdint>
#include <thread>
#include <mutex>
#include <atomic>
#include <time.h>
#include <chrono>

#include "ugv_sdk/details/async_port/async_can.hpp"
#include "ugv_sdk/details/interface/robot_common_interface.hpp"
#include "ugv_sdk/details/interface/parser_interface.hpp"

using namespace std::chrono;

namespace westonrobot {
template <typename ParserType>
class AgilexBase : public RobotCommonInterface {
 public:
  AgilexBase() {
    static_assert(
        std::is_base_of<ParserInterface<ProtocolVersion::AGX_V1>,
                        ParserType>::value ||
            std::is_base_of<ParserInterface<ProtocolVersion::AGX_V2>,
                            ParserType>::value,
        "Incompatible parser for the AgilexBase class, expecting one derived "
        "from ParserInterface!");
  };
  virtual ~AgilexBase() { DisconnectPort(); }

  // do not allow copy or assignment
  AgilexBase(const AgilexBase &hunter) = delete;
  AgilexBase &operator=(const AgilexBase &hunter) = delete;

  void Connect(std::string can_name) override {
    ConnectPort(can_name, std::bind(&AgilexBase<ParserType>::ParseCANFrame,
                                    this, std::placeholders::_1));
  }

  int counter = 0;
  // switch to commanded mode
  void EnableCommandedMode() {
    // construct message
    AgxMessage msg;
    msg.type = AgxMsgControlModeConfig;
    msg.body.control_mode_config_msg.mode = CONTROL_MODE_CAN;

    // encode msg to can frame and send to bus
    can_frame frame;
    if (parser_.EncodeMessage(&msg, &frame)) can_->SendFrame(frame);
  }

  // must be called at a frequency >= 50Hz
  void SendMotionCommand(double linear_vel, double angular_vel,
                         double lateral_vel, double steering_angle) {
    if (can_connected_) {
      // motion control message
      AgxMessage msg;
      if (parser_.GetParserProtocolVersion() == ProtocolVersion::AGX_V1) {
        msg.type = AgxMsgMotionCommandV1;
        msg.body.v1_motion_command_msg.control_mode = CONTROL_MODE_CAN;
        msg.body.v1_motion_command_msg.clear_all_error = false;
        msg.body.v1_motion_command_msg.linear = linear_vel;
        // normally only one of angular_vel and steering_angle can be non-zero
        msg.body.v1_motion_command_msg.angular =
            std::abs(angular_vel) > std::abs(steering_angle) ? angular_vel
                                                             : steering_angle;
        msg.body.v1_motion_command_msg.lateral = lateral_vel;
      } else if (parser_.GetParserProtocolVersion() ==
                 ProtocolVersion::AGX_V2) {
        msg.type = AgxMsgMotionCommand;
        msg.body.motion_command_msg.linear_velocity = linear_vel;
        msg.body.motion_command_msg.angular_velocity = angular_vel;
        msg.body.motion_command_msg.lateral_velocity = lateral_vel;
        msg.body.motion_command_msg.steering_angle = steering_angle;
      }

//      std::cout << "sending motion cmd: " << linear_vel << "," << angular_vel
//                << "," << lateral_vel << std::endl;

      // send to can bus
      can_frame frame;
      if (parser_.EncodeMessage(&msg, &frame)) can_->SendFrame(frame);
    }
  }

  // one-shot light command
  void SendLightCommand(LightMode front_mode, uint8_t front_custom_value,
                        LightMode rear_mode, uint8_t rear_custom_value) {
    if (can_connected_) {
      AgxMessage msg;
      msg.type = AgxMsgLightCommand;
      msg.body.light_command_msg.enable_cmd_ctrl = true;
      msg.body.light_command_msg.front_light.mode = front_mode;
      msg.body.light_command_msg.front_light.custom_value = front_custom_value;
      msg.body.light_command_msg.rear_light.mode = rear_mode;
      msg.body.light_command_msg.rear_light.custom_value = rear_custom_value;

      // send to can bus
      can_frame frame;
      if (parser_.EncodeMessage(&msg, &frame)) can_->SendFrame(frame);
    }
  }

  void DisableLightControl() {
    if (can_connected_) {
      AgxMessage msg;
      msg.type = AgxMsgLightCommand;

      msg.body.light_command_msg.enable_cmd_ctrl = false;

      // send to can bus
      can_frame frame;
      if (parser_.EncodeMessage(&msg, &frame)) can_->SendFrame(frame);
    }
  }

  // motion mode change
  void SetMotionMode(uint8_t mode) {
    if (can_connected_) {
      AgxMessage msg;
      msg.type = AgxMsgSetMotionModeCommand;
      msg.body.motion_mode_msg.motion_mode = mode;

      // send to can bus
      can_frame frame;
      if (parser_.EncodeMessage(&msg, &frame)) can_->SendFrame(frame);
    }
  }

  void ResetRobotState() override {}

  ProtocolVersion GetParserProtocolVersion() override {
    return parser_.GetParserProtocolVersion();
  }

  CoreStateMsgGroup GetRobotCoreStateMsgGroup() override {
    std::lock_guard<std::mutex> guard(core_state_mtx_);
    return core_state_msgs_;
  }

  ActuatorStateMsgGroup GetActuatorStateMsgGroup() override {
    std::lock_guard<std::mutex> guard(actuator_state_mtx_);
    return actuator_state_msgs_;
  }

  CommonSensorStateMsgGroup GetCommonSensorStateMsgGroup() override {
    std::lock_guard<std::mutex> guard(common_sensor_state_mtx_);
    return common_sensor_state_msgs_;
  }

  ResponseVersionMsgGroup GetResponseVersionMsgGroup() override {
    std::lock_guard<std::mutex> guard(response_version_mtx_);
    return  response_version_msgs_;
  }

  MotorMsgGroup GetMotorMsgGroup() override {
    std::lock_guard<std::mutex> guard(motor_state_mtx_);
    return  motor_msgs;
  }


 protected:
  ParserType parser_;

  // divide feedback messages into smaller groups to avoid the
  // state mutex being locked for too often such that accessing
  // the data become difficult

  /* feedback group 1: core state */
  std::mutex core_state_mtx_;
  CoreStateMsgGroup core_state_msgs_;

  /* feedback group 2: actuator state */
  std::mutex actuator_state_mtx_;
  ActuatorStateMsgGroup actuator_state_msgs_;

  /* feedback group 3: common sensor */
  std::mutex common_sensor_state_mtx_;
  CommonSensorStateMsgGroup common_sensor_state_msgs_;

  std::mutex response_version_mtx_;
  ResponseVersionMsgGroup response_version_msgs_;

  std::mutex motor_state_mtx_;
  MotorMsgGroup motor_msgs;

  std::mutex bms_state_mtx_;
  MotorMsgGroup bms_msgs;

//  std::mutex response_version_mtx_;
//  ResponseVersionMsgGroup response_version_msgs_;

  // communication interface
  bool can_connected_ = false;
  std::shared_ptr<AsyncCAN> can_;

  // connect to roboot from CAN or serial
  using CANFrameRxCallback = AsyncCAN::ReceiveCallback;
  void ConnectPort(std::string dev_name, CANFrameRxCallback cb) {
    can_ = std::make_shared<AsyncCAN>(dev_name);
    can_->SetReceiveCallback(cb);
    can_->StartListening();
    can_connected_ = true;
  }

  void DisconnectPort() {
    if (can_connected_) can_->StopService();
  }

  void SetBrakeMode(BrakeMode mode) {
    // construct message
    AgxMessage msg;
    msg.type = AgxMsgBrakeModeConfig;
    msg.body.brake_mode_config_msg.mode = mode;

    // encode msg to can frame and send to bus
    can_frame frame;
    if (parser_.EncodeMessage(&msg, &frame)) can_->SendFrame(frame);
  }

 std::string sendRequest()
 {
   can_frame frame;
   frame.can_id = ((uint32_t)0x4a1);
   frame.can_dlc = 8;
   typedef struct {
     uint8_t mode;
   } CheckRequest;

   CheckRequest tx_frame;

   tx_frame.mode = 1;
   memcpy(frame.data, (uint8_t *)(&tx_frame), frame.can_dlc);
   can_->SendFrame(frame);

   auto begin = system_clock::now();
   while(true)
   {
     auto now = system_clock::now();
     auto duration = duration_cast<seconds>(now - begin);
     double dt = double(duration.count()) * seconds::period::num / seconds::period::den;
     if(dt >= 3)
       break;
     if(response_version_msgs_.str_version_response.size() >= 80)
       break;
   }

   return response_version_msgs_.str_version_response;
 }


  void ParseCANFrame(can_frame *rx_frame) {
    AgxMessage status_msg;

    if (parser_.DecodeMessage(rx_frame, &status_msg)) {

      UpdateRobotCoreState(status_msg);
      UpdateActuatorState(status_msg);
      UpdateCommonSensorState(status_msg);
      UpdateResponseVersion(status_msg);
      UpdateMotorState(status_msg);
    }
  }

  void UpdateRobotCoreState(const AgxMessage &status_msg) {
    std::lock_guard<std::mutex> guard(core_state_mtx_);
    switch (status_msg.type) {
      case AgxMsgSystemState: {
        //   std::cout << "system status feedback received" << std::endl;
        core_state_msgs_.time_stamp = AgxMsgRefClock::now();
        core_state_msgs_.system_state = status_msg.body.system_state_msg;
        break;
      }
      case AgxMsgMotionState: {
        // std::cout << "motion control feedback received" << std::endl;
        core_state_msgs_.time_stamp = AgxMsgRefClock::now();
        core_state_msgs_.motion_state = status_msg.body.motion_state_msg;
        break;
      }
      case AgxMsgLightState: {
        // std::cout << "light control feedback received" << std::endl;
        core_state_msgs_.time_stamp = AgxMsgRefClock::now();
        core_state_msgs_.light_state = status_msg.body.light_state_msg;
        break;
      }
      case AgxMsgMotionModeState: {
        // std::cout << "motion mode feedback received" << std::endl;
        core_state_msgs_.time_stamp = AgxMsgRefClock::now();
        core_state_msgs_.motion_mode_state =
            status_msg.body.motion_mode_state_msg;
        break;
      }
      case AgxMsgRcState: {
        // std::cout << "rc feedback received" << std::endl;
        core_state_msgs_.time_stamp = AgxMsgRefClock::now();
        core_state_msgs_.rc_state = status_msg.body.rc_state_msg;
        break;
      }
      default:
        break;
    }
  }

  void UpdateActuatorState(const AgxMessage &status_msg) {
    std::lock_guard<std::mutex> guard(actuator_state_mtx_);
    switch (status_msg.type) {
      case AgxMsgActuatorHSState: {
        // std::cout << "actuator hs feedback received" << std::endl;
        actuator_state_msgs_.time_stamp = AgxMsgRefClock::now();
        actuator_state_msgs_
            .actuator_hs_state[status_msg.body.actuator_hs_state_msg.motor_id] =
            status_msg.body.actuator_hs_state_msg;
        break;
      }
      case AgxMsgActuatorLSState: {
        // std::cout << "actuator ls feedback received" << std::endl;
        actuator_state_msgs_.time_stamp = AgxMsgRefClock::now();
        actuator_state_msgs_
            .actuator_ls_state[status_msg.body.actuator_ls_state_msg.motor_id] =
            status_msg.body.actuator_ls_state_msg;
        break;
      }
      case AgxMsgActuatorStateV1: {
        // std::cout << "actuator v1 feedback received" << std::endl;
        actuator_state_msgs_.time_stamp = AgxMsgRefClock::now();
        actuator_state_msgs_
            .actuator_state[status_msg.body.v1_actuator_state_msg.motor_id] =
            status_msg.body.v1_actuator_state_msg;
        break;
      }
      default:
        break;
    }
  }
  void UpdateCommonSensorState(const AgxMessage &status_msg) {
    std::lock_guard<std::mutex> guard(common_sensor_state_mtx_);
//    std::cout << common_sensor_state_msgs_.bms_basic_state.battery_soc<< std::endl;
    switch (status_msg.type) {
      case AgxMsgBmsBasic: {
//      std::cout << "system status feedback received" << std::endl;
        common_sensor_state_msgs_.time_stamp = AgxMsgRefClock::now();
        common_sensor_state_msgs_.bms_basic_state = status_msg.body.bms_basic_msg;
        break;
      }
      default:
        break;
    }

  }

  void UpdateResponseVersion(const AgxMessage &status_msg){
    std::lock_guard<std::mutex> guard(response_version_mtx_);
    switch (status_msg.type) {
      case AgxMsgVersionResponse: {

      for (int i = 0;i<8;i++)
      {
        uint8_t data = status_msg.body.version_str[i];
        if(data < 32 || data>126)
          data = 32;
        response_version_msgs_.str_version_response += data;
//        std::cout << counter << std::endl;
//        std::cout << std::hex << static_cast<int>(status_msg.body.version_str[i])  << " ";
      }
//      std::cout << std::endl;
      counter++;
      if(counter == 10)
      {
//        std::cout << response_version_msgs_.str_version_response << std::endl;
        response_version_msgs_.str_version_response.clear();
        counter=0;
      }
//      response_version_msgs_.str_version_response += "\n";


        break;
      }
      default:
        break;
    }
  }
  void UpdateMotorState(const AgxMessage &status_msg){
    std::lock_guard<std::mutex> guard(motor_state_mtx_);
    switch (status_msg.type) {
      case AgxMsgMotorAngle: {

        motor_msgs.MoterAngle.angle_5 = status_msg.body.motor_angle_msg.angle_5;
        motor_msgs.MoterAngle.angle_6 = status_msg.body.motor_angle_msg.angle_6;
        motor_msgs.MoterAngle.angle_7 = status_msg.body.motor_angle_msg.angle_7;
        motor_msgs.MoterAngle.angle_8 = status_msg.body.motor_angle_msg.angle_8;
        break;
      }
    case AgxMsgMotorSpeed: {
        motor_msgs.MoterSpeed.speed_1 = status_msg.body.motor_speed_msg.speed_1;
        motor_msgs.MoterSpeed.speed_2 = status_msg.body.motor_speed_msg.speed_2;
        motor_msgs.MoterSpeed.speed_3 = status_msg.body.motor_speed_msg.speed_3;
        motor_msgs.MoterSpeed.speed_4 = status_msg.body.motor_speed_msg.speed_4;
      break;
    }
      default:
        break;
    }
  }
};
}  // namespace westonrobot

#endif /* AGILEX_BASE_HPP */
