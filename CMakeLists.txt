cmake_minimum_required(VERSION 3.7)
project(UNIXLindaFIFO)

set(CMAKE_CXX_STANDARD 11)

set(SHARED_FILES
        src/shared/Tuple.h
        src/shared/Tuple.cpp
        src/shared/TupleSet.cpp
        src/shared/TupleSet.h
        src/shared/TupleMessage.h
        src/shared/TupleMessage.cpp
        )

set(SERVER_FILES src/server/main.cpp ${SHARED_FILES}
        src/server/model/Server.cpp
        src/server/model/Server.h
        src/server/model/ITupleManager.cpp
        src/server/model/ITupleManager.h
        src/server/model/TupleManager.cpp
        src/server/model/TupleManager.h)

set(CLIENT_FILES src/client/main.cpp ${SHARED_FILES})
add_executable(ServerProcess ${SERVER_FILES})
add_executable(ClientProcess ${CLIENT_FILES})