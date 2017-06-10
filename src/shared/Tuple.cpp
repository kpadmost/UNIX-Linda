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
            if(tupleData.find(">=", 0)!=std::string::npos && tupleData.find(">=", 0)==0)
            {

            }
            else if(tupleData.find(">", 0)!=std::string::npos && tupleData.find(">", 0)==0)
            {

            }
            else if(tupleData.find("<=", 0)!=std::string::npos && tupleData.find("<=", 0)==0)
            {

            }
            else if(tupleData.find("<", 0)!=std::string::npos && tupleData.find(">", 0)==0)
            {

            }
            else if(tupleData.find("==", 0)!=std::string::npos && tupleData.find("==", 0)==0)
            {
                if(tupleFormat == "float")
                    return false;
            }
            else
            {

            }
        }
    }
    else if(tupleFormat == "string")
    {

    }
}

bool Tuple::checkSubStr(std::string substr)
{
    try {
        boost::lexical_cast<int>(substr);
        return true;
    } catch (boost::bad_lexical_cast) {
        return false;
    }
}
