#include <iostream>
#include "IUnknown.h"
#include "iserv2.h"
#include "iserv.h"
#include "ServerFactory.h"
//using std::cout, std::endl, std::cin;
int main()
{
//  IServer * s = NULL;
    IClassFactory_ * PF=NULL;
    CLSID_ clsid = 1;
    IID_ iid = 1;
    HRESULT_ res = GetClassObject(clsid, iid, (void**) & PF);

//  HRESULT_ res = CreateInstance(clsid,iid, (void **) &s);
    if(res == 0){
        IServer * s1 = NULL;
        iid = 1;
        res = PF->CreateInstance(iid, (void **) &s1);
        if(res == 0){
            s1->func();

        }
    }
    return 0;
}
