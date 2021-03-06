//
// Created by konstantin on 05.06.17.
//

#ifndef UNIXLINDAFIFO_TUPLE_H
#define UNIXLINDAFIFO_TUPLE_H

#include <limits>
#include <cstring>
#include <ostream>
enum TupleComparator {
    GT,     // >
    LT,     // >
    EQ,     // ==
    GEQ,    // >=
    LEQ,     // <=
    DM      // *
};

enum TupleFormat {
    INT,
    FLOAT,
    STRING
};

class TupleValue {
private:
    bool stringComparsion(const char* first, const char* second) const;
    template<typename T>
        bool fieldComparsion(const T& first, const T& second) const;


public:
    static const int STRING_MAX = 20;
    union {
        int int_;
        float float_;
        char string_[STRING_MAX];
    };
    TupleFormat format;
    bool operator==(const TupleValue& other) const;
    friend std::ostream& operator<<(std::ostream& os, const TupleValue& val);
    // only for comparsion sake
    TupleComparator comparator;
};

#include "TupleValue.tpp"


#endif //UNIXLINDAFIFO_TUPLE_H
