#include <stdio.h>
#include "testtypes.h"
#include <sys/socket.h>
#include <unistd.h>
#include <time.h>

typedef struct message{
  time_t time;
  char name[32];
  char text[256];
}message;

int main(){
  message msg;
  socket_mdata server = host_connection(2222);
  recv(server.destination_handle, &msg, sizeof(msg), 0);
  puts(msg.name);
  puts(msg.text);
}
