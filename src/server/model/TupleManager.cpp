//
// Created by konstantin on 10.06.17.
//

#include "TupleManager.h"

const Tuple & TupleManager::readTuple(const Tuple &tupleTemplate) const {


    return ITupleManager::noTuple;
}

const Tuple & TupleManager::getTuple(const Tuple &tupleTemplate) {
    return ITupleManager::noTuple;
}

void TupleManager::putTuple(const Tuple &tupleTemplate) {

}

Tuple &TupleManager::findTuple(const Tuple &tupleTemplate) {
    return *std::find(tuples.begin(), tuples.end(), tupleTemplate);
}
