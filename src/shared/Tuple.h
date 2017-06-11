//
// Created by konstantin on 05.06.17.
//

#ifndef UNIXLINDAFIFO_TUPLESET_H
#define UNIXLINDAFIFO_TUPLESET_H

#include "TupleValue.h"

class Tuple {
public:
    static const int MAX_TUPLES = 10;
    const int tupleNumber;
    TupleValue tuples[MAX_TUPLES];

    Tuple(const int tupleNumber = 1);
    Tuple& operator=(const Tuple& other);
    bool operator==(const Tuple& other) const;
};


#endif //UNIXLINDAFIFO_TUPLESET_H
