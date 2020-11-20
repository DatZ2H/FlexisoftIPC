#include <client.h>
#include <flexisoft_fx.h>
#include <flexisoft_msg.h>

/**
 * Main Constructor of TCPClient Connector Object
 * @param host IP Address of Host
 * @param port Port for the TCP Connection
 * @return     A TCPClient Connector Object
 */
TCPClient::TCPClient(std::string host, uint16_t port = 502)
{
    HOST = host;
    PORT = port;
    _slaveid = 1;
    _msg_id = 1;
    _connected = false;
    err = false;
    err_no = 0;
    error_msg = "";
}

/**
 * Destructor of TCPClient Connector Object
 */
TCPClient::~TCPClient(void) = default;

/**
 * TCPClient Slave ID Setter
 * @param id  ID of the TCPClient Server Slave
 */

/**
 * Build up a TCPClient/TCP Connection
 * @return   If A Connection Is Successfully Built
 */
bool TCPClient::TCPClient_connect()
{
    if (HOST.empty() || PORT == 0)
    {
        std::cout << "Missing Host and Port" << std::endl;
        return false;
    }
    else
    {
        std::cout << "Found Proper Host " << HOST << " and Port " << PORT << std::endl;
    }

    _socket = socket(AF_INET, SOCK_STREAM, 0);
    if (_socket == -1)
    {
        std::cout << "Error Opening Socket" << std::endl;
        return false;
    }
    else
    {
        std::cout << "Socket Opened Successfully" << std::endl;
    }

    struct timeval timeout
    {
    };
    timeout.tv_sec = 20; // after 20 seconds connect() will timeout
    timeout.tv_usec = 0;
    setsockopt(_socket, SOL_SOCKET, SO_SNDTIMEO, &timeout, sizeof(timeout));
    setsockopt(_socket, SOL_SOCKET, SO_RCVTIMEO, &timeout, sizeof(timeout));

    _server.sin_family = AF_INET;
    _server.sin_addr.s_addr = inet_addr(HOST.c_str());
    _server.sin_port = htons(PORT);

    if (connect(_socket, (struct sockaddr *)&_server, sizeof(_server)) < 0)
    {
        std::cout << "Connection Error" << std::endl;
        return false;
    }

    std::cout << "Connected" << std::endl;
    _connected = true;
    return true;
}

/**
 * Close the TCPClient/TCP Connection
 */
void TCPClient::TCPClient_close() const
{
    close(_socket);
    std::cout << "Socket Closed" << std::endl;
}

/**
 * TCPClient Request Builder
 * @param to_send   Message Buffer to Be Sent
 * @param address   Reference Address
 * @param func      TCPClient Functional Code
 */
void TCPClient::TCPClient_build_request(uint8_t *to_send, uint address, int func) const
{
    to_send[0] = (uint8_t)_msg_id >> 8u;
    to_send[1] = (uint8_t)(_msg_id & 0x00FFu);
    to_send[2] = 0;
    to_send[3] = 0;
    to_send[4] = 0;
    to_send[6] = (uint8_t)_slaveid;
    to_send[7] = (uint8_t)func;
    to_send[8] = (uint8_t)(address >> 8u);
    to_send[9] = (uint8_t)(address & 0x00FFu);
}





void TCPClient::set_bad_con()
{
    err = true;
    error_msg = "BAD CONNECTION";
}

void TCPClient::set_bad_input()
{
    err = true;
    error_msg = "BAD FUNCTION INPUT";
}
void TCPClient::set_bad_req_read()
{
    err = true;
    error_msg = "BAD FUNCTION INPUT";
}
void TCPClient::set_bad_res_read()
{
    err = true;
    error_msg = "BAD FUNCTION INPUT";
}
void TCPClient::set_bad_req_write()
{
    err = true;
    error_msg = "BAD FUNCTION INPUT";
}
void TCPClient::set_bad_res_write()
{
    err = true;
    error_msg = "BAD FUNCTION INPUT";
}

