#include <iostream>
#include <fstream>
#include <string>
#include <dos.h>
#include <algorithm>
#include <vector>
using namespace std;

struct Phone{
    int Price;
    int ReleaseDate;
    int eDRAM;
    string color;
    string brand;
    double scrdl;
    void out();
};
void Phone::out()
{
    cout<<endl<<" ------------------------- "<<endl;
    cout<<" Brand: "<<brand<<endl;
    cout<<" Color: "<<color<<endl;
    cout<<" Screen diagonal: "<<scrdl<<endl;
    cout<<" eDRAM (Gb): "<<eDRAM<<endl;
    cout<<" Release date (Year): "<<ReleaseDate<<endl;
    cout<<" Price: "<<Price<<endl;
    cout<<endl<<" ------------------------- "<<endl;
}
struct Tree
{
    Phone data;
    Tree* left;
    Tree* right;
};
bool Compare(Tree* , Phone& ,int);
int GetTreeSize (Tree* T)
{
    if (!T) return 0;
    if (!T->left && !T->right)
        return 1;
    int left = 0;
    int right = 0;
    if (T->left)
    {
        left = GetTreeSize(T->left);
    }
    if (T->right)
    {
        right = GetTreeSize(T->right);
    }
    return left+right+1;
}
void Add (Tree*& T, Phone data,int key)
{
    if(!T)
    {
        T = new Tree;
        T->data = data;
        T->left = NULL;
        T->right = NULL;
        //cout<<"N"<<endl;
        return;
    }
    if (Compare(T, data,key))
    {
        Add(T->left, data,key);
        cout<<"L"<<endl;
    }
    else
    {
        Add(T->right, data,key);
        cout<<"R"<<endl;
    }
}
void PrintLRR (Tree* T)
{
    if (!T) {/*cout<<"F"*/;return;}
    PrintLRR (T->left);/*cout<<"T";*/
    T->data.out();
    PrintLRR (T->right);
}
void Delete (Tree*& T)
{
    if (T)
    {
        if (T->left) Delete(T->left);
        if (T->right) Delete(T->right);
        delete T;
        T=NULL;
    }
    else cout<<"Tree is empty"<<endl;
}


void Menu();
void Read(string );
void Read_a(Tree*& ,string ,int);
void Sort_n(Tree*& , Phone& );
void Sort_s(Tree*& , Phone& );
bool Condition(Phone& ,Phone&,int );
void Print(Phone& ,string ,int );

