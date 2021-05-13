#ifndef MUTEX_H
#define MUTEX_H

#include <pthread.h>
#include <cstdlib>
#include "mutexexception.h"

/**
 * @brief https://stackoverflow.com/questions/13161153/c11-interprocess-atomics-and-mutexes
 */
class Mutex
{
    char *_handle;
public:
    Mutex(char *shmemMutex);
    virtual ~Mutex();

    void lock();
    void unlock();
    bool tryLock();
};

#endif // MUTEX_H
