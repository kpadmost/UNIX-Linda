//
// Created by konstantin on 05.06.17.
//

#include <iostream>

#include "controller/Server.h"
#include "model/implementation/TupleManager.h"
#include "model/implementation/CommunicationManagerFIFO.h"

#include <thread>

int main() {
    Server server = Server(new CommunicationManagerFIFO(), new TupleManager());
    std::thread servThread(&Server::waitForRequests, &server);
    servThread.detach();
    char c;
    std::cin >> c;

    server.kill();
    return 0;
}