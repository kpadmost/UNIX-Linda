//
// Created by konstantin on 11.06.17.
//

#include "FifoManager.h"
const std::string FifoManager::fifoPath = "/tmp/fifo/fifo_";
void FifoManager::openFifo() {
    if(isOwner)
        createFifo();
    else
        descriptor = open(name.c_str(), mode);
}

void FifoManager::closeFifo() {
    close(descriptor);
    if(isOwner)
        destroyFifo();

}

void FifoManager::readFromFIFO(TupleMessage &message) {
    ssize_t bytes = 0;
    if((bytes = read(descriptor, &message, sizeof(message))) < 0)
        throw std::invalid_argument("read from fifo");

}

void FifoManager::writeToFifo(const TupleMessage &message) {
    size_t messageSize = sizeof(message);
    if(write(descriptor, &message, messageSize) != messageSize)
        throw std::invalid_argument("write to fifo");
}

void FifoManager::createFifo() {
    descriptor = mkfifo(name.c_str(), mode);
    if(descriptor <0)
        throw std::invalid_argument("cant create fifo");
}

void FifoManager::destroyFifo() {
    if(unlink(name.c_str()) < 0)
        printf("cant close fifo %s", name.c_str());
    printf("closed serv fifo");
}


