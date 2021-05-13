#ifndef LOGINMANAGER_H
#define LOGINMANAGER_H

#define IP_FILE "info_ip"
#define PASSWORD_FILE "user_password"
#define BLOCKED_IP_FILE "blocked_ip"

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>
#include "user.h"
#include "ipentry.h"

enum Status {
    SUCCESS,
    WRONG_PASS,
    WRONG_USER,
    BLOCKED,
    FAILURE
};

class LoginManager
{
    std::vector<User> users;
    std::vector<std::string> blockedIPs;
    std::vector<IPEntry> ips;
public:
    LoginManager();
    int loadFiles();
    int saveIpFile();
    int saveBlockedIpFile();
    int wrongPassHandler(std::string ip);
    Status attemptLogin(std::string username, std::string password, std::string ip);
    void blockIP(std::string ip);
    bool isIPBlocked(std::string ip);
    User * getUser(std::string username);
    std::vector<IPEntry> getIps() const;
    void setIps(const std::vector<IPEntry> &value);
};

#endif // LOGINMANAGER_H
