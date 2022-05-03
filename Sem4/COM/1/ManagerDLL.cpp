#include "managerDll.h"
#include "ModuleInfo.h"
#include <vector>
#include <fstream>
#include <string>
//using namespace std;
using std::vector;
using std::fstream;
using std::string;
using std::ios;


vector<HINSTANCE> libs(1);

HRESULT_  GetClassObject(CLSID_ clsid, IID_ iid, void** ppv){
    HRESULT_ hr = 1;
    HINSTANCE h;
    FunctionArg DLLGetClassObject;
    bool isFind = false;
    fstream file;
    string line, num;
    const char *path;
    int pos_sep;

    file.open("reg.txt", ios::in);
    while(getline(file, line)){
        pos_sep = line.find(":");
        num = line.substr(0, pos_sep);
        if (stoi(num) == clsid){
            line = line.substr(pos_sep + 1, line.length());
            path = line.c_str();
            isFind = true;
            break;
        }
    }
    file.close();
    if (isFind){
        h = LoadLibrary(path);
        if (h){
            DLLGetClassObject = (FunctionArg) GetProcAddress(h, "DLLGetClassObject");
            libs.push_back(h);
            if (DLLGetClassObject){
                hr = DLLGetClassObject(clsid, iid, ppv);
            }
        }
    }
    return hr;
}

HRESULT_ CreateInstance(CLSID_ clsid, IID_ iid, void** ppv){
    HRESULT_ hr = 0;
    IClassFactory_* factory;
    hr = GetClassObject(clsid, IID_ClassFactory, (void**)&factory);
    factory->CreateInstance(iid, ppv);
    return hr;
}

HRESULT_ FreeUnusedLibraries(){
    HRESULT_ hr = 1;
    FunctionNotArg DllCanUnloadNow;
    for (int i = 0; i < libs.size(); i++){
        DllCanUnloadNow = (FunctionNotArg) GetProcAddress(libs[i], "DLLCanUnloadNow");
        if (DllCanUnloadNow){
            hr = DllCanUnloadNow();
            if (hr == S_OK_){
                FreeLibrary(libs[i]);
                libs.erase(libs.begin() + i);
                libs.resize(libs.size() - 1);
            }
        }
    }
    return hr;
}

