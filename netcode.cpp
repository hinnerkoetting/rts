/////////////////////////////////////////////////////////////////
//
//					
//					netcode.cpp
//					
//					
//
/////////////////////////////////////////////////////////////////

//#include <winsock2.h>
#include "netcode.h"
#include "errors.h"
#include "settings.h"
#include "errors.h"

namespace Netcode
{
	int iPlayerID = 0;
	int nBytes;
	FD_SET masterSet;
	int mySocket;
}




unsigned int Netcode::Init()
{
	
	FD_ZERO(&masterSet);
	unsigned int mySocket = startupClient(7654, "84.129.9.204");
	FD_SET(mySocket, &masterSet);
	if (mySocket == -1) 
	{
		shutdownClient(mySocket);
		return false;
	}
	return mySocket;
}

void Netcode::Send(unsigned int mySocket, char* buffer)
{
	unsigned long messageSize = strlen(buffer);
	messageSize = htonl(messageSize);
	if ((nBytes = send(mySocket, (char*)&messageSize, sizeof(messageSize), 0)) == SOCKET_ERROR)
	{
		Error::MesBoxOk("Fehler", "Send Failed!\n");
	}
	messageSize = ntohl(messageSize);
	if ((nBytes = send(mySocket, buffer, messageSize, 0)) == SOCKET_ERROR) 
	{
		Error::MesBoxOk("Fehler", "Send Failed!\n");
	}
}

char* Netcode::Recv(unsigned int mySocket)
{
	#define MAX_MESSAGE_SIZE 4096
	char buffer[MAX_MESSAGE_SIZE];
	FD_SET tmpSet = masterSet;
	timeval waitTime;
	waitTime.tv_sec = 0;
	waitTime.tv_usec = 0;
	int result = select(tmpSet.fd_count, &tmpSet, NULL, NULL, &waitTime);
	
	if (result == 0) 
	{ 
		return "OK";
	}
	if (result == SOCKET_ERROR) 
	{
		return "FAILED";
	}
	else
	{
		nBytes = recv(mySocket, buffer, 50, 0);
		
		if (nBytes == SOCKET_ERROR) 
		{
			Error::MesBoxOk("error", "Recv Failed!\n");
			return "FAILED";
		}
		int i = 0;
		while (int(buffer[i]) != -52)
			i++;
		buffer[i] = '\0';
		return buffer;
	}
}
void Netcode::init1() 
{
	
	mySocket = Init();
	int nBytes;
	unsigned long iPlayerID;
	nBytes = recv(mySocket, (char*)&iPlayerID, sizeof(iPlayerID), 0);
	Netcode::iPlayerID = iPlayerID;
	char buffer[80];
	strcpy(buffer, "Version: ");
	strcat(buffer, Settings::cchVersionNumber);
	Send(mySocket, buffer);
	//shutdownClient(mySocket);
	//
	//char* buffer;
	//char buffer[MAX_MESSAGE_SIZE];
	
	/*for (;;)
	{
		
	}*/
	//Sleep(10000);
}

int Netcode::startupClient(unsigned short port, const char* serverName) 
{
	int error;
	WSAData wsaData;
	if ((error = WSAStartup(MAKEWORD(2, 2), &wsaData)) == SOCKET_ERROR) 
	{
		Error::MesBoxOk("Fehler", "Could Not Start Up Winsock!\n");
		return -1;
	}
	int mySocket = socket(AF_INET, SOCK_STREAM, 0);
	if (mySocket == SOCKET_ERROR) 
	{
		Error::MesBoxOk("Fehler", "Error Opening Socket!\n");
		return -1;
	}
	struct hostent *host_entry;
	if ((host_entry = gethostbyname(serverName)) == NULL) 
	{
		Error::MesBoxOk("Fehler", "Could not find host!\n");
	}
	struct sockaddr_in server;
	server.sin_family = AF_INET;
	server.sin_port = htons(port);
	server.sin_addr.s_addr = *(unsigned long*) host_entry->h_addr;
	if (connect(mySocket, (sockaddr*)&server, sizeof(server)) == SOCKET_ERROR) 
	{
		Error::MesBoxOk("Fehler", "Error connecting to server!\n");
	}
	return mySocket;
}

void Netcode::shutdownClient(int clientSocket)
{
	closesocket(clientSocket);
	WSACleanup();
}
