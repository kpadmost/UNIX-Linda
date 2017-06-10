//
// Created by konstantin on 10.06.17.
//

#include "TupleManager.h"



void TupleManager::putTuple(const Tuple &tupleTemplate) {

}

TupleValue &TupleManager::findTuple(const TupleValue &tupleTemplate) {
    return *std::find(tuples.begin(), tuples.end(), tupleTemplate);
}

Tuple TupleManager::readTuple(const Tuple &tupleTemplate) const {
    Tuple t;
    return t;
}

Tuple TupleManager::getTuple(const Tuple &tupleTemplate) {
    Tuple t;
    return t;
}


