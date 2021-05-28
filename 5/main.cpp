#include <iostream>
#include <fstream>
#include <string>
#include <dos.h>
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

struct DLList
{
    struct Node
    {
        Phone data;
        Node *next;
        Node *prev;
    };
    Node *F = NULL;
    Node *L = NULL;
    Node *C = NULL;
    int Count;
    void Out();
    void Info();
    void Clear();

    bool MoveNext();
    bool MovePrev();
    bool MoveFirst();
    bool MoveLast();

    bool Init(Phone);
    bool AddNext(Phone);
    bool AddPrev(Phone);
    bool AddFirst(Phone);
    bool AddLast(Phone);

    bool Del(Phone&);
    bool DelNext(Phone&);
    bool DelPrev(Phone&);
    bool DelFirst(Phone&);
    bool DelLast(Phone&);

};
void Phone::out(){
    cout<<" Brand: "<<brand<<endl;
    cout<<" Color: "<<color<<endl;
    cout<<" Screen diagonal: "<<scrdl<<endl;
    cout<<" eDRAM (Gb): "<<eDRAM<<endl;
    cout<<" Release date (Year): "<<ReleaseDate<<endl;
    cout<<" Price: "<<Price<<endl;
}

bool DLList::MoveNext()
{
    if(!F)       return false;
    if(!C)       {C=F; return true;}
    if(!C->next) return false;
    C=C->next;
    return true;
}

bool DLList::MovePrev()
{
    if(!F)       return false;
    if(!C)       {C=F; return true;}
    if(!C->prev) return false;
    C=C->prev;
    return true;
}
bool DLList::MoveFirst()
{
    if(!F) return false;
    C=F;
    return true;
}

bool DLList::MoveLast()
{
    if(!L) return false;
    C=L;
    return true;
}

bool DLList::Init(Phone data)
{
    if(!F)
    {
        F=new Node;
        L=F;
        C=F;
        F->prev=NULL;
        F->next=NULL;
        F->data = data;
        Count=1;
        return true;
    }
    else
        return false;
}

bool DLList::AddNext(Phone data)
{
    if(!F) return Init(data);

    Node* temp=C->next;
    C->next=new Node;
    C->next->next=temp;
    C->next->prev=C;

    if(!temp)
        L=C->next;
    else
        temp->prev=C->next;

    C=C->next;
    C->data=data;
    Count++;
    return true;

}

bool DLList::AddPrev(Phone data)
{
    if(!F) return Init(data);

    Node* temp=C->prev;
    C->prev=new Node;
    C->prev->next=C;
    C->prev->prev=temp;

    if(!temp)
        F=C->prev;
    else
        temp->next=C->prev;

    C=C->prev;
    C->data=data;
    Count++;
    return true;
}

bool DLList::AddFirst(Phone data)
{
    if (MoveFirst())return AddPrev(data);
    else return false;
}

bool DLList::AddLast(Phone data)
{
    if (MoveLast())return AddNext(data);
    else return false;
}

void DLList::Out()
{
    if(!F)  {
        cout<<"List is empty"<<endl;
        return;
    }

    Node* temp=F;
    cout<<"List: "<<endl;
    do
    {
        temp->data.out();
        cout<<endl<<" ------------------------- "<<endl;
        temp=temp->next;
    }
    while(temp);
    cout<<endl;
}

void DLList::Info()
{

    if(Count) cout << "List node count: " <<Count<< endl;
    else
        cout << "List is empty" << endl;
    if(C)
    {
        cout << "Current node data = " ; C->data.out();
    }
    else if (MoveFirst())
    {
        cout << "Current node data = " ; C->data.out();
    }

}

bool DLList::DelFirst(Phone& data)
{
    if(!F)      return false;
    if(C!=F)    MoveFirst();

    Node* temp = C->next;
    data = C->data;

    if(temp) temp->prev=NULL;
    delete C;

    C=temp;
    F=temp;
    Count--;
    if(!temp) {L=NULL; return false;}
    return true;
}

bool DLList::DelLast(Phone& data)
{
    if(!F)      return false;
    if(C!=L)    MoveLast();

    Node* temp = C->prev;
    data = C->data;

    if(temp) temp->next=NULL;
    delete C;

    C=temp;
    L=temp;
    Count--;

    if(!temp) {F=NULL; return false;}
    return true;
}

bool DLList::Del(Phone& data)
{
    if(!F) return false;
    if(!C) return false;

    if(C==F) return DelFirst(data);
    if(C==L) return DelLast(data);

    Node* temp = C->next;
    data=C->data;

    C->prev->next=C->next;
    C->next->prev=C->prev;

    delete C;
    C=temp;
    Count--;
    return true;
}

