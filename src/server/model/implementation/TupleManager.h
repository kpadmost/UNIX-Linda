//
// Created by konstantin on 10.06.17.
//

#ifndef UNIXLINDAFIFO_TUPLEMANAGER_H
#define UNIXLINDAFIFO_TUPLEMANAGER_H

#include <vector>
#include <algorithm>

#include "../interfaces/ITupleManager.h"
#include "../../../shared/TupleValue.h"


class TupleManager : public ITupleManager {
private:
    std::vector<TupleValue> tuples;
    TupleValue& findTuple(const TupleValue& tupleTemplate);
public:

    Tuple readTuple(const Tuple &tupleTemplate) const override;

    Tuple getTuple(const Tuple &tupleTemplate) override;

    void putTuple(const Tuple &tupleTemplate) override;
};


#endif //UNIXLINDAFIFO_TUPLEMANAGER_H
