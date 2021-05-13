#include "mutex.h"

Mutex::Mutex(char *shmemMutex)
{
    _handle = shmemMutex;

    pthread_mutexattr_t attr;
    pthread_mutexattr_init(&attr);
    pthread_mutexattr_setpshared(&attr, PTHREAD_PROCESS_SHARED);
    pthread_mutexattr_settype(&attr, PTHREAD_MUTEX_FAST_NP);

    if (pthread_mutex_init((pthread_mutex_t*)_handle, &attr) == -1) {
        free(_handle);
        throw MutexException("Unable to create mutex");
    }
}

Mutex::~Mutex()
{
    pthread_mutex_destroy((pthread_mutex_t*)_handle);
}

void Mutex::lock()
{
    if (pthread_mutex_lock((pthread_mutex_t*)_handle) != 0) {
        throw MutexException("Unable to lock mutex");
    }
}

void Mutex::unlock()
{
    if (pthread_mutex_unlock((pthread_mutex_t*)_handle) != 0) {
        throw MutexException("Unable to unlock mutex");
    }
}

bool Mutex::tryLock()
{
    int tryResult = pthread_mutex_trylock((pthread_mutex_t*)_handle);
    if (tryResult != 0) {
        if (EBUSY == tryResult) return false;
        throw MutexException("Unable to lock mutex");
    }
    return true;
}
