#include <iostream>
#include "iserv.h"
//using std::cout, std::endl, std::cin;
int main()
{
    IServer *S = CreateInstance();
    S->func();
    delete S;
    return 0;
}
