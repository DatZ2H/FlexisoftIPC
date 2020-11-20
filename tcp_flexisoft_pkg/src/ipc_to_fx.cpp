#include <client.h>
#include <flexisoft_fx.h>
#include <flexisoft_msg.h>

#include <diagnostic_msgs/DiagnosticArray.h>
#include <diagnostic_msgs/DiagnosticStatus.h>
#include <diagnostic_msgs/KeyValue.h>

#include <tcp_flexisoft_pkg/fx_to_ipc.h>
#include <tcp_flexisoft_pkg/agv_action.h>

bool value = 1;
bool data;

TCPClient *flexisoft = new TCPClient("192.168.1.21", 80);

void SafetyIoActionCallback(const tcp_flexisoft_pkg::agv_action &st_io_action)
{

  uint16_t st_io_action_Action = st_io_action.action;
  uint16_t st_io_action_Status = st_io_action.status;
  ROS_ERROR("-------------------------------------");
  ROS_ERROR(" gia tri st_io_action_Action %d", st_io_action_Action);
  ROS_ERROR(" gia tri st_io_action_Status %d", st_io_action_Status);
  ROS_ERROR(" -===================================");
  switch (st_io_action_Action)
  {
  case 0: //ACTION_FLOAT

    break;
  case 1: //ACTION_MANUAL

    break;
  case 2: //ACTION_INITIAL_POSE

    break;
  case 3: //ACTION_QUALITY_POSE

    break;
  case 4: //ACTION_ROTATE_GOAL

    break;
  case 5: //ACTION_MOVE_GOAL

    break;
  case 6: //ACTION_CHARGING_IN
    flexisoft->TCPClientWriteArrayBit16(SAFE_IO_Pose_Charge_In, 1);
    flexisoft->TCPClientWriteArrayBit16(SAFE_IO_Pose_Charge_Out, 0);
    flexisoft->TCPClientWriteArrayBit16(SAFE_IO_Pose_Pick_In, 0);
    flexisoft->TCPClientWriteArrayBit16(SAFE_IO_Pose_Pick_Up, 0);
    flexisoft->TCPClientWriteArrayBit16(SAFE_IO_Pose_Pick_Down, 0);
    flexisoft->TCPClientWriteArrayBit16(SAFE_IO_Pose_Pick_Out, 0);

    break;
  case 7: //ACTION_CHARGING_OUT
    flexisoft->TCPClientWriteArrayBit16(SAFE_IO_Pose_Charge_In, 0);
    flexisoft->TCPClientWriteArrayBit16(SAFE_IO_Pose_Charge_Out, 1);
    flexisoft->TCPClientWriteArrayBit16(SAFE_IO_Pose_Pick_In, 0);
    flexisoft->TCPClientWriteArrayBit16(SAFE_IO_Pose_Pick_Up, 0);
    flexisoft->TCPClientWriteArrayBit16(SAFE_IO_Pose_Pick_Down, 0);
    flexisoft->TCPClientWriteArrayBit16(SAFE_IO_Pose_Pick_Out, 0);

    break;
  case 8: //ACTION_LIFT_IN
    flexisoft->TCPClientWriteArrayBit16(SAFE_IO_Pose_Charge_In, 0);
    flexisoft->TCPClientWriteArrayBit16(SAFE_IO_Pose_Charge_Out, 0);
    flexisoft->TCPClientWriteArrayBit16(SAFE_IO_Pose_Pick_In, 1);
    flexisoft->TCPClientWriteArrayBit16(SAFE_IO_Pose_Pick_Up, 0);
    flexisoft->TCPClientWriteArrayBit16(SAFE_IO_Pose_Pick_Down, 0);
    flexisoft->TCPClientWriteArrayBit16(SAFE_IO_Pose_Pick_Out, 0);

    break;
  case 9: //ACTION_LIFT_UP
    flexisoft->TCPClientWriteArrayBit16(SAFE_IO_Pose_Charge_In, 0);
    flexisoft->TCPClientWriteArrayBit16(SAFE_IO_Pose_Charge_Out, 0);
    flexisoft->TCPClientWriteArrayBit16(SAFE_IO_Pose_Pick_In, 0);
    flexisoft->TCPClientWriteArrayBit16(SAFE_IO_Pose_Pick_Up, 1);
    flexisoft->TCPClientWriteArrayBit16(SAFE_IO_Pose_Pick_Down, 0);
    flexisoft->TCPClientWriteArrayBit16(SAFE_IO_Pose_Pick_Out, 0);

    break;
  case 10: //ACTION_LIFT_DOWN
    flexisoft->TCPClientWriteArrayBit16(SAFE_IO_Pose_Charge_In, 0);
    flexisoft->TCPClientWriteArrayBit16(SAFE_IO_Pose_Charge_Out, 0);
    flexisoft->TCPClientWriteArrayBit16(SAFE_IO_Pose_Pick_In, 0);
    flexisoft->TCPClientWriteArrayBit16(SAFE_IO_Pose_Pick_Up, 0);
    flexisoft->TCPClientWriteArrayBit16(SAFE_IO_Pose_Pick_Down, 1);
    flexisoft->TCPClientWriteArrayBit16(SAFE_IO_Pose_Pick_Out, 0);

    break;
  case 11: //ACTION_LIFT_OUT
    flexisoft->TCPClientWriteArrayBit16(SAFE_IO_Pose_Charge_In, 0);
    flexisoft->TCPClientWriteArrayBit16(SAFE_IO_Pose_Charge_Out, 0);
    flexisoft->TCPClientWriteArrayBit16(SAFE_IO_Pose_Pick_In, 0);
    flexisoft->TCPClientWriteArrayBit16(SAFE_IO_Pose_Pick_Up, 0);
    flexisoft->TCPClientWriteArrayBit16(SAFE_IO_Pose_Pick_Down, 0);
    flexisoft->TCPClientWriteArrayBit16(SAFE_IO_Pose_Pick_Out, 1);

    break;

  default:
    break;
  }

  switch (st_io_action_Status)
  {
  case 0: //STATUS_PENDING
    flexisoft->TCPClientWriteArrayBit16(SAFE_IO_Status_Pending, 1);
    flexisoft->TCPClientWriteArrayBit16(SAFE_IO_Status_Active, 0);
    flexisoft->TCPClientWriteArrayBit16(SAFE_IO_Status_Succeeded, 0);
    flexisoft->TCPClientWriteArrayBit16(SAFE_IO_Status_Rejected, 0);
    flexisoft->TCPClientWriteArrayBit16(SAFE_IO_Status_Lost, 0);

    break;
  case 1: //STATUS_ACTIVE
    flexisoft->TCPClientWriteArrayBit16(SAFE_IO_Status_Pending, 0);
    flexisoft->TCPClientWriteArrayBit16(SAFE_IO_Status_Active, 1);
    flexisoft->TCPClientWriteArrayBit16(SAFE_IO_Status_Succeeded, 0);
    flexisoft->TCPClientWriteArrayBit16(SAFE_IO_Status_Rejected, 0);
    flexisoft->TCPClientWriteArrayBit16(SAFE_IO_Status_Lost, 0);

    break;
  case 2: //STATUS_PREEMPTED

    break;
  case 3: //STATUS_SUCCEEDED
    flexisoft->TCPClientWriteArrayBit16(SAFE_IO_Status_Pending, 0);
    flexisoft->TCPClientWriteArrayBit16(SAFE_IO_Status_Active, 0);
    flexisoft->TCPClientWriteArrayBit16(SAFE_IO_Status_Succeeded, 1);
    flexisoft->TCPClientWriteArrayBit16(SAFE_IO_Status_Rejected, 0);
    flexisoft->TCPClientWriteArrayBit16(SAFE_IO_Status_Lost, 0);
    break;
  case 4: //STATUS_ABORTED

    break;
  case 5: //STATUS_REJECTED
    flexisoft->TCPClientWriteArrayBit16(SAFE_IO_Status_Pending, 0);
    flexisoft->TCPClientWriteArrayBit16(SAFE_IO_Status_Active, 0);
    flexisoft->TCPClientWriteArrayBit16(SAFE_IO_Status_Succeeded, 0);
    flexisoft->TCPClientWriteArrayBit16(SAFE_IO_Status_Rejected, 1);
    flexisoft->TCPClientWriteArrayBit16(SAFE_IO_Status_Lost, 0);
    break;
  case 6: //STATUS_PREEMPTING

    break;
  case 7: //STATUS_RECALLING

    break;
  case 8: //STATUS_RECALLED

    break;
  case 9: //STATUS_LOST
    flexisoft->TCPClientWriteArrayBit16(SAFE_IO_Status_Pending, 0);
    flexisoft->TCPClientWriteArrayBit16(SAFE_IO_Status_Active, 0);
    flexisoft->TCPClientWriteArrayBit16(SAFE_IO_Status_Succeeded, 0);
    flexisoft->TCPClientWriteArrayBit16(SAFE_IO_Status_Rejected, 0);
    flexisoft->TCPClientWriteArrayBit16(SAFE_IO_Status_Lost, 1);

  default:
    break;
  }
}
void SafetyIoDirectionCallback(const tcp_flexisoft_pkg::fx_to_ipc &st_io_direction)
{
  // ROS_ERROR("SafetyIoDirectionCallback");
  uint16_t st_io_direction_Direction = st_io_direction.IPC_SAFE_IO_Direction;
  ROS_ERROR("-------------------------------------");
  ROS_ERROR(" gia tri st_io_direction_Direction %d", st_io_direction_Direction);

  ROS_ERROR(" -===================================");
  switch (st_io_direction_Direction)
  {
  case 0:
    flexisoft->TCPClientWriteArrayBit16(SAFE_IO_Pose_SStill_F, 1);
    flexisoft->TCPClientWriteArrayBit16(SAFE_IO_Pose_SStill_B, 0);
    flexisoft->TCPClientWriteArrayBit16(SAFE_IO_Pose_Turn_L, 0);
    flexisoft->TCPClientWriteArrayBit16(SAFE_IO_Pose_Turn_R, 0);
    flexisoft->TCPClientWriteArrayBit16(SAFE_IO_Pose_Forward, 0);
    flexisoft->TCPClientWriteArrayBit16(SAFE_IO_Pose_Backward, 0);
    flexisoft->TCPClientWriteArrayBit16(SAFE_IO_Pose_Stop, 0);

    break;
  case 1:
    flexisoft->TCPClientWriteArrayBit16(SAFE_IO_Pose_SStill_F, 0);
    flexisoft->TCPClientWriteArrayBit16(SAFE_IO_Pose_SStill_B, 1);
    flexisoft->TCPClientWriteArrayBit16(SAFE_IO_Pose_Turn_L, 0);
    flexisoft->TCPClientWriteArrayBit16(SAFE_IO_Pose_Turn_R, 0);
    flexisoft->TCPClientWriteArrayBit16(SAFE_IO_Pose_Forward, 0);
    flexisoft->TCPClientWriteArrayBit16(SAFE_IO_Pose_Backward, 0);
    flexisoft->TCPClientWriteArrayBit16(SAFE_IO_Pose_Stop, 0);
    break;
  case 2:
    flexisoft->TCPClientWriteArrayBit16(SAFE_IO_Pose_SStill_F, 0);
    flexisoft->TCPClientWriteArrayBit16(SAFE_IO_Pose_SStill_B, 0);
    flexisoft->TCPClientWriteArrayBit16(SAFE_IO_Pose_Turn_L, 1);
    flexisoft->TCPClientWriteArrayBit16(SAFE_IO_Pose_Turn_R, 0);
    flexisoft->TCPClientWriteArrayBit16(SAFE_IO_Pose_Forward, 0);
    flexisoft->TCPClientWriteArrayBit16(SAFE_IO_Pose_Backward, 0);
    flexisoft->TCPClientWriteArrayBit16(SAFE_IO_Pose_Stop, 0);
    break;
  case 3:
    flexisoft->TCPClientWriteArrayBit16(SAFE_IO_Pose_SStill_F, 0);
    flexisoft->TCPClientWriteArrayBit16(SAFE_IO_Pose_SStill_B, 0);
    flexisoft->TCPClientWriteArrayBit16(SAFE_IO_Pose_Turn_L, 0);
    flexisoft->TCPClientWriteArrayBit16(SAFE_IO_Pose_Turn_R, 1);
    flexisoft->TCPClientWriteArrayBit16(SAFE_IO_Pose_Forward, 0);
    flexisoft->TCPClientWriteArrayBit16(SAFE_IO_Pose_Backward, 0);
    flexisoft->TCPClientWriteArrayBit16(SAFE_IO_Pose_Stop, 0);
    break;
  case 4:
    flexisoft->TCPClientWriteArrayBit16(SAFE_IO_Pose_SStill_F, 0);
    flexisoft->TCPClientWriteArrayBit16(SAFE_IO_Pose_SStill_B, 0);
    flexisoft->TCPClientWriteArrayBit16(SAFE_IO_Pose_Turn_L, 0);
    flexisoft->TCPClientWriteArrayBit16(SAFE_IO_Pose_Turn_R, 0);
    flexisoft->TCPClientWriteArrayBit16(SAFE_IO_Pose_Forward, 1);
    flexisoft->TCPClientWriteArrayBit16(SAFE_IO_Pose_Backward, 0);
    flexisoft->TCPClientWriteArrayBit16(SAFE_IO_Pose_Stop, 0);
    break;
  case 5:
    flexisoft->TCPClientWriteArrayBit16(SAFE_IO_Pose_SStill_F, 0);
    flexisoft->TCPClientWriteArrayBit16(SAFE_IO_Pose_SStill_B, 0);
    flexisoft->TCPClientWriteArrayBit16(SAFE_IO_Pose_Turn_L, 0);
    flexisoft->TCPClientWriteArrayBit16(SAFE_IO_Pose_Turn_R, 0);
    flexisoft->TCPClientWriteArrayBit16(SAFE_IO_Pose_Forward, 0);
    flexisoft->TCPClientWriteArrayBit16(SAFE_IO_Pose_Backward, 1);
    flexisoft->TCPClientWriteArrayBit16(SAFE_IO_Pose_Stop, 0);
    break;
  case 6:
    flexisoft->TCPClientWriteArrayBit16(SAFE_IO_Pose_SStill_F, 0);
    flexisoft->TCPClientWriteArrayBit16(SAFE_IO_Pose_SStill_B, 0);
    flexisoft->TCPClientWriteArrayBit16(SAFE_IO_Pose_Turn_L, 0);
    flexisoft->TCPClientWriteArrayBit16(SAFE_IO_Pose_Turn_R, 0);
    flexisoft->TCPClientWriteArrayBit16(SAFE_IO_Pose_Forward, 0);
    flexisoft->TCPClientWriteArrayBit16(SAFE_IO_Pose_Backward, 0);
    flexisoft->TCPClientWriteArrayBit16(SAFE_IO_Pose_Stop, 1);
    break;

  default:
    break;
  }
}
void IPCSafetyIoCallback(const tcp_flexisoft_pkg::fx_to_ipc &ipc_st_io)
{

  /*         ROS_ERROR("-------------------------------------");
    ROS_ERROR(" gia tri ipc_st_io_AGV_Run %x", ipc_st_io_AGV_Run);
    ROS_ERROR(" gia tri ipc_st_io_AGV_Brake %x", ipc_st_io_AGV_Brake);
        ROS_ERROR(" gia tri ipc_st_io_IPC_Ok %x", ipc_st_io_IPC_Ok);
            ROS_ERROR(" gia tri ipc_st_io_IPC_Error %x", ipc_st_io_IPC_Error);
                ROS_ERROR(" gia tri ipc_st_io_Reset_ALM_M %x", ipc_st_io_Reset_ALM_M);
    ROS_ERROR(" -==================================="); */
  bool ipc_st_io_AGV_Run = ipc_st_io.IPC_SAFE_IO_AGV_Run;
  bool ipc_st_io_AGV_Brake = ipc_st_io.IPC_SAFE_IO_AGV_Brake;
  bool ipc_st_io_IPC_Ok = ipc_st_io.IPC_SAFE_IO_IPC_Ok;
  bool ipc_st_io_IPC_Error = ipc_st_io.IPC_SAFE_IO_IPC_Error;
  bool ipc_st_io_Reset_ALM_M = ipc_st_io.IPC_SAFE_IO_Reset_ALM_M;

  flexisoft->TCPClientWriteArrayBit16(SAFE_IO_AGV_Run, ipc_st_io_AGV_Run);
  flexisoft->TCPClientWriteArrayBit16(SAFE_IO_AGV_Brake, ipc_st_io_AGV_Brake);
  flexisoft->TCPClientWriteArrayBit16(SAFE_IO_IPC_Ok, ipc_st_io_IPC_Ok);
  flexisoft->TCPClientWriteArrayBit16(SAFE_IO_IPC_Error, ipc_st_io_IPC_Error);
  flexisoft->TCPClientWriteArrayBit16(SAFE_IO_Reset_ALM_M, ipc_st_io_Reset_ALM_M);
}
void SafetyMs3ResetCallback(const tcp_flexisoft_pkg::fx_to_ipc &st_ms3_reset)
{

  bool st_ms3_reset_Ms3_F = st_ms3_reset.IPC_SAFE_MS3_Reset_MS3_F;
  bool st_ms3_reset_Ms3_B = st_ms3_reset.IPC_SAFE_MS3_Reset_MS3_B;
  /*         ROS_ERROR("-------------------------------------");
    ROS_ERROR(" gia tri st_ms3_reset_Ms3_F %d", st_ms3_reset_Ms3_F);
    ROS_ERROR(" gia tri st_ms3_reset_Ms3_B %d", st_ms3_reset_Ms3_B);

    ROS_ERROR(" -==================================="); */
  flexisoft->TCPClientWriteArrayBit16(SAFE_MS3_Reset_MS3_F, st_ms3_reset_Ms3_F);
  flexisoft->TCPClientWriteArrayBit16(SAFE_MS3_Reset_MS3_B, st_ms3_reset_Ms3_B);
}
void SafetySpeedLimitCallback(const tcp_flexisoft_pkg::fx_to_ipc &st_speed_limit)
{

  uint16_t st_speed_limit_SAFE_SP_Limit = 100 * st_speed_limit.IPC_SAFE_SP_Limit; //m/s to cm/s
  ROS_ERROR("-------------------------------------");
  ROS_ERROR(" gia tri st_speed_limit_SAFE_SP_Limit %d", st_speed_limit_SAFE_SP_Limit);

  ROS_ERROR(" -===================================");
  bool *IPC_SAFE_SP_Limit = flexisoft->TCPClientDecToBin16(st_speed_limit_SAFE_SP_Limit);

  flexisoft->TCPClientWriteArrayBit16(SAFE_SP_Limit_0, IPC_SAFE_SP_Limit[0]);
  flexisoft->TCPClientWriteArrayBit16(SAFE_SP_Limit_1, IPC_SAFE_SP_Limit[1]);
  flexisoft->TCPClientWriteArrayBit16(SAFE_SP_Limit_2, IPC_SAFE_SP_Limit[2]);
  flexisoft->TCPClientWriteArrayBit16(SAFE_SP_Limit_3, IPC_SAFE_SP_Limit[3]);
  flexisoft->TCPClientWriteArrayBit16(SAFE_SP_Limit_4, IPC_SAFE_SP_Limit[4]);
  flexisoft->TCPClientWriteArrayBit16(SAFE_SP_Limit_5, IPC_SAFE_SP_Limit[5]);
  flexisoft->TCPClientWriteArrayBit16(SAFE_SP_Limit_6, IPC_SAFE_SP_Limit[6]);
  flexisoft->TCPClientWriteArrayBit16(SAFE_SP_Limit_7, IPC_SAFE_SP_Limit[7]);
}

