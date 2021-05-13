#ifndef MOCKIP_H
#define MOCKIP_H

#include <string>
#include <sstream>
#include <sys/types.h>
#include <unistd.h>

class MockIP
{

public:
    static std::string getIP();

};

#endif // MOCKIP_H
