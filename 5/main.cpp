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
    //bool IsEqual(Cars);
};

struct DLList
{
    struct Node
    {
        //void* data=(Phone) data
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

    //void deletion(Cars&);
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
    cout<<"List: ";
    do
    {
        temp->data.out();//<<" ";
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
void read(DLList& ,string );
void Add(DLList& , Phone& );
void ToTheTop(DLList& , Phone& );
void ToTheEnd(DLList& , Phone& );
void ToTheCP(DLList& , Phone& );
void FromTheTop(DLList& , Phone& );
void FromTheEnd(DLList& , Phone& );
void FromTheCP(DLList& , Phone& );
void Delt(DLList& , Phone& );
void Sort();
void Updata();
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
    read(MyList,"Phone.txt");
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
                //Sort();
                break;
            case 4:
                MyList.Clear();
                break;
            case 5:
                //Updata();
                break;
            case 6:
                MyList.Info();
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
    //DLList MyList;
    //Phone k;

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
void Delt(DLList& MyList, Phone& k)
{
    //DLList MyList;
    //Phone k;
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
/*void Sort()
{

}
void Updata()
{

}*/
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
/*void writeFile()
{
    if(MyList.Count == 0)
    {
        cout << "Warning! The list is empty." << endl;
    }
    system("clear");
    std::ofstream out("bunnyOut");
    S.MoveFirst();
    for(int i{}; i < S.Count; i++)
    {
        Bunny outData = S.current->data;
        out << outData.name << " " << outData.age << " " << outData.weight << " " << outData.isHungry << endl;
        S.moveNext();
    }
    out.close();
}*/
void read(DLList& MyList,string FileName)
{
    ifstream F(FileName.c_str());
    if (!F){ cout<<"Error";
        return;
    }
    Phone k;
    while(F>>k.brand>>k.color>>k.scrdl>>k.eDRAM>>k.ReleaseDate>>k.Price) MyList.AddNext(k);
    F.close();
}
/*void Bubble (int n)
{
    double c;
    for (int i=0;i<n-1;i++) {
        for (int j = n - 2; j >= i; j--)
            if (A[j] > A[j + 1]) {
                c=A[j];
                A[j]=A[j+1];
                A[j+1]=c;
            }
    }
}*/
/*void Shell (int n)
{
    long long int i,j,k,s;
    double x;
    for (k=steps(n);k>=0;k--)
    {
        s=S[k];
        for(i=s;i<n;i++)
        {
            x=A[i];
            for(j=i-s; (j>=0) && (x<A[j]);j=j-s) A[j+s]=A[j];
            A[j+s]=x;
        }
    }
}
int steps (int N)
{
    int i=-1;
    do
    {
        i++;
        if(i%2==0){S[i]=9*pow(2,i)-9*pow(2,i/2)+1;}
        else S[i]=8*pow(2,i)-6*pow(2,(i+1)/2)+1;
    }
    while (3*S[i]<N);
    return i-1;
}*/
