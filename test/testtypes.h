#ifndef TESTTYPES_H
#define TESTTYPES_H

// types of buffers
#define T_DATA "DAT" // label of message with data 
#define T_CTRL "CTL" // label of control message 
//

// structures
typedef struct control_message{
  const char[] = T_CTRL;
  char ctl_data[64];
} control_message;

typedef struct data_message{
  const char[] = T_DATA;
  void* buf;
  size_t buff_size;
} data_message;

// flags //
#define F_SESSIONSTART 0x01
#define F_SESSIONEND 0xFF
//       //

#ifdef __cplusplus
extern "C" {
#endif

#ifdef __cplusplus
}
#endif

#endif
