#include <iostream>
#include "IUnknown.h"
#include "iserv2.h"
#include "iserv.h"
//using std::cout, std::endl, std::cin;
int main()
{
    IServer * s;
    HRESULT_ res;
    CLSID_ clsid = 2;
    IID_ iid = 2;
    res = CreateInstance(clsid,iid, (void **) &s);
    if(res == 0){
        s->func();

        IServer2 * s2;
        iid = 1;
        res = s->QueryInterface_(iid, (void **) & s2);
        if(res == 0){
            s2->func2();
        }
    }
    return 0;
}
