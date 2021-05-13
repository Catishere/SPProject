#include "sharedmemory.h"

Mutex *SharedMemory::getMutex() const
{
    return mutex;
}

SharedMemory::SharedMemory()
{
    key = ftok("sharedmemory", 42);
}

SharedMemory::~SharedMemory()
{
    close();
}

char * SharedMemory::getMemory()
{
    return memory;
}

Data *SharedMemory::getData()
{
    return (Data *)memory;
}

int SharedMemory::open()
{
    com_id = shmget(key, 1024, 0666|IPC_CREAT);
    memory = (char*) shmat(com_id, nullptr, 0);
    mutex = new Mutex(getData()->mutex);
    return 0;
}

int SharedMemory::close()
{
    shmdt(memory);
    shmctl(com_id, IPC_RMID, NULL);
    delete mutex;
    memory = NULL;
    return 0;
}
