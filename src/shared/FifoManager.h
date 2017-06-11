//
// Created by konstantin on 11.06.17.
//

#ifndef UNIXLINDAFIFO_FIFOMANAGER_H
#define UNIXLINDAFIFO_FIFOMANAGER_H

#include <string>
#include <memory>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <stdio.h>
#include <unistd.h>

#include "TupleMessage.h"

class FifoManager {
private:

    void closeFifo();
    int descriptor;
    const mode_t mode;
    std::string name; //fifo_name
    const static std::string fifoPath;
public:
    FifoManager(const int pid, const mode_t mode_ = O_RDWR) :
            name(fifoPath + std::to_string(pid)), mode(mode_) {  }
    void openFifo();
    ~FifoManager() { closeFifo(); }
    void readFromFIFO(TupleMessage &message);
    void writeToFifo(const TupleMessage &message);
};
typedef std::unique_ptr<FifoManager> FifoPtr;

#endif //UNIXLINDAFIFO_FIFOMANAGER_H