void TCPClient::TCPClienterror_handle(const uint8_t *msg, int func)
{
    if (msg[7] == func + 0x80)
    {
        err = true;
        switch (msg[8])
        {
        case EX_ILLEGAL_FUNCTION:
            error_msg = "1 Illegal Function";
            break;
        case EX_ILLEGAL_ADDRESS:
            error_msg = "2 Illegal Address";
            break;
        case EX_ILLEGAL_VALUE:
            error_msg = "3 Illegal Value";
            break;
        case EX_SERVER_FAILURE:
            error_msg = "4 Server Failure";
            break;
        case EX_ACKNOWLEDGE:
            error_msg = "5 Acknowledge";
            break;
        case EX_SERVER_BUSY:
            error_msg = "6 Server Busy";
            break;
        case EX_NEGATIVE_ACK:
            error_msg = "7 Negative Acknowledge";
            break;
        case EX_MEM_PARITY_PROB:
            error_msg = "8 Memory Parity Problem";
            break;
        case EX_GATEWAY_PROBLEMP:
            error_msg = "10 Gateway Path Unavailable";
            break;
        case EX_GATEWYA_PROBLEMF:
            error_msg = "11 Gateway Target Device Failed to Respond";
            break;
        default:
            error_msg = "UNK";
            break;
        }
    }
    err = false;
    error_msg = "NO ERR";
}

bool* TCPClient::TCPClientDecToBin16(uint16_t dec)
{

	bool *bit = new bool[16];
	int i = 0;
	while (dec > 0)
	{
		bit[i] = dec % 2;
		dec = dec / 2;
		i++;
	}

	return bit;
}
int TCPClient::Bin16ToDec(int n)
{
	int DecNumber = 0;
	int base = 1;
	int temp = n;
	while (temp)
	{
		int lastDigit = temp % 10;
		temp = temp / 10;
		DecNumber += lastDigit * base;
		base = base * 2;
	}
	
}
uint16_t TCPClient::ArrayBinToDec16(bool ArrayBit[16])
{

	uint16_t DecNumber = 0;

	for (size_t i = 0; i < 16; i++)
	{
		DecNumber += ArrayBit[i] * pow(2, i);
	}

	return DecNumber;
}
uint16_t* TCPClient::ArrayBit16ToArrayHex(bool ArrayBit[][16])
{
	uint16_t *ArrayHex = new uint16_t[16];

	for (size_t i = 0; i < 5; i++)
	{
		ArrayHex[i] = ArrayBinToDec16(ArrayBit[i]);
		
	}

	return ArrayHex;
}

bool TCPClient::ReadBit(uint16_t DataDec, int Pose)
{

	bool Status;
	Status = DataDec & 1 << Pose;
	return Status;
}
uint16_t TCPClient::TCPClientWriteArrayBit16(int row, int col, bool value)
{
	Fx_Write_Gent[row][col] = value;
}
uint16_t TCPClient::WriteBit(uint16_t &Data, bool Status, int Pose)
{
	if (Status == 1)
	{
		Data = Data | 1 << Pose;
	}
	else
	{
		Data = Data ^ 1 << Pose;
	}
	return Data;
}

