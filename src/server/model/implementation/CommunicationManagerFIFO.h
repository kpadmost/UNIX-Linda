//
// Created by konstantin on 10.06.17.
//

#ifndef UNIXLINDAFIFO_COMMUNICATIONMANAGERFIFO_H
#define UNIXLINDAFIFO_COMMUNICATIONMANAGERFIFO_H

#include "../interfaces/ICommunicationManager.h"

class CommunicationManagerFIFO : public ICommunicationManager {
public:
    void sendMessage(const TupleMessage &message) override;

    TupleMessage receiveMessage() override;
};


#endif //UNIXLINDAFIFO_COMMUNICATIONMANAGERFIFO_H
