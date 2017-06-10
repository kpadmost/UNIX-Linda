//
// Created by konstantin on 05.06.17.
//

#ifndef UNIXLINDAFIFO_TUPLEMESSAGE_H
#define UNIXLINDAFIFO_TUPLEMESSAGE_H

#include "Tuple.h"

enum RequestType {
    OUTPUT,
    INPUT,
    READ
};

class TupleMessage {
public:
    int clientPid;
    RequestType requestType; // O - output, I - input, R - read
    int tupleNumber;
    Tuple t;
};


#endif //UNIXLINDAFIFO_TUPLEMESSAGE_H
