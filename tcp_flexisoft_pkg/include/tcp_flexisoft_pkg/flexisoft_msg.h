

#ifndef FLEXISOFT_MSG_H
#define FLEXISOFT_MSG_H
#pragma once

#include <diagnostic_msgs/DiagnosticArray.h>
#include <diagnostic_msgs/DiagnosticStatus.h>
#include <diagnostic_msgs/KeyValue.h>

diagnostic_msgs::KeyValue FX_IO_M1I1_EMC;
diagnostic_msgs::KeyValue FX_IO_M1I3_Start_Run;
diagnostic_msgs::KeyValue FX_IO_M1I4_Reset;
diagnostic_msgs::KeyValue FX_IO_M1I6_Key_Brake;
diagnostic_msgs::KeyValue FX_IO_M1I7_FX_Ok;
diagnostic_msgs::KeyValue FX_IO_M1I8_IPC_Run;
diagnostic_msgs::KeyValue FX_IO_M2I1_EDM_MC_01;
diagnostic_msgs::KeyValue FX_IO_M2I2_EDM_MC_02;
diagnostic_msgs::KeyValue FX_IO_M2I3_ALM_01;
diagnostic_msgs::KeyValue FX_IO_M2I4_ALM_02;
diagnostic_msgs::KeyValue FX_IO_M1Q1_Stop_Mode;
diagnostic_msgs::KeyValue FX_IO_M1Q2_Reset_ALM;
diagnostic_msgs::KeyValue FX_IO_M1Q3_Button_Start;
diagnostic_msgs::KeyValue FX_IO_M1Q4_Button_Reset;
diagnostic_msgs::KeyValue FX_IO_M2Q1_OSSD_01;
diagnostic_msgs::KeyValue FX_IO_M2Q2_OSSD_02;
diagnostic_msgs::KeyValue FX_IO_M2Q3_FWD_REV;
diagnostic_msgs::KeyValue FX_IO_M2Q4_MBF;

diagnostic_msgs::KeyValue MS_MS3_F_Status;
diagnostic_msgs::KeyValue MS_MS3_F_MS;
diagnostic_msgs::KeyValue MS_MS3_F_CE;
diagnostic_msgs::KeyValue MS_MS3_F_COPS_01;
diagnostic_msgs::KeyValue MS_MS3_F_COPS_02;
diagnostic_msgs::KeyValue MS_MS3_F_COPS_03;
diagnostic_msgs::KeyValue MS_MS3_F_COPS_04;
diagnostic_msgs::KeyValue MS_MS3_F_COPNS_01;
diagnostic_msgs::KeyValue MS_MS3_F_COPNS_02;
diagnostic_msgs::KeyValue MS_MS3_F_COPNS_03;
diagnostic_msgs::KeyValue MS_MS3_F_COPNS_04;

diagnostic_msgs::KeyValue MS_MS3_B_Status;
diagnostic_msgs::KeyValue MS_MS3_B_MS;
diagnostic_msgs::KeyValue MS_MS3_B_CE;
diagnostic_msgs::KeyValue MS_MS3_B_COPS_01;
diagnostic_msgs::KeyValue MS_MS3_B_COPS_02;
diagnostic_msgs::KeyValue MS_MS3_B_COPS_03;
diagnostic_msgs::KeyValue MS_MS3_B_COPS_04;
diagnostic_msgs::KeyValue MS_MS3_B_COPNS_01;
diagnostic_msgs::KeyValue MS_MS3_B_COPNS_02;
diagnostic_msgs::KeyValue MS_MS3_B_COPNS_03;
diagnostic_msgs::KeyValue MS_MS3_B_COPNS_04;

diagnostic_msgs::KeyValue EN_ENC_L_DIR;
diagnostic_msgs::KeyValue EN_ENC_L_SSTILL;
diagnostic_msgs::KeyValue EN_ENC_R_DIR;
diagnostic_msgs::KeyValue EN_ENC_R_SSTILL;

