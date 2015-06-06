#ifndef NULLELEMENTEXCEPTION_H
#define NULLELEMENTEXCEPTION_H

#include <string>

class NullElementException
{
private:
    std::string error;

public:
    NullElementException(std::string what);

    inline std::string getError (){return error;}
};

#endif // NULLELEMENTEXCEPTION_H
