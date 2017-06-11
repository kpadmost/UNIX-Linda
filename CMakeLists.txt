cmake_minimum_required(VERSION 3.7)
project(UNIXLindaFIFO)

set(CMAKE_CXX_STANDARD 11)

set(CMAKE_CXX_FLAGS ${CMAKE_CXX_FLAGS} -pthread)

set(SHARED_FILES
        src/shared/TupleValue.h
        src/shared/TupleValue.cpp
        src/shared/Tuple.cpp
        src/shared/Tuple.h
        src/shared/TupleMessage.h
        src/shared/TupleMessage.cpp
        src/shared/TupleValue.tpp
        src/shared/FifoManager.cpp src/shared/FifoManager.h)

set(SERVER_FILES src/server/main.cpp ${SHARED_FILES}
        src/server/model/interfaces/ITupleManager.cpp
        src/server/model/interfaces/ITupleManager.h
        src/server/model/implementation/TupleManager.cpp
        src/server/model/implementation/TupleManager.h
        src/server/model/interfaces/ICommunicationManager.cpp
        src/server/model/interfaces/ICommunicationManager.h
        src/server/controller/Server.cpp
        src/server/controller/Server.h
        src/server/model/implementation/CommunicationManagerFIFO.cpp
        src/server/model/implementation/CommunicationManagerFIFO.h
        )

set(CLIENT_FILES ${SHARED_FILES}
        src/client/main.cpp
        src/client/Client.h
        src/client/Client.cpp
        )
add_executable(ServerProcess ${SERVER_FILES})
add_executable(ClientProcess ${CLIENT_FILES})