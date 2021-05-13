#include <iostream>
#include "sharedmemory.h"
#include "mockip.h"

using namespace std;

int main()
{
    SharedMemory sharedMemory;
    sharedMemory.open();
    Data * data = sharedMemory.getData();
    std::string username;
    std::string password;

    while (true) {
        std::cout << "Username: ";
        std::cin >> username;
        std::cout << "Password: ";
        std::cin >> password;

        while (data->sig != IDLE);

        sharedMemory.getMutex()->lock();
        strcpy(data->username, username.c_str());
        strcpy(data->password, password.c_str());
        strcpy(data->ip, MockIP::getIP().c_str());
        data->sig = LOGIN;
        sharedMemory.getMutex()->unlock();

        while (data->sig != IDLE);

        std::cout << data->status << std::endl;
        if (!strcmp(data->status, "Logged in")) break;
    }

    sharedMemory.getMutex()->lock();
    strcpy(data->username, username.c_str());
    strcpy(data->command, "ROLE");
    data->sig = COMMAND;
    sharedMemory.getMutex()->unlock();

    while (data->sig != IDLE);

    std::cout << "You are logged as " << data->status << std::endl;
    if (!strcmp(data->status, "Admin")) {
        std::cout << "Press any key to show blocked ips: ";
        std::string temp;
        std::cin >> temp;

        sharedMemory.getMutex()->lock();
        strcpy(data->command, "SBIL");
        data->sig = COMMAND;
        sharedMemory.getMutex()->unlock();

        while (data->sig != IDLE);

        std::cout << data->status;
    }
    return 0;
}

