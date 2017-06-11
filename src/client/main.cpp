//
// Created by konstantin on 05.06.17.
//
#include "Client.h"
#include "src/shared/TupleMessage.h"

int main(int argc, char* argv[])
{
    Tuple tuple(argc-3);
    Client client;
    RequestType type;
    if(argc<4 || argc>3+tuple.MAX_TUPLES)
    {
        std::cout<<"Invalid number of arguments"<<std::endl;
        return -1;
    }
    int pid = getpid();
    char* requestType = argv[1];
    if(std::string(requestType) == "output")
        type = OUTPUT;
    else if(std::string(requestType) == "input")
        type = INPUT;
    else if(std::string(requestType) == "read")
        type = READ;
    else
    {
        std::cout<<"Unknown command"<<std::endl;
        return -1;
    }
    int timeout = atoi(argv[2]);
    for(int i = 3; i < argc; i++)
    {
        if(!client.addTupleValue(argv[i], i-3, tuple, type))
        {
            std::cout<<"Problem with "<<i<<" argument"<<std::endl;
            return -1;
        }
    }

    client.setMessage(pid, tuple, timeout, type);
    std::cout<<client.getMessage()->tuples.tuples[0].string_<<std::endl;
    std::cout<<client.getMessage()->tuples.tuples[1].string_<<std::endl;
    std::cout<<client.getMessage()->tuples.tuples[2].string_<<std::endl;
    return 0;
}
