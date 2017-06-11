//
// Created by konstantin on 05.06.17.
//

#include "Tuple.h"

Tuple::Tuple(const int tupleNumber) : tupleNumber(tupleNumber) {}

Tuple &Tuple::operator=(const Tuple& other)  {
    if(this == &other)
        return *this;
    for(int i = 0; i < other.tupleNumber; ++i)
        this->tuples[i] = other.tuples[i];

    // ugly
    int* tupnum = const_cast<int*>(&tupleNumber);
    *tupnum = other.tupleNumber;
    return *this;

}

bool Tuple::operator==(const Tuple &other) const {
    for(int i = 0; i < tupleNumber; ++i)
        if(!(tuples[i] == other.tuples[i]))
            return false;
    return true;
}
