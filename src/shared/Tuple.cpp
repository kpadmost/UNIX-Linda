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
    if(tupleNumber != other.tupleNumber) return false;
    for(int i = 0; i < tupleNumber; ++i)
        if(!(tuples[i] == other.tuples[i]))
            return false;
    return true;
}

std::ostream &operator<<(std::ostream& os, const Tuple &val) {
    for(int i = 0; i < val.tupleNumber; ++i)
        os << i << ") " << val.tuples[i] << std::endl;
    return os;
}
