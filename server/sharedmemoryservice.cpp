#include "sharedmemoryservice.h"

SharedMemoryService::SharedMemoryService()
{
    key = ftok("shm_request", 42);
}

int SharedMemoryService::write(const char * data, size_t size)
{
    std::memcpy(memory, data, size);
    return 0;
}

int SharedMemoryService::read(char ** data, size_t size)
{
    std::memcpy(*data, memory, size);
    return 0;
}

int SharedMemoryService::open()
{
    com_id = shmget(key, 1024, 0666|IPC_CREAT);
    memory = (char*) shmat(com_id, (void*)0, 0);
    return 0;
}

int SharedMemoryService::close()
{
    shmdt(memory);
    return shmctl(com_id, IPC_RMID, NULL);
}

