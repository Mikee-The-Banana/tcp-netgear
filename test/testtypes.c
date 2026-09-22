#include <stdio.h>
#include <stdlib.h>
#include <arpa/inet.h>
#include <sys/socket.h>

#define T_CTL "CTL"
#define T_MSG "MSG"
#define F_SESSION_START "SST"
#define F_SESSION_END "SED"

int send_flag(int handle, char* flag)
{
 char flg[] = "MSG";
 return send(handle, &flg, (size_t) 3,0) ;
};

