#include "ipentry.h"

std::string IPEntry::getIp() const
{
    return ip;
}

void IPEntry::setIp(const std::string &value)
{
    ip = value;
}

int IPEntry::getAttempts() const
{
    return attempts;
}

void IPEntry::setAttempts(int value)
{
    attempts = value;
}

void IPEntry::increment()
{
    attempts++;
}

IPEntry::IPEntry()
{
    attempts = 0;
}

IPEntry::IPEntry(std::string ip)
{
    this->ip = ip;
    attempts = 0;
}

