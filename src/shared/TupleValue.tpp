#ifndef TUPLEVALUE_TPP
#define TUPLEVALUE_TPP

#include <functional>

#include "TupleValue.h"


template<typename T>
bool TupleValue::fieldComparsion(const T& first, const T& second) {
    switch (comparator) {
        case GT:
            return (std::bind(std::greater<T>(), first, second))();
        case LT:
            return (std::bind(std::less<T>(), first, second))();
        case EQ:
            return (std::bind(std::equal_to<T>(), first, second))();
        case GEQ:
            return (std::bind(std::greater_equal<T>(), first, second))();
        case LEQ:
            return (std::bind(std::less_equal<T>(), first, second))();
        case DM:
            return true;
    }
    return false;
}

#endif
