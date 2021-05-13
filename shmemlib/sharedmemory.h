#ifndef SHAREDMEMORY_H
#define SHAREDMEMORY_H

#include <sys/ipc.h>
#include <sys/shm.h>
#include <iostream>
#include <cstring>
#include <vector>

#include "data.h"
#include "mutex.h"

#define SERVER 0
#define CLIENT 1

class SharedMemory
{
    key_t key;
    int com_id;
    unsigned int socket_id;
    char * memory;
    Data * data;
    Mutex * mutex;

public:
    SharedMemory();
    ~SharedMemory();
    char * getMemory();
    Data * getData();
    int write(const char *data, size_t size, size_t offset);
    int read(char *data, size_t size);
    int open();
    int close();
    Mutex *getMutex() const;
};

#endif // SHAREDMEMORY_H
