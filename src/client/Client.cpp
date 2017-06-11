#include "Client.h"

Client::Client()
{

}

bool Client::addTupleValue(char* command, int position)
{
    TupleValue tupleValue;
    std::string line = command;
    std::string delimiter = ":";
    std::string tupleFormat;
    std::string tupleData;
    int int_;
    float float_;
    std::string string_;
    TupleFormat format;
    TupleComparator comparator;


    tupleFormat = line.substr(0, line.find(delimiter));
    tupleData = line.substr(line.find(delimiter)+1, line.length());

    if(tupleFormat == "float")
        format = FLOAT;
    else if(tupleFormat == "int")
        format = INT;
    else if(tupleFormat == "string")
        format = STRING;
    else
        return false;

    if(tupleData.find(">=", 0)!=std::string::npos && tupleData.find(">=", 0)==0)
    {
        if(tupleFormat == "float")
        {
            if(!getData(float_, tupleData.substr(2)))
                return false;
        }
        else if(tupleFormat == "int")
        {
            if(!getData(int_, tupleData.substr(2)))
                return false;
        }
        else
            if(!getData(string_, tupleData.substr(2), tupleValue.STRING_MAX))
                return false;
        comparator = GEQ;
    }
    else if(tupleData.find(">", 0)!=std::string::npos && tupleData.find(">", 0)==0)
    {
        if(tupleFormat == "float")
        {
            if(!getData(float_, tupleData.substr(1)))
                return false;
        }
        else if(tupleFormat == "int")
        {
            if(!getData(int_, tupleData.substr(1)))
                return false;
        }
        else
            if(!getData(string_, tupleData.substr(1), tupleValue.STRING_MAX))
                return false;
        comparator = GT;
    }
    else if(tupleData.find("<=", 0)!=std::string::npos && tupleData.find("<=", 0)==0)
    {
        if(tupleFormat == "float")
        {
            if(!getData(float_, tupleData.substr(2)))
                return false;
        }
        else if(tupleFormat == "int")
        {
            if(!getData(int_, tupleData.substr(2)))
                return false;
        }
        else
            if(!getData(string_, tupleData.substr(2), tupleValue.STRING_MAX))
                return false;
        comparator = LEQ;
    }
    else if(tupleData.find("<", 0)!=std::string::npos && tupleData.find(">", 0)==0)
    {
        if(tupleFormat == "float")
        {
            if(!getData(float_, tupleData.substr(1)))
                return false;
        }
        else if(tupleFormat == "int")
        {
            if(!getData(int_, tupleData.substr(1)))
                return false;
        }
        else
            if(!getData(string_, tupleData.substr(1), tupleValue.STRING_MAX))
                return false;
        comparator = LT;
    }
    else if(tupleData.find("==", 0)!=std::string::npos && tupleData.find("==", 0)==0)
    {
        if(tupleFormat == "float")
            return false;
        else
        {
            if(tupleFormat == "int")
            {
                if(!getData(int_, tupleData.substr(2)))
                    return false;
            }
            else
                if(!getData(string_, tupleData.substr(2), tupleValue.STRING_MAX))
                    return false;
        }

        comparator = EQ;
    }
    else
    {
        if(tupleFormat == "float")
        {
            if(!getData(float_, tupleData))
                return false;
        }
        else if(tupleFormat == "int")
        {
            if(!getData(int_, tupleData))
                return false;
        }
        else
            if(!getData(string_, tupleData, tupleValue.STRING_MAX))
                return false;
    }



    return true;
}

bool Client::getData(std::string& string_, std::string substr, int max)
{
    substr.erase(0, 1);
    substr.erase(substr.length()-1, 1);
    if(substr.length()>(unsigned int) max)
        return false;
    else
    {
        string_ = substr;
        return true;
    }
}

bool Client::getData(int& int_, std::string substr)
{
    try {
        int_ = boost::lexical_cast<int>(substr);
        return true;
    } catch (boost::bad_lexical_cast) {
        return false;
    }
}

bool Client::getData(float& float_, std::string substr)
{
    try {
        float_ = boost::lexical_cast<float>(substr);
        return true;
    } catch (boost::bad_lexical_cast) {
        return false;
    }
}
