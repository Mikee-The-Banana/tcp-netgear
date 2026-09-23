#ifndef TESTTYPES_H
#define TESTTYPES_H

// types of buffers
#define T_DATA "DAT" // label of message with data 
#define T_CTRL "CTL" // label of control message 
//

// structures
typedef struct control_message{
  char ctl_data[64];
} control_message;

typedef struct data_message{
  void* buf;
  size_t buff_size;
} data_message;

typedef struct socket_mdata{
  int source_handle, destination_handle;
} socket_mdata;
// flags //
#define F_SESSIONSTART 0x01
#define F_SESSIONEND 0xFF
//       //

#ifdef __cplusplus
extern "C" {
#endif

extern int try_connect(const char* ip_addr, int port);

extern socket_mdata host_connection(int port);

#ifdef __cplusplus
}
#endif

#endif
