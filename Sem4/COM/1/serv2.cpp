#include <iostream>
#include "serv2.h"


using std::cout;//, std::cin;
using std::endl;
Server2::Server2() {

}

void Server2::func() {
    cout << "SERV_2 FUNC"<<endl;

}
void Server2::func2() {
    cout << "SERV_2 FUNC_2"<<endl;

}
HRESULT_ Server2::QueryInterface_(IID_ iid, void **ppv){
    switch (iid) {
        case 1:
        {
            *ppv=(void *)(IServer*)this;
            AddRef();
            return 0;
        }
        case 2:
        {
            *ppv=(void *)(IServer2*)this;
            AddRef();
            return 0;
        }
        default:
            *ppv=NULL;
            return 1;

    }

    /*if (iid == 1){
        *ppv=(void *)(IServer*)this;
        return 0;
    }
    if (iid == 2){
        *ppv=(void *)(IServer2*)this;
        return 0;
    }
    else{
        *ppv=NULL;
        return 1;
    }*/

}
U_LONG_ Server2::AddRef() {
    CountRef++;
    cout<<"AddReference"<<CountRef<<endl;
    return CountRef;
}
U_LONG_ Server2::Release() {
    CountRef--;
    cout<<"DeleteReference"<<CountRef<<endl;
    if(CountRef == 0)
    {
        cout<<"DeleteServer2Reference"<<endl;
        delete this;
    }
    return CountRef;
}

Server2::~Server2() {

}

