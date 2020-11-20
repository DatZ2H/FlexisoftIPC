// Server side C/C++ program to demonstrate Socket programming
#include "socket_fx.h"

using namespace std;

//uint16_t Array[25] = {0xff01, 0x0203, 0x0405, 0x0607, 0x0809, 0x0A0B, 0x0C0D, 0x0E0F, 0x1011, 0x1213, 0x1415, 0x1617, 0x1819, 0x1A1B, 0x1C1D, 0x1E1F, 0x2021, 0x2223, 0x2425, 0x2627, 0x2829, 0x2A2B, 0x2C2D, 0x2E2f, 0x3031};
//bool ArrayB[25][16];
bool demo[16] = {1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0};


bool *Dec2BinWord(uint16_t d)
{

	bool *b = new bool[16];
	int i = 0;
	while (d > 0)
	{
		b[i] = d % 2;
		d = d / 2;
		i++;
	}

	return b;
}
int Bin2DecWord(int n)
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
	cout << "Bin2Dec " << DecNumber << endl;
}
uint16_t ArrayBin2DecWord(bool ArrayBit[16])
{

	uint16_t DecNumber = 0;

	for (size_t i = 0; i < 16; i++)
	{
		DecNumber += ArrayBit[i] * pow(2, i);
	}

	return DecNumber;
}
uint16_t *ArrayBit2ArrayHex(bool ArrayBit[][16])
{
	uint16_t *ArrayHex = new uint16_t[16];

	for (size_t i = 0; i < 5; i++)
	{
		ArrayHex[i] = ArrayBin2DecWord(ArrayBit[i]);
		cout << "ArrayHex == " << ArrayHex[i] << endl;
	}

	return ArrayHex;
}

bool ReadBit(uint16_t Data, int Pose)
{

	bool Status;
	Status = Data & 1 << Pose;
	return Status;
}
uint16_t WriteArrayBit(bool ArrayBit[][16], int row, int col, bool value)
{
	ArrayBit[row][col] = value;
}
uint16_t WriteBit(uint16_t &Data, bool Status, int Pose)
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

int WriteOutputGentArray(int SocketIP, int OutputSet)
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

	req_write_gent[pose_write_w_0] = ArrayBin2DecWord(Fx_Write_Gent[0]);
	req_write_gent[pose_write_w_1] = ArrayBin2DecWord(Fx_Write_Gent[1]);
	req_write_gent[pose_write_w_2] = ArrayBin2DecWord(Fx_Write_Gent[2]);
	req_write_gent[pose_write_w_3] = ArrayBin2DecWord(Fx_Write_Gent[3]);
	req_write_gent[pose_write_w_4] = ArrayBin2DecWord(Fx_Write_Gent[4]);
	send(SocketIP, req_write_gent, 22, 0);
	bool ReadOk = 1;
	cout << " chuan bi roi ne " << endl;
	while (ReadOk)
	{
		cout << "doi tin nhan gent" << endl;
		read(SocketIP, res_write_gent, 2);

		cout << " gia tri nhan duoc ne " << res_write_gent << endl;
		if (res_write_gent[0] == 0x2F00 && res_write_gent[1] == 0x0000)
		{
			cout << "gui ok roi day" << endl;
			ReadOk = 0;
			break;
		}

		/* code */
	}
}

