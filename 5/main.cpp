#include <iostream>
#include <fstream>
#include <string>
#include <dos.h>
using namespace std;

/*struct Cars{
    int Price, ReleaseDate, HP, Seats;
    string color,brand,ToWD;
    void out();
    bool IsEqual(Cars);
};*/

struct DLList
{
    struct Node
    {
        int data;
        Node *next;
        Node *prev;
    };
    Node *F = NULL;
    Node *L = NULL;
    Node *C = NULL;
    int Count;
    void out();
    void Info();
    void Clear();

    bool MoveNext();
    bool MovePrev();
    bool MoveFirst();
    bool MoveLast();

    bool Init(int);
    bool AddNext(int);
    bool AddPrev(int);
    bool AddFirst(int);
    bool AddLast(int);

    bool Del(int&);
    bool DelNext(int&);
    bool DelPrev(int&);
    bool DelFirst(int&);
    bool DelLast(int&);

    //void deletion(Cars&);
};

void DLList::out(){
    if (!F)
    {
        cout<<"List is empty"<<endl;
        return;
    }
    Node* temp=F;
    cout<<"List: ";
    do{
        cout<<temp->data<<" ";
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
        cout << "Current node data = " << C->data << endl;
    }
}
bool DLList::MoveFirst()
{
    if(!F) return false;
    if(!L) C=F;
    return true;
}
bool DLList::MoveLast()
{
    if(!L) return false;
    C=L;
    return true;
}
bool DLList::MoveNext()
{
    if(!F) return false;
    if(!C) {C=F; return true;}
    if(!C->next) return false;
    C=C->next;
    return true;
}
bool DLList::MovePrev()
{
    if(!F) return false;
    if(!C) {C=F; return true;}
    if(!C->prev) return false;
    C=C->prev;
    return true;
}
bool DLList::Init(int data)
{
    if(!F)
    {
        F=new Node;
        L=F;
        C=F;
        F->prev=NULL;
        F->next=NULL;
        F->data=data;
        Count=1;
        return true;
    }
    else
        return false;
}
bool DLList::AddNext(int data)
{
    if (!F) return Init(data);
    Node* temp=C->next;
    C->next=new Node;
    C->next->next=temp;
    C->next->prev=C;
    if(!temp) L=C->next;
    else temp->prev=C->next;
    C=C->next;
    C->data=data;
    Count++;
    return true;
}
bool DLList::AddPrev(int data)
{
    if (!F) return Init(data);
    Node* temp=C->prev;
    C->next=new Node;
    C->prev->next=temp;
    C->prev->prev=C;
    if(!temp) F=C->prev;
    else temp->next=C->prev;
    C=C->prev;
    C->data=data;
    Count++;
    return true;
}
bool DLList::AddFirst(int data)
{
    if (MoveFirst()) return AddPrev(data);
    else return Init(data);
}
bool DLList::AddLast(int data)
{
    if (MoveLast()) return AddNext(data);
    else return Init(data);
}
bool DLList::DelFirst(int &data)
{
    if (!F) return false;
    if (C!=F) MoveFirst();
    Node* temp=C->next;
    data =C->data;
    if(!temp) temp->prev=NULL;
    delete C;
    C=temp;
    F=temp;
    Count--;
    if(!temp){L=NULL; return true;}
    return true;
}
bool DLList::DelLast(int &data)
{
    if (!F) return false;
    if (C!=L) MoveLast();
    Node* temp=C->prev;
    data =C->data;
    if(!temp) temp->next=NULL;
    delete C;
    C=temp;
    L=temp;
    Count--;
    if(!temp){F=NULL; return true;}
    return true;
}
bool DLList::Del(int &data)
{
    if (!F) return false;
    if (!C) return false;
    if (C==F) return DelFirst(data);
    if (C==L) return DelLast(data);
    Node* temp=C->next;
    data =C->data;
    C->prev->next=C->next;
    C->next->prev=C->prev;
    delete C;
    C=temp;
    Count--;
    return true;
}
bool DLList::DelNext(int &data)
{
    if (!F) return false;
    if (!C) return false;
    if(MoveNext()) return Del(data);
    return false;
}
bool DLList::DelPrev(int &data)
{
    if (!F) return false;
    if (!C) return false;
    if(MovePrev()) return Del(data);
    return false;
}
void DLList::Clear()
{
    if(!MoveFirst())
    {
        cout<<"List is empty"<<endl;
        return;
    }
    int k;
    while(Del(k));
}
int main()
{
    DLList MyList;
    MyList.out();
    for (int i=1;i<10;i++)
        MyList.AddNext(i);
    MyList.out();
    return 0;
}
