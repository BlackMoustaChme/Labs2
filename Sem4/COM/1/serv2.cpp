#include <iostream>
#include "serv2.h"


using std::cout;//, std::endl, std::cin;
/*Server::Server(int a)
{
    this->a=a;
}*/
Server2::Server2() {
    a = new int(3);
    b = new int(3);
    c = new int(4)
}

void Server2::func() {
    cout << "SERV_2 FUNC"<<*a;

}
void Server2::func2() {
    cout << "SERV_2 FUNC_2"<<*c;

}
HRESULT_ Server2::QueryInterface_(IID_ iid, void **ppv){
    /*if (iid == 0){
        *ppv=(IUnknown_*)this;
        return 0;
    }*/
    if (iid == 1){
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
    }
}
/*IServer* CreateInstance(){
    return new Server();
}*/
Server2::~Server2() {

}

