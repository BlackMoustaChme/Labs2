#include <iostream>
#include "IUnknown.h"
#include "serv.h"
#include "serv2.h"
HRESULT_ CreateInstance(CLSID_  clsid, IID_  iid, void **ppv){
    HRESULT_ res;
    if(clsid == 1){

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


