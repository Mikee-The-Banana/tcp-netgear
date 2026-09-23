#include <stdio.h>
#include <stdlib.h>
#include <netinet.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include "testtypes.h"

int try_connect(const char* ip_addr, int port){
  int handle = socket(AF_INET, SOCK_STREAM, 0);
  sockaddr_in server;
  server.sin_family = AF_INET;
  server.sin_port = htons(port);
  server.sin_addr.s_addr = inet_addr(&ip_addr);

  if (connect(handle, (struct sockaddr*) &server, sizeof(server)) < 0) 
    close(handle);
  else return handle;
};

int host_connection(int port){
  int handle = socket(AF_INET, SOCK_STREAM, 0);
  sockaddr_in server;
  server.sin_family = AF_INET;
  server.sin_port = htons(port);
  server.sin_addr.s_addr = INADDR_ANY;


  if (bind(handle, (struct sockaddr*) &server, sizeof(server)) < 0) 
    close(handle);
  else return handle;
};

