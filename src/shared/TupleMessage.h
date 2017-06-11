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
    const static int INVALID_PID = -1;
    int clientPid;
    unsigned int timeout;
    RequestType requestType; // O - output, I - input, R - read
    TupleMessage(int clientPid = INVALID_PID, Tuple tuples = Tuple(),  unsigned int timeout = 0
            , RequestType requestType = RequestType::INPUT);

    Tuple tuples;
};


#endif //UNIXLINDAFIFO_TUPLEMESSAGE_H
