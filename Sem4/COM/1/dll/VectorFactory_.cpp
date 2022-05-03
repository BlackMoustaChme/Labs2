#include <iostream>
#include "../headers/VectorFactory_.h"
#include "../headers/Vector_.h"
using std::cout;//, std::cin;
using std::endl;
namespace global{
    int global_iRef = 0;
}
HRESULT_ VectorFactory_::CreateInstance(IID_ iid, void **ppv) {
    Vector_* vector = new Vector_();
    switch (iid) {
        case 1:
        {
            vector->QueryInterface_(iid, ppv);
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
HRESULT_ VectorFactory_::QueryInterface_(IID_ iid, void **ppv){
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