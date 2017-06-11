//
// Created by konstantin on 10.06.17.
//

#ifndef UNIXLINDAFIFO_ICOMMUNICATIONMANAGER_H
#define UNIXLINDAFIFO_ICOMMUNICATIONMANAGER_H

#include <bits/unique_ptr.h>
#include "../../../shared/TupleMessage.h"

class ICommunicationManager {
public:

    virtual void sendMessage(const TupleMessage& message) = 0;
    virtual void sendMessage(const int clientId, const Tuple& tuple) = 0;
    virtual TupleMessage receiveMessage() = 0;
};
typedef std::unique_ptr<ICommunicationManager> CommunicationManagerPtr;

#endif //UNIXLINDAFIFO_ICOMMUNICATIONMANAGER_H
