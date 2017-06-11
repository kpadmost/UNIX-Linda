//
// Created by konstantin on 11.06.17.
//

#include "FifoManager.h"
const std::string FifoManager::fifoPath = "/fifo/fifo_";
const std::string FifoManager::SERVER_FIFO = "serv";
void FifoManager::openFifo() {
    descriptor = mkfifo(name.c_str(), mode);
    if(descriptor <0)
        throw std::invalid_argument("cant open fifo");
}

void FifoManager::closeFifo() {
    if(unlink(name.c_str()) < 0)
        printf("cant close fifo %s", name.c_str());
}

void FifoManager::readFromFIFO(TupleMessage &message) {
    ssize_t bytes = 0;
    if((bytes = read(descriptor, &message, sizeof(message))) < 0)
        throw std::invalid_argument("bla");

}

void FifoManager::writeToFifo(const TupleMessage &message) {
    size_t messageSize = sizeof(message);
    if(write(descriptor, &message, messageSize) != messageSize)
        throw std::invalid_argument("bla");
}


