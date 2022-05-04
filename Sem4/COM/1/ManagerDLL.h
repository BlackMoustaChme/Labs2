#ifndef INC_1_MANAGERDLL_H
#define INC_1_MANAGERDLL_H
#include "ModuleInfo.h"

extern "C" HRESULT_ __declspec(dllexport) GetClassObject(CLSID_ clsid, IID_ iid, void** ppv);
extern "C" HRESULT_ __declspec(dllexport) CreateInstance();
extern "C" HRESULT_ __declspec(dllexport) FreeUnusedLibraries();

#endif //INC_1_MANAGERDLL_H