diagnostic_msgs::KeyValue ST_SAFE_IO_GB_EMC;
diagnostic_msgs::KeyValue ST_SAFE_IO_GB_Start;
diagnostic_msgs::KeyValue ST_SAFE_IO_GB_Reset;
diagnostic_msgs::KeyValue ST_SAFE_IO_GB_Key_Brake;
diagnostic_msgs::KeyValue ST_SAFE_IO_GB_EDM_MC;
diagnostic_msgs::KeyValue ST_SAFE_IO_GB_ALM_M;
diagnostic_msgs::KeyValue ST_SAFE_IO_GB_IPC_Ok;
diagnostic_msgs::KeyValue ST_SAFE_IO_GB_IPC_Run;
diagnostic_msgs::KeyValue ST_SAFE_IO_GB_FX_Run;
diagnostic_msgs::KeyValue ST_SAFE_FC_ST_Ready;
diagnostic_msgs::KeyValue ST_SAFE_FC_ST_G;
diagnostic_msgs::KeyValue ST_SAFE_FC_ST_B_G;
diagnostic_msgs::KeyValue ST_SAFE_FC_SW_Ok;
diagnostic_msgs::KeyValue ST_SAFE_FC_Auto_Restart;
diagnostic_msgs::KeyValue ST_SAFE_FC_EDM_E;
diagnostic_msgs::KeyValue ST_SAFE_FC_En_Ctr_ST;

diagnostic_msgs::KeyValue ST_SAFE_MS3_Power_Ok;
diagnostic_msgs::KeyValue ST_SAFE_MS3_Brake_Ok;
diagnostic_msgs::KeyValue ST_SAFE_MS3_Warn_Ok;
diagnostic_msgs::KeyValue ST_SAFE_MS3_Detect_Ok;
diagnostic_msgs::KeyValue ST_SAFE_MS3_Contour_Ok;

diagnostic_msgs::KeyValue ST_SAFE_MS3_SP_SStill;
diagnostic_msgs::KeyValue ST_SAFE_MS3_SP_VSlow;
diagnostic_msgs::KeyValue ST_SAFE_MS3_SP_Slow;
diagnostic_msgs::KeyValue ST_SAFE_MS3_SP_Medium;
diagnostic_msgs::KeyValue ST_SAFE_MS3_SP_Fast;
diagnostic_msgs::KeyValue ST_SAFE_MS3_SP_VFast;

diagnostic_msgs::KeyValue ST_SAFE_MS3_DIR_F;
diagnostic_msgs::KeyValue ST_SAFE_MS3_DIR_B;
diagnostic_msgs::KeyValue ST_SAFE_MS3_Turn_L;
diagnostic_msgs::KeyValue ST_SAFE_MS3_Turn_R;
diagnostic_msgs::KeyValue ST_SAFE_MS3_Forward;
diagnostic_msgs::KeyValue ST_SAFE_MS3_Backward;
diagnostic_msgs::KeyValue ST_SAFE_MS3_Standstill;

diagnostic_msgs::KeyValue ST_SAFE_Action_Pose_Charge_In;
diagnostic_msgs::KeyValue ST_SAFE_Action_Pose_Charge_Out;
diagnostic_msgs::KeyValue ST_SAFE_Action_Pose_Pick_In;
diagnostic_msgs::KeyValue ST_SAFE_Action_Pose_Pick_Up;
diagnostic_msgs::KeyValue ST_SAFE_Action_Pose_Pick_Down;
diagnostic_msgs::KeyValue ST_SAFE_Action_Pose_Pick_Out;

diagnostic_msgs::KeyValue ST_SAFE_Status_Status_Pending;
diagnostic_msgs::KeyValue ST_SAFE_Status_Status_Active;
diagnostic_msgs::KeyValue ST_SAFE_Status_Status_Succeeded;
diagnostic_msgs::KeyValue ST_SAFE_Status_Status_Rejected;
diagnostic_msgs::KeyValue ST_SAFE_Status_Status_Lost;

diagnostic_msgs::KeyValue DE_Status_CPU0_PS;
diagnostic_msgs::KeyValue DE_Status_CPU0_OS;
diagnostic_msgs::KeyValue DE_Status_IOXTIO1_PS;
diagnostic_msgs::KeyValue DE_Status_IOXTIO1_OS;
diagnostic_msgs::KeyValue DE_Status_IOXTIO2_PS;
diagnostic_msgs::KeyValue DE_Status_IOXTIO2_OS;
diagnostic_msgs::KeyValue DE_Status_IOXTIO3_PS;
diagnostic_msgs::KeyValue DE_Status_IOXTIO3_OS;
diagnostic_msgs::KeyValue DE_Status_MOC_ENC_L;
diagnostic_msgs::KeyValue DE_Status_MOC_ENC_R;
diagnostic_msgs::KeyValue DE_Status_MOC_PS;
diagnostic_msgs::KeyValue DE_Status_GERP_MS3_F;
diagnostic_msgs::KeyValue DE_Status_GERP_MS3_B;
diagnostic_msgs::KeyValue DE_Status_GENT_Error;
diagnostic_msgs::KeyValue DE_Status_MS3F_Error;
diagnostic_msgs::KeyValue DE_Status_MS3B_Error;

#endif