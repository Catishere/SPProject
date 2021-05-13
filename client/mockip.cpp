#include "mockip.h"

std::string MockIP::getIP()
{
    int oct = (int)getpid();
    oct %= 256;
    std::ostringstream strstream;
    strstream << oct << "."<< oct << "."<< oct << "." << oct;
    return strstream.str();
}