bool DLList::DelNext(Phone& data)
{
    if(!F) return false;
    if(!C) return false;
    if (MoveNext()) return Del(data);
    return false;
}
bool DLList::DelPrev(Phone& data)
{
    if(!F) return false;
    if(!C) return false;
    if (MovePrev()) return Del(data);
    return false;
}

void DLList::Clear()
{
    if(!MoveFirst())
    {
        cout<<"List is empty"<<endl;
        return;
    }
    Phone k;
    while(Del(k));
}
void Menu();
void Read(DLList& ,string );
void Add(DLList& , Phone& );
void ToTheTop(DLList& , Phone& );
void ToTheEnd(DLList& , Phone& );
void ToTheCP(DLList& , Phone& );
void Delt(DLList& , Phone& );
void FromTheTop(DLList& , Phone& );
void FromTheEnd(DLList& , Phone& );
void FromTheCP(DLList& , Phone& );
void Sort(DLList& , Phone& );
void Bubble (DLList& , Phone& , int );
bool Compare(DLList& , Phone& , int );
void Record(DLList& ,string );
int main()
{
    cout<<"Liakhim: Yrros, ris, tub siht ebyam eb ton 001% lanigiro"<<endl;
    Menu();
    return 0;

}
void Menu()
{
    DLList MyList;
    Phone k;
    Read(MyList,"Phone.txt");
    int key;

    do {
        cout<<endl;
        cout<<endl<<" ------------------------- "<<endl;
        cout<<"1 - Add element "<<endl;
        cout<<"2 - Delete element"<<endl;
        cout<<"3 - Sort"<<endl;
        cout<<"4 - Clear List"<<endl;
        cout<<"5 - Upload data to the file"<<endl;
        cout<<"6 - Info"<<endl;
        cout<<"0 - Exit"<<endl;
        cout<<endl<<" ------------------------- "<<endl;
        cout << "Choose what to do and enter the key " << endl;
        cin >> key;

        switch (key) {
            case 1:
                Add(MyList,k);
                break;
            case 2:
                Delt(MyList,k);
                break;
            case 3:
                Sort(MyList,k);
                break;
            case 4:
                MyList.Clear();
                break;
            case 5:
                Record(MyList, "Phone.txt");
                break;
            case 6:
                MyList.Info();
                cout<<endl;
                MyList.Out();
                break;
            case 0:
                cout << "Bye:)" << endl;
                return;
            default:
                cout << "--->Error, try again... " << endl;
        }
    } while (key);
}

