//
// Created by konstantin on 10.06.17.
//

#ifndef UNIXLINDAFIFO_ICOMMUNICATIONMANAGER_H
#define UNIXLINDAFIFO_ICOMMUNICATIONMANAGER_H

#include "../../../shared/TupleMessage.h"

class ICommunicationManager {
public:

    virtual void sendMessage(const TupleMessage& message) = 0;
    virtual TupleMessage& receiveMessage() = 0;
};


#endif //UNIXLINDAFIFO_ICOMMUNICATIONMANAGER_H
