#include <iostream>
#include "IUnknown.h"
#include "serv.h"
#include "serv2.h"
#include "ServerFactory.h"
HRESULT_ CreateInstance(CLSID_  clsid, IID_  iid, void **ppv){
    HRESULT_ res;
    if(clsid == 1){


// * Возможная реализация через фабрики
    IClassFactory_ * PF=NULL;
    res = GetClassObject(clsid, iid, (void **) & PF);
    if(res == 0){
//        IServer * s1 = NULL;
        res = PF->CreateInstance(iid, (void **) &ppv);
        return res;
        }

        Server *s = new Server();
        res = s->QueryInterface_(iid, ppv);
        return res;
        }
    if(clsid == 2){

            Server2 *s2 = new Server2();
            res = s2->QueryInterface_(iid, ppv);
            return res;

    }
    if(iid == 0){
        Server *s = new Server();
        * ppv = (void *)(IUnknown_ *)(IServer *) s;
                return 0;
    }
    else{
        * ppv = NULL;
        return 1;
    }
}

HRESULT_ GetClassObject(CLSID_  clsid, IID_  iid, void **ppv){
    HRESULT_ res;
    if(clsid == 1){

        ServerFactory *s = new ServerFactory();
        res = s->QueryInterface_(iid, ppv);
        return res;

    }
    if(clsid == 2){

        Server2 *s2 = new Server2();
        res = s2->QueryInterface_(iid, ppv);
        return res;

    }
    if(iid == 0){
        Server *s = new Server();
        * ppv = (void *)(IUnknown_ *)(IServer *) s;
        return 0;
    }
    else{
        * ppv = NULL;
        return 1;
    }
}


