

#ifndef FLEXISOFT_FX_H
#define FLEXISOFT_FX_H
#pragma once



#define pose_read_data_cmd 0
#define pose_read_data_1 1
#define pose_read_data_2 2
#define pose_read_data_3 3
#define pose_read_data_4 4

#define pose_read_data_cmd 0
#define pose_read_data_1 1
#define pose_read_data_2 2
#define pose_read_data_3 3
#define pose_read_data_4 4
#define pose_read_w_0 5
#define pose_read_w_1 6
#define pose_read_w_2 7
#define pose_read_w_3 8
#define pose_read_w_4 9
#define pose_read_w_5 10
#define pose_read_w_6 11
#define pose_read_w_7 12
#define pose_read_w_8 13
#define pose_read_w_9 14
#define pose_read_w_10 15
#define pose_read_w_11 16
#define pose_read_w_12 17
#define pose_read_w_13 18
#define pose_read_w_14 19
#define pose_read_w_15 20
#define pose_read_w_16 21
#define pose_read_w_17 22
#define pose_read_w_18 23
#define pose_read_w_19 24
#define pose_read_w_20 25
#define pose_read_w_21 26
#define pose_read_w_22 27
#define pose_read_w_23 28
#define pose_read_w_24 29

#define pose_write_cmd 0
#define pose_write_data_1 1
#define pose_write_data_2 2
#define pose_write_data_3 3
#define pose_write_data_4 4
#define pose_write_data_5 5
#define pose_write_w_0 6
#define pose_write_w_1 7
#define pose_write_w_2 8
#define pose_write_w_3 9
#define pose_write_w_4 10

#define pose_write_cmd 0
#define pose_write_status 1

#define IO_M1I1_EMC   4 , 0
#define IO_M1I2_EMC_Spare   4 , 1
#define IO_M1I3_Start_Run   4 , 2
#define IO_M1I4_Reset   4 , 3
#define IO_M1I5_Stop_Spare   4 , 4
#define IO_M1I6_Key_Brake   4 , 5
#define IO_M1I7_FX_Ok   4 , 6
#define IO_M1I8_IPC_Run   4 , 7
#define IO_M2I1_EDM_MC_01   4 , 8
#define IO_M2I2_EDM_MC_02   4 , 9
#define IO_M2I3_ALM_01   4 , 10
#define IO_M2I4_ALM_02   4 , 11

#define IO_M1Q1_Stop_Mode   8 , 0
#define IO_M1Q2_Reset_ALM   8 , 1
#define IO_M1Q3_Button_Start   8 , 2
#define IO_M1Q4_Button_Reset   8 , 3

#define IO_M2Q1_OSSD_01   8 , 8
#define IO_M2Q2_OSSD_02   8 , 9
#define IO_M2Q3_FWD_REV   8 , 10
#define IO_M2Q4_MBF   8 , 11

#define MS3_F_Status   12 , 0
#define MS3_F_MS   12 , 1
#define MS3_F_CE   12 , 2

#define MS3_F_COPS_01   12 , 4
#define MS3_F_COPS_02   12 , 5
#define MS3_F_COPS_03   12 , 6
#define MS3_F_COPS_04   12 , 7

#define MS3_F_COPNS_01   12 , 8
#define MS3_F_COPNS_02   12 , 9
#define MS3_F_COPNS_03   12 , 10
#define MS3_F_COPNS_04   12 , 11

#define MS3_B_Status   13 , 0
#define MS3_B_MS   13 , 1
#define MS3_B_CE   13 , 2

#define MS3_B_COPS_01   13 , 4
#define MS3_B_COPS_02   13 , 5
#define MS3_B_COPS_03   13 , 6
#define MS3_B_COPS_04   13 , 7

#define MS3_B_COPNS_01   13 , 8
#define MS3_B_COPNS_02   13 , 9
#define MS3_B_COPNS_03   13 , 10
#define MS3_B_COPNS_04   13 , 11

#define ENC_L_DIR   14 , 0
#define ENC_L_SSTILL   14 , 1
#define ENC_L_Speed   14 , 8
#define ENC_R_DIR   15 , 0
#define ENC_R_SSTILL   15 , 1
#define ENC_R_Speed   15 , 8

