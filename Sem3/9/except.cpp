#include "except.h"
#include <string>
#include <iostream>
Except::Except(int code, string message)
{
    this->code = code;
    this->message = message;
}

Except::~Except() {}

void Except::Show()
{
    cout << "Error " << code << ": " << message << endl;
}
