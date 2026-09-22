#include <iostream>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <chrono>
#include <cstdio>
#include "testtypes.h"

struct message {
  time_t send_time;
  char name[32];
  char text[256];
};

void print_msg(message msg1){
    std::cout<< "Send From: " << msg1.name << "\n";
    std::cout<< "Message: " << msg1.text << "\n";
  return;
};

int Open_socket(){

  int handle = socket(AF_INET, SOCK_STREAM, 0);

  if (handle <= 0)
    return -1;

  return handle;
};

int Connect_to_server(std::string server_ip, int port,int handle){
  sockaddr_in server;
  server.sin_family = AF_INET;
  server.sin_port = htons(port);
  server.sin_addr.s_addr = inet_addr(&server_ip[0]);
  
  if (connect(handle,(struct sockaddr *) &server, sizeof(server)) < 0)
    return -1;
  else return 0; 
};

int main() {
  message msg;
  std::cout << "Enter Your Name: \n";
  std::cin.getline(msg.name, sizeof(msg.name)); 
  std::cout << "Enter Your Message: \n";
  std::cin.getline(msg.text, sizeof(msg.text));

  int socket = Open_socket();

  if (Connect_to_server("127.0.0.1", 2222, socket) < 0){
    std::cout << "unable to connect\n";
    close(socket);
  };

  std::cout << send_flag(socket, "MSG");

  close(socket);
  return 0;
} 