#define SAFE_IO_GB_EMC   16 , 0
#define SAFE_IO_GB_Start   16 , 1
#define SAFE_IO_GB_Reset   16 , 2
#define SAFE_IO_GB_Key_Brake   16 , 3
#define SAFE_IO_GB_EDM_MC   16 , 4
#define SAFE_IO_GB_ALM_M   16 , 5
#define SAFE_IO_GB_IPC_Ok   16 , 6
#define SAFE_IO_GB_IPC_Run   16 , 7
#define SAFE_IO_GB_FX_Run   16 , 8
#define SAFE_FC_ST_Ready   16 , 9
#define SAFE_FC_ST_G   16 , 10
#define SAFE_FC_ST_B_G   16 , 11
#define SAFE_FC_SW_Ok   16 , 12
#define SAFE_FC_Auto_Restart   16 , 13
#define SAFE_FC_EDM_E   16 , 14
#define SAFE_FC_En_Ctr_ST   16 , 15

#define SAFE_MS3_Power_Ok   17 , 0
#define SAFE_MS3_Brake_Ok   17 , 1
#define SAFE_MS3_Warn_Ok   17 , 2
#define SAFE_MS3_Detect_Ok   17 , 3
#define SAFE_MS3_Contour_Ok   17 , 4

#define SAFE_MS3_SP_SStill   17 , 8
#define SAFE_MS3_SP_VSlow   17 , 9
#define SAFE_MS3_SP_Slow   17 , 10
#define SAFE_MS3_SP_Medium   17 , 11
#define SAFE_MS3_SP_Fast   17 , 12
#define SAFE_MS3_SP_VFast   17 , 13

#define SAFE_MS3_DIR_F   18 , 0
#define SAFE_MS3_DIR_B   18 , 1
#define SAFE_MS3_Turn_L   18 , 2
#define SAFE_MS3_Turn_R   18 , 3
#define SAFE_MS3_Forward   18 , 4
#define SAFE_MS3_Backward   18 , 5
#define SAFE_MS3_Standstill   18 , 6

#define SAFE_Action_Pose_Charge_In   18 , 8
#define SAFE_Action_Pose_Charge_Out   18 , 9
#define SAFE_Action_Pose_Pick_In   18 , 10
#define SAFE_Action_Pose_Pick_Up   18 , 11
#define SAFE_Action_Pose_Pick_Down   18 , 12
#define SAFE_Action_Pose_Pick_Out   18 , 13

#define SAFE_Status_Status_Pending   19 , 0
#define SAFE_Status_Status_Active   19 , 1
#define SAFE_Status_Status_Succeeded   19 , 2
#define SAFE_Status_Status_Rejected   19 , 3
#define SAFE_Status_Status_Lost   19 , 4

#define Status_CPU0_PS   23 , 0
#define Status_CPU0_OS   23 , 1
#define Status_IOXTIO1_PS   23 , 2
#define Status_IOXTIO1_OS   23 , 3
#define Status_IOXTIO2_PS   23 , 4
#define Status_IOXTIO2_OS   23 , 5
#define Status_IOXTIO3_PS   23 , 6
#define Status_IOXTIO3_OS   23 , 7
#define Status_IOXTDS_OL   23 , 8
#define Status_IOXTDS_PS   23 , 9
#define Status_IOXTDS_OS   23 , 10
#define Status_IOSTIO_OL   23 , 11
#define Status_IOSTIO_PS   23 , 12
#define Status_IOSTIO_OS   23 , 13
#define Status_MOC_ENC_L   23 , 8
#define Status_MOC_ENC_R   23 , 9
#define Status_MOC_PS   23 , 10
#define Status_GERP_MS3_F   23 , 11
#define Status_GERP_MS3_B   23 , 12
#define Status_GENT_Error   23 , 13
#define Status_MS3F_Error   23 , 14
#define Status_MS3B_Error   23 , 15

#define SAFE_IO_AGV_Run   0 , 0
#define SAFE_IO_AGV_Brake   0 , 1
#define SAFE_IO_IPC_Ok   0 , 2
#define SAFE_IO_IPC_Error   0 , 3
#define SAFE_IO_Reset_ALM_M   0 , 4

