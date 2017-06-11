//
// Created by konstantin on 11.06.17.
//

#ifndef UNIXLINDAFIFO_FIFOMANAGER_H
#define UNIXLINDAFIFO_FIFOMANAGER_H

#include <string>
#include <memory>
class FifoManager {
private:
    void openFifo(std::string name);
    void closeFifo();
    int fifoDesk;
    std::string name; //fifo_bomz
    const static std::string fifoPath;
public:
    FifoManager(const int pid) : name(fifoPath + std::to_string(pid)) {  }
    ~FifoManager() { closeFifo(); }
    void readFromFIFO();
    void writeToFifo();
};
std::unique_ptr<FifoManager> FifoPtr;

#endif //UNIXLINDAFIFO_FIFOMANAGER_H
