#include <iostream>
#include "ServerFactory.h"
#include "iserv.h"
#include "serv.h"
using std::cout;//, std::cin;
using std::endl;
ServerFactory::~ServerFactory() {}
ServerFactory::ServerFactory() {}
HRESULT_ ServerFactory::CreateInstance(IID_ iid, void **ppv) {
    Server* server = new Server();
    switch (iid) {
        case 1:
        {
            server->QueryInterface_(iid, ppv);
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
HRESULT_ ServerFactory::QueryInterface_(IID_ iid, void **ppv){
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

U_LONG_ ServerFactory::AddRef() {
    CountRef++;
    cout<<"AddReference"<<CountRef<<endl;
    return CountRef;
}
U_LONG_ ServerFactory::Release() {
    CountRef--;
    cout<<"DeleteReference"<<CountRef<<endl;
    if(CountRef == 0)
    {
        cout<<"DeleteServerFactoryReference"<<endl;
        delete this;
    }
    return CountRef;
}