#define SAFE_IO_Pose_Charge_In   1 , 0
#define SAFE_IO_Pose_Charge_Out   1 , 1
#define SAFE_IO_Pose_Pick_In   1 , 2
#define SAFE_IO_Pose_Pick_Up   1 , 3
#define SAFE_IO_Pose_Pick_Down   1 , 4
#define SAFE_IO_Pose_Pick_Out   1 , 5

#define SAFE_IO_Status_Pending   0 , 8
#define SAFE_IO_Status_Active   0 , 9
#define SAFE_IO_Status_Succeeded   0 , 10
#define SAFE_IO_Status_Rejected   0 , 11
#define SAFE_IO_Status_Lost   0 , 12

#define SAFE_IO_Pose_SStill_F   1 , 8
#define SAFE_IO_Pose_SStill_B   1 , 9
#define SAFE_IO_Pose_Turn_L   1 , 10
#define SAFE_IO_Pose_Turn_R   1 , 11
#define SAFE_IO_Pose_Forward   1 , 12
#define SAFE_IO_Pose_Backward   1 , 13
#define SAFE_IO_Pose_Stop   1 , 14

#define SAFE_MS3_Reset_MS3_F   2 , 0
#define SAFE_MS3_Reset_MS3_B   2 , 1

#define SAFE_SP_Limit_0   3 , 0
#define SAFE_SP_Limit_1   3 , 1
#define SAFE_SP_Limit_2   3 , 2
#define SAFE_SP_Limit_3   3 , 3
#define SAFE_SP_Limit_4   3 , 4
#define SAFE_SP_Limit_5   3 , 5
#define SAFE_SP_Limit_6   3 , 6
#define SAFE_SP_Limit_7   3 , 7
/*
00F2
000A0000000000000000
11
00
00
00
00
00
00
00
00


11
  */
bool Fx_Read_Gent[25][16];
bool Fx_Read_Gent_Check[25][16];

bool Fx_Write_Gent_Ckeck[5][16];
bool Fx_Write_Gent[5][16];
uint16_t req_read_gent[5];

uint16_t req_read_data_cmd = 0xF100;
uint16_t req_read_data_1 = 0x1000;
uint16_t req_read_data_2 = 0x1000;
uint16_t req_read_data_3 = 0x1000;
uint16_t req_read_data_4 = 0x1000;

uint16_t res_read_gent[30];

uint16_t res_read_data_cmd = 0x1F00;
uint16_t res_read_data_1;
uint16_t res_read_data_2;
uint16_t res_read_data_3;
uint16_t res_read_data_4;

uint16_t res_read_w_[25];

uint16_t res_read_w_0;
uint16_t res_read_w_1;
uint16_t res_read_w_2;
uint16_t res_read_w_3;
uint16_t res_read_w_4;
uint16_t res_read_w_5;
uint16_t res_read_w_6;
uint16_t res_read_w_7;
uint16_t res_read_w_8;
uint16_t res_read_w_9;
uint16_t res_read_w_10;
uint16_t res_read_w_11;
uint16_t res_read_w_12;
uint16_t res_read_w_13;
uint16_t res_read_w_14;
uint16_t res_read_w_15;
uint16_t res_read_w_16;
uint16_t res_read_w_17;
uint16_t res_read_w_18;
uint16_t res_read_w_19;
uint16_t res_read_w_20;
uint16_t res_read_w_21;
uint16_t res_read_w_22;
uint16_t res_read_w_23;
uint16_t res_read_w_24;

uint16_t req_write_gent[11];

uint16_t req_write_cmd = 0xF200;
uint16_t req_write_data_1 = 0x0A00;
uint16_t req_write_data_2 = 0x0A00;
uint16_t req_write_data_3 = 0x0A00;
uint16_t req_write_data_4 = 0x0A00;
uint16_t req_write_data_5 = 0x0A00;
uint16_t req_write_w_0 ;
uint16_t req_write_w_1 ;
uint16_t req_write_w_2 ;
uint16_t req_write_w_3 ;
uint16_t req_write_w_4 ;

uint16_t res_write_gent[2];

uint16_t res_write_cmd = 0x2F00;
uint16_t res_write_status;







    


	#endif