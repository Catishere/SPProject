#include "loginmanager.h"

std::vector<IPEntry> LoginManager::getIps() const
{
    return ips;
}

void LoginManager::setIps(const std::vector<IPEntry> &value)
{
    ips = value;
}

LoginManager::LoginManager()
{

}

int LoginManager::loadFiles()
{
    std::ifstream passwords(PASSWORD_FILE, std::ifstream::in);
    std::string line;

    while (std::getline(passwords, line))
    {
        User user;
        try {
            user.setRole(static_cast<Role>(std::stoi(line.substr(0, 1))));
        } catch (std::exception e) {
            std::cerr << "For line "<< line << "!" << e.what() << std::endl;
        }
        size_t delim = line.find(" ", 2);
        user.setUsername(line.substr(2, delim - 2));
        user.setPassword(line.substr(delim + 1));
        users.push_back(user);
    }
    passwords.close();

    std::ifstream ips_in(IP_FILE, std::ifstream::in);

    while (std::getline(ips_in, line))
    {
        size_t delim = line.find(" ");
        std::string ip = line.substr(0, delim);
        std::string loginAttempts = line.substr(delim + 1);

        IPEntry ipEntry;
        ipEntry.setIp(ip);
        try {
            ipEntry.setAttempts(std::stoi(loginAttempts));
        } catch (std::exception e) {
            std::cerr << e.what() << std::endl;
        }
        ips.push_back(ipEntry);
    }
    ips_in.close();

    std::ifstream blocked_ips_in(BLOCKED_IP_FILE, std::ifstream::in);
    while (std::getline(ips_in, line)) {
        blockedIPs.push_back(line);
    }
    blocked_ips_in.close();
    return 0;
}

int LoginManager::saveIpFile()
{
    std::ofstream ips_out(IP_FILE, std::ofstream::trunc);
    for (IPEntry& _ip : ips) {
        std::ostringstream  userIpData;
        userIpData << _ip.getIp() << " "
                   << _ip.getAttempts() << "\n";
        ips_out.write(userIpData.str().c_str(), userIpData.str().length());
    }
    return 0;
}

int LoginManager::saveBlockedIpFile()
{
    std::ofstream blocked_ips(BLOCKED_IP_FILE, std::ofstream::trunc);
    for (auto &ip : blockedIPs) {
        std::string bip = ip + "\n";
        blocked_ips.write(bip.c_str(), bip.length());
    }
    blocked_ips.close();
    return 0;
}

int LoginManager::wrongPassHandler(std::string ip)
{
    bool any = false;
    for (auto& _ip : ips) {
        if (_ip.getIp() == ip) {
            _ip.increment();
            if (_ip.getAttempts() == 10)
                blockIP(_ip.getIp());
            any = true;
        }
    }
    if (!any)
        ips.push_back(IPEntry(ip));
    saveIpFile();
    return 0;
}

Status LoginManager::attemptLogin(std::string username, std::string password, std::string ip)
{
    if (isIPBlocked(ip))
        return BLOCKED;

    for (User& user : users) {
        if (user.getUsername() == username) {
            if (user.getPassword() == password) {
                return SUCCESS;
            }
            wrongPassHandler(ip);
            return WRONG_PASS;
        }
    }
    return WRONG_USER;
}

void LoginManager::blockIP(std::string ip)
{
    blockedIPs.push_back(ip);
    saveBlockedIpFile();
}

bool LoginManager::isIPBlocked(std::string ip)
{
    for (auto& ip_e : blockedIPs) {
        if (ip == ip_e)
            return true;
    }
    return false;
}

User * LoginManager::getUser(std::string username)
{
    for (User &user : users) {
        if (user.getUsername() == username)
            return &user;
    }
    return nullptr;
}
