//
// Created by konstantin on 05.06.17.
//

#include "TupleMessage.h"

TupleMessage::TupleMessage(int clientPid, unsigned int timeout, RequestType requestType)
        : clientPid(clientPid),timeout(timeout), requestType(requestType), tuples(Tuple(0)) {}
