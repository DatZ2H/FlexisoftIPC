//
// Created by Fanzhe on 5/28/2017.
//

#ifndef CLIENT_H
#define CLIENT_H
#pragma once

#include <stdio.h> 
#include <iostream>
#include <string.h> //strlen 
#include <stdlib.h> 
#include <errno.h> 
#include <unistd.h> //close 
#include <arpa/inet.h> //close 
#include <netdb.h> 
#include <sys/types.h> 
#include <sys/socket.h> 
#include <netinet/in.h> 
#include <sys/time.h> //FD_SET, FD_ISSET, FD_ZERO macros 



#include <cmath> 

#include "ros/ros.h"


using namespace std;

#define MAX_MSG_LENGTH 260

///Function Code
#define READ_COILS 0x01
#define READ_INPUT_BITS 0x02
#define READ_REGS 0x03
#define READ_INPUT_REGS 0x04
#define WRITE_COIL 0x05
#define WRITE_REG 0x06
#define WRITE_COILS 0x0F
#define WRITE_REGS 0x10

///Exception Codes

#define EX_ILLEGAL_FUNCTION 0x01 // Function Code not Supported
#define EX_ILLEGAL_ADDRESS 0x02  // Output Address not exists
#define EX_ILLEGAL_VALUE 0x03    // Output Value not in Range
#define EX_SERVER_FAILURE 0x04   // Slave Deive Fails to process request
#define EX_ACKNOWLEDGE 0x05      // Service Need Long Time to Execute
#define EX_SERVER_BUSY 0x06      // Server Was Unable to Accept MB Request PDU
#define EX_NEGATIVE_ACK 0x07
#define EX_MEM_PARITY_PROB 0x08
#define EX_GATEWAY_PROBLEMP 0x0A // Gateway Path not Available
#define EX_GATEWYA_PROBLEMF 0x0B // Target Device Failed to Response
#define EX_BAD_DATA 0XFF         // Bad Data lenght or Address

#define BAD_CON -1

/// Modbus Operator Class
/**
 * Modbus Operator Class
 * Providing networking support and mobus operation support.
 */
class TCPClient
{
private:
    bool _connected{};
    uint16_t PORT{};
    int _socket{};
    uint _msg_id{};
    int _slaveid{};


    uint16_t req_read_gent[5]{};
    uint16_t res_read_gent[30]{};
    uint16_t res_read_w_[25]{};
    uint16_t req_write_gent[11]{};
    uint16_t res_write_gent[2]{};

    std::string HOST;

    struct sockaddr_in _server;


    inline void TCPClient_build_request(uint8_t *to_send, uint address, int func) const;

   

    void TCPClienterror_handle(const uint8_t *msg, int func);

    inline void set_bad_con();
    inline void set_bad_input();
    inline void set_bad_req_read();
    inline void set_bad_res_read();
    inline void set_bad_req_write();
    inline void set_bad_res_write();

   
    int Bin16ToDec(int n);
    uint16_t ArrayBinToDec16(bool ArrayBit[16]);
    uint16_t* ArrayBit16ToArrayHex(bool ArrayBit[][16]);
    bool ReadBit(uint16_t DataDec, int Pose);
    
    uint16_t WriteBit(uint16_t &Data, bool Status, int Pose);
    int ArrayHexToArrayBit16(uint16_t ArrayHex[25], bool (& ArrayBit)[25][16]);

public:

    bool testvalue=1;
    bool Fx_Read_Gent[25][16]={};
    bool Fx_Write_Gent[5][16]={};
    bool err{};
    int err_no{};
    std::string error_msg;

    TCPClient(std::string host, uint16_t port);
    ~TCPClient();

    bool TCPClient_connect();
    void TCPClient_close() const;
    int TCPClientWriteOutputGentArray(int OutputSet);
    int TCPClientWriteOutputGent(int OutputSet);
    int TCPClientWriteOutputGentArrayBit( int OutputSet, int row, int col, bool value);
    int TCPClientWriteOutputGentBit(int OutputSet, uint16_t Data0, uint16_t Data1, uint16_t Data2, uint16_t Data3, uint16_t Data4);
    uint16_t TCPClientWriteArrayBit16(int row, int col, bool value);

    int TCPClientReadInputGent( int InputRead);
    int TCPClientReadInputGentArray( int InputRead);
    bool TCPClientReadInputGentBit( int x, int y);

    bool TCPClientReadArrayBit(bool ArrayBit[][16],int x, int y);
    bool TCPClientReadGent(int x, int y);
    bool* TCPClientDecToBin16(uint16_t dec);
};
#endif