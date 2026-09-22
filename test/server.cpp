#include <iostream>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <chrono>
#include <cstring>
#include "testtypes.h"

struct message{
  time_t time;
  char name[32];
  char text[256];
};

void print_message(message msg, int bytes_read) {
  std::cout << "Received " << bytes_read << " bytes\n";
  std::cout << "From: " << msg.name << "\n";
  std::cout << "Sent at: " << std::ctime(&msg.time);
  std::cout << msg.text << "\n";
  return;
}

void receive_message(int socket) {
  message msg;
  int bytes_read = recv(socket, &msg, sizeof(msg), 0);
  if (bytes_read == 0) std::cout << "Client hadn't sent anything\n";
  else print_message(msg, bytes_read);
  return;
}

time_t get_current_time() {
  auto stime = std::chrono::system_clock::now();
  time_t time = std::chrono::system_clock::to_time_t(stime);
  return time;
}

void send_message(int sock, std::string name, std::string text) {
  message m1;
  std::strncpy(m1.name, name.c_str(), sizeof(m1.name) - 1);
  std::strncpy(m1.text, text.c_str(), sizeof(m1.text) - 1);
  m1.time = get_current_time();
  send(sock, &m1, sizeof(m1), 0);
  return;
}

int launch_server(int port) {
  sockaddr_in server_addr;
  server_addr.sin_family = AF_INET;
  server_addr.sin_port = htons(port);
  server_addr.sin_addr.s_addr = htons(INADDR_ANY);
  int server = socket(AF_INET, SOCK_STREAM, 0);
  if (bind(server, (struct sockaddr *) &server_addr, sizeof(server_addr)) < 0) {
    return -1;
  }
  return server;
}



int main() {
  char buf[256];
  int server = launch_server(2222);
  if (server < 0) {
    std::cout << "Unable to connect server with port\n";
    return 1;
  }
  else std::cout << "Port opened successfully\n";
  if (listen(server, 1) == 0) {
    std::cout << "Socket entered listening mode\n";
    int client = accept(server, nullptr, nullptr);
    if (client < 0) {
      std::cout << "Unable to establish connection with client";
      close(server);
      return 1;
    }
    else std::cout << "Successfully established connection with client\n";
    std::cout << (int) recv(client, &buf, sizeof(buf),0);
    std::cout << buf;
    std::cout << "\n";
    close(client);
  }
  else {
    close(server);
    std::cout << "Unable to listen the socket\n";
    return 1;
  }
  close(server);
  return 0;
}
