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
    CLSID_ clsid = 2;
    IID_ iid = 2;
    HRESULT_ res = GetClassObject(clsid, iid, (void**) & PF);

//  HRESULT_ res = CreateInstance(clsid,iid, (void **) &s);
    if(res == 0){
        IServer * s1 = NULL;
        iid = 2;
        res = PF->CreateInstance(iid, (void **) &s1);
        if(res == 0){
            s1->func();
            s1->Release();

        }
        PF->Release();
    }
    return 0;
}
