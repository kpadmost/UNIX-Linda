//
// Created by konstantin on 10.06.17.
//

#ifndef UNIXLINDAFIFO_TUPLEMANAGER_H
#define UNIXLINDAFIFO_TUPLEMANAGER_H

#include <vector>
#include <algorithm>

#include "ITupleManager.h"
#include "../../shared/Tuple.h"


class TupleManager : public ITupleManager {
private:
    std::vector<Tuple> tuples;
    Tuple& findTuple(const Tuple& tupleTemplate);
public:

    const Tuple & readTuple(const Tuple &tupleTemplate) const override;

    const Tuple & getTuple(const Tuple &tupleTemplate) override;

    void putTuple(const Tuple &tupleTemplate) override;
};


#endif //UNIXLINDAFIFO_TUPLEMANAGER_H
