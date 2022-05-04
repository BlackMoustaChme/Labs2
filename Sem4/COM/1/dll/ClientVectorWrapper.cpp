#include "../headers/ClientVectorWrapper.h"
ClientVectorWrapper::ClientVectorWrapper(){
    HRESULT_ res;
    CLSID_ CLSID_Vector_ = 3;
    IID_ IID_IPrint = 1, IID_IOperation = 2;
    IID_  IID_IUnknown = 0, IID_ClassFactory = 1;
    const HRESULT_ S_OK = 0;

    this->factory = nullptr;
    res = DLLGetClassObject(CLSID_Vector_, IID_ClassFactory, (void**)&this->factory);
    if (res == S_OK){
        this->operations = nullptr;
        this->factory->CreateInstance(IID_IOperation, (void**)&this->operations);
        this->print = nullptr;
        this->operations->QueryInterface_(IID_IPrint, (void**)&this->print);
    }
}
ClientVectorWrapper::ClientVectorWrapper(ClientVectorWrapper& cvw){
    this->factory = cvw.factory;
    this->operations = cvw.operations;
    this->print = cvw.print;
    this->factory->AddRef();
    this->operations->AddRef();
    this->print->AddRef();
}
ClientVectorWrapper& ClientVectorWrapper::operator=(ClientVectorWrapper &cvw){
    this->factory = cvw.factory;
    this->operations = cvw.operations;
    this->print = cvw.print;
    this->factory->AddRef();
    this->operations->AddRef();
    this->print->AddRef();
    return *this;
}
ClientVectorWrapper::~ClientVectorWrapper(){
    this->factory->Release();
    this->operations->Release();
    this->print->Release();
}
void ClientVectorWrapper::InputVector() {
    this->operations->Input();
}
void ClientVectorWrapper::PrintVector() {
    this->print->Print();
}
void ClientVectorWrapper::VectorDistanceBetweenPointsR2() {
    this->operations->DistanceBetweenPointsR2();
}
void ClientVectorWrapper::VectorDistanceBetweenPointsR3() {
    this->operations->DistanceBetweenPointsR3();
}
void ClientVectorWrapper::VectorPotenoteSolavation() {
    this->operations->PotenoteSolvation();
}