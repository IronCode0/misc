#include <iostream>
#include <winsock2.h>
using namespace std;
DWORD WINAPI serverReceive(LPVOID lpParam)
{
	// Created buffer[] to
	// receive message
	char buffer[1024] = { 0 };

	// Created client socket
	SOCKET client = *(SOCKET*)lpParam;

	// Server executes continuously
	while (true) {

		// If received buffer gives
		// error then return -1
		if (recv(client, buffer, sizeof(buffer), 0)
			== SOCKET_ERROR) {
			cout << "recv function failed with error "
				<< WSAGetLastError() << endl;
			return -1;
		}

		// If Client exits
		if (strcmp(buffer, "exit") == 0) {
			cout << "Client Disconnected."
				<< endl;
			break;
		}

		// Print the message
		// given by client that
		// was stored in buffer
		cout << "Client: " << buffer << endl;

		// Clear buffer message
		memset(buffer, 0,
			sizeof(buffer));
	}
	return 1;
}

// Function that sends data to client
DWORD WINAPI serverSend(LPVOID lpParam)
{
	// Created buffer[] to
	// receive message
	char buffer[1024] = { 0 };

	// Created client socket
	SOCKET client = *(SOCKET*)lpParam;

	// Server executes continuously
	while (true) {

		// Input message server
		// wants to send to client
		gets(buffer);

		// If sending failed
		// return -1
		if (send(client,
				buffer,
				sizeof(buffer), 0)
			== SOCKET_ERROR) {
			cout << "send failed with error "
				<< WSAGetLastError() << endl;
			return -1;
		}

		// If server exit
		if (strcmp(buffer, "exit") == 0) {
			cout << "Thank you for using the application"
				<< endl;
			break;
		}
	}
	return 1;
}