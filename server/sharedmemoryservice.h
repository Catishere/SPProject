#ifndef SHAREDMEMORYSERVICE_H
#define SHAREDMEMORYSERVICE_H

#include <sys/ipc.h>
#include <sys/shm.h>
#include <iostream>
#include <cstring>

class SharedMemoryService
{
    key_t key;
    char * memory;
    int com_id;
public:
    SharedMemoryService();
    int write(const char *data, size_t size);
    int read(char **data, size_t size);
    int open();
    int close();
};

#endif // SHAREDMEMORYSERVICE_H
