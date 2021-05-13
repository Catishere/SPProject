#ifndef IPENTRY_H
#define IPENTRY_H

#include <string>

class IPEntry
{
    std::string ip;
    int attempts;
public:
    IPEntry();
    IPEntry(std::string ip);
    std::string getIp() const;
    void setIp(const std::string &value);
    int getAttempts() const;
    void setAttempts(int value);
    void increment();
};

#endif // IPENTRY_H