int main(int argc, char **argv)
{

  // create a modbus object

  // set slave id

  // connect with the server
  flexisoft->TCPClient_connect();

  tcp_flexisoft_pkg::fx_to_ipc fx_st_io;
  tcp_flexisoft_pkg::fx_to_ipc fx_st_fc;
  tcp_flexisoft_pkg::fx_to_ipc st_ms3_field;
  tcp_flexisoft_pkg::fx_to_ipc st_ms3_speed;

  tcp_flexisoft_pkg::agv_action st_io_action_status;
  ros::init(argc, argv, "safety_function");
  ros::NodeHandle nh;

  ros::Publisher fx_st_io_pub = nh.advertise<tcp_flexisoft_pkg::fx_to_ipc>("/fx_safety_io", 10);
  ros::Publisher fx_st_fc_pub = nh.advertise<tcp_flexisoft_pkg::fx_to_ipc>("/fx_st_fc", 10);
  ros::Publisher st_ms3_field_pub = nh.advertise<tcp_flexisoft_pkg::fx_to_ipc>("/st_ms3_field", 10);
  ros::Publisher st_ms3_speed_pub = nh.advertise<tcp_flexisoft_pkg::fx_to_ipc>("/st_ms3_speed", 10);
  ros::Publisher st_io_action_pub = nh.advertise<tcp_flexisoft_pkg::agv_action>("/st_io_action_status", 10);

  ros::Subscriber st_io_action_sub = nh.subscribe("st_io_action", 1000, SafetyIoActionCallback);
  ros::Subscriber st_io_direction_sub = nh.subscribe("st_io_direction", 1000, SafetyIoDirectionCallback);
  ros::Subscriber ipc_st_io_sub = nh.subscribe("ipc_st_io", 1000, IPCSafetyIoCallback);
  ros::Subscriber st_ms3_reset_sub = nh.subscribe("st_ms3_reset", 1000, SafetyMs3ResetCallback);
  ros::Subscriber st_speed_limit_sub = nh.subscribe("st_speed_limit", 1000, SafetySpeedLimitCallback);

  ros::Rate loop_rate(10);
  while (ros::ok())
  {
    uint st_io_action_status_action;
    uint st_io_action_status_status;

    //   ROS_INFO(" vong while ros ");
    fx_st_io.ST_SAFE_IO_GB_EMC = 1;
    // fx_st_io.ST_SAFE_IO_GB_EMC = flexisoft->TCPClientReadArrayBit(flexisoft->Fx_Read_Gent, SAFE_IO_GB_EMC);
    fx_st_io.ST_SAFE_IO_GB_Start = flexisoft->TCPClientReadArrayBit(flexisoft->Fx_Read_Gent, SAFE_IO_GB_Start);
    fx_st_io.ST_SAFE_IO_GB_Reset = flexisoft->TCPClientReadArrayBit(flexisoft->Fx_Read_Gent, SAFE_IO_GB_Reset);
    fx_st_io.ST_SAFE_IO_GB_Key_Brake = flexisoft->TCPClientReadArrayBit(flexisoft->Fx_Read_Gent, SAFE_IO_GB_Key_Brake);
    fx_st_io.ST_SAFE_IO_GB_EDM_MC = flexisoft->TCPClientReadArrayBit(flexisoft->Fx_Read_Gent, SAFE_IO_GB_EDM_MC);
    fx_st_io.ST_SAFE_IO_GB_ALM_M = flexisoft->TCPClientReadArrayBit(flexisoft->Fx_Read_Gent, SAFE_IO_GB_ALM_M);
    fx_st_io.ST_SAFE_IO_GB_IPC_Ok = flexisoft->TCPClientReadArrayBit(flexisoft->Fx_Read_Gent, SAFE_IO_GB_IPC_Ok);
    fx_st_io.ST_SAFE_IO_GB_IPC_Run = flexisoft->TCPClientReadArrayBit(flexisoft->Fx_Read_Gent, SAFE_IO_GB_IPC_Run);
    fx_st_io.ST_SAFE_IO_GB_FX_Run = flexisoft->TCPClientReadArrayBit(flexisoft->Fx_Read_Gent, SAFE_IO_GB_FX_Run);

    fx_st_io_pub.publish(fx_st_io);

    fx_st_fc.ST_SAFE_FC_ST_Ready = flexisoft->TCPClientReadArrayBit(flexisoft->Fx_Read_Gent, SAFE_FC_ST_Ready);
    fx_st_fc.ST_SAFE_FC_ST_G = flexisoft->TCPClientReadArrayBit(flexisoft->Fx_Read_Gent, SAFE_FC_ST_G);
    fx_st_fc.ST_SAFE_FC_ST_B_G = flexisoft->TCPClientReadArrayBit(flexisoft->Fx_Read_Gent, SAFE_FC_ST_B_G);
    fx_st_fc.ST_SAFE_FC_SW_Ok = flexisoft->TCPClientReadArrayBit(flexisoft->Fx_Read_Gent, SAFE_FC_SW_Ok);
    fx_st_fc.ST_SAFE_FC_Auto_Restart = flexisoft->TCPClientReadArrayBit(flexisoft->Fx_Read_Gent, SAFE_FC_Auto_Restart);
    fx_st_fc.ST_SAFE_FC_EDM_E = flexisoft->TCPClientReadArrayBit(flexisoft->Fx_Read_Gent, SAFE_FC_EDM_E);
    fx_st_fc.ST_SAFE_FC_En_Ctr_ST = flexisoft->TCPClientReadArrayBit(flexisoft->Fx_Read_Gent, SAFE_FC_En_Ctr_ST);

    fx_st_fc_pub.publish(fx_st_fc);

    //  st_ms3_field.ST_SAFE_MS3_Field =
    st_ms3_field.ST_SAFE_MS3_Power_Ok = flexisoft->TCPClientReadArrayBit(flexisoft->Fx_Read_Gent, SAFE_MS3_Power_Ok);
    st_ms3_field.ST_SAFE_MS3_Brake_Ok = flexisoft->TCPClientReadArrayBit(flexisoft->Fx_Read_Gent, SAFE_MS3_Brake_Ok);
    st_ms3_field.ST_SAFE_MS3_Warn_Ok = flexisoft->TCPClientReadArrayBit(flexisoft->Fx_Read_Gent, SAFE_MS3_Warn_Ok);
    st_ms3_field.ST_SAFE_MS3_Detect_Ok = flexisoft->TCPClientReadArrayBit(flexisoft->Fx_Read_Gent, SAFE_MS3_Detect_Ok);
    st_ms3_field.ST_SAFE_MS3_Contour_Ok = flexisoft->TCPClientReadArrayBit(flexisoft->Fx_Read_Gent, SAFE_MS3_Contour_Ok);

    st_ms3_field_pub.publish(st_ms3_field);

    //   st_ms3_speed.ST_SAFE_MS3_SP =
    st_ms3_speed.ST_SAFE_MS3_SP_SStill = flexisoft->TCPClientReadArrayBit(flexisoft->Fx_Read_Gent, SAFE_MS3_SP_SStill);
    st_ms3_speed.ST_SAFE_MS3_SP_VSlow = flexisoft->TCPClientReadArrayBit(flexisoft->Fx_Read_Gent, SAFE_MS3_SP_VSlow);
    st_ms3_speed.ST_SAFE_MS3_SP_Slow = flexisoft->TCPClientReadArrayBit(flexisoft->Fx_Read_Gent, SAFE_MS3_SP_Slow);
    st_ms3_speed.ST_SAFE_MS3_SP_Medium = flexisoft->TCPClientReadArrayBit(flexisoft->Fx_Read_Gent, SAFE_MS3_SP_Medium);
    st_ms3_speed.ST_SAFE_MS3_SP_Fast = flexisoft->TCPClientReadArrayBit(flexisoft->Fx_Read_Gent, SAFE_MS3_SP_Fast);
    st_ms3_speed.ST_SAFE_MS3_SP_VFast = flexisoft->TCPClientReadArrayBit(flexisoft->Fx_Read_Gent, SAFE_MS3_SP_VFast);

    st_ms3_speed_pub.publish(st_ms3_speed);

    if (flexisoft->TCPClientReadArrayBit(flexisoft->Fx_Read_Gent, SAFE_Action_Pose_Charge_In))
    {
      st_io_action_status_action = 6 ;
    }
    else if (flexisoft->TCPClientReadArrayBit(flexisoft->Fx_Read_Gent, SAFE_Action_Pose_Charge_Out))
    {
      st_io_action_status_action = 7 ;
    }
    else if (flexisoft->TCPClientReadArrayBit(flexisoft->Fx_Read_Gent, SAFE_Action_Pose_Pick_In))
    {
      st_io_action_status_action = 8 ;
    }
    else if (flexisoft->TCPClientReadArrayBit(flexisoft->Fx_Read_Gent, SAFE_Action_Pose_Pick_Up))
    {
      st_io_action_status_action = 9 ;
    }
    else if (flexisoft->TCPClientReadArrayBit(flexisoft->Fx_Read_Gent, SAFE_Action_Pose_Pick_Down))
    {
      st_io_action_status_action = 10 ;
    }
    else if (flexisoft->TCPClientReadArrayBit(flexisoft->Fx_Read_Gent, SAFE_Action_Pose_Pick_Out))
    {
      st_io_action_status_action = 11 ;
    }

    if (flexisoft->TCPClientReadArrayBit(flexisoft->Fx_Read_Gent, SAFE_Status_Status_Pending))
    {
      st_io_action_status_status = 0 ;
    }
    else if (flexisoft->TCPClientReadArrayBit(flexisoft->Fx_Read_Gent, SAFE_Status_Status_Active))
    {
      st_io_action_status_status = 1 ;
    }
    else if (flexisoft->TCPClientReadArrayBit(flexisoft->Fx_Read_Gent, SAFE_Status_Status_Succeeded))
    {
      st_io_action_status_status = 3 ;
    }
    else if (flexisoft->TCPClientReadArrayBit(flexisoft->Fx_Read_Gent, SAFE_Status_Status_Rejected))
    {
      st_io_action_status_status = 5 ;
    }
    else if (flexisoft->TCPClientReadArrayBit(flexisoft->Fx_Read_Gent, SAFE_Status_Status_Lost))
    {
      st_io_action_status_status = 9 ;
    }


    st_io_action_status.action = st_io_action_status_action;
    st_io_action_status.status = st_io_action_status_status;

    st_io_action_pub.publish(st_io_action_status);

    flexisoft->TCPClientWriteOutputGentArray(2);

    ros::spinOnce();
    loop_rate.sleep();
  }
  // ros::spin();

  return 0;
}