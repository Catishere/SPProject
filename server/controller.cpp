#include "controller.h"

Controller::Controller()
{

}

void Controller::handleLogin()
{
    std::string username(data->username);
    std::string password(data->password);
    std::string ip(data->ip);

    Status status = loginManager.attemptLogin(username, password, ip);
    std::string status_message;

    switch (status) {
    case WRONG_PASS:
        status_message = "Wrong pass";
        break;
    case WRONG_USER:
        status_message = "Wrong user";
        break;
    case BLOCKED:
        status_message = "Blocked";
        break;
    case SUCCESS:
        status_message = "Logged in";
        break;
    case FAILURE:
        status_message = "Failed";
        break;
    }

    std::cout << "Login attempt from " << ip
              << " for " << username
              << " with status: " << status_message
              << std::endl;

    strcpy(data->status, status_message.c_str());
    data->sig = IDLE;
}

void Controller::handleCommand()
{
    if (!strcmp(data->command, "ROLE")) {
        std::string username(data->username);
        User * user = loginManager.getUser(username);
        if (user)
            strcpy(data->status, ToString(user->getRole()));
        data->sig = IDLE;
    }

    if (!strcmp(data->command, "SBIL")) {

        std::ifstream blocked_ips_in(BLOCKED_IP_FILE, std::ifstream::in);
        char line[127];
        blocked_ips_in.readsome(line, 127);
        strcpy(data->status, line);
        blocked_ips_in.close();
        data->sig = IDLE;
    }
}


Controller::Controller(SharedMemory * _sharedMemory)
{
    sharedMemory = _sharedMemory;
    data = sharedMemory->getData();
    loginManager = LoginManager();
    loginManager.loadFiles();
}
