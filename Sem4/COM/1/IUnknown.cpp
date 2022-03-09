#include <iostream>
#include "IUnknown.h"
#include "serv.h"
#include "serv2.h"
HRESULT_ CreateInstance(CLSID_  clsid, IID_  iid, void **ppv){
    if(clsid == 1){
        if(iid == 1){
            Server *s = new Server();
            //* ppv = (void*)(IUnknown_*)(IServer*)
            return  0;
        }
    }
    if(clsid == 2){

        if(iid == 1){
            Server2 *s = new Server2();
            //* ppv = (void*)(IUnknown_*)(IServer*)
            return 0;
        }
        if(iid == 2){
            Server2 *s2 = new Server2();
            //* ppv = (void*)(IUnknown_*)(IServer*)
            return 0;
        }
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