int TCPClient::TCPClientWriteOutputGentArray(int OutputSet)
{

	req_write_gent[pose_write_cmd] = req_write_cmd;

	if (OutputSet == 1)
	{
		req_write_gent[pose_write_data_1] = req_write_data_1;
		req_write_gent[pose_write_data_2] = 0;
		req_write_gent[pose_write_data_3] = 0;
		req_write_gent[pose_write_data_4] = 0;
		req_write_gent[pose_write_data_5] = 0;
	}
	else if (OutputSet == 2)
	{
		req_write_gent[pose_write_data_1] = 0;
		req_write_gent[pose_write_data_2] = req_write_data_2;
		req_write_gent[pose_write_data_3] = 0;
		req_write_gent[pose_write_data_4] = 0;
		req_write_gent[pose_write_data_5] = 0;
	}
	else if (OutputSet == 3)
	{
		req_write_gent[pose_write_data_1] = 0;
		req_write_gent[pose_write_data_2] = 0;
		req_write_gent[pose_write_data_3] = req_write_data_3;
		req_write_gent[pose_write_data_4] = 0;
		req_write_gent[pose_write_data_5] = 0;
	}
	else if (OutputSet == 4)
	{
		req_write_gent[pose_write_data_1] = 0;
		req_write_gent[pose_write_data_2] = 0;
		req_write_gent[pose_write_data_3] = 0;
		req_write_gent[pose_write_data_4] = req_write_data_4;
		req_write_gent[pose_write_data_5] = 0;
	}
	else if (OutputSet == 5)
	{
		req_write_gent[pose_write_data_1] = 0;
		req_write_gent[pose_write_data_2] = 0;
		req_write_gent[pose_write_data_3] = 0;
		req_write_gent[pose_write_data_4] = 0;
		req_write_gent[pose_write_data_5] = req_write_data_5;
	}
	else
	{
		/* code */
	}

	req_write_gent[pose_write_w_0] = ArrayBinToDec16(Fx_Write_Gent[0]);
	req_write_gent[pose_write_w_1] = ArrayBinToDec16(Fx_Write_Gent[1]);
	req_write_gent[pose_write_w_2] = ArrayBinToDec16(Fx_Write_Gent[2]);
	req_write_gent[pose_write_w_3] = ArrayBinToDec16(Fx_Write_Gent[3]);
	req_write_gent[pose_write_w_4] = ArrayBinToDec16(Fx_Write_Gent[4]);
	send(_socket, req_write_gent, 22, 0);
	bool ReadOk = 1;
//	cout << " chuan bi roi ne 0  =>>>" << req_write_cmd<< endl;
	/* cout << " chuan bi roi ne 1  =>>>" << req_write_data_1<< endl;
	cout << " chuan bi roi ne 2  =>>>" << req_write_data_2<< endl;
	cout << " chuan bi roi ne 3  =>>>" << req_write_data_3<< endl;
	cout << " chuan bi roi ne 4  =>>>" << req_write_data_4<< endl;
	cout << " chuan bi roi ne 5  =>>>" << req_write_data_5<< endl;

	cout << " chuan 0  =>>>" << req_write_gent[0]<< endl;
	cout << " chuan  1  =>>>" << req_write_gent[1]<< endl;
	cout << " chuan  2  =>>>" << req_write_gent[2]<< endl;
	cout << " chuan 3  =>>>" << req_write_gent[3]<< endl;
	cout << " chuan 4  =>>>" << req_write_gent[4]<< endl;
	cout << " chuan 5  =>>>" << req_write_gent[5]<< endl;

	cout << " chuan bi roi ne 8  =>>>" << ArrayBinToDec16(Fx_Write_Gent[0])<< endl;
	cout << " chuan bi roi ne 9 =>>>" << ArrayBinToDec16(Fx_Write_Gent[1])<< endl;
	cout << " chuan bi roi ne 10 =>>>" <<  ArrayBinToDec16(Fx_Write_Gent[2])<< endl;
	cout << " chuan bi roi ne 11 =>>>" << ArrayBinToDec16(Fx_Write_Gent[3])<< endl;
	cout << " chuan bi roi ne 12 =>>>" << ArrayBinToDec16(Fx_Write_Gent[4])<< endl;
	cout << " chuan bi roi ne 13 =>>>" << req_write_gent<< endl;
	cout << " chuan bi roi ne 14 =>>>" << Fx_Write_Gent[1][14]<< endl;
	cout << " -------------------------" <<endl; */
	while (ReadOk)
	{
		read(_socket, res_write_gent, 2);

		if (res_write_gent[0] == 0x2F00 && res_write_gent[1] == 0x0000)
		{
	//		cout << "gui ok roi day" << endl;
			ReadOk = 0;
			break;
		}

		/* code */
	}
}

