#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "sharedmemory.h"
#include "loginmanager.h"
#include <cstring>
#include <fstream>
#include <string>

class Controller
{
    LoginManager loginManager;
    SharedMemory * sharedMemory;
    Data * data;
public:
    Controller();
    Controller(SharedMemory * sharedMemory);
    void handleLogin();
    void handleCommand();
};

#endif // CONTROLLER_H
