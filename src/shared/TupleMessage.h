//
// Created by konstantin on 05.06.17.
//

#ifndef UNIXLINDAFIFO_TUPLEMESSAGE_H
#define UNIXLINDAFIFO_TUPLEMESSAGE_H

#include "TupleSet.h"

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
    TupleSet tuples;
};


#endif //UNIXLINDAFIFO_TUPLEMESSAGE_H
