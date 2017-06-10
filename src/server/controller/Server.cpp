//
// Created by konstantin on 10.06.17.
//

#include "Server.h"

void Server::updateServer(const unsigned int deltaT) {
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
    }
}

void Server::addRequest(const TupleMessage &request) {
    tupleRequests.push_back(request);
}
