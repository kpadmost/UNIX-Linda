//
// Created by konstantin on 05.06.17.
//
#include "Client.h"
#include "src/shared/TupleMessage.h"

int main(int argc, char* argv[])
{
    Tuple tuple;
    Client client;
    if(argc<4 || argc>3+tuple.MAX_TUPLES)
    {
        errno = ENOEXEC;
        perror("Error: invalid number of arguments");
        return -1;
    }
    char* requestType = argv[1];
    int timeout = atoi(argv[2]);
    for(int i = 3; i < argc; i++)
    {

    }

    return 0;
}
