#include <iostream>
#include "Server2Factory.h"
#include "iserv.h"
#include "iserv2.h"
#include "serv2.h"
using std::cout;//, std::cin;
using std::endl;
Server2Factory::~Server2Factory() {}

Server2Factory::Server2Factory() {}

HRESULT_ Server2Factory::CreateInstance(IID_ iid, void **ppv) {
    Server2* server2 = new Server2();
    switch (iid) {
        case 1:
        {
            server2->QueryInterface_(iid, ppv);
            return 0;
        }
        case 2:
        {
            server2->QueryInterface_(iid, ppv);
            return 0;
        }
        default:
            *ppv=NULL;
            return 1;

    }
    /*if (iid == 0){
        *ppv=(void *)(IUnknown_*)this;
        return 0;
    }
    if (iid == 1){
        *ppv=(IServer*)(new Server);
        return 0;
    }
    else{
        *ppv=NULL;
        return 1;
    }*/
}
HRESULT_ Server2Factory::QueryInterface_(IID_ iid, void **ppv){
    switch (iid) {
        case 0:
        {
            *ppv=(void *)(IUnknown_*)((IClassFactory_*)this);
            AddRef();
            return 0;
        }
        case 1:
        {
            *ppv=(void *)(IClassFactory_*)this;
            AddRef();
            return 0;
        }
        case 2:
        {
            *ppv=(void *)(IClassFactory_*)this;
            AddRef();
            return 0;
        }
        default:
            *ppv=NULL;
            return 1;

    }
    /*if (iid == 0)
    {
        *ppv=(void *)(IUnknown_*)((IClassFactory_*)this);
        return 0;
    }
    if (iid == 1){
        *ppv=(void *)(IClassFactory_*)this;
        return 0;
    }
    else{
        *ppv=NULL;
        return 1;
    }
*/
}

U_LONG_ Server2Factory::AddRef() {
    CountRef++;
    cout<<"AddReference"<<CountRef<<endl;
    return CountRef;
}
U_LONG_ Server2Factory::Release() {
    CountRef--;
    cout<<"DeleteReference"<<CountRef<<endl;
    if(CountRef == 0)
    {
        cout<<"DeleteServer2FactoryReference"<<endl;
        delete this;
    }
    return CountRef;
}

