#include <iostream>
#include "serv.h"


using std::cout;//, std::endl, std::cin;
/*Server::Server(int a)
{
    this->a=a;
}*/
Server::Server() {
    a = new int(2);
    b = new int(3);
}

void Server::func() {

    cout << "SERV1_FUNC" <<*a + *b;

}
HRESULT_ Server::QueryInterface_(IID_ iid, void **ppv){
    /*if (iid == 0){
        *ppv=(void *)(IUnknown_*)this;
        return 0;
    }*/
    if (iid == 1){
        *ppv=(void *)(IServer*)this;
        return 0;
    }
    else{
        *ppv=NULL;
        return 1;
    }
}
/*IServer* CreateInstance(){
    return new Server();
}*/
Server::~Server() {

}