//
// Created by konstantin on 05.06.17.
//

#include "TupleValue.h"

bool TupleValue::operator==(const TupleValue &other) const {
    if(format != other.format)
        return false;
    switch (format) {

        case INT:
            return fieldComparsion(this->int_, other.int_);
        case FLOAT:
            return fieldComparsion(this->float_, other.float_);
        case STRING:
            return stringComparsion(this->string_, other.string_);
    };
}

bool TupleValue::stringComparsion(const char *first, const char *second) const {
    const int cmp = strcmp(first, second);
    switch (comparator) {

        case GT:
            return cmp > 0;
        case EQ:
            return cmp == 0;
        case GEQ:
            return cmp >= 0;
        case LEQ:
            return cmp <= 0;
        case LT:
            return cmp < 0;
        case DM:
            return true;
    }
    return false;
}
