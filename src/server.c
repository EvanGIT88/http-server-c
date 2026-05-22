#define UNICODE
#define WIN32_LEAN_AND_MEAN

#include <stdio.h>
#include <stdlib.h>
#include <winsock2.h>
#include <ws2tcpip.h>
#include "tools/tools.h"

#pragma pack(1)

typedef struct {
  WSADATA data;
  int result_buffer;
} wsa;

typedef struct {
  SOCKET listen;
  SOCKET accept;
} sockets;

void init_winsock(wsa* winsock) {
    winsock = malloc(1 * sizeof(wsa));

    (*winsock).result_buffer = WSAStartup(MAKEWORD(2, 2), &(*winsock).data);
    if ((*winsock).result_buffer != NO_ERROR) {
        printf("wsa_startup failed, errno: %ld \n", (*winsock).result_buffer);
        free_addresses(1, winsock);
        exit(1);
    }

    printf("wsa_startup success... \n");
}


void run_server_socket(sockets* server_sockets) {
    server_sockets = malloc(1 * sizeof(sockets));

    i 
}


int main(void)
{
    //----------------------
    // Initialize Winsock.
    wsa* winsock = malloc(0 * sizeof(wsa));
    sockets* server_socket = malloc(0 * sizeof(sockets));

    init_winsock(winsock);



    //----------------------
    // Create a SOCKET for listening for
    // incoming connection requests.
    SOCKET ListenSocket;
    ListenSocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    if (ListenSocket == INVALID_SOCKET) {
        wprintf(L"socket failed with error: %ld\n", WSAGetLastError());
        WSACleanup();
        return 1;
    }
    //----------------------
    // The sockaddr_in structure specifies the address family,
    // IP address, and port for the socket that is being bound.
    struct sockaddr_in service;
    service.sin_family = AF_INET;
    service.sin_port = htons(4008);
    inet_pton(AF_INET, "127.0.0.1", &service.sin_addr);

    if (bind(ListenSocket,
             (SOCKADDR *) & service, sizeof (service)) == SOCKET_ERROR) {
        wprintf(L"bind failed with error: %ld\n", WSAGetLastError());
        closesocket(ListenSocket);
        WSACleanup();
        return 1;
    }
    //----------------------
    // Listen for incoming connection requests.
    // on the created socket
    if (listen(ListenSocket, 1) == SOCKET_ERROR) {
        wprintf(L"listen failed with error: %ld\n", WSAGetLastError());
        closesocket(ListenSocket);
        WSACleanup();
        return 1;
    }
    //----------------------
    // Create a SOCKET for accepting incoming requests.
    SOCKET AcceptSocket;
    wprintf(L"Waiting for client to connect...\n");

    //----------------------
    // Accept the connection.
    AcceptSocket = accept(ListenSocket, NULL, NULL);
    if (AcceptSocket == INVALID_SOCKET) {
        wprintf(L"accept failed with error: %ld\n", WSAGetLastError());
        closesocket(ListenSocket);
        WSACleanup();
        return 1;
    } else
        wprintf(L"Client connected.\n");

    // No longer need server socket
    closesocket(ListenSocket);

    WSACleanup();
    return 0;
}