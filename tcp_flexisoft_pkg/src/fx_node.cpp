#include <client.h>
#include <flexisoft_fx.h>
#include <flexisoft_msg.h>

#include <diagnostic_msgs/DiagnosticArray.h>
#include <diagnostic_msgs/DiagnosticStatus.h>
#include <diagnostic_msgs/KeyValue.h>

using namespace std;

int main(int argc, char **argv)
{

    // create a modbus object
    TCPClient *flexisoft = new TCPClient("192.168.1.21", 80);
    // set slave id

    // connect with the server
    flexisoft->TCPClient_connect();
    ros::init(argc, argv, "diagnostics");
    ros::NodeHandle nh;

    ros::Publisher diagnostic_pub = nh.advertise<diagnostic_msgs::DiagnosticArray>("/diagnostics", 10);

    ros::Rate loop_rate(10);

    diagnostic_msgs::DiagnosticArray dia_array;

    diagnostic_msgs::DiagnosticStatus flexisoft_status;
    flexisoft_status.name = "flexisoft";
 
    diagnostic_msgs::DiagnosticStatus ms3_f_status;
    ms3_f_status.name = "Microscan3 F";

    diagnostic_msgs::DiagnosticStatus ms3_b_status;
    ms3_b_status.name = "Microscan3 B";

    diagnostic_msgs::DiagnosticStatus enc_status;
    enc_status.name = "ENC ";

    diagnostic_msgs::DiagnosticStatus safety_status;
    safety_status.name = "safety ";

    diagnostic_msgs::DiagnosticStatus device_status;
    device_status.name = "device ";


        while (ros::ok())
    {
        const char *strKey;
        const char *strValue;

        flexisoft_status.values.clear();
        ms3_f_status.values.clear();
        ms3_b_status.values.clear();
        enc_status.values.clear();
        safety_status.values.clear();
        device_status.values.clear();

        flexisoft->TCPClientReadInputGentArray(1);
        cout << "gias tri x la " << flexisoft->TCPClientReadArrayBit(flexisoft->Fx_Read_Gent, IO_M1I1_EMC) << endl;

        flexisoft_status.level = diagnostic_msgs::DiagnosticStatus::OK;
        flexisoft_status.message = "Everything seem to be ok.";

        ms3_f_status.level = diagnostic_msgs::DiagnosticStatus::OK;
        ms3_f_status.message = "Everything seem to be ok.";

        ms3_b_status.level = diagnostic_msgs::DiagnosticStatus::OK;
        ms3_b_status.message = "Everything seem to be ok.";

// Start flexisoft_status
        if (flexisoft->TCPClientReadArrayBit(flexisoft->Fx_Read_Gent, IO_M1I1_EMC) == 1)
        {
            strKey = "Exited normally";
            strValue = "TRUE";
        }
        else
        {
            strKey = "Emgergencystop hit";
            strValue = "FALSE";
        }
        FX_IO_M1I1_EMC.key = strKey;
        FX_IO_M1I1_EMC.value = strValue;

        flexisoft_status.values.push_back(FX_IO_M1I1_EMC);

// Start flexisoft_status

        if (flexisoft->TCPClientReadArrayBit(flexisoft->Fx_Read_Gent, IO_M1I3_Start_Run) == 1)
        {
            strKey = "Exited normally";
            strValue = "TRUE";
        }
        else
        {
            strKey = "Emgergencystop hit";
            strValue = "FALSE";
        }
        FX_IO_M1I3_Start_Run.key = strKey;
        FX_IO_M1I3_Start_Run.value = strValue;

        flexisoft_status.values.push_back(FX_IO_M1I3_Start_Run);

// Start flexisoft_status

        if (flexisoft->TCPClientReadArrayBit(flexisoft->Fx_Read_Gent, IO_M1I4_Reset) == 1)
        {
            strKey = "Exited normally";
            strValue = "TRUE";
        }
        else
        {
            strKey = "Emgergencystop hit";
            strValue = "FALSE";
        }
        FX_IO_M1I4_Reset.key = strKey;
        FX_IO_M1I4_Reset.value = strValue;

        flexisoft_status.values.push_back(FX_IO_M1I4_Reset);

// Start flexisoft_status

        if (flexisoft->TCPClientReadArrayBit(flexisoft->Fx_Read_Gent, IO_M1I6_Key_Brake) == 1)
        {
            strKey = "Exited normally";
            strValue = "TRUE";
        }
        else
        {
            strKey = "Emgergencystop hit";
            strValue = "FALSE";
        }
        FX_IO_M1I6_Key_Brake.key = strKey;
        FX_IO_M1I6_Key_Brake.value = strValue;

        flexisoft_status.values.push_back(FX_IO_M1I6_Key_Brake);
// Start flexisoft_status

        if (flexisoft->TCPClientReadArrayBit(flexisoft->Fx_Read_Gent, IO_M1I7_FX_Ok) == 1)
        {
            strKey = "Exited normally";
            strValue = "TRUE";
        }
        else
        {
            strKey = "Emgergencystop hit";
            strValue = "FALSE";
        }
        FX_IO_M1I7_FX_Ok.key = strKey;
        FX_IO_M1I7_FX_Ok.value = strValue;

        flexisoft_status.values.push_back(FX_IO_M1I7_FX_Ok);
// Start flexisoft_status

        if (flexisoft->TCPClientReadArrayBit(flexisoft->Fx_Read_Gent, IO_M1I8_IPC_Run) == 1)
        {
            strKey = "Exited normally";
            strValue = "TRUE";
        }
        else
        {
            strKey = "Emgergencystop hit";
            strValue = "FALSE";
        }
        FX_IO_M1I8_IPC_Run.key = strKey;
        FX_IO_M1I8_IPC_Run.value = strValue;

        flexisoft_status.values.push_back(FX_IO_M1I8_IPC_Run);
// Start flexisoft_status

        if (flexisoft->TCPClientReadArrayBit(flexisoft->Fx_Read_Gent, IO_M2I1_EDM_MC_01) == 1)
        {
            strKey = "Exited normally";
            strValue = "TRUE";
        }
        else
        {
            strKey = "Emgergencystop hit";
            strValue = "FALSE";
        }
        FX_IO_M2I1_EDM_MC_01.key = strKey;
        FX_IO_M2I1_EDM_MC_01.value = strValue;

        flexisoft_status.values.push_back(FX_IO_M2I1_EDM_MC_01);
// Start flexisoft_status

        if (flexisoft->TCPClientReadArrayBit(flexisoft->Fx_Read_Gent, IO_M2I2_EDM_MC_02) == 1)
        {
            strKey = "Exited normally";
            strValue = "TRUE";
        }
        else
        {
            strKey = "Emgergencystop hit";
            strValue = "FALSE";
        }
        FX_IO_M2I2_EDM_MC_02.key = strKey;
        FX_IO_M2I2_EDM_MC_02.value = strValue;

        flexisoft_status.values.push_back(FX_IO_M2I2_EDM_MC_02);
// Start flexisoft_status

        if (flexisoft->TCPClientReadArrayBit(flexisoft->Fx_Read_Gent, IO_M2I3_ALM_01) == 1)
        {
            strKey = "Exited normally";
            strValue = "TRUE";
        }
        else
        {
            strKey = "Emgergencystop hit";
            strValue = "FALSE";
        }
        FX_IO_M2I3_ALM_01.key = strKey;
        FX_IO_M2I3_ALM_01.value = strValue;

        flexisoft_status.values.push_back(FX_IO_M2I3_ALM_01);
// Start flexisoft_status

        if (flexisoft->TCPClientReadArrayBit(flexisoft->Fx_Read_Gent, IO_M2I4_ALM_02) == 1)
        {
            strKey = "Exited normally";
            strValue = "TRUE";
        }
        else
        {
            strKey = "Emgergencystop hit";
            strValue = "FALSE";
        }
        FX_IO_M2I4_ALM_02.key = strKey;
        FX_IO_M2I4_ALM_02.value = strValue;

        flexisoft_status.values.push_back(FX_IO_M2I4_ALM_02);
// Start flexisoft_status

        if (flexisoft->TCPClientReadArrayBit(flexisoft->Fx_Read_Gent, IO_M1Q1_Stop_Mode) == 1)
        {
            strKey = "Exited normally";
            strValue = "TRUE";
        }
        else
        {
            strKey = "Emgergencystop hit";
            strValue = "FALSE";
        }
        FX_IO_M1Q1_Stop_Mode.key = strKey;
        FX_IO_M1Q1_Stop_Mode.value = strValue;

        flexisoft_status.values.push_back(FX_IO_M1Q1_Stop_Mode);
// Start flexisoft_status

        if (flexisoft->TCPClientReadArrayBit(flexisoft->Fx_Read_Gent, IO_M1Q2_Reset_ALM) == 1)
        {
            strKey = "Exited normally";
            strValue = "TRUE";
        }
        else
        {
            strKey = "Emgergencystop hit";
            strValue = "FALSE";
        }
        FX_IO_M1Q2_Reset_ALM.key = strKey;
        FX_IO_M1Q2_Reset_ALM.value = strValue;

        flexisoft_status.values.push_back(FX_IO_M1Q2_Reset_ALM);
// Start flexisoft_status

        if (flexisoft->TCPClientReadArrayBit(flexisoft->Fx_Read_Gent, IO_M1Q3_Button_Start) == 1)
        {
            strKey = "Exited normally";
            strValue = "TRUE";
        }
        else
        {
            strKey = "Emgergencystop hit";
            strValue = "FALSE";
        }
        FX_IO_M1Q3_Button_Start.key = strKey;
        FX_IO_M1Q3_Button_Start.value = strValue;

        flexisoft_status.values.push_back(FX_IO_M1Q3_Button_Start);
// Start flexisoft_status

        if (flexisoft->TCPClientReadArrayBit(flexisoft->Fx_Read_Gent, IO_M1Q4_Button_Reset) == 1)
        {
            strKey = "Exited normally";
            strValue = "TRUE";
        }
        else
        {
            strKey = "Emgergencystop hit";
            strValue = "FALSE";
        }
        FX_IO_M1Q4_Button_Reset.key = strKey;
        FX_IO_M1Q4_Button_Reset.value = strValue;

        flexisoft_status.values.push_back(FX_IO_M1Q4_Button_Reset);
// Start flexisoft_status

        if (flexisoft->TCPClientReadArrayBit(flexisoft->Fx_Read_Gent, IO_M2Q1_OSSD_01) == 1)
        {
            strKey = "Exited normally";
            strValue = "TRUE";
        }
        else
        {
            strKey = "Emgergencystop hit";
            strValue = "FALSE";
        }
        FX_IO_M2Q1_OSSD_01.key = strKey;
        FX_IO_M2Q1_OSSD_01.value = strValue;

        flexisoft_status.values.push_back(FX_IO_M2Q1_OSSD_01);
// Start flexisoft_status

        if (flexisoft->TCPClientReadArrayBit(flexisoft->Fx_Read_Gent, IO_M2Q2_OSSD_02) == 1)
        {
            strKey = "Exited normally";
            strValue = "TRUE";
        }
        else
        {
            strKey = "Emgergencystop hit";
            strValue = "FALSE";
        }
        FX_IO_M2Q2_OSSD_02.key = strKey;
        FX_IO_M2Q2_OSSD_02.value = strValue;

        flexisoft_status.values.push_back(FX_IO_M2Q2_OSSD_02);
// Start flexisoft_status

        if (flexisoft->TCPClientReadArrayBit(flexisoft->Fx_Read_Gent, IO_M2Q3_FWD_REV) == 1)
        {
            strKey = "Exited normally";
            strValue = "TRUE";
        }
        else
        {
            strKey = "Emgergencystop hit";
            strValue = "FALSE";
        }
        FX_IO_M2Q3_FWD_REV.key = strKey;
        FX_IO_M2Q3_FWD_REV.value = strValue;

        flexisoft_status.values.push_back(FX_IO_M2Q3_FWD_REV);
// Start flexisoft_status

        if (flexisoft->TCPClientReadArrayBit(flexisoft->Fx_Read_Gent, IO_M2Q4_MBF) == 1)
        {
            strKey = "Exited normally";
            strValue = "TRUE";
        }
        else
        {
            strKey = "Emgergencystop hit";
            strValue = "FALSE";
        }
        FX_IO_M2Q4_MBF.key = strKey;
        FX_IO_M2Q4_MBF.value = strValue;

        flexisoft_status.values.push_back(FX_IO_M2Q4_MBF);


// MS3 F

// Start ms3_f_status

        if (flexisoft->TCPClientReadArrayBit(flexisoft->Fx_Read_Gent, MS3_F_Status) == 1)
        {
            strKey = "Exited normally";
            strValue = "TRUE";
        }
        else
        {
            strKey = "Emgergencystop hit";
            strValue = "FALSE";
        }
        MS_MS3_F_Status.key = strKey;
        MS_MS3_F_Status.value = strValue;

        ms3_f_status.values.push_back(MS_MS3_F_Status);
// Start ms3_f_status

        if (flexisoft->TCPClientReadArrayBit(flexisoft->Fx_Read_Gent, MS3_F_MS) == 1)
        {
            strKey = "Exited normally";
            strValue = "TRUE";
        }
        else
        {
            strKey = "Emgergencystop hit";
            strValue = "FALSE";
        }
        MS_MS3_F_MS.key = strKey;
        MS_MS3_F_MS.value = strValue;

         ms3_f_status.values.push_back(MS_MS3_F_MS);
// Start ms3_f_status

        if (flexisoft->TCPClientReadArrayBit(flexisoft->Fx_Read_Gent, MS3_F_CE) == 1)
        {
            strKey = "Exited normally";
            strValue = "TRUE";
        }
        else
        {
            strKey = "Emgergencystop hit";
            strValue = "FALSE";
        }
        MS_MS3_F_CE.key = strKey;
        MS_MS3_F_CE.value = strValue;

         ms3_f_status.values.push_back(MS_MS3_F_CE);
// Start ms3_f_status

        if (flexisoft->TCPClientReadArrayBit(flexisoft->Fx_Read_Gent, MS3_F_COPS_01) == 1)
        {
            strKey = "Exited normally";
            strValue = "TRUE";
        }
        else
        {
            strKey = "Emgergencystop hit";
            strValue = "FALSE";
        }
        MS_MS3_F_COPS_01.key = strKey;
        MS_MS3_F_COPS_01.value = strValue;

         ms3_f_status.values.push_back(MS_MS3_F_COPS_01);
// Start ms3_f_status

        if (flexisoft->TCPClientReadArrayBit(flexisoft->Fx_Read_Gent, MS3_F_COPS_02) == 1)
        {
            strKey = "Exited normally";
            strValue = "TRUE";
        }
        else
        {
            strKey = "Emgergencystop hit";
            strValue = "FALSE";
        }
        MS_MS3_F_COPS_02.key = strKey;
        MS_MS3_F_COPS_02.value = strValue;

         ms3_f_status.values.push_back(MS_MS3_F_COPS_02);
// Start ms3_f_status

        if (flexisoft->TCPClientReadArrayBit(flexisoft->Fx_Read_Gent, MS3_F_COPS_03) == 1)
        {
            strKey = "Exited normally";
            strValue = "TRUE";
        }
        else
        {
            strKey = "Emgergencystop hit";
            strValue = "FALSE";
        }
        MS_MS3_F_COPS_03.key = strKey;
        MS_MS3_F_COPS_03.value = strValue;

         ms3_f_status.values.push_back(MS_MS3_F_COPS_03);
// Start ms3_f_status

        if (flexisoft->TCPClientReadArrayBit(flexisoft->Fx_Read_Gent, MS3_F_COPS_04) == 1)
        {
            strKey = "Exited normally";
            strValue = "TRUE";
        }
        else
        {
            strKey = "Emgergencystop hit";
            strValue = "FALSE";
        }
        MS_MS3_F_COPS_04.key = strKey;
        MS_MS3_F_COPS_04.value = strValue;

         ms3_f_status.values.push_back(MS_MS3_F_COPS_04);
// Start ms3_f_status

        if (flexisoft->TCPClientReadArrayBit(flexisoft->Fx_Read_Gent, MS3_F_COPNS_01) == 1)
        {
            strKey = "Exited normally";
            strValue = "TRUE";
        }
        else
        {
            strKey = "Emgergencystop hit";
            strValue = "FALSE";
        }
        MS_MS3_F_COPNS_01.key = strKey;
        MS_MS3_F_COPNS_01.value = strValue;

         ms3_f_status.values.push_back(MS_MS3_F_COPNS_01);
// Start ms3_f_status

        if (flexisoft->TCPClientReadArrayBit(flexisoft->Fx_Read_Gent, MS3_F_COPNS_02) == 1)
        {
            strKey = "Exited normally";
            strValue = "TRUE";
        }
        else
        {
            strKey = "Emgergencystop hit";
            strValue = "FALSE";
        }
        MS_MS3_F_COPNS_02.key = strKey;
        MS_MS3_F_COPNS_02.value = strValue;

         ms3_f_status.values.push_back(MS_MS3_F_COPNS_02);
// Start ms3_f_status

        if (flexisoft->TCPClientReadArrayBit(flexisoft->Fx_Read_Gent, MS3_F_COPNS_03) == 1)
        {
            strKey = "Exited normally";
            strValue = "TRUE";
        }
        else
        {
            strKey = "Emgergencystop hit";
            strValue = "FALSE";
        }
        MS_MS3_F_COPNS_03.key = strKey;
        MS_MS3_F_COPNS_03.value = strValue;

         ms3_f_status.values.push_back(MS_MS3_F_COPNS_03);
// Start ms3_f_status

        if (flexisoft->TCPClientReadArrayBit(flexisoft->Fx_Read_Gent, MS3_F_COPNS_04) == 1)
        {
            strKey = "Exited normally";
            strValue = "TRUE";
        }
        else
        {
            strKey = "Emgergencystop hit";
            strValue = "FALSE";
        }
        MS_MS3_F_COPNS_04.key = strKey;
        MS_MS3_F_COPNS_04.value = strValue;

         ms3_f_status.values.push_back(MS_MS3_F_COPNS_04);

// MS3 B
// Start ms3_b_status

        if (flexisoft->TCPClientReadArrayBit(flexisoft->Fx_Read_Gent, MS3_B_Status) == 1)
        {
            strKey = "Exited normally";
            strValue = "TRUE";
        }
        else
        {
            strKey = "Emgergencystop hit";
            strValue = "FALSE";
        }
        MS_MS3_B_Status.key = strKey;
        MS_MS3_B_Status.value = strValue;

         ms3_b_status.values.push_back(MS_MS3_B_Status);
// Start ms3_b_status

        if (flexisoft->TCPClientReadArrayBit(flexisoft->Fx_Read_Gent, MS3_B_Status) == 1)
        {
            strKey = "Exited normally";
            strValue = "TRUE";
        }
        else
        {
            strKey = "Emgergencystop hit";
            strValue = "FALSE";
        }
        MS_MS3_B_Status.key = strKey;
        MS_MS3_B_Status.value = strValue;

         ms3_b_status.values.push_back(MS_MS3_B_Status);

// Start ms3_b_status

        if (flexisoft->TCPClientReadArrayBit(flexisoft->Fx_Read_Gent, MS3_B_Status) == 1)
        {
            strKey = "Exited normally";
            strValue = "TRUE";
        }
        else
        {
            strKey = "Emgergencystop hit";
            strValue = "FALSE";
        }
        MS_MS3_B_Status.key = strKey;
        MS_MS3_B_Status.value = strValue;

         ms3_b_status.values.push_back(MS_MS3_B_Status);

// Start ms3_b_status

        if (flexisoft->TCPClientReadArrayBit(flexisoft->Fx_Read_Gent, MS3_B_Status) == 1)
        {
            strKey = "Exited normally";
            strValue = "TRUE";
        }
        else
        {
            strKey = "Emgergencystop hit";
            strValue = "FALSE";
        }
        MS_MS3_B_Status.key = strKey;
        MS_MS3_B_Status.value = strValue;

         ms3_b_status.values.push_back(MS_MS3_B_Status);

// Start ms3_b_status

        if (flexisoft->TCPClientReadArrayBit(flexisoft->Fx_Read_Gent, MS3_B_Status) == 1)
        {
            strKey = "Exited normally";
            strValue = "TRUE";
        }
        else
        {
            strKey = "Emgergencystop hit";
            strValue = "FALSE";
        }
        MS_MS3_B_Status.key = strKey;
        MS_MS3_B_Status.value = strValue;

         ms3_b_status.values.push_back(MS_MS3_B_Status);

// Start ms3_b_status

        if (flexisoft->TCPClientReadArrayBit(flexisoft->Fx_Read_Gent, MS3_B_Status) == 1)
        {
            strKey = "Exited normally";
            strValue = "TRUE";
        }
        else
        {
            strKey = "Emgergencystop hit";
            strValue = "FALSE";
        }
        MS_MS3_B_Status.key = strKey;
        MS_MS3_B_Status.value = strValue;

         ms3_b_status.values.push_back(MS_MS3_B_Status);

// Start ms3_b_status

        if (flexisoft->TCPClientReadArrayBit(flexisoft->Fx_Read_Gent, MS3_B_MS) == 1)
        {
            strKey = "Exited normally";
            strValue = "TRUE";
        }
        else
        {
            strKey = "Emgergencystop hit";
            strValue = "FALSE";
        }
        MS_MS3_B_MS.key = strKey;
        MS_MS3_B_MS.value = strValue;

         ms3_b_status.values.push_back(MS_MS3_B_MS);

// Start ms3_b_status

        if (flexisoft->TCPClientReadArrayBit(flexisoft->Fx_Read_Gent, MS3_B_CE) == 1)
        {
            strKey = "Exited normally";
            strValue = "TRUE";
        }
        else
        {
            strKey = "Emgergencystop hit";
            strValue = "FALSE";
        }
        MS_MS3_B_CE.key = strKey;
        MS_MS3_B_CE.value = strValue;

         ms3_b_status.values.push_back(MS_MS3_B_CE);

// Start ms3_b_status

        if (flexisoft->TCPClientReadArrayBit(flexisoft->Fx_Read_Gent, MS3_B_COPS_01) == 1)
        {
            strKey = "Exited normally";
            strValue = "TRUE";
        }
        else
        {
            strKey = "Emgergencystop hit";
            strValue = "FALSE";
        }
        MS_MS3_B_COPS_01.key = strKey;
        MS_MS3_B_COPS_01.value = strValue;

         ms3_b_status.values.push_back(MS_MS3_B_COPS_01);

// Start ms3_b_status

        if (flexisoft->TCPClientReadArrayBit(flexisoft->Fx_Read_Gent, MS3_B_COPS_02) == 1)
        {
            strKey = "Exited normally";
            strValue = "TRUE";
        }
        else
        {
            strKey = "Emgergencystop hit";
            strValue = "FALSE";
        }
        MS_MS3_B_COPS_02.key = strKey;
        MS_MS3_B_COPS_02.value = strValue;

         ms3_b_status.values.push_back(MS_MS3_B_COPS_02);

// Start ms3_b_status

        if (flexisoft->TCPClientReadArrayBit(flexisoft->Fx_Read_Gent, MS3_B_COPS_03) == 1)
        {
            strKey = "Exited normally";
            strValue = "TRUE";
        }
        else
        {
            strKey = "Emgergencystop hit";
            strValue = "FALSE";
        }
        MS_MS3_B_COPS_03.key = strKey;
        MS_MS3_B_COPS_03.value = strValue;

         ms3_b_status.values.push_back(MS_MS3_B_COPS_03);

// Start ms3_b_status

        if (flexisoft->TCPClientReadArrayBit(flexisoft->Fx_Read_Gent, MS3_B_COPS_04) == 1)
        {
            strKey = "Exited normally";
            strValue = "TRUE";
        }
        else
        {
            strKey = "Emgergencystop hit";
            strValue = "FALSE";
        }
        MS_MS3_B_COPS_04.key = strKey;
        MS_MS3_B_COPS_04.value = strValue;

         ms3_b_status.values.push_back(MS_MS3_B_COPS_04);

// Start ms3_b_status

        if (flexisoft->TCPClientReadArrayBit(flexisoft->Fx_Read_Gent, MS3_B_COPNS_01) == 1)
        {
            strKey = "Exited normally";
            strValue = "TRUE";
        }
        else
        {
            strKey = "Emgergencystop hit";
            strValue = "FALSE";
        }
        MS_MS3_B_COPNS_01.key = strKey;
        MS_MS3_B_COPNS_01.value = strValue;

         ms3_b_status.values.push_back(MS_MS3_B_COPNS_01);
// Start ms3_b_status

        if (flexisoft->TCPClientReadArrayBit(flexisoft->Fx_Read_Gent, MS3_B_COPNS_02) == 1)
        {
            strKey = "Exited normally";
            strValue = "TRUE";
        }
        else
        {
            strKey = "Emgergencystop hit";
            strValue = "FALSE";
        }
        MS_MS3_B_COPNS_02.key = strKey;
        MS_MS3_B_COPNS_02.value = strValue;

         ms3_b_status.values.push_back(MS_MS3_B_COPNS_02);
// Start ms3_b_status

        if (flexisoft->TCPClientReadArrayBit(flexisoft->Fx_Read_Gent, MS3_B_COPNS_03) == 1)
        {
            strKey = "Exited normally";
            strValue = "TRUE";
        }
        else
        {
            strKey = "Emgergencystop hit";
            strValue = "FALSE";
        }
        MS_MS3_B_COPNS_03.key = strKey;
        MS_MS3_B_COPNS_03.value = strValue;

         ms3_b_status.values.push_back(MS_MS3_B_COPNS_03);
// Start ms3_b_status

        if (flexisoft->TCPClientReadArrayBit(flexisoft->Fx_Read_Gent, MS3_B_COPNS_04) == 1)
        {
            strKey = "Exited normally";
            strValue = "TRUE";
        }
        else
        {
            strKey = "Emgergencystop hit";
            strValue = "FALSE";
        }
        MS_MS3_B_COPNS_04.key = strKey;
        MS_MS3_B_COPNS_04.value = strValue;

         ms3_b_status.values.push_back(MS_MS3_B_COPNS_04);
// ENC
// Start Encoder

        if (flexisoft->TCPClientReadArrayBit(flexisoft->Fx_Read_Gent, ENC_L_DIR) == 1)
        {
            strKey = "Exited normally";
            strValue = "TRUE";
        }
        else
        {
            strKey = "Emgergencystop hit";
            strValue = "FALSE";
        }
        EN_ENC_L_DIR.key = strKey;
        EN_ENC_L_DIR.value = strValue;

         enc_status.values.push_back(EN_ENC_L_DIR);

// Start Encoder

        if (flexisoft->TCPClientReadArrayBit(flexisoft->Fx_Read_Gent, ENC_L_SSTILL) == 1)
        {
            strKey = "Exited normally";
            strValue = "TRUE";
        }
        else
        {
            strKey = "Emgergencystop hit";
            strValue = "FALSE";
        }
        EN_ENC_L_SSTILL.key = strKey;
        EN_ENC_L_SSTILL.value = strValue;

         enc_status.values.push_back(EN_ENC_L_SSTILL);

// Start Encoder

        if (flexisoft->TCPClientReadArrayBit(flexisoft->Fx_Read_Gent, ENC_R_DIR) == 1)
        {
            strKey = "Exited normally";
            strValue = "TRUE";
        }
        else
        {
            strKey = "Emgergencystop hit";
            strValue = "FALSE";
        }
        EN_ENC_R_DIR.key = strKey;
        EN_ENC_R_DIR.value = strValue;

         enc_status.values.push_back(EN_ENC_R_DIR);

// Start Encoder

        if (flexisoft->TCPClientReadArrayBit(flexisoft->Fx_Read_Gent, ENC_R_SSTILL) == 1)
        {
            strKey = "Exited normally";
            strValue = "TRUE";
        }
        else
        {
            strKey = "Emgergencystop hit";
            strValue = "FALSE";
        }
        EN_ENC_R_SSTILL.key = strKey;
        EN_ENC_R_SSTILL.value = strValue;

         enc_status.values.push_back(EN_ENC_R_SSTILL);

//SAFETY
// Start SAFETY

        if (flexisoft->TCPClientReadArrayBit(flexisoft->Fx_Read_Gent, SAFE_IO_GB_EMC) == 1)
        {
            strKey = "Exited normally";
            strValue = "TRUE";
        }
        else
        {
            strKey = "Emgergencystop hit";
            strValue = "FALSE";
        }
        ST_SAFE_IO_GB_EMC.key = strKey;
        ST_SAFE_IO_GB_EMC.value = strValue;

         safety_status.values.push_back(ST_SAFE_IO_GB_EMC);

// Start SAFETY

        if (flexisoft->TCPClientReadArrayBit(flexisoft->Fx_Read_Gent, SAFE_IO_GB_Start) == 1)
        {
            strKey = "Exited normally";
            strValue = "TRUE";
        }
        else
        {
            strKey = "Emgergencystop hit";
            strValue = "FALSE";
        }
        ST_SAFE_IO_GB_Start.key = strKey;
        ST_SAFE_IO_GB_Start.value = strValue;

         safety_status.values.push_back(ST_SAFE_IO_GB_Start);
// Start SAFETY

        if (flexisoft->TCPClientReadArrayBit(flexisoft->Fx_Read_Gent, SAFE_IO_GB_Reset) == 1)
        {
            strKey = "Exited normally";
            strValue = "TRUE";
        }
        else
        {
            strKey = "Emgergencystop hit";
            strValue = "FALSE";
        }
        ST_SAFE_IO_GB_Reset.key = strKey;
        ST_SAFE_IO_GB_Reset.value = strValue;

         safety_status.values.push_back(ST_SAFE_IO_GB_Reset);
// Start SAFETY

        if (flexisoft->TCPClientReadArrayBit(flexisoft->Fx_Read_Gent, SAFE_IO_GB_Reset) == 1)
        {
            strKey = "Exited normally";
            strValue = "TRUE";
        }
        else
        {
            strKey = "Emgergencystop hit";
            strValue = "FALSE";
        }
        ST_SAFE_IO_GB_Reset.key = strKey;
        ST_SAFE_IO_GB_Reset.value = strValue;

         safety_status.values.push_back(ST_SAFE_IO_GB_Reset);
// Start SAFETY

        if (flexisoft->TCPClientReadArrayBit(flexisoft->Fx_Read_Gent, SAFE_IO_GB_Key_Brake) == 1)
        {
            strKey = "Exited normally";
            strValue = "TRUE";
        }
        else
        {
            strKey = "Emgergencystop hit";
            strValue = "FALSE";
        }
        ST_SAFE_IO_GB_Key_Brake.key = strKey;
        ST_SAFE_IO_GB_Key_Brake.value = strValue;

         safety_status.values.push_back(ST_SAFE_IO_GB_Key_Brake);
// Start SAFETY

        if (flexisoft->TCPClientReadArrayBit(flexisoft->Fx_Read_Gent, SAFE_IO_GB_EDM_MC) == 1)
        {
            strKey = "Exited normally";
            strValue = "TRUE";
        }
        else
        {
            strKey = "Emgergencystop hit";
            strValue = "FALSE";
        }
        ST_SAFE_IO_GB_EDM_MC.key = strKey;
        ST_SAFE_IO_GB_EDM_MC.value = strValue;

         safety_status.values.push_back(ST_SAFE_IO_GB_EDM_MC);
// Start SAFETY

        if (flexisoft->TCPClientReadArrayBit(flexisoft->Fx_Read_Gent, SAFE_IO_GB_ALM_M) == 1)
        {
            strKey = "Exited normally";
            strValue = "TRUE";
        }
        else
        {
            strKey = "Emgergencystop hit";
            strValue = "FALSE";
        }
        ST_SAFE_IO_GB_ALM_M.key = strKey;
        ST_SAFE_IO_GB_ALM_M.value = strValue;

         safety_status.values.push_back(ST_SAFE_IO_GB_ALM_M);
// Start SAFETY

        if (flexisoft->TCPClientReadArrayBit(flexisoft->Fx_Read_Gent, SAFE_IO_GB_IPC_Ok) == 1)
        {
            strKey = "Exited normally";
            strValue = "TRUE";
        }
        else
        {
            strKey = "Emgergencystop hit";
            strValue = "FALSE";
        }
        ST_SAFE_IO_GB_IPC_Ok.key = strKey;
        ST_SAFE_IO_GB_IPC_Ok.value = strValue;

         safety_status.values.push_back(ST_SAFE_IO_GB_IPC_Ok);
// Start SAFETY

        if (flexisoft->TCPClientReadArrayBit(flexisoft->Fx_Read_Gent, SAFE_IO_GB_IPC_Run) == 1)
        {
            strKey = "Exited normally";
            strValue = "TRUE";
        }
        else
        {
            strKey = "Emgergencystop hit";
            strValue = "FALSE";
        }
        ST_SAFE_IO_GB_IPC_Run.key = strKey;
        ST_SAFE_IO_GB_IPC_Run.value = strValue;

         safety_status.values.push_back(ST_SAFE_IO_GB_IPC_Run);
// Start SAFETY

        if (flexisoft->TCPClientReadArrayBit(flexisoft->Fx_Read_Gent, SAFE_IO_GB_FX_Run) == 1)
        {
            strKey = "Exited normally";
            strValue = "TRUE";
        }
        else
        {
            strKey = "Emgergencystop hit";
            strValue = "FALSE";
        }
        ST_SAFE_IO_GB_FX_Run.key = strKey;
        ST_SAFE_IO_GB_FX_Run.value = strValue;

         safety_status.values.push_back(ST_SAFE_IO_GB_FX_Run);
// Start SAFETY

        if (flexisoft->TCPClientReadArrayBit(flexisoft->Fx_Read_Gent, SAFE_FC_ST_Ready) == 1)
        {
            strKey = "Exited normally";
            strValue = "TRUE";
        }
        else
        {
            strKey = "Emgergencystop hit";
            strValue = "FALSE";
        }
        ST_SAFE_FC_ST_Ready.key = strKey;
        ST_SAFE_FC_ST_Ready.value = strValue;

         safety_status.values.push_back(ST_SAFE_FC_ST_Ready);
// Start SAFETY

        if (flexisoft->TCPClientReadArrayBit(flexisoft->Fx_Read_Gent, SAFE_FC_ST_G) == 1)
        {
            strKey = "Exited normally";
            strValue = "TRUE";
        }
        else
        {
            strKey = "Emgergencystop hit";
            strValue = "FALSE";
        }
        ST_SAFE_FC_ST_G.key = strKey;
        ST_SAFE_FC_ST_G.value = strValue;

         safety_status.values.push_back(ST_SAFE_FC_ST_G);
// Start SAFETY

        if (flexisoft->TCPClientReadArrayBit(flexisoft->Fx_Read_Gent, SAFE_FC_ST_B_G) == 1)
        {
            strKey = "Exited normally";
            strValue = "TRUE";
        }
        else
        {
            strKey = "Emgergencystop hit";
            strValue = "FALSE";
        }
        ST_SAFE_FC_ST_B_G.key = strKey;
        ST_SAFE_FC_ST_B_G.value = strValue;

         safety_status.values.push_back(ST_SAFE_FC_ST_B_G);
// Start SAFETY

        if (flexisoft->TCPClientReadArrayBit(flexisoft->Fx_Read_Gent, SAFE_FC_SW_Ok) == 1)
        {
            strKey = "Exited normally";
            strValue = "TRUE";
        }
        else
        {
            strKey = "Emgergencystop hit";
            strValue = "FALSE";
        }
        ST_SAFE_FC_SW_Ok.key = strKey;
        ST_SAFE_FC_SW_Ok.value = strValue;

         safety_status.values.push_back(ST_SAFE_FC_SW_Ok);
// Start SAFETY

        if (flexisoft->TCPClientReadArrayBit(flexisoft->Fx_Read_Gent, SAFE_FC_Auto_Restart) == 1)
        {
            strKey = "Exited normally";
            strValue = "TRUE";
        }
        else
        {
            strKey = "Emgergencystop hit";
            strValue = "FALSE";
        }
        ST_SAFE_FC_Auto_Restart.key = strKey;
        ST_SAFE_FC_Auto_Restart.value = strValue;

         safety_status.values.push_back(ST_SAFE_FC_Auto_Restart);
// Start SAFETY

        if (flexisoft->TCPClientReadArrayBit(flexisoft->Fx_Read_Gent, SAFE_FC_EDM_E) == 1)
        {
            strKey = "Exited normally";
            strValue = "TRUE";
        }
        else
        {
            strKey = "Emgergencystop hit";
            strValue = "FALSE";
        }
        ST_SAFE_FC_EDM_E.key = strKey;
        ST_SAFE_FC_EDM_E.value = strValue;

         safety_status.values.push_back(ST_SAFE_FC_EDM_E);

// Start SAFETY

        if (flexisoft->TCPClientReadArrayBit(flexisoft->Fx_Read_Gent, SAFE_FC_En_Ctr_ST) == 1)
        {
            strKey = "Exited normally";
            strValue = "TRUE";
        }
        else
        {
            strKey = "Emgergencystop hit";
            strValue = "FALSE";
        }
        ST_SAFE_FC_En_Ctr_ST.key = strKey;
        ST_SAFE_FC_En_Ctr_ST.value = strValue;
         safety_status.values.push_back(ST_SAFE_FC_En_Ctr_ST);

// Start SAFETY

        if (flexisoft->TCPClientReadArrayBit(flexisoft->Fx_Read_Gent, SAFE_MS3_Power_Ok) == 1)
        {
            strKey = "Exited normally";
            strValue = "TRUE";
        }
        else
        {
            strKey = "Emgergencystop hit";
            strValue = "FALSE";
        }
        ST_SAFE_MS3_Power_Ok.key = strKey;
        ST_SAFE_MS3_Power_Ok.value = strValue;

         safety_status.values.push_back(ST_SAFE_MS3_Power_Ok);
// Start SAFETY

        if (flexisoft->TCPClientReadArrayBit(flexisoft->Fx_Read_Gent, SAFE_MS3_Brake_Ok) == 1)
        {
            strKey = "Exited normally";
            strValue = "TRUE";
        }
        else
        {
            strKey = "Emgergencystop hit";
            strValue = "FALSE";
        }
        ST_SAFE_MS3_Brake_Ok.key = strKey;
        ST_SAFE_MS3_Brake_Ok.value = strValue;

         safety_status.values.push_back(ST_SAFE_MS3_Brake_Ok);
// Start SAFETY

        if (flexisoft->TCPClientReadArrayBit(flexisoft->Fx_Read_Gent, SAFE_MS3_Warn_Ok) == 1)
        {
            strKey = "Exited normally";
            strValue = "TRUE";
        }
        else
        {
            strKey = "Emgergencystop hit";
            strValue = "FALSE";
        }
        ST_SAFE_MS3_Warn_Ok.key = strKey;
        ST_SAFE_MS3_Warn_Ok.value = strValue;

         safety_status.values.push_back(ST_SAFE_MS3_Warn_Ok);
// Start SAFETY

        if (flexisoft->TCPClientReadArrayBit(flexisoft->Fx_Read_Gent, SAFE_MS3_Detect_Ok) == 1)
        {
            strKey = "Exited normally";
            strValue = "TRUE";
        }
        else
        {
            strKey = "Emgergencystop hit";
            strValue = "FALSE";
        }
        ST_SAFE_MS3_Detect_Ok.key = strKey;
        ST_SAFE_MS3_Detect_Ok.value = strValue;

         safety_status.values.push_back(ST_SAFE_MS3_Detect_Ok);
// Start SAFETY

        if (flexisoft->TCPClientReadArrayBit(flexisoft->Fx_Read_Gent, SAFE_MS3_Contour_Ok) == 1)
        {
            strKey = "Exited normally";
            strValue = "TRUE";
        }
        else
        {
            strKey = "Emgergencystop hit";
            strValue = "FALSE";
        }
        ST_SAFE_MS3_Contour_Ok.key = strKey;
        ST_SAFE_MS3_Contour_Ok.value = strValue;

         safety_status.values.push_back(ST_SAFE_MS3_Contour_Ok);
// Start SAFETY

        if (flexisoft->TCPClientReadArrayBit(flexisoft->Fx_Read_Gent, SAFE_MS3_SP_SStill) == 1)
        {
            strKey = "Exited normally";
            strValue = "TRUE";
        }
        else
        {
            strKey = "Emgergencystop hit";
            strValue = "FALSE";
        }
        ST_SAFE_MS3_SP_SStill.key = strKey;
        ST_SAFE_MS3_SP_SStill.value = strValue;

         safety_status.values.push_back(ST_SAFE_MS3_SP_SStill);
// Start SAFETY

        if (flexisoft->TCPClientReadArrayBit(flexisoft->Fx_Read_Gent, SAFE_MS3_SP_VSlow) == 1)
        {
            strKey = "Exited normally";
            strValue = "TRUE";
        }
        else
        {
            strKey = "Emgergencystop hit";
            strValue = "FALSE";
        }
        ST_SAFE_MS3_SP_VSlow.key = strKey;
        ST_SAFE_MS3_SP_VSlow.value = strValue;

         safety_status.values.push_back(ST_SAFE_MS3_SP_VSlow);

// Start SAFETY

        if (flexisoft->TCPClientReadArrayBit(flexisoft->Fx_Read_Gent, SAFE_MS3_SP_Slow) == 1)
        {
            strKey = "Exited normally";
            strValue = "TRUE";
        }
        else
        {
            strKey = "Emgergencystop hit";
            strValue = "FALSE";
        }
        ST_SAFE_MS3_SP_Slow.key = strKey;
        ST_SAFE_MS3_SP_Slow.value = strValue;

         safety_status.values.push_back(ST_SAFE_MS3_SP_Slow);

// Start SAFETY

        if (flexisoft->TCPClientReadArrayBit(flexisoft->Fx_Read_Gent, SAFE_MS3_SP_Medium) == 1)
        {
            strKey = "Exited normally";
            strValue = "TRUE";
        }
        else
        {
            strKey = "Emgergencystop hit";
            strValue = "FALSE";
        }
        ST_SAFE_MS3_SP_Medium.key = strKey;
        ST_SAFE_MS3_SP_Medium.value = strValue;

         safety_status.values.push_back(ST_SAFE_MS3_SP_Medium);

// Start SAFETY

        if (flexisoft->TCPClientReadArrayBit(flexisoft->Fx_Read_Gent, SAFE_MS3_SP_Fast) == 1)
        {
            strKey = "Exited normally";
            strValue = "TRUE";
        }
        else
        {
            strKey = "Emgergencystop hit";
            strValue = "FALSE";
        }
        ST_SAFE_MS3_SP_Fast.key = strKey;
        ST_SAFE_MS3_SP_Fast.value = strValue;

         safety_status.values.push_back(ST_SAFE_MS3_SP_Fast);

// Start SAFETY

        if (flexisoft->TCPClientReadArrayBit(flexisoft->Fx_Read_Gent, SAFE_MS3_SP_VFast) == 1)
        {
            strKey = "Exited normally";
            strValue = "TRUE";
        }
        else
        {
            strKey = "Emgergencystop hit";
            strValue = "FALSE";
        }
        ST_SAFE_MS3_SP_VFast.key = strKey;
        ST_SAFE_MS3_SP_VFast.value = strValue;

         safety_status.values.push_back(ST_SAFE_MS3_SP_VFast);

// Start SAFETY

        if (flexisoft->TCPClientReadArrayBit(flexisoft->Fx_Read_Gent, SAFE_MS3_DIR_F) == 1)
        {
            strKey = "Exited normally";
            strValue = "TRUE";
        }
        else
        {
            strKey = "Emgergencystop hit";
            strValue = "FALSE";
        }
        ST_SAFE_MS3_DIR_F.key = strKey;
        ST_SAFE_MS3_DIR_F.value = strValue;

         safety_status.values.push_back(ST_SAFE_MS3_DIR_F);

// Start SAFETY

        if (flexisoft->TCPClientReadArrayBit(flexisoft->Fx_Read_Gent, SAFE_MS3_DIR_B) == 1)
        {
            strKey = "Exited normally";
            strValue = "TRUE";
        }
        else
        {
            strKey = "Emgergencystop hit";
            strValue = "FALSE";
        }
        ST_SAFE_MS3_DIR_B.key = strKey;
        ST_SAFE_MS3_DIR_B.value = strValue;

         safety_status.values.push_back(ST_SAFE_MS3_DIR_B);

// Start SAFETY

        if (flexisoft->TCPClientReadArrayBit(flexisoft->Fx_Read_Gent, SAFE_MS3_Turn_L) == 1)
        {
            strKey = "Exited normally";
            strValue = "TRUE";
        }
        else
        {
            strKey = "Emgergencystop hit";
            strValue = "FALSE";
        }
        ST_SAFE_MS3_Turn_L.key = strKey;
        ST_SAFE_MS3_Turn_L.value = strValue;

         safety_status.values.push_back(ST_SAFE_MS3_Turn_L);

// Start SAFETY

        if (flexisoft->TCPClientReadArrayBit(flexisoft->Fx_Read_Gent, SAFE_MS3_Turn_R) == 1)
        {
            strKey = "Exited normally";
            strValue = "TRUE";
        }
        else
        {
            strKey = "Emgergencystop hit";
            strValue = "FALSE";
        }
        ST_SAFE_MS3_Turn_R.key = strKey;
        ST_SAFE_MS3_Turn_R.value = strValue;

         safety_status.values.push_back(ST_SAFE_MS3_Turn_R);

// Start SAFETY

        if (flexisoft->TCPClientReadArrayBit(flexisoft->Fx_Read_Gent, SAFE_MS3_Forward) == 1)
        {
            strKey = "Exited normally";
            strValue = "TRUE";
        }
        else
        {
            strKey = "Emgergencystop hit";
            strValue = "FALSE";
        }
        ST_SAFE_MS3_Forward.key = strKey;
        ST_SAFE_MS3_Forward.value = strValue;

         safety_status.values.push_back(ST_SAFE_MS3_Forward);

// Start SAFETY

        if (flexisoft->TCPClientReadArrayBit(flexisoft->Fx_Read_Gent, SAFE_MS3_Backward) == 1)
        {
            strKey = "Exited normally";
            strValue = "TRUE";
        }
        else
        {
            strKey = "Emgergencystop hit";
            strValue = "FALSE";
        }
        ST_SAFE_MS3_Backward.key = strKey;
        ST_SAFE_MS3_Backward.value = strValue;

         safety_status.values.push_back(ST_SAFE_MS3_Backward);
  
  // Start SAFETY

        if (flexisoft->TCPClientReadArrayBit(flexisoft->Fx_Read_Gent, SAFE_MS3_Standstill) == 1)
        {
            strKey = "Exited normally";
            strValue = "TRUE";
        }
        else
        {
            strKey = "Emgergencystop hit";
            strValue = "FALSE";
        }
        ST_SAFE_MS3_Standstill.key = strKey;
        ST_SAFE_MS3_Standstill.value = strValue;

         safety_status.values.push_back(ST_SAFE_MS3_Standstill);
  
//device_status
// Start device_status

        if (flexisoft->TCPClientReadArrayBit(flexisoft->Fx_Read_Gent, Status_CPU0_PS) == 1)
        {
            strKey = "Exited normally";
            strValue = "TRUE";
        }
        else
        {
            strKey = "Emgergencystop hit";
            strValue = "FALSE";
        }
        DE_Status_CPU0_PS.key = strKey;
        DE_Status_CPU0_PS.value = strValue;

         device_status.values.push_back(DE_Status_CPU0_PS);

// Start device_status

        if (flexisoft->TCPClientReadArrayBit(flexisoft->Fx_Read_Gent, Status_CPU0_OS) == 1)
        {
            strKey = "Exited normally";
            strValue = "TRUE";
        }
        else
        {
            strKey = "Emgergencystop hit";
            strValue = "FALSE";
        }
        DE_Status_CPU0_OS.key = strKey;
        DE_Status_CPU0_OS.value = strValue;

         device_status.values.push_back(DE_Status_CPU0_OS);

// Start device_status

        if (flexisoft->TCPClientReadArrayBit(flexisoft->Fx_Read_Gent, Status_IOXTIO1_PS) == 1)
        {
            strKey = "Exited normally";
            strValue = "TRUE";
        }
        else
        {
            strKey = "Emgergencystop hit";
            strValue = "FALSE";
        }
        DE_Status_IOXTIO1_PS.key = strKey;
        DE_Status_IOXTIO1_PS.value = strValue;

         device_status.values.push_back(DE_Status_IOXTIO1_PS);

// Start device_status

        if (flexisoft->TCPClientReadArrayBit(flexisoft->Fx_Read_Gent, Status_IOXTIO1_OS) == 1)
        {
            strKey = "Exited normally";
            strValue = "TRUE";
        }
        else
        {
            strKey = "Emgergencystop hit";
            strValue = "FALSE";
        }
        DE_Status_IOXTIO1_OS.key = strKey;
        DE_Status_IOXTIO1_OS.value = strValue;

         device_status.values.push_back(DE_Status_IOXTIO1_OS);

// Start device_status

        if (flexisoft->TCPClientReadArrayBit(flexisoft->Fx_Read_Gent, Status_IOXTIO2_PS) == 1)
        {
            strKey = "Exited normally";
            strValue = "TRUE";
        }
        else
        {
            strKey = "Emgergencystop hit";
            strValue = "FALSE";
        }
        DE_Status_IOXTIO2_PS.key = strKey;
        DE_Status_IOXTIO2_PS.value = strValue;

         device_status.values.push_back(DE_Status_IOXTIO2_PS);

// Start device_status

        if (flexisoft->TCPClientReadArrayBit(flexisoft->Fx_Read_Gent, Status_IOXTIO2_OS) == 1)
        {
            strKey = "Exited normally";
            strValue = "TRUE";
        }
        else
        {
            strKey = "Emgergencystop hit";
            strValue = "FALSE";
        }
        DE_Status_IOXTIO2_OS.key = strKey;
        DE_Status_IOXTIO2_OS.value = strValue;

         device_status.values.push_back(DE_Status_IOXTIO2_OS);

// Start device_status

        if (flexisoft->TCPClientReadArrayBit(flexisoft->Fx_Read_Gent, Status_IOXTIO3_PS) == 1)
        {
            strKey = "Exited normally";
            strValue = "TRUE";
        }
        else
        {
            strKey = "Emgergencystop hit";
            strValue = "FALSE";
        }
        DE_Status_IOXTIO3_PS.key = strKey;
        DE_Status_IOXTIO3_PS.value = strValue;

         device_status.values.push_back(DE_Status_IOXTIO3_PS);

// Start device_status

        if (flexisoft->TCPClientReadArrayBit(flexisoft->Fx_Read_Gent, Status_MOC_ENC_L) == 1)
        {
            strKey = "Exited normally";
            strValue = "TRUE";
        }
        else
        {
            strKey = "Emgergencystop hit";
            strValue = "FALSE";
        }
        DE_Status_MOC_ENC_L.key = strKey;
        DE_Status_MOC_ENC_L.value = strValue;

         device_status.values.push_back(DE_Status_MOC_ENC_L);

// Start device_status

        if (flexisoft->TCPClientReadArrayBit(flexisoft->Fx_Read_Gent, Status_MOC_ENC_R) == 1)
        {
            strKey = "Exited normally";
            strValue = "TRUE";
        }
        else
        {
            strKey = "Emgergencystop hit";
            strValue = "FALSE";
        }
        DE_Status_MOC_ENC_R.key = strKey;
        DE_Status_MOC_ENC_R.value = strValue;

         device_status.values.push_back(DE_Status_MOC_ENC_R);

// Start device_status

        if (flexisoft->TCPClientReadArrayBit(flexisoft->Fx_Read_Gent, Status_MOC_PS) == 1)
        {
            strKey = "Exited normally";
            strValue = "TRUE";
        }
        else
        {
            strKey = "Emgergencystop hit";
            strValue = "FALSE";
        }
        DE_Status_MOC_PS.key = strKey;
        DE_Status_MOC_PS.value = strValue;

         device_status.values.push_back(DE_Status_MOC_PS);

// Start device_status

        if (flexisoft->TCPClientReadArrayBit(flexisoft->Fx_Read_Gent, Status_GERP_MS3_F) == 1)
        {
            strKey = "Exited normally";
            strValue = "TRUE";
        }
        else
        {
            strKey = "Emgergencystop hit";
            strValue = "FALSE";
        }
        DE_Status_GERP_MS3_F.key = strKey;
        DE_Status_GERP_MS3_F.value = strValue;

         device_status.values.push_back(DE_Status_GERP_MS3_F);

// Start device_status

        if (flexisoft->TCPClientReadArrayBit(flexisoft->Fx_Read_Gent, Status_GERP_MS3_B) == 1)
        {
            strKey = "Exited normally";
            strValue = "TRUE";
        }
        else
        {
            strKey = "Emgergencystop hit";
            strValue = "FALSE";
        }
        DE_Status_GERP_MS3_B.key = strKey;
        DE_Status_GERP_MS3_B.value = strValue;

         device_status.values.push_back(DE_Status_GERP_MS3_B);

// Start device_status

        if (flexisoft->TCPClientReadArrayBit(flexisoft->Fx_Read_Gent, Status_GENT_Error) == 1)
        {
            strKey = "Exited normally";
            strValue = "TRUE";
        }
        else
        {
            strKey = "Emgergencystop hit";
            strValue = "FALSE";
        }
        DE_Status_GENT_Error.key = strKey;
        DE_Status_GENT_Error.value = strValue;

         device_status.values.push_back(DE_Status_GENT_Error);

// Start device_status

        if (flexisoft->TCPClientReadArrayBit(flexisoft->Fx_Read_Gent, Status_MS3F_Error) == 1)
        {
            strKey = "Exited normally";
            strValue = "TRUE";
        }
        else
        {
            strKey = "Emgergencystop hit";
            strValue = "FALSE";
        }
        DE_Status_MS3F_Error.key = strKey;
        DE_Status_MS3F_Error.value = strValue;

         device_status.values.push_back(DE_Status_MS3F_Error);

// Start device_status

        if (flexisoft->TCPClientReadArrayBit(flexisoft->Fx_Read_Gent, Status_MS3B_Error) == 1)
        {
            strKey = "Exited normally";
            strValue = "TRUE";
        }
        else
        {
            strKey = "Emgergencystop hit";
            strValue = "FALSE";
        }
        DE_Status_MS3B_Error.key = strKey;
        DE_Status_MS3B_Error.value = strValue;

         device_status.values.push_back(DE_Status_MS3B_Error);





        dia_array.status.push_back(flexisoft_status);
        dia_array.status.push_back(ms3_f_status);
        dia_array.status.push_back(ms3_b_status);
        dia_array.status.push_back(enc_status);
        dia_array.status.push_back(safety_status);
        dia_array.status.push_back(device_status);

        diagnostic_pub.publish(dia_array);

        ros::spinOnce();

        loop_rate.sleep();
    }

    return 0;
}