//
// Created by konstantin on 10.06.17.
//

#ifndef UNIXLINDAFIFO_SERVER_H
#define UNIXLINDAFIFO_SERVER_H

#include <list>
#include <algorithm>
#include <iostream>
#include "../model/interfaces/ICommunicationManager.h"
#include "../../shared/FifoManager.h"
#include "../model/interfaces/ITupleManager.h"
class Server {
private:
    CommunicationManagerPtr communicationManager;
    TupleManagerPtr tupleStorage;
    std::list<TupleMessage> tupleRequests;


    void removeOuttimedRequests();
    void updateRequests(const unsigned int deltaT);
    void resolveRequests();

    bool resolveRequest(const TupleMessage& request);
    bool outputRequest(const TupleMessage& request);
    bool inputRequest(const TupleMessage& request);
    bool readRequest(const TupleMessage& request);
    void addRequest(const TupleMessage& request);
    bool checkAndSendTuple(const int clientId, const Tuple &tuple, const RequestType request);

    volatile bool endProcess;

public:
    void kill() { endProcess = true; }
    void updateServer(const unsigned int deltaT);

    void waitForRequests();
    Server(ICommunicationManager* communicationManager, ITupleManager* manager);
};


#endif //UNIXLINDAFIFO_SERVER_H
