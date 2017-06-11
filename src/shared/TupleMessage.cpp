//
// Created by konstantin on 05.06.17.
//

#include "TupleMessage.h"

TupleMessage::TupleMessage(int clientPid, Tuple tuple, unsigned int timeout, RequestType requestType)
        : clientPid(clientPid),timeout(timeout), requestType(requestType), tuples(tuple) {}

std::ostream &operator<<(std::ostream &os, const TupleMessage &value) {
    std::string requestType = "";
    switch (value.requestType) {

        case OUTPUT: requestType = "OUTPUT"; break;
        case INPUT: requestType = "INPUT"; break;
        case READ: requestType = "READ"; break;
    };
    os << "Tuple message to: " << value.clientPid
       << " with request:" << value.requestType
        << " and tuple: " << std::endl << value.tuples;

    return os;
}
