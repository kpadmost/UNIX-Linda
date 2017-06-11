#ifndef CLIENT_H
#define CLIENT_H

#include <sys/types.h>
#include <unistd.h>
#include "iostream"
#include <boost/lexical_cast.hpp>
#include "src/shared/TupleMessage.h"

class Client
{
public:
    Client();
    bool addTupleValue(char*, int);
    bool getData(std::string&, std::string, int);
    bool getData(int&, std::string);
    bool getData(float&, std::string);
    TupleMessage* message;
};

#endif // CLIENT_H
