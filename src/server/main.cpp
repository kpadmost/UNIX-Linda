//
// Created by konstantin on 05.06.17.
//

#include <iostream>

#include "../shared/TupleMessage.h"

int main() {
    TupleMessage m(132);
    std::cout << sizeof(m);
    return 0;
}