#include <iostream>
#include "serv.h"


using std::cout;//, std::cin;
using std::endl;

Server::Server() {
}

void Server::func() {

    cout << "SERV1_FUNC"<<endl;

}
HRESULT_ Server::QueryInterface_(IID_ iid, void **ppv){
    if (iid == 1){
        *ppv=(void *)(IServer*)this;
        AddRef();
        return 0;
    }
    else{
        *ppv=NULL;
        return 1;
    }

}
U_LONG_ Server::AddRef() {
    CountRef++;
    cout<<"AddReference"<<CountRef<<endl;
    return CountRef;
}
U_LONG_ Server::Release() {
    CountRef--;
    cout<<"DeleteReference"<<CountRef<<endl;
    if(CountRef == 0)
    {
        cout<<"DeleteServerReference"<<endl;
        delete this;
    }
    return CountRef;
}
Server::~Server() {

}