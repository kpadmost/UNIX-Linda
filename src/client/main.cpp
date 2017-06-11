//
// Created by konstantin on 05.06.17.
//
#include "Client.h"

int main(int argc, char* argv[])
{
    Tuple tuple(argc-3);
    int pid = getpid();
    Client client(pid);
    RequestType type;
    if(argc<4 || argc>3+tuple.MAX_TUPLES)
    {
        std::cout<<"Invalid number of arguments"<<std::endl;
        return -1;
    }
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

    client.openServerFifo();

    client.writeCommand();

    std::cout<<"Successfuly write to fifo"<<std::endl;

    client.closeServerFifo();

    if(type == INPUT || type == READ)
    {
        client.openClientFifo();
        if(client.readAnswer(timeout))
            std::cout<<"Successfuly read to fifo"<<std::endl;
        client.closeClientFifo();
    }


    //std::cout<<client.getMessage()->tuples.tuples[0].int_<<std::endl;

    //std::cout<<client.getMessage()->tuples.tuples[1].float_<<std::endl;

    //std::cout<<client.getMessage()->tuples.tuples[2].string_<<std::endl;



    return 0;
}
