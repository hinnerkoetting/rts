/////////////////////////////////////////////////////////////////
//
//					
//					netcode.h
//					
//					
//
/////////////////////////////////////////////////////////////////

#ifndef NETCODE_H_DEF
#define NETCODE_H_DEF

typedef struct fd_set FD_SET;
namespace Netcode
{
	extern int iPlayerID;
	extern int mySocket;

	void shutdownClient(int clientSocket);
	int startupClient(unsigned short port, const char* serverName);
	unsigned int Init();
	void init1();
	void Send(unsigned int, char*);
	char* Recv(unsigned int);
}

#endif