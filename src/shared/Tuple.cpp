//
// Created by konstantin on 05.06.17.
//

#include "Tuple.h"

Tuple::Tuple(const int tupleNumber) : tupleNumber(tupleNumber) {}

Tuple &Tuple::operator=(const Tuple& other)  {
    if(this == &other)
        return *this;
    for(int i = 0; i < other.tupleNumber; ++i)
        this->tuples[i] = other.tuples[i];
    return *this;

}

bool Tuple::addTupleValue(char* command, int position)
{
    TupleValue tupleValue;
    std::string line = command;
    std::string delimiter = ":";
    std::string tupleFormat;
    std::string tupleData;

    tupleFormat = line.substr(0, line.find(delimiter));
    tupleData = line.substr(line.find(delimiter)+1, line.length());

    if(tupleFormat == "float" || tupleFormat == "int")
    {
        if(tupleData == "*")
        {

        }
        else
        {

        }
    }
    else if(tupleFormat == "string")
    {

    }
}
