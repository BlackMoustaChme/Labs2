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
//    cout<<*a;
    cout << *a + *b;

}

IServer* CreateInstance(){
    return new Server();
}
Server::~Server() {

}