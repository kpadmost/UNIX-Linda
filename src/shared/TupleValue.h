//
// Created by konstantin on 05.06.17.
//

#ifndef UNIXLINDAFIFO_TUPLEVALUE_H
#define UNIXLINDAFIFO_TUPLEVALUE_H

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
    TupleComparator comparator;
};


#endif //UNIXLINDAFIFO_TUPLEVALUE_H
