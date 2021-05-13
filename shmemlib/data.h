#ifndef DATA
#define DATA

#define IDLE 0
#define LOGIN 1
#define COMMAND 2
#define CONTINUE_REQ 3
#define CONTINUE_RES 4

struct Data {
    char username[128];
    char password[128];
    char status[128];
    char sockets[256];
    char sig;
    char mutex[8];
    char reserved[354];
    char command[5];
    char ip[16];
};
typedef struct Data Data;

#endif // DATA

