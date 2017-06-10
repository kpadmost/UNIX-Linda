//
// Created by konstantin on 10.06.17.
//

#ifndef UNIXLINDAFIFO_ITUPLEMANAGER_H
#define UNIXLINDAFIFO_ITUPLEMANAGER_H

#include <memory>
#include "../../../shared/TupleMessage.h"

class ITupleManager {
public:
    virtual Tuple readTuple(const Tuple &tupleTemplate) const = 0;
    virtual Tuple getTuple(const Tuple &tupleTemplate) = 0;
    virtual void putTuple(const Tuple &tupleTemplate) = 0;
    virtual bool isValidTuple(const Tuple& tuple) = 0;
};
typedef std::unique_ptr<ITupleManager> TupleManagerPtr;

#endif //UNIXLINDAFIFO_ITUPLEMANAGER_H
