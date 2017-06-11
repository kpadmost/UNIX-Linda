//
// Created by konstantin on 10.06.17.
//

#ifndef UNIXLINDAFIFO_COMMUNICATIONMANAGERFIFO_H
#define UNIXLINDAFIFO_COMMUNICATIONMANAGERFIFO_H

#include "../interfaces/ICommunicationManager.h"

#include "../../../shared/FifoManager.h"

class CommunicationManagerFIFO : public ICommunicationManager {
private:
    FifoPtr fifo;

public:

    TupleMessage receiveMessage() override;

    void sendMessage(const int clientId, const Tuple tuple) override;

    void sendMessage(const TupleMessage &message) override;
};


#endif //UNIXLINDAFIFO_COMMUNICATIONMANAGERFIFO_H
