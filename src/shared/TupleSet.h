//
// Created by konstantin on 05.06.17.
//

#ifndef UNIXLINDAFIFO_TUPLESET_H
#define UNIXLINDAFIFO_TUPLESET_H

#include "Tuple.h"

class TupleSet {
public:
    static const int MAX_TUPLES = 10;
    Tuple tuples[MAX_TUPLES];
};


#endif //UNIXLINDAFIFO_TUPLESET_H
