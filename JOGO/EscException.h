#ifndef IOSTREAM
#define IOSTREAM
#include <iostream>
#endif

#include <stdexcept>

class EscException : public std::exception
{
    public:
        void exibeMensagem();
};