int TCPClient::TCPClientWriteOutputGent(int OutputSet)
{
	req_write_gent[pose_write_cmd] = req_write_cmd;

	if (OutputSet == 1)
	{
		req_write_gent[pose_write_data_1] = req_write_data_1;
		req_write_gent[pose_write_data_2] = 0;
		req_write_gent[pose_write_data_3] = 0;
		req_write_gent[pose_write_data_4] = 0;
		req_write_gent[pose_write_data_5] = 0;
	}
	else if (OutputSet == 2)
	{
		req_write_gent[pose_write_data_1] = 0;
		req_write_gent[pose_write_data_2] = req_write_data_2;
		req_write_gent[pose_write_data_3] = 0;
		req_write_gent[pose_write_data_4] = 0;
req_write_gent[pose_write_data_5] = 0;
	}
	else if (OutputSet == 3)
	{
		req_write_gent[pose_write_data_1] = 0;
		req_write_gent[pose_write_data_2] = 0;
		req_write_gent[pose_write_data_3] = req_write_data_3;
		req_write_gent[pose_write_data_4] = 0;
		req_write_gent[pose_write_data_5] = 0;
	}
	else if (OutputSet == 4)
	{
		req_write_gent[pose_write_data_1] = 0;
		req_write_gent[pose_write_data_2] = 0;
		req_write_gent[pose_write_data_3] = 0;
		req_write_gent[pose_write_data_4] = req_write_data_4;
		req_write_gent[pose_write_data_5] = 0;
	}
	else if (OutputSet == 5)
	{
		req_write_gent[pose_write_data_1] = 0;
		req_write_gent[pose_write_data_2] = 0;
		req_write_gent[pose_write_data_3] = 0;
		req_write_gent[pose_write_data_4] = 0;
		req_write_gent[pose_write_data_5] = req_write_data_5;
	}
	else
	{
		/* code */
	}
	req_write_gent[pose_write_w_0] = req_write_w_0;
	req_write_gent[pose_write_w_1] = req_write_w_1;
	req_write_gent[pose_write_w_2] = req_write_w_2;
	req_write_gent[pose_write_w_3] = req_write_w_3;
	req_write_gent[pose_write_w_4] = req_write_w_4;
	send(_socket, req_write_gent, 22, 0);
	bool ReadOk = 1;
	cout << " chuan bi roi ne " << endl;
	while (ReadOk)
	{
		cout << "doi tin nhan gent" << endl;
		read(_socket, res_write_gent, 2);

		cout << " gia tri nhan duoc ne " << res_write_gent << endl;
		if (res_write_gent[0] == 0x2F00 && res_write_gent[1] == 0x0000)
		{
			cout << "gui ok roi day" << endl;
			ReadOk = 0;
			break;
		}

		/* code */
	}

	//send(SocketIP,(const void *)&req_write_cmd,4,0);
}
int TCPClient::TCPClientWriteOutputGentArrayBit( int OutputSet, int row, int col, bool value)
{
	TCPClientWriteArrayBit16(row, col, value);
	TCPClientWriteOutputGentArray(OutputSet);
}
int TCPClient::TCPClientWriteOutputGentBit(int OutputSet, uint16_t Data0, uint16_t Data1, uint16_t Data2, uint16_t Data3, uint16_t Data4)
{
	req_write_gent[pose_write_cmd] = req_write_cmd;

	if (OutputSet == 1)
	{
		req_write_gent[pose_write_data_1] = req_write_data_1;
		req_write_gent[pose_write_data_2] = 0;
		req_write_gent[pose_write_data_3] = 0;
		req_write_gent[pose_write_data_4] = 0;
		req_write_gent[pose_write_data_5] = 0;
	}
	else if (OutputSet == 2)
	{
		req_write_gent[pose_write_data_1] = 0;
		req_write_gent[pose_write_data_2] = req_write_data_2;
		req_write_gent[pose_write_data_3] = 0;
		req_write_gent[pose_write_data_4] = 0;
		req_write_gent[pose_write_data_5] = 0;
	}
	else if (OutputSet == 3)
	{
		req_write_gent[pose_write_data_1] = 0;
		req_write_gent[pose_write_data_2] = 0;
		req_write_gent[pose_write_data_3] = req_write_data_3;
		req_write_gent[pose_write_data_4] = 0;
		req_write_gent[pose_write_data_5] = 0;
	}
	else if (OutputSet == 4)
	{
		req_write_gent[pose_write_data_1] = 0;
		req_write_gent[pose_write_data_2] = 0;
		req_write_gent[pose_write_data_3] = 0;
		req_write_gent[pose_write_data_4] = req_write_data_4;
		req_write_gent[pose_write_data_5] = 0;
	}
	else if (OutputSet == 5)
	{
		req_write_gent[pose_write_data_1] = 0;
        req_write_gent[pose_write_data_2] = 0;
		req_write_gent[pose_write_data_3] = 0;
		req_write_gent[pose_write_data_4] = 0;
		req_write_gent[pose_write_data_5] = req_write_data_5;
	}
	else
	{
		/* code */
	}
	req_write_gent[pose_write_w_0] = Data0;
	req_write_gent[pose_write_w_1] = Data1;
	req_write_gent[pose_write_w_2] = Data2;
	req_write_gent[pose_write_w_3] = Data3;
	req_write_gent[pose_write_w_4] = Data4;
	send(_socket, req_write_gent, 22, 0);
	bool ReadOk = 1;
	cout << " chuan bi roi ne " << endl;
	while (ReadOk)
	{
		cout << "doi tin nhan gent" << endl;
		read(_socket, res_write_gent, 2);

		//	cout << " gia tri nhan duoc ne " << res_write_gent << endl;
		if (res_write_gent[0] == 0x2F00 && res_write_gent[1] == 0x0000)
		{
			cout << "gui ok roi day" << endl;
			ReadOk = 0;
			break;
		}

		/* code */
	}
}
int TCPClient::ArrayHexToArrayBit16(uint16_t ArrayHex[25], bool (& ArrayBit)[25][16])
{
	int Hx = 0;
	int Bx = 0;
	int By = 0;
	bool *bit;

	for (size_t x = 0; x < 25; x++)
	{
		Bx = Hx;
		bit = TCPClientDecToBin16(ArrayHex[x]);
		cout << " Gia tri mang Array hex = " << ArrayHex[x] << endl;

		for (size_t y = 0; y < 16; y++)
		{

			ArrayBit[x][y] = bit[y];

			cout << "Mảng  = [" << x << "]  [" << y << "] = " << bit[y] << " ; " << endl;
		}
		cout << "gia tri bit ";
		for (size_t i = 0; i < 16; i++)
		{
			cout << bit[i] << ", ";
		}

		cout << endl;
		cout << "-------------------" << endl;
	}
}



