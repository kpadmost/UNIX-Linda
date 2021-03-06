//
// Created by konstantin on 10.06.17.
//


#include "CommunicationManagerFIFO.h"



TupleMessage CommunicationManagerFIFO::receiveMessage() {
    TupleMessage m;
    fifo->readFromFIFO(m);
    if(m.clientPid != m.INVALID_PID)
        std::cout << "\nmessage received " << m << std::endl;
    return m;
}

void CommunicationManagerFIFO::sendMessage(const int clientId, const Tuple &tuple, const RequestType type) {
    sendMessage(TupleMessage(clientId, tuple, type));
}

void CommunicationManagerFIFO::sendMessage(const TupleMessage &message) {
    FifoManager clientFifo(message.clientPid,false , O_WRONLY);
    clientFifo.openFifo();
    std::cout << "message sent: " << message << std::endl;
    clientFifo.writeToFifo(message);
}

CommunicationManagerFIFO::CommunicationManagerFIFO() :
    fifo(std::unique_ptr<FifoManager>(new FifoManager(FifoManager::SERVER_FIFO, true, O_RDONLY))){
    fifo->openFifo();
}

CommunicationManagerFIFO::~CommunicationManagerFIFO() {
    fifo->closeFifo();
}
