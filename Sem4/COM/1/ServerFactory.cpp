#include <iostream>
#include "ServerFactory.h"
#include "iserv.h"
#include "serv.h"
HRESULT_ ServerFactory::CreateInstance(IID_ iid, void **ppv) {
    /*if (iid == 0){
        *ppv=(void *)(IUnknown_*)this;
        return 0;
    }*/
    if (iid == 1){
        *ppv=(IServer*)(new Server);
        return 0;
    }
    else{
        *ppv=NULL;
        return 1;
    }
}
HRESULT_ ServerFactory::QueryInterface_(IID_ iid, void **ppv){

    if (iid == 0)
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
    AddRef();
}