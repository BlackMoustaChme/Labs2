#include <iostream>
#include "../headers/IUnknown.h"
#include "../servs/serv.h"
#include "../servs/serv2.h"
#include "../servs/ServerFactory.h"
#include "../servs/Server2Factory.h"
#include "../headers/Vector_.h"
#include "../headers/VectorFactory_.h"
#include <windows.h>
#include <fstream>
#include <string>
#include <vector>
using std::fstream;
using std::string;
using std::vector;
using std::ios;
//using namespace std;

char module_name[MAX_PATH];
/*HRESULT_ CreateInstance(CLSID_ clsid, IID_ iid, void** ppv){
    HRESULT_ hr = 1;
    if(clsid == 1){
        IClassFactory_ *pClassFactory = NULL;
        SlaeFactory *comFact = new SlaeFactory();
        comFact->QueryInterface(clsid, (void**)&pClassFactory);
        hr = pClassFactory->CreateInstance(iid, ppv);
    }
    return hr;
}

HRESULT_ DLLGetClassObject(CLSID_ clsid, IID_ iid, void** ppv){
    HRESULT_ hr = 1;
    switch(clsid){
        case 1:{
            SlaeFactory *pClassFactory = new SlaeFactory();
            hr = pClassFactory->QueryInterface(iid, ppv);
            return hr;
        }
        default:
            return hr;
    }
}*/
HRESULT_ CreateInstance(CLSID_  clsid, IID_  iid, void **ppv){
    HRESULT_ res;
    if(clsid == 1){


// * Возможная реализация через фабрики
    IClassFactory_ * PF=NULL;
    res = GetClassObject(clsid, iid, (void **) & PF);
    if(res == 0){
//        IServer * s1 = NULL;
        res = PF->CreateInstance(iid, (void **) &ppv);
        return res;
        }

        Server *s = new Server();
        res = s->QueryInterface_(iid, ppv);
        return res;
        }
    if(clsid == 2){

            Server2 *s2 = new Server2();
            res = s2->QueryInterface_(iid, ppv);
            return res;

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

HRESULT_ GetClassObject(CLSID_  clsid, IID_  iid, void **ppv){
    HRESULT_ res;
    switch (clsid) {
        case 1:
        {
            ServerFactory *s = new ServerFactory();
            res = s->QueryInterface_(iid, ppv);
            return res;
        }
        case 2:
        {
            Server2Factory *s = new Server2Factory();
            res = s->QueryInterface_(iid, ppv);
            return res;
        }
        default:
            * ppv = NULL;
            return 1;

    }
}
HRESULT_ DllRegisterServer(){
    HRESULT_ hr = 0;
    fstream file;
    int pos_sep;
    string line, num;
    vector<string> lines;
    file.open("reg.txt", ios::in);
    while(!file.eof()){
        if (getline(file, line)){
            lines.push_back(line);
        }
    }
    file.close();
    for(int i = 0; i<lines.size(); i++){
        pos_sep = lines[i].find(":");
        num = line.substr(0, pos_sep);
        if (stoi(num) == 1){
            lines[i] = "1:" + (string)module_name;
            break;
        }
    }
    file.open("reg.txt", ios::out);
    if (lines.empty()){
        file << "1:" + (string)module_name;
    } else{
        for(int i = 0; i<lines.size(); i++){
            file << lines[i];
        }
    }
    file.close();
    return hr;
}

HRESULT_ DllUnregisterServer(){
    HRESULT_ hr = 0;
    fstream file;
    int pos_sep;
    string line, num;
    vector<string> lines;
    file.open("reg.txt", ios::in);
    while(!file.eof()){
        getline(file, line);
        lines.push_back(line);
    }
    file.close();
    for(int i = 0; i<lines.size(); i++){
        pos_sep = lines[i].find(":");
        num = line.substr(0, pos_sep);
        if (stoi(num) == 1){
            lines[i].erase();
            break;
        }
    }

    file.open("reg.txt", ios::out);
    for(int i = 0; i<lines.size(); i++){
        file << lines[i];
    }

    file.close();
    return hr;
}

HRESULT_ DLLCanUnloadNow(){
    HRESULT_ hr = 1;
    if (global::global_iRef == 0) hr = 0;
    return hr;
}

BOOL APIENTRY DllMain(HINSTANCE hinstDLL, DWORD fdwReason, LPVOID lpvReserved){
    GetModuleFileName(hinstDLL, module_name, sizeof module_name);
    return TRUE;
}


