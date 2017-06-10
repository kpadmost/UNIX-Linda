//
// Created by konstantin on 05.06.17.
//

#ifndef UNIXLINDAFIFO_TUPLESET_H
#define UNIXLINDAFIFO_TUPLESET_H

#include "TupleValue.h"

class Tuple {
public:
    static const int MAX_TUPLES = 10;
    TupleValue tuples[MAX_TUPLES];
};


#endif //UNIXLINDAFIFO_TUPLESET_H