void Add(DLList& MyList, Phone& k)
{

    cout<<"Enter Brand: ";cin>>k.brand;
    cout<<"Enter Color: ";cin>>k.color;
    cout<<"Enter Screen diagonal: ";cin>>k.scrdl;
    cout<<"Enter eDRAM (Gb): ";cin>>k.eDRAM;
    cout<<"Enter Release date (Year): ";cin>>k.ReleaseDate;
    cout<<"Enter Price: ";cin>>k.Price;

    int key;

    do {
        cout<<endl;
        cout<<"Where you want to add the element?"<<endl;
        cout<<endl<<" ------------------------- "<<endl;
        cout<<"1 - Top"<<endl;
        cout<<"2 - Last"<<endl;
        cout<<"3 - Certain position"<<endl;
        cout<<"0 - Exit"<<endl;
        cout<<endl<<" ------------------------- "<<endl;
        cout << "Choose what to do and enter the key " << endl;
        cin >> key;

        switch (key) {
            case 1:
                ToTheTop(MyList,k);
                break;
            case 2:
                ToTheEnd(MyList,k);
                break;
            case 3:
                ToTheCP(MyList,k);
                break;
            case 0:
                cout << "Bye:)" << endl;
                return;
            default:
                cout << "--->Error, try again... " << endl;
        }
    } while (key);

}
void ToTheTop(DLList& MyList, Phone& k)
{
    if(MyList.Count != 0)
    {
        MyList.AddFirst(k);
    }
    else
    {
        MyList.Init(k);
    }
}
void ToTheEnd(DLList& MyList, Phone& k)
{
    MyList.AddLast(k);
}
void ToTheCP(DLList& MyList, Phone& k)
{
    cout << "Count " <<MyList.Count << endl;
    int cp= 0;
    while (cp <= 0 || cp>MyList.Count)
    {
        cout << "CP = "; cin >>cp; cout << endl;
    }
    if(cp == 1)
    {
        MyList.AddFirst(k);
    }
    else
    {
        if(cp ==MyList.Count){
            MyList.AddLast(k);
        }
        else{
            MyList.MoveFirst();
            for(int i{1}; i < cp-1; i++)
            {
                MyList.C =MyList.C->next;
            }
            MyList.AddNext(k);
        }
    }
}
void Delt(DLList& MyList, Phone& k)
{

    int key;

    do {
        cout<<endl;
        cout<<"Where you want to delete the element?"<<endl;
        cout<<endl<<" ------------------------- "<<endl;
        cout<<"1 - Top"<<endl;
        cout<<"2 - Last"<<endl;
        cout<<"3 - Certain position"<<endl;
        cout<<"0 - Exit"<<endl;
        cout<<endl<<" ------------------------- "<<endl;
        cout << "Choose what to do and enter the key " << endl;
        cin >> key;

        switch (key) {
            case 1:
                FromTheTop(MyList,k);
                break;
            case 2:
                FromTheEnd(MyList,k);
                break;
            case 3:
                FromTheCP(MyList,k);
                break;
            case 0:
                cout << "Bye:)" << endl;
                return;
            default:
                cout << "--->Error, try again... " << endl;
        }
    } while (key);

}
void FromTheTop(DLList& MyList, Phone& k)
{
    if(MyList.Count != 0)
    {
        MyList.DelFirst(k);
    }
    else
    {
        cout << "Error! The list is empty." << endl;
    }
}
void FromTheEnd(DLList& MyList, Phone& k)
{
    if(MyList.Count != 0)
    {
        MyList.DelLast(k);
    }
    else
    {
        cout << "Error! The list is empty." << endl;
    }
}
void FromTheCP(DLList& MyList, Phone& k)
{
    cout << "Count " <<MyList.Count << endl;
    int cp= 0;
    while (cp <= 0 || cp>MyList.Count)
    {
        cout << "CP = "; cin >>cp; cout << endl;
    }
    if(cp == 1)
    {
        MyList.DelFirst(k);
    }
    else
    {
        if(cp ==MyList.Count){
            MyList.DelLast(k);
        }
        else{
            MyList.MoveFirst();
            for(int i{1}; i <cp+1; i++)
            {
                MyList.C =MyList.C->next;
            }
            MyList.DelPrev(k);
        }
    }
}
void Sort(DLList& MyList, Phone& k)
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
        cout<<"0 - Exit"<<endl;
        cout<<endl<<" ------------------------- "<<endl;
        cout << "Choose what to do and enter the key " << endl;
        cin >> key;

        switch (key) {
            case 1:
                Bubble(MyList,k,key);
                break;
            case 2:
                Bubble(MyList,k,key);
                break;
            case 3:
                Bubble(MyList,k,key);
                break;
            case 4:
                Bubble(MyList,k,key);
                break;
            case 0:
                cout << "Bye:)" << endl;
                return;
            default:
                cout << "--->Error, try again... " << endl;
        }
    } while (key);
}
bool Compare(DLList& MyList, Phone& k,int key)
{
    switch (key) {
        case 1:
            if (MyList.C->data.Price > MyList.C->prev->data.Price) return true;
            break;
        case 2:
            if (MyList.C->data.eDRAM > MyList.C->prev->data.eDRAM) return true;
            break;
        case 3:
            if (MyList.C->data.scrdl > MyList.C->prev->data.scrdl) return true;
            break;
        case 4:
            if (MyList.C->data.ReleaseDate > MyList.C->prev->data.ReleaseDate) return true;
            break;
    }
    return false;
}
void Bubble (DLList& MyList, Phone& k, int key)
{
    Phone t;
    for (int i=0;i<MyList.Count-1;i++)
    {
        MyList.MoveLast();
        for (int j = MyList.Count - 2; j >= i; j--)
        {
            if (Compare(MyList,k,key)) {
                t = MyList.C->data;
                MyList.C->data = MyList.C->prev->data;
                MyList.C->prev->data = t;
            }
            MyList.MovePrev();
        }
    }
}
void Record(DLList& MyList,string FileName)
{
    if(MyList.Count == 0)
    {
        cout << "Warning! The list is empty" << endl;
    }
    ofstream F(FileName.c_str());
    MyList.MoveFirst();
    for(int i=0; i < MyList.Count; i++)
    {
        Phone k = MyList.C->data;
        F<<k.brand<<" "<<k.color<<" "<<k.scrdl<<" "<<k.eDRAM<<" "<<k.ReleaseDate<<" "<<k.Price<<endl;
        MyList.MoveNext();
    }
    F.close();
}
void Read(DLList& MyList,string FileName)
{
    ifstream F(FileName.c_str());
    if (!F){ cout<<"Error";
        return;
    }
    Phone k;
    while(F>>k.brand>>k.color>>k.scrdl>>k.eDRAM>>k.ReleaseDate>>k.Price)
    {
        MyList.AddNext(k);
    }
    F.close();
}
