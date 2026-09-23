#include <stdio.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <unistd.h>
#include "testtypes.h"

int try_connect(const char* ip_addr, int port){
  int handle = socket(AF_INET, SOCK_STREAM, 0);
  struct sockaddr_in server;
  server.sin_family = AF_INET;
  server.sin_port = htons(port);
  server.sin_addr.s_addr = inet_addr(ip_addr);

  if (connect(handle, (struct sockaddr*) &server, sizeof(server)) < 0) 
  {
    close(handle);
    return -1;
  }
  return handle;
};

socket_mdata host_connection(int port){
  socket_mdata md;
  md.source_handle = socket(AF_INET, SOCK_STREAM, 0);

  struct sockaddr_in server;
  server.sin_family = AF_INET;
  server.sin_port = htons(port);
  server.sin_addr.s_addr = INADDR_ANY;


  if (bind(md.source_handle, (struct sockaddr*) &server, sizeof(server)) < 0) 
   {
    close(md.source_handle);
    exit(0);
   };
  
  if(listen(md.source_handle, 1) == 0)
    md.destination_handle = accept(md.source_handle, NULL, NULL)
  else exit(0);
 
  return md;
};