int main()
{
    //cout<<"Liakhim: Yrros, ris, tub siht ebyam eb ton 001% lanigiro"<<endl;
    Menu();
    return 0;

}
void Menu()
{
    Tree* T=NULL;
    //Tree* T1=NULL;
    Phone k;
    Read("Phone.txt");
    int key;

    do {
        cout<<endl;
        cout<<endl<<" ------------------------- "<<endl;
        cout<<"1 - Sort"<<endl;
        cout<<"2 - Display items matching given value"<<endl;
        cout<<"3 - Clear Tree"<<endl;
        cout<<"4 - Show Tree in order LRR and clear it"<<endl;
        cout<<"0 - Exit and clear"<<endl;
        cout<<endl<<" ------------------------- "<<endl;
        cout << "Choose what to do and enter the key " << endl;
        //cout << "If you have already initialized sort, you need to Clear Tree to sort by new field" << endl;
        cin >> key;

        switch (key) {
            case 1:
                Sort_n(T,k);
                break;
            case 2:
                Sort_s(T,k);
                break;
            case 3:
                Delete (T);
                break;
            case 4:
                PrintLRR(T);
                Delete (T);
                break;
            case 0:
                Delete (T);
                cout << "Bye:)" << endl;
                return;
            default:
                cout << "--->Error, try again... " << endl;
        }
    } while (key);
}
void Sort_n(Tree*& T, Phone& k)
{
    int key;

    do {
        cout<<endl;
        cout<<"By What you want to sort?"<<endl;
        cout<<endl<<" ------------------------- "<<endl;
        cout<<"1 - By Price"<<endl;
        cout<<"2 - By eDRAM (Gb)"<<endl;
        cout<<"3 - By Screen diagonal"<<endl;
        cout<<"4 - By Release date (Year)"<<endl;
        cout<<"5 - By Brand"<<endl;
        cout<<"6 - By Color"<<endl;
        cout<<"0 - Exit"<<endl;
        cout<<endl<<" ------------------------- "<<endl;
        cout << "Choose what to do and enter the key " << endl;
        cin >> key;

        switch (key) {
            case 1:
                Read_a(T ,"Phone.txt" ,key);
                break;
            case 2:
                Read_a(T ,"Phone.txt" ,key);
                break;
            case 3:
                Read_a(T ,"Phone.txt" ,key);
                break;
            case 4:
                Read_a(T ,"Phone.txt" ,key);
                break;
            case 5:
                Read_a(T ,"Phone.txt" ,key);
                break;
            case 6:
                Read_a(T ,"Phone.txt" ,key);
                break;
            case 0:
                cout << "Bye:)" << endl;
                return;
            default:
                cout << "--->Error, try again... " << endl;
        }
    } while (key);
}
void Sort_s(Tree*& T, Phone& k)
{
    cout<<"Enter Brand (Capital letter): ";cin>>k.brand;
    cout<<"Enter Color (Capital letter): ";cin>>k.color;
    cout<<"Enter Screen diagonal: ";cin>>k.scrdl;
    cout<<"Enter eDRAM (Gb): ";cin>>k.eDRAM;
    cout<<"Enter Release date (Year): ";cin>>k.ReleaseDate;
    cout<<"Enter Price: ";cin>>k.Price;
    int key;

    do {
        cout << endl;
        cout << "By What you want to sort?" << endl;
        cout << endl << " ------------------------- " << endl;
        cout << "1 - By Price" << endl;
        cout << "2 - By eDRAM (Gb)" << endl;
        cout << "3 - By Screen diagonal" << endl;
        cout << "4 - By Release date (Year)" << endl;
        cout << "5 - By Brand"<<endl;
        cout << "6 - By Color"<<endl;
        cout << "0 - Exit" << endl;
        cout << endl << " ------------------------- " << endl;
        cout << "Choose what to do and enter the key " << endl;
        cin >> key;

        switch (key) {
            case 1:

                Print(k ,"Phone.txt" ,key);
                break;
            case 2:

                Print(k ,"Phone.txt" ,key);
                break;
            case 3:

                Print(k ,"Phone.txt" ,key);
                break;
            case 4:
                Print(k ,"Phone.txt" ,key);
                break;
            case 5:
                Print(k ,"Phone.txt" ,key);
                break;
            case 6:
                Print(k ,"Phone.txt" ,key);
                break;
            case 0:
                cout << "Bye:)" << endl;
                return;
            default:
                cout << "--->Error, try again... " << endl;
        }

    }while (key);
}
void Read(string FileName)
{
    ifstream F(FileName.c_str());
    if (!F){ cout<<"Error";
        return;
    }
    Phone k;
    while(F>>k.brand>>k.color>>k.scrdl>>k.eDRAM>>k.ReleaseDate>>k.Price)
    {
        k.out();
    }
    F.close();
}
void Print(Phone& k0,string FileName,int key)
{
    ifstream F(FileName.c_str());
    if (!F){ cout<<"Error";
        return;
    }
    Phone k;
    while(F>>k.brand>>k.color>>k.scrdl>>k.eDRAM>>k.ReleaseDate>>k.Price)
    {
        if(Condition(k0,k,key)) k.out();
    }
    F.close();
}
void Read_a(Tree*& T,string FileName,int key)
{
    ifstream F(FileName.c_str());
    if (!F){ cout<<"Error";
        return;
    }
    Phone k;
    while(F>>k.brand>>k.color>>k.scrdl>>k.eDRAM>>k.ReleaseDate>>k.Price)
    {
        Add(T,k,key);
    }
    F.close();
}
bool Compare(Tree* T, Phone& k,int key)
{

    switch (key) {
        case 1:
            if (k.Price < T->data.Price) return true;
            break;
        case 2:
            if (k.eDRAM < T->data.eDRAM) return true;
            break;
        case 3:
            if (k.scrdl < T->data.scrdl) return true;
            break;
        case 4:
            if (k.ReleaseDate < T->data.ReleaseDate) return true;
            break;
        case 5:
        {vector <string> s = {k.brand,T->data.brand};
            sort(s.begin(), s.end());
            if (s[0]==k.brand) return true;}
            break;
        case 6:
        {vector <string> s = {k.color,T->data.color};
            sort(s.begin(), s.end());
            if (s[0]==k.color) return true;}
            break;
    }
    return false;
}
bool Condition( Phone& k0,Phone& k,int key) {

    switch (key) {
        case 1:
            if (k0.Price > k.Price) return true;
            break;
        case 2:
            if (k0.eDRAM > k.Price) return true;
            break;
        case 3:
            if (k0.scrdl > k.Price) return true;
            break;
        case 4:
            if (k0.ReleaseDate > k.Price) return true;
            break;
        case 5:
            if(k0.brand[0] == k.brand[0]) return true;
            break;
        case 6:
            if(k0.color[0] == k.color[0]) return true;
            break;
    }
    return false;
}
