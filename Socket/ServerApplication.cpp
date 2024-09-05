// C++ program to create Server

#include <iostream>
#include <string.h>
#include <winsock2.h>
#include <vector>
#include "ServerSocket.hpp"
using namespace std;
vector<string> split(const string &);

void boot() {
	cout << "start";
}
// Driver Code
int main() {
	// Data
	WSADATA WSAData;

	// Created socket server
	// and client
	SOCKET server, client;

	// Socket address for server
	// and client
	SOCKADDR_IN serverAddr, clientAddr;

	WSAStartup(MAKEWORD(2, 0), &WSAData);

	// Making server
	server = socket(AF_INET,
					SOCK_STREAM, 0);

	// If invalid socket created,
	// return -1
	if (server == INVALID_SOCKET) {
		cout << "Socket creation failed with error:" << WSAGetLastError() << endl;
		return -1;
	}
	serverAddr.sin_addr.s_addr = INADDR_ANY;
	serverAddr.sin_family = AF_INET;
	serverAddr.sin_port = htons(5555);

	// If socket error occurred,
	// return -1
	if (bind(server, (SOCKADDR*)&serverAddr, sizeof(serverAddr)) == SOCKET_ERROR) {
		cout << "Bind function failed with error: " << WSAGetLastError() << endl;
		return -1;
	}

	// Get the request from
	// server
	if (listen(server, 0) == SOCKET_ERROR) {
		cout << "Listen function failed with error:" << WSAGetLastError() << endl;
		return -1;
	}

	cout << "Listening for incoming connections...." << endl;
			// Create buffer[]
			char buffer[1024];

	// Initialize client address
	int clientAddrSize = sizeof(clientAddr);

	// If connection established
	if ((client = accept(server, (SOCKADDR*)&clientAddr, &clientAddrSize))
		!= INVALID_SOCKET) {
		cout << "Client connected!" << endl;
		cout << "Now you can use our live chat application." << "Enter \"exit\" to disconnect" << endl;

		// Create variable of
		// type DWORD
		DWORD tid;

		// Create Thread t1
		HANDLE t1 = CreateThread(NULL, 0, serverReceive, &client, 0, &tid);

		// If created thread
		// is not created
		if (t1 == NULL) {
			cout << "Thread Creation Error: "
				<< WSAGetLastError() << endl;
		}

		// Create Thread t2
		HANDLE t2 = CreateThread(NULL, 0, serverSend, &client, 0, &tid);

		// If created thread
		// is not created
		if (t2 == NULL) {
			cout << "Thread Creation Error: "
				<< WSAGetLastError() << endl;
		}

		// Received Objects
		// from client
		WaitForSingleObject(t1, INFINITE);
		WaitForSingleObject(t2, INFINITE);

		// Close the socket
		closesocket(client);

		// If socket closing
		// failed.
		if (closesocket(server) == SOCKET_ERROR) {
			cout << "Close socket failed with error: " << WSAGetLastError() << endl;
			return -1;
		}
		WSACleanup();
	}
}
vector<string> split(const char* &buffer) {
	std::string str(buffer, buffer + sizeof(buffer));
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}