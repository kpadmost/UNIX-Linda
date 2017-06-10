//
// Created by konstantin on 05.06.17.
//

#ifndef UNIXLINDAFIFO_TUPLEMESSAGE_H
#define UNIXLINDAFIFO_TUPLEMESSAGE_H

#include <utility>
#include "Tuple.h"

enum RequestType {
    OUTPUT,
    INPUT,
    READ
};

// Tuple template & timeout
class TupleMessage {
public:
    int clientPid;
    unsigned int timeout;
    RequestType requestType; // O - output, I - input, R - read
    int tupleNumber;
    Tuple tuples;
};


#endif //UNIXLINDAFIFO_TUPLEMESSAGE_H
