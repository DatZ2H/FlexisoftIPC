bool ST_SAFE_IO_GB_EMC
bool ST_SAFE_IO_GB_Start
bool ST_SAFE_IO_GB_Reset
bool ST_SAFE_IO_GB_Key_Brake
bool ST_SAFE_IO_GB_EDM_MC
bool ST_SAFE_IO_GB_ALM_M
bool ST_SAFE_IO_GB_IPC_Ok
bool ST_SAFE_IO_GB_IPC_Run
bool ST_SAFE_IO_GB_FX_Run

bool ST_SAFE_FC_ST_Ready
bool ST_SAFE_FC_ST_G
bool ST_SAFE_FC_ST_B_G
bool ST_SAFE_FC_SW_Ok
bool ST_SAFE_FC_Auto_Restart
bool ST_SAFE_FC_EDM_E
bool ST_SAFE_FC_En_Ctr_ST


uint16 ST_SAFE_MS3_Field
bool ST_SAFE_MS3_Power_Ok       #       = 0 #
bool ST_SAFE_MS3_Brake_Ok      #        = 1 #
bool ST_SAFE_MS3_Warn_Ok        #       = 2 #
bool ST_SAFE_MS3_Detect_Ok      #       = 3 #
bool ST_SAFE_MS3_Contour_Ok     #       = 4 #

uint16 ST_SAFE_MS3_SP                      
bool ST_SAFE_MS3_SP_SStill           #  = 0 #
bool ST_SAFE_MS3_SP_VSlow         #     = 1 #
bool ST_SAFE_MS3_SP_Slow             #  = 2 #
bool ST_SAFE_MS3_SP_Medium           #  = 3 #
bool ST_SAFE_MS3_SP_Fast             #  = 4 #
bool ST_SAFE_MS3_SP_VFast            #  = 5 #

uint16 IPC_SAFE_IO_Action            
#bool IPC_SAFE_IO_Pose_Charge_In        = 6 # 
#bool IPC_SAFE_IO_Pose_Charge_Out       = 7 # 
#bool IPC_SAFE_IO_Pose_Pick_In          = 8 # 
#bool IPC_SAFE_IO_Pose_Pick_Up          = 9 # 
#bool IPC_SAFE_IO_Pose_Pick_Down        = 10 # 
#bool IPC_SAFE_IO_Pose_Pick_Out         = 11 # 

uint16 IPC_SAFE_IO_Direction
#bool  IPC_SAFE_IO_Pose_SStill_F       #  = 0 # 
#bool  IPC_SAFE_IO_Pose_SStill_B      #   = 1 #  
#bool  IPC_SAFE_IO_Pose_Turn_L        #  = 2 # 
#bool  IPC_SAFE_IO_Pose_Turn_R         #  = 3 # 
#bool  IPC_SAFE_IO_Pose_Forward        #  = 4 # 
#bool  IPC_SAFE_IO_Pose_Backward        # = 5 # 
#bool  IPC_SAFE_IO_Pose_Stop                 # = 6 #

bool IPC_SAFE_IO_AGV_Run
bool IPC_SAFE_IO_AGV_Brake
bool IPC_SAFE_IO_IPC_Ok
bool IPC_SAFE_IO_IPC_Error
bool IPC_SAFE_IO_Reset_ALM_M



bool IPC_SAFE_MS3_Reset_MS3_F
bool IPC_SAFE_MS3_Reset_MS3_B

float32 IPC_SAFE_SP_Limit
#bool  IPC_SAFE_SP_Limit_0
#bool  IPC_SAFE_SP_Limit_1
#bool  IPC_SAFE_SP_Limit_2
#bool  IPC_SAFE_SP_Limit_3
#bool  IPC_SAFE_SP_Limit_4
#bool  IPC_SAFE_SP_Limit_5
#bool  IPC_SAFE_SP_Limit_6
#bool  IPC_SAFE_SP_Limit_7