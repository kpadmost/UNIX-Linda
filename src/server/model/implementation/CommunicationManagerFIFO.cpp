//
// Created by konstantin on 10.06.17.
//


#include "CommunicationManagerFIFO.h"



TupleMessage CommunicationManagerFIFO::receiveMessage() {
    TupleMessage m;
    fifo->readFromFIFO(m);
    std::cout << "\nmessage received " << m << std::endl;
    return m;
}

void CommunicationManagerFIFO::sendMessage(const int clientId, const Tuple& tuple) {
    sendMessage(TupleMessage(clientId, tuple));
}

void CommunicationManagerFIFO::sendMessage(const TupleMessage &message) {
    FifoManager clientFifo(message.clientPid, O_WRONLY);
    clientFifo.openFifo();
    std::cout << "message sent: " << message << std::endl;
    clientFifo.writeToFifo(message);
}

CommunicationManagerFIFO::CommunicationManagerFIFO() :
    fifo(std::unique_ptr<FifoManager>(new FifoManager(FifoManager::SERVER_FIFO, O_RDONLY))){
    fifo->openFifo();
}
