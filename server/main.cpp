#include "loginmanager.h"
#include "sharedmemory.h"
#include "controller.h"
#include <unistd.h>


int main()
{
    SharedMemory sharedMemory;
    sharedMemory.open();
    Controller controller(&sharedMemory);
    Data * data = sharedMemory.getData();
    data->sig = IDLE;

    while (true) {
        sharedMemory.getMutex()->lock();

        if (data->sig == IDLE) {
            sharedMemory.getMutex()->unlock();
            continue;
        }
        if (data->sig == LOGIN) {
            controller.handleLogin();
        } else if (data->sig == COMMAND)
            controller.handleCommand();

        sharedMemory.getMutex()->unlock();
    }

    return 0;
}
