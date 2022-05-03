//#include <iostream>
//#include "headers/IUnknown.h"
//#include "servs/iserv2.h"
//#include "servs/iserv.h"
//#include "servs/ServerFactory.h"
//using std::cout, std::endl, std::cin;
#include "ModuleInfo.h"
#include "managerDll.h"
int main()
{
    HINSTANCE h;
    HRESULT_ res;
    VectorFactory_* factory;
    FunctionArg GetClassObject, CreateInstance;
    FunctionNotArg FreeUnusedLibraries;
    h = LoadLibrary("managerDll.dll");

    GetClassObject = (FunctionArg) GetProcAddress(h, "GetClassObject");
    FreeUnusedLibraries = (FunctionNotArg) GetProcAddress(h, "FreeUnusedLibraries");
    CreateInstance = (FunctionArg) GetProcAddress(h, "CreateInstance");

    res = GetClassObject(CLSID_Slae, IID_SlaeFactory, (void**)&factory);
    if (res == S_OK_){
        IOperations* op = NULL;
        res = factory->CreateInstance(IID_IOperation, (void**)&op);
        if (res == S_OK_){
            op->Input();
//            op->solve();
        }
        op->Release();
        factory->Release();
    }
    FreeUnusedLibraries();
    FreeLibrary(h);
/*//  IServer * s = NULL;
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
    return 0;*/
}
