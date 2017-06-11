#ifndef CLIENT_H
#define CLIENT_H

#include <sys/types.h>
#include <unistd.h>
#include "iostream"
#include <boost/lexical_cast.hpp>
#include "src/shared/TupleMessage.h"
#include "src/shared/FifoManager.h"

class Client
{
public:
    Client();
    Client(int pid) : pid(pid){}
    bool addTupleValue(char*, int, Tuple&, RequestType);
    bool getData(std::string&, std::string, int);
    bool getData(int&, std::string);
    bool getData(float&, std::string);
    TupleMessage* getMessage();
    void setMessage(int, Tuple, unsigned int, RequestType);
    void openServerFifo();
    void closeServerFifo();
    void writeCommand();
    void readAnswer();
    void openClientFifo();
    void closeClientFifo();
private:
    TupleMessage* tupleMessage;
    FifoManager* server;
    FifoManager* client;
    int pid;
};

#endif // CLIENT_H
