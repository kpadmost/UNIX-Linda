cmake_minimum_required(VERSION 3.7)
project(UNIXLindaFIFO)

set(CMAKE_CXX_STANDARD 11)

set(SHARED_FILES
        src/shared/TupleValue.h
        src/shared/TupleValue.cpp
        src/shared/Tuple.cpp
        src/shared/Tuple.h
        src/shared/TupleMessage.h
        src/shared/TupleMessage.cpp
        )

set(SERVER_FILES src/server/main.cpp ${SHARED_FILES}
        src/server/model/interfaces/ITupleManager.cpp
        src/server/model/interfaces/ITupleManager.h
        src/server/model/implementation/TupleManager.cpp
        src/server/model/implementation/TupleManager.h
        src/server/model/interfaces/ICommunicationManager.cpp
        src/server/model/interfaces/ICommunicationManager.h
        src/server/controller/Server.cpp
        src/server/controller/Server.h src/server/model/implementation/CommunicationManagerFIFO.cpp src/server/model/implementation/CommunicationManagerFIFO.h)

set(CLIENT_FILES src/client/main.cpp ${SHARED_FILES})
add_executable(ServerProcess ${SERVER_FILES})
add_executable(ClientProcess ${CLIENT_FILES})