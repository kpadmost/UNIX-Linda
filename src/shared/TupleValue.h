//
// Created by konstantin on 05.06.17.
//

#ifndef UNIXLINDAFIFO_TUPLE_H
#define UNIXLINDAFIFO_TUPLE_H

#include <limits>
#include <cstring>

enum TupleComparator {
    MT,     // >
    LT,     // >
    EQ,     // ==
    MEQ,    // >=
    LEQ     // <=
};

enum TupleFormat {
    INT,
    FLOAT,
    STRING
};

class TupleValue {
public:
    static const int STRING_MAX = 20;
    union {
        int int_;
        float float_;
        char string_[STRING_MAX];
    };
    TupleFormat format;
    bool operator==(const TupleValue& other);
    // only for comparsion sake
    TupleComparator comparator;
};



#endif //UNIXLINDAFIFO_TUPLE_H
