#ifndef TESTTYPES_H
#define TESTTYPES_H

// types of buffers
#define T_CONTROL "CTL" // label of message with interpreter commands
#define T_DATA "DAT" // label of message with user-send data 
#define T_FLAG "FLG" // label of flag
#define T_ERROR "ERR" // label of error 
#define _MSG_BUFFER_SIZE_ 2048 // max message buffer size in bytes  

#ifdef __cplusplus
extern "C" {
#endif

// structure of message pakage
typedef struct pakage{
  char type[3];
  void* buf;
  size_t pkgsize;
} package;

extern int send_flag(int handle, char* flag);
// it sends flags, ...thats it

#ifdef __cplusplus
}
#endif

#endif
