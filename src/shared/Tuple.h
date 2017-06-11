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
<<<<<<< HEAD
=======
    bool operator==(const Tuple& other) const;
>>>>>>> 28576b3752c934aac542fae6d42435b941b8b104
};


#endif //UNIXLINDAFIFO_TUPLESET_H
