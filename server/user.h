#ifndef USER_H
#define USER_H

#include <string>
#include <vector>

enum Role {
    USER,
    ADMIN
};

inline const char* ToString(Role v)
{
    switch (v)
    {
        case USER:   return "User";
        case ADMIN:   return "Admin";
        default:      return "UNKNOWN";
    }
}

class User
{
    std::string username;
    std::string password;
    Role role;
public:
    User();
    std::string getUsername() const;
    void setUsername(const std::string &value);
    std::string getPassword() const;
    void setPassword(const std::string &value);
    Role getRole() const;
    void setRole(const Role &value);
};

#endif // USER_H
