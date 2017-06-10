//
// Created by konstantin on 10.06.17.
//

#ifndef UNIXLINDAFIFO_SERVER_H
#define UNIXLINDAFIFO_SERVER_H

#include <list>
#include <algorithm>

#include "../model/interfaces/ICommunicationManager.h"
#include "../model/interfaces/ITupleManager.h"
class Server {
private:
    CommunicationManagerPtr communicationManager;
    TupleManagerPtr tupleStorage;
    std::list<TupleMessage> tupleRequests;


    void removeOuttimedRequests();
    void updateRequests(const unsigned int deltaT);
    volatile bool endProcess;
    void addRequest(const TupleMessage& request);
public:
    void updateServer(const unsigned int deltaT);

    void waitForRequests();

};


#endif //UNIXLINDAFIFO_SERVER_H
