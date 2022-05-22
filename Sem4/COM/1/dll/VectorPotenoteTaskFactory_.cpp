#include <iostream>
#include "../headers/VectorPotenoteTaskFactory_.h"
#include "../headers/VectorPotenoteTask_.h"
using std::cout;//, std::cin;
using std::endl;
namespace global{
    int global_iRef = 0;
}
VectorPotenoteTaskFactory::VectorPotenoteTaskFactory() {

}
VectorPotenoteTaskFactory::~VectorPotenoteTaskFactory() {

}
HRESULT_ VectorPotenoteTaskFactory::CreateInstance(IID_ iid, void **ppv) {
VectorPotenoteTask* vectorpt = new VectorPotenoteTask();
switch (iid) {
case 1:
{
vectorpt->QueryInterface_(iid, ppv);
return 0;
}
case 2:
{
vectorpt->QueryInterface_(iid, ppv);
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
HRESULT_ VectorPotenoteTaskFactory::QueryInterface_(IID_ iid, void **ppv){
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
case 2:
{
*ppv=(void *)(VectorPotenoteTaskFactory*)this;
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
U_LONG_ VectorPotenoteTaskFactory::AddRef() {
    CountRef++;
    cout<<"AddReference"<<CountRef<<endl;
    return CountRef;
}
U_LONG_ VectorPotenoteTaskFactory::Release() {
    CountRef--;
    cout<<"DeleteReference"<<CountRef<<endl;
    if(CountRef == 0)
    {
        cout<<"DeleteVectorFactoryReference"<<endl;
        delete this;
    }
    return CountRef;
}
