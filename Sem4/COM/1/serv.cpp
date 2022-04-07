#include <iostream>
#include "serv.h"


using std::cout;//, std::endl, std::cin;

Server::Server() {
    a = new int(2);
    b = new int(3);
}

void Server::func() {

    cout << "SERV1_FUNC" <<*a + *b;

}
HRESULT_ Server::QueryInterface_(IID_ iid, void **ppv){
    if (iid == 1){
        *ppv=(void *)(IServer*)this;
        return 0;
    }
    else{
        *ppv=NULL;
        return 1;
    }
    AddRef();
}
U_LONG_ Server::AddRef() {
    CountRef++;
    cout<<"AddReference"<<CountRef;
    return CountRef;
}
U_LONG_ Server::Release() {
    CountRef--;
    cout<<"DeleteReference"<<CountRef;
    if(CountRef == 0)
    {
        delete this;
    }
    return CountRef;
}
Server::~Server() {

}