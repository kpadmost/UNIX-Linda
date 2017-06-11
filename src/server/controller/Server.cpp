//
// Created by konstantin on 10.06.17.
//

#include "Server.h"

void Server::updateServer(const unsigned int deltaT) {
    resolveRequests();

    updateRequests(deltaT);

    removeOuttimedRequests();
}

void Server::removeOuttimedRequests() {
    tupleRequests.erase(std::remove_if(tupleRequests.begin()
            , tupleRequests.end(), [](TupleMessage& m) -> bool {
                return m.timeout == 0;
            }));
}

void Server::updateRequests(const unsigned int deltaT) {
    std::for_each(std::begin(tupleRequests), std::end(tupleRequests)
            , [&](TupleMessage& m) -> void {
                if(m.timeout - deltaT < 0)
                    m.timeout = 0;
                else
                    m.timeout -= deltaT;
            });
}

void Server::waitForRequests() {
    while (!endProcess) {
        TupleMessage m = communicationManager->receiveMessage();
        addRequest(m);
        sleep(10);
    }
}

void Server::addRequest(const TupleMessage &request) {
    tupleRequests.push_back(request);
}

void Server::resolveRequests() {
    for(auto it = tupleRequests.begin(); it!= tupleRequests.end();) {
        if(resolveRequest(*it)) {
            auto temp = it++;
            tupleRequests.erase(temp);
        } else ++it;

    }
}

bool Server::resolveRequest(const TupleMessage &request) {
    switch (request.requestType) {

        case OUTPUT:
            return outputRequest(request);
        case INPUT:
            return inputRequest(request);
        case READ:
            return readRequest(request);
    };
    return false;
}

bool Server::outputRequest(const TupleMessage &request) {
    tupleStorage->putTuple(request.tuples);
    return true;
}

bool Server::inputRequest(const TupleMessage &request) {
    Tuple tuple = tupleStorage->inputTuple(request.tuples);
    return checkAndSendTuple(request.clientPid, tuple);
}

bool Server::readRequest(const TupleMessage &request) {
    Tuple tuple = tupleStorage->readTuple(request.tuples);
    return checkAndSendTuple(request.clientPid, tuple);
}

bool Server::checkAndSendTuple(const int clientId, const Tuple &tuple) {
    if(tupleStorage->isValidTuple(tuple)) {
        communicationManager->sendMessage(clientId, tuple);
        return true;
    }
    return false;
}

Server::Server(ICommunicationManager *communicationManager_, ITupleManager *manager_) :
endProcess(false){
    communicationManager = std::unique_ptr<ICommunicationManager>(communicationManager_);
    tupleStorage = std::unique_ptr<ITupleManager>(manager_);
}




