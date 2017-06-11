//
// Created by konstantin on 10.06.17.
//

#include "CommunicationManagerFIFO.h"



TupleMessage CommunicationManagerFIFO::receiveMessage() {
    TupleMessage m;
    fifo->readFromFIFO(m);
    return m;
}

void CommunicationManagerFIFO::sendMessage(const int clientId, const Tuple& tuple) {
    TupleMessage m(clientId, tuple);
    fifo->writeToFifo(m);
}

void CommunicationManagerFIFO::sendMessage(const TupleMessage &message) {
    fifo->writeToFifo(message);
}

CommunicationManagerFIFO::CommunicationManagerFIFO() :
    fifo(std::unique_ptr<FifoManager>(new FifoManager(FifoManager::SERVER_FIFO, O_RDONLY))){
    fifo->openFifo();
}
