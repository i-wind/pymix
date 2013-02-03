// call_socket.c - A sample program to demonstrate the TCP client
//
#ifdef WIN32
#include <sys/types.h>
#include <Winsock2.h>
#define	WINSOCKVERSION	MAKEWORD( 2,2 )
#else
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <time.h>
#endif

#include <stdio.h>
#include <string.h>

#define MAX_BUFFER		128
#define HOST			"127.0.0.1"
#define PORT     		50007

int main ()
{
  int connectionFd, rc, index = 0, limit = MAX_BUFFER;
  struct sockaddr_in servAddr, localAddr;
  char buffer[MAX_BUFFER+1];

#ifdef WIN32
  // Start up WinSock2
  WSADATA wsaData;
  if( WSAStartup( WINSOCKVERSION, &wsaData) != 0 ) return ERROR;
#endif

  memset(&servAddr, 0, sizeof(servAddr));
  servAddr.sin_family = AF_INET;
  servAddr.sin_port = htons(PORT);
  servAddr.sin_addr.s_addr = inet_addr(HOST);

  // Create socket
  connectionFd = socket(AF_INET, SOCK_STREAM, 0);

  /* bind any port number */
  localAddr.sin_family = AF_INET;
  localAddr.sin_addr.s_addr = htonl(INADDR_ANY);
  localAddr.sin_port = htons(0);

  rc = bind(connectionFd, (struct sockaddr *) &localAddr, sizeof(localAddr));

  // Connect to Server
  connect(connectionFd,
           (struct sockaddr *)&servAddr, sizeof(servAddr));

  // Send request to Server
  sprintf( buffer, "%s", "Hello, Server!" );
  send( connectionFd, buffer, strlen(buffer), 0 );

  printf("Client sent to sever \"%s\"\n", buffer);

  // Receive data from Server
  sprintf( buffer, "%s", "" );
  recv(connectionFd, buffer, MAX_BUFFER, 0);
  printf("Client read from Server \"%s\"\n", buffer);

#ifdef WIN32
  closesocket(connectionFd);
#else
  close(connectionFd);
#endif

  printf("Client closed.\n");

  return(0);
}
