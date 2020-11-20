#include <client.h>
#include <flexisoft_fx.h>
#include <flexisoft_msg.h>

#include <diagnostic_msgs/DiagnosticArray.h>
#include <diagnostic_msgs/DiagnosticStatus.h>
#include <diagnostic_msgs/KeyValue.h>
#include <tcp_flexisoft_pkg/fx_to_ipc.h>
#include <tcp_flexisoft_pkg/agv_action.h>

int value = 1;
bool data;


int main(int argc, char **argv)
{

    // create a modbus object

    tcp_flexisoft_pkg::fx_to_ipc fx_st_io;
    tcp_flexisoft_pkg::fx_to_ipc fx_st_fc;
    tcp_flexisoft_pkg::fx_to_ipc st_ms3_field;
    tcp_flexisoft_pkg::fx_to_ipc st_ms3_speed;
    tcp_flexisoft_pkg::fx_to_ipc agv;
    ros::init(argc, argv, "ipc_function");
    ros::NodeHandle nh;


 ros::Publisher fx_st_io_pub = nh.advertise<tcp_flexisoft_pkg::fx_to_ipc>("/st_io_direction", 10);

ros::Rate loop_rate(10);
 while (ros::ok())
 {
        fx_st_io.IPC_SAFE_IO_Direction = 2 ;
        fx_st_io_pub.publish(fx_st_io);

 }
 

  //  ros::Subscriber action = nh.subscribe("agv_action", 20, actionCallback);




    return 0;
}