#include "user.h"

std::string User::getUsername() const
{
    return username;
}

void User::setUsername(const std::string &value)
{
    username = value;
}

std::string User::getPassword() const
{
    return password;
}

void User::setPassword(const std::string &value)
{
    password = value;
}

Role User::getRole() const
{
    return role;
}

void User::setRole(const Role &value)
{
    role = value;
}

User::User()
{

}
