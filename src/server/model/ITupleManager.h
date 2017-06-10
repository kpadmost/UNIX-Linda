//
// Created by konstantin on 10.06.17.
//

#ifndef UNIXLINDAFIFO_ITUPLEMANAGER_H
#define UNIXLINDAFIFO_ITUPLEMANAGER_H

#include "../../shared/TupleMessage.h"

class ITupleManager {
public:
    virtual const Tuple& readTuple(const Tuple& tupleTemplate) const = 0;
    virtual const Tuple& getTuple(const Tuple& tupleTemplate) = 0;
    virtual void putTuple(const Tuple& tupleTemplate) = 0;
    static constexpr Tuple noTuple = Tuple();
};


#endif //UNIXLINDAFIFO_ITUPLEMANAGER_H
