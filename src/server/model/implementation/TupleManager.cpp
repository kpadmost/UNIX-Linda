//
// Created by konstantin on 10.06.17.
//

#include "TupleManager.h"



void TupleManager::putTuple(const Tuple &tuple) {
    tuples.push_back(tuple);
}

const Tuple TupleManager::findTuple(const Tuple &tupleTemplate) const {
    auto tupleIterator = std::find(tuples.begin(), tuples.end(), tupleTemplate);
    if(tupleIterator != tuples.end())
        return *tupleIterator;
    else
        return Tuple();
}

Tuple TupleManager::readTuple(const Tuple &tupleTemplate) const {
    return findTuple(tupleTemplate);
}

Tuple TupleManager::inputTuple(const Tuple &tupleTemplate) {
    const Tuple& tuple = readTuple(tupleTemplate);
    if(isValidTuple(tuple))
        removeTuple(tupleTemplate);
    return tuple;
}



void TupleManager::removeTuple(const Tuple &tupleTemplate) {
    tuples.erase(std::find(tuples.begin(), tuples.end(), tupleTemplate));
}

bool TupleManager::isValidTuple(const Tuple &tuple) const {
    return tuple.tupleNumber != 0;
}