int TCPClient::TCPClientReadInputGent( int InputRead)

{
	bool CheckSend = 0;
	bool CheckRead = 0;
	bool SendOk;
	uint16_t temp[30];
	req_read_gent[pose_read_data_cmd] = 0xF100;
	if (InputRead == 1)
	{
		req_read_gent[pose_read_data_1] = req_read_data_1;
		req_read_gent[pose_read_data_2] = 0;
		req_read_gent[pose_read_data_3] = 0;
		req_read_gent[pose_read_data_4] = 0;
	}
	else if (InputRead == 2)
	{
		req_read_gent[pose_read_data_1] = 0;
		req_read_gent[pose_read_data_2] = req_read_data_2;
		req_read_gent[pose_read_data_3] = 0;
		req_read_gent[pose_read_data_4] = 0;
	}
	else if (InputRead == 3)
	{
		req_read_gent[pose_read_data_1] = 0;
		req_read_gent[pose_read_data_2] = 0;
		req_read_gent[pose_read_data_3] = req_read_data_3;
		req_read_gent[pose_read_data_4] = 0;
	}
	else if (InputRead == 4)
	{
		req_read_gent[pose_read_data_1] = 0;
		req_read_gent[pose_read_data_2] = 0;
		req_read_gent[pose_read_data_3] = 0;
		req_read_gent[pose_read_data_4] = req_read_data_4;
	}
	else
	{
		/* code */
	}

	CheckSend = send(_socket, req_read_gent, 10, 0);
	for (size_t i = 0; i < 6; i++)
	{
		cout << "  Buffer" << i << " = " << req_read_gent[i];
	}
	cout << "send  xong roi ne" << endl;
	cout << "---------------------------------------------" << endl;
	if (CheckSend > 0)
	{
		SendOk = 1;
		while (SendOk)
		{
			CheckRead = read(_socket, temp, 60);
			if (CheckRead > 0)
			{
				if (temp[0] == 0x1F00 && temp[1] == 0x3200)
				{
					for (size_t i = 0; i < 30; i++)
					{
						res_read_gent[i] = temp[i];
					}
					res_read_data_cmd = res_read_gent[pose_read_data_cmd];
					res_read_data_1 = res_read_gent[pose_read_data_1];
					res_read_data_2 = res_read_gent[pose_read_data_2];
					res_read_data_3 = res_read_gent[pose_read_data_3];
					res_read_data_4 = res_read_gent[pose_read_data_4];

					res_read_w_[0] = res_read_gent[pose_read_w_0];
					res_read_w_[1] = res_read_gent[pose_read_w_1];
					res_read_w_[2] = res_read_gent[pose_read_w_2];
					res_read_w_[3] = res_read_gent[pose_read_w_3];
					res_read_w_[4] = res_read_gent[pose_read_w_4];
					res_read_w_[5] = res_read_gent[pose_read_w_5];
					res_read_w_[6] = res_read_gent[pose_read_w_6];
					res_read_w_[7] = res_read_gent[pose_read_w_7];
					res_read_w_[8] = res_read_gent[pose_read_w_8];
					res_read_w_[9] = res_read_gent[pose_read_w_9];
					res_read_w_[10] = res_read_gent[pose_read_w_10];
					res_read_w_[11] = res_read_gent[pose_read_w_11];
					res_read_w_[12] = res_read_gent[pose_read_w_12];
					res_read_w_[13] = res_read_gent[pose_read_w_13];
					res_read_w_[14] = res_read_gent[pose_read_w_14];
					res_read_w_[15] = res_read_gent[pose_read_w_15];
					res_read_w_[16] = res_read_gent[pose_read_w_16];
					res_read_w_[17] = res_read_gent[pose_read_w_17];
					res_read_w_[18] = res_read_gent[pose_read_w_18];
					res_read_w_[19] = res_read_gent[pose_read_w_19];
					res_read_w_[20] = res_read_gent[pose_read_w_20];
					res_read_w_[21] = res_read_gent[pose_read_w_21];
					res_read_w_[22] = res_read_gent[pose_read_w_22];
					res_read_w_[23] = res_read_gent[pose_read_w_23];
					res_read_w_[24] = res_read_gent[pose_read_w_24];
					for (size_t i = 0; i < 30; i++)
					{
						cout << "Buffer" << i << " = " << res_read_gent[i] << endl;
					}
					cout << "read xong roi ne" << endl;
					//ArrayHexToArrayBit(Array, ArrayB);

					cout << "---------------------------------------------" << endl;
					/* 			for (size_t i = 0; i < 24; i++)
			{
				cout << "res_read_gent " << i << " = " << res_read_gent[i] << endl;
			} */

					break;
				}
			}
			else
			{
				return 0;
			}
		}
	}
	else
	{
		return 0;
	}
}
int TCPClient::TCPClientReadInputGentArray( int InputRead)
{
	TCPClientReadInputGent(InputRead);
	ArrayHexToArrayBit16(res_read_w_, Fx_Read_Gent);
}
bool TCPClient::TCPClientReadInputGentBit( int x, int y)
{
   
	bool value;
     TCPClientReadInputGentArray( 1);
	value = Fx_Read_Gent[x][y];

	cout << " gia tri cuar bien kia laf"
		 << " x = " << x << " Y=  " << y << " =>> " << value << endl;
	return value;
}
bool TCPClient::TCPClientReadArrayBit(bool ArrayBit[][16],int x, int y){
	bool value;
	value= ArrayBit[x][y];
	return value;
}
bool TCPClient::TCPClientReadGent(int x, int y){
	return TCPClientReadArrayBit(Fx_Read_Gent,x,y);

}
