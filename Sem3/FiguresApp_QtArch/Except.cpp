#include "Except.h"
#include <string>
#include <iostream>
using namespace std;
Except::Except(int code, std::string message)
{
	this->code = code;
	this->message = message;
}

Except::~Except() {}

void Except::Show()
{
    cout << "Error " << code << ": " << message << std::endl;
}
