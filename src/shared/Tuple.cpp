//
// Created by konstantin on 05.06.17.
//


#include "Tuple.h"

bool Tuple::operator==(const Tuple &other) {
    if(format != other.format)
        return false;
    switch (format) {

        case INT:
            return int_ == other.int_;
        case FLOAT:
            return (float_ - other.float_ < std::numeric_limits<float>::epsilon());
        case STRING:
            return strcmp(string_, other.string_) >= 0;
    };
}