int WriteOutputGent(int SocketIP, int OutputSet)
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
	send(SocketIP, req_write_gent, 22, 0);
	bool ReadOk = 1;
	cout << " chuan bi roi ne " << endl;
	while (ReadOk)
	{
		cout << "doi tin nhan gent" << endl;
		read(SocketIP, res_write_gent, 2);

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
int WriteOutputGentArrayBit(int SocketIP, int OutputSet, int row, int col, bool value)
{
	WriteArrayBit(Fx_Write_Gent, row, col, value);
	WriteOutputGentArray(SocketIP, OutputSet);
}
int WriteOutputGentBit(int SocketIP, int OutputSet, uint16_t Data0, uint16_t Data1, uint16_t Data2, uint16_t Data3, uint16_t Data4)
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
	send(SocketIP, req_write_gent, 22, 0);
	bool ReadOk = 1;
	cout << " chuan bi roi ne " << endl;
	while (ReadOk)
	{
		cout << "doi tin nhan gent" << endl;
		read(SocketIP, res_write_gent, 2);

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
int ArrayHexToArrayBit(uint16_t ArrayHex[25], bool ArrayBit[][16])
{
	int Hx = 0;
	int Bx = 0;
	int By = 0;
	bool *bit;

	for (size_t x = 0; x < 25; x++)
	{
		Bx = Hx;
		bit = Dec2BinWord(ArrayHex[x]);
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

int ReadInputGent(int SocketIP, int InputRead)

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

	CheckSend = send(SocketIP, req_read_gent, 10, 0);
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
			CheckRead = read(SocketIP, temp, 60);
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
int ReadInputGentArray(int SocketIP, int InputRead)
{
	ReadInputGent(SocketIP, InputRead);
	ArrayHexToArrayBit(res_read_w_, Fx_Read_Gent);
}
bool ReadInputGentBit(bool ArrayBit[][16], int x, int y)
{
	bool value;
	value = ArrayBit[x][y];

	cout << " gia tri cuar bien kia laf"
		 << " x = " << x << " Y=  " << y << " =>> " << value << endl;
	return value;
}

/* int main(int argc, char const *argv[])
{
	
	int server_fd, new_socket, valread;
	struct sockaddr_in address;
	int opt = 1;
	int addrlen = sizeof(address);
	uint16_t buffer[4] = {0};
	const char *hello = "Hello from server";

	//cout<<"gia tri bit "<<ArrayBin2DecWord(demo)<<endl;
	//ArrayBit2ArrayHex(demoMatrix);
	//  b= Dec2BinWord(k);
	// cout << " Gia tri mang Array hex = " << b << endl;
	//ArrayHexToArrayBit(Array, ArrayB);

	// Creating socket file descriptor
	if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0)
	{
		perror("socket failed");
		exit(EXIT_FAILURE);
	}
// Forcefully attaching socket to the port 8080
	if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt)))
	{
		perror("setsockopt");
		exit(EXIT_FAILURE);
	}
	address.sin_family = AF_INET;
	address.sin_addr.s_addr = INADDR_ANY;
	address.sin_port = htons(PORT);

	// Forcefully attaching socket to the port 8080
	if (bind(server_fd, (struct sockaddr *)&address, sizeof(address)) < 0)
	{
		perror("bind failed");
		exit(EXIT_FAILURE);
	}
	if (listen(server_fd, 3) < 0)
	{
		perror("listen");
		exit(EXIT_FAILURE);
	}
	if ((new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t *)&addrlen)) < 0)
	{
		perror("accept");
		exit(EXIT_FAILURE);
	}
 
	WriteOutputGentArray(new_socket,1);
	//WriteOutputGentArrayBit(new_socket, 1, SAFE_IO_Pose_Pick_In, 1);
	//ReadInputGentArray(new_socket,1);
	//WriteOutputGentArray(new_socket,1);
	//	while (1)
	//{
	//WriteOutputGent(new_socket, 1);
	//	ReadInputGent(new_socket, 1);
	//	ReadInputGentBit(Fx_Read_Gent, IO_M1I1_EMC);
	//	}

	//WriteOutputGent(new_socket, 1);
	//WriteOutputGent(new_socket, 1);


	return 0;
} */

Server::Server(int port)
{
	initialiseall(port);
}
/***************************************************/
Server::Server(void)
{
	initialiseall(PORT);
}
Server::~Server()
{
	
}
/***************************************************/
void Server::initialiseall(int port)
{
	for (int i = 0; i < max_clients; i++) 
	{ 
		server_class.client_socket[i] = 0; 
	} 
	//create a master socket  
	// tạo file mô tả socket
	if( (server_class.master_socket = socket(AF_INET , SOCK_STREAM , 0)) == 0) 
	{ 
		perror("socket failed"); 
		exit(EXIT_FAILURE); 
	} 

	//set master socket to allow multiple connections , 
	//this is just a good habit, it will work without this 
	// gán địa chỉ cho socket
	if( setsockopt(server_class.master_socket, SOL_SOCKET, SO_REUSEADDR, (char *)&server_class.opt,sizeof(server_class.opt)) < 0 ) 
	{ 
		perror("setsockopt"); 
		exit(EXIT_FAILURE); 
	} 

	//type of socket created 
	address.sin_family = AF_INET; 
	address.sin_addr.s_addr = INADDR_ANY;//inet_addr("192.168.1.199"); 
	address.sin_port = htons( PORT ); 

	//bind the socket to localhost port 8888 
	if (bind(server_class.master_socket, (struct sockaddr *)&address, sizeof(address))<0) 
	{ 
		perror("bind failed"); 
		exit(EXIT_FAILURE); 
	} 
	printf("Listener on port %d \n", PORT); 

	//try to specify maximum of 3 pending connections for the master socket 
	if (listen(server_class.master_socket, 3) < 0) 
	{ 
		perror("listen"); 
		exit(EXIT_FAILURE); 
	} 

	//accept the incoming connection 
	server_class.addrlen = sizeof(address); 
	puts("Waiting for connections ..."); 
}

/***************************************************/
//process in loop
void Server::socketloop(void)
{
	//clear the socket set 
	FD_ZERO(&readfds); 

	//add master socket to set 
	FD_SET(server_class.master_socket, &readfds); 
	server_class.max_sd = server_class.master_socket; 

	//add child sockets to set 
	for (int i = 0 ; i < max_clients ; i++) 
	{ 
		//socket descriptor 
		server_class.sd = server_class.client_socket[i]; 

		//if valid socket descriptor then add to read list 
		if(server_class.sd > 0) FD_SET( server_class.sd , &readfds); 

		//highest file descriptor number, need it for the select function 
		if(server_class.sd > server_class.max_sd) server_class.max_sd = server_class.sd; 
	} 

	//wait for an activity on one of the sockets , timeout is NULL , 
	//so wait indefinitely 
	if ((select( server_class.max_sd + 1 , &readfds , NULL , NULL , NULL) < 0) && (errno!=EINTR)) {
		printf("select error");
		} 
	//If something happened on the master socket , 
	//then its an incoming connection 
	if (FD_ISSET(server_class.master_socket, &readfds)) 
	{ 
		if ((server_class.new_socket = accept(server_class.master_socket,(struct sockaddr *)&address, (socklen_t*)&server_class.addrlen))<0) 
		{ 
			perror("accept"); 
			exit(EXIT_FAILURE); 
		} 

		//inform user of socket number - used in send and receive commands 
		cout<<"New connection , socket fd is "<< inet_ntoa(address.sin_addr) << "---Port is :"<< ntohs(address.sin_port) << endl; 

		//send new connection greeting message 
/* 		if( send(server_class.new_socket, message, strlen(message), 0) != strlen(message)) 
			if( send(server_class.new_socket, message, strlen(message), 0) != strlen(message)) {perror("send");} 
			printf("Welcome message sent successfully -- "); 

			//add new socket to array of sockets 
			for (int i = 0; i < max_clients; i++) 
			{ 
				//if position is empty 
				if( server_class.client_socket[i] == 0 ) 
				{ 
					server_class.client_socket[i] = server_class.new_socket;
					printf("Adding to list of sockets as %s\n" , client_class[i].hostbuffer);
					printf("....................................................................\n"); 
					break; 
				} 
			}  */
            send(server_class.new_socket, req_read_gent, 10, 0);
	} 

	//else its some IO operation on some other socket 
	for (int i = 0; i < max_clients; i++) 
	{ 
		server_class.sd = server_class.client_socket[i]; 

		if (FD_ISSET( server_class.sd , &readfds)) 
		{ 
			//Check if it was for closing , and also read the 
			//incoming message 
			if ((server_class.valread = read( server_class.sd , buffer, 1024)) == 0) 
			{ 
				//Somebody disconnected , get his details and print 
				getpeername(server_class.sd , (struct sockaddr*)&address , (socklen_t*)&server_class.addrlen); 
				printf("Host disconnected , ip %s , port %d \n," , 
				inet_ntoa(address.sin_addr) , ntohs(address.sin_port)); 
				printf("....................................................................\n"); 

				//Close the socket and mark as 0 in list for reuse 
				close( server_class.sd ); 
				server_class.client_socket[i] = 0; 
			} 
  			
			//Echo back the message that came in 
			else
			{ 
				//set the string terminating NULL byte on the end 
				//of the data read 
				buffer[server_class.valread] = '\0'; 
				strcpy(client_class[i].ip_address ,inet_ntoa(address.sin_addr));
				strcpy(client_class[i].databuffer ,buffer);
			} 
		} 
	} 
}