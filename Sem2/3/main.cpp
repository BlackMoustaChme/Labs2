#include <iostream>
#include <fstream>
#include <string>
#include <dos.h>
using namespace std;

struct Cars{
    int Price, ReleaseDate, HP, Seats;
    string color,brand,ToWD;
    void out();
    bool IsEqual(Cars);
};

struct MyStack
{
    struct Node
    {
        Cars data;
        Node *prev;
    };
    Node *Top = NULL;
    int Count;
    bool Push(Cars);
    bool Pop(Cars&);
    void Info();
    void deletion(Cars&);
};

void Cars::out(){
    cout<<" Brand: "<<brand<<endl<<" Type of Wheel Drive: "<<ToWD<<endl<<" Horse Power: "<<HP<<endl<<" Seats capacity: "<<Seats<<endl<<" Color: "<<
        color<<endl<<" Price: "<<Price<<endl<<" Release date: "<<ReleaseDate<<endl;
}

bool Cars::IsEqual(Cars a){
    if(a.brand==brand&&a.ToWD==ToWD&&a.HP==HP&&a.Seats==Seats&&a.color==color&&a.Price==Price&&a.ReleaseDate==ReleaseDate) return true;
    return false;
}

bool MyStack::Push(Cars data)
{
    if(!Top)
    {
        Top = new Node;
        Top -> prev = NULL;
        Count = 1;
    }
    else
    {
        Node *temp;
        temp = new Node;
        temp -> prev = Top;
        Top = temp;
        Count++;
    }
    Top -> data = data;
    return true;
}
bool MyStack::Pop(Cars &data)
{
    if(!Top) return false;
    Node *temp = Top -> prev;
    data = Top -> data;
    delete Top;
    Top = temp;
    Count--;
    return true;
}
void MyStack::Info()
{
    if(!Top) cout << "Garage (Stack) is empty" << endl;
    else
    {
        cout << endl << "\tGarage (Stack) info: " << endl;
        cout << "\tGarage (Stack) size = " << Count << endl;
        Top->data.out();
    }
}

void MyStack::deletion(Cars& k){
    while (Count !=0) Pop(k);
}

struct warehouse {
    double Price;
    int Amount;
    void out();
};

void warehouse::out() {
    cout << "Price: " << Price << " " << "Amount: " << Amount<<endl;
}

struct MyQueue
{
    struct Node
    {
        warehouse data;
        Node* next;
    };
    Node* First = NULL;
    int Count = 0;
    int payment = 0;
    int MinPrice = 0;
    int full = 0;
    bool Push(warehouse);
    bool Pop(warehouse&);
    void Info();
};
bool MyQueue::Push(warehouse data)
{
    if (!First)
    {
        First = new Node;
        First->next = NULL;
        First->data = data;
        Count = 1;
        MinPrice=First->data.Price;
    }
    else
    {
        Node* temp;
        temp = First;
        while (temp->next != NULL) temp = temp->next;
        temp->next = new Node;
        temp->next->data = data;
        temp->next->next = NULL;
        Count++;
        if (MinPrice<First->data.Price) MinPrice=First->data.Price;
    }
    return true;
}
bool MyQueue::Pop(warehouse& data)
{
    if (!First) return false;
    Node* temp = First->next;
    data = First->data;
    delete First;
    First = temp;
    Count--;
    return true;
}
void MyQueue::Info()
{
    if (!First) cout << "Queue is empty" << endl;
    else
    {
        cout << endl << "Queue info: " << endl;
        cout << "\tQueue size = " << Count << endl;
        First->data.out();
    }
}

void menu(MyQueue q);

void read(MyStack&,string);
void FindCr(MyStack&,Cars);
void Add(MyStack&, Cars);
void Search(MyStack&, Cars);
void AddPr(MyQueue& , warehouse& , double&, int& );
void Sell(MyQueue& , warehouse& , double& , int& );
void MenuG();
void MenuW();
void Menu();

int main()
{
    Menu();
    //S.deletion(k);
    return 0;

}

void Menu()
{
    int key;

    do {
        cout<<endl;
        cout<<"Chrnsv: LVL 238: Securo Serv - Boss"<<endl;
        cout<<"1 - Go to Garage (St) "<<endl;
        cout<<"2 - Go to Office (Q)"<<endl;
        cout<<"0 - Exit"<<endl;

        cout << "Choose what to do and enter the key " << endl;
        cin >> key;

        switch (key) {
            case 1:
                MenuG();
                break;
            case 2:
                MenuW();
                break;
            case 0:
                cout << "Bye:)" << endl;
                return;
            default:
                cout << "--->Error, try again... " << endl;
        }
    } while (key);
}

void MenuG()
{
    Cars k;
    Cars find;
    MyStack S;
    //char* color;
    //int price;
    read(S,"Cars.txt");
    int key;

    do {
        cout<<endl;
        cout<<"-------Menu-------"<<endl;
        cout<<"1 - Show info about Garage(Stack:)) and top Car "<<endl;
        cout<<"2 - Add new Car"<<endl;
        cout<<"3 - Find Car and Take it (delete)"<<endl;
        cout<<"4 - Delete all"<<endl;
        cout<<"0 - Exit"<<endl;

        cout << "Choose what to do and enter the key " << endl;
        cin >> key;

        switch (key) {
            case 1:
                S.Info();
                break;
            case 2:
                Add(S,k);
                break;
            case 3:
                Search(S,find);
                break;
            case 4:
                S.deletion(k);
                break;
            case 0:
                S.deletion(k);
                cout << "Bye:)" << endl;
                return;
            default:
                cout << "--->Error, try again... " << endl;
        }
    } while (key);
}

void Add(MyStack& S, Cars k)
{
    cout<<"Enter Brand: ";cin>>k.brand;
    cout<<"Enter Type of Wheel Drive:: ";cin>>k.ToWD;
    cout<<"Enter Horse Power: ";cin>>k.HP;
    cout<<"Enter Seats capacity: ";cin>>k.Seats;
    cout<<"Enter Color: ";cin>>k.color;
    cout<<"Enter Price: ";cin>>k.Price;
    cout<<"Enter Release date (Year): ";cin>>k.ReleaseDate;
    S.Push(k);
}
void Search(MyStack& S, Cars find)
{
    cout<<"Find:"<<endl;
    cout<<"Which Brand: ";cin>>find.brand;
    cout<<"Which Type of Wheel Drive:: ";cin>>find.ToWD;
    cout<<"Which Horse Power: ";cin>>find.HP;
    cout<<"Which Seats capacity: ";cin>>find.Seats;
    cout<<"Which Color: ";cin>>find.color;
    cout<<"Which Price: ";cin>>find.Price;
    cout<<"Which Release date (Year): ";cin>>find.ReleaseDate;
    FindCr(S,find);
}

void read(MyStack& S,string FileName){
    ifstream F(FileName);
    if (!F){ cout<<"Error";
        return;
    }
    Cars cr;
    while(F>>cr.brand>>cr.ToWD>>cr.HP>>cr.Seats>>cr.color>>cr.Price>>cr.ReleaseDate) S.Push(cr);
    F.close();
}

void FindCr(MyStack& S,Cars find){
    Cars cr;
    MyStack second;
    while(S.Count != 0&&!(S.Top->data.IsEqual(find))){
        S.Pop(cr);
        second.Push(cr);
    }
    if(S.Count!=0){
        cout<<"Car is found"<<endl;
        S.Pop(cr);
    }
    else cout<<"Car is not found"<<endl;
    while(second.Pop(cr)) S.Push(cr);
}

void MenuW()
{
    cout<<endl;
    cout<<"Warehouse Management System"<<endl;
    cout<<endl;_sleep(500);
    cout<<"Login:Chrnsv"<<endl;
    cout<<endl;_sleep(500);
    cout<<"Password:*******"<<endl;
    cout<<endl;
    _sleep(500);
    MyQueue Q;
    warehouse Ctop;
    warehouse a;
    double pr;
    int am;
    int key;

    do {
        _sleep(500);
        cout<<"-------Menu-------"<<endl;
        cout << "1 - Add new product" << endl;
        cout << "2 - Sell product" << endl;
        cout << "3 - Report" << endl;
        cout << "0 - Exit" << endl;

        cout << "Choose what to do and enter the key " << endl;
        cin >> key;

        switch (key) {
            case 1:
                AddPr(Q,a,pr,am);
                break;
            case 2:
                Sell(Q,a,pr,am);
                break;
            case 3:
                Q.Info();
                cout << "Payment: " << Q.payment << endl;
                cout << "Full: " << Q.full << endl;;
                break;
            case 0:
                cout << "Bye:)" << endl;
                return;
            default:
                cout << "--->Error, try again... " << endl;
        }
    } while (key);
    while (Q.Pop(a));
}

void AddPr(MyQueue& q, warehouse& a, double& pr, int& am)
{
    cout << "Enter Price: "; cin >> pr;
    cout << "Enter Amount: "; cin >> am;
    a.Price = pr;
    a.Amount = am;
    q.Push(a);
    q.full+=am;
}
void Sell(MyQueue& q, warehouse& a, double& pr, int& am)
{
    cout<<"Enter Price: ";cin>>pr;
    cout<<"Enter Amount: ";cin>>am;
    while(am!=0)
    {
        if(q.MinPrice>pr)
        {
            cout<<"WARNING--Too cheap--WARNING"<<endl;
            break;
        }
        if(q.full<am) {
            cout << "WARNING--AMOUNT IS TOO BIG--WARNING" << endl;
            break;
        }
        if(am<q.First->data.Amount&&q.First->data.Price<=pr)
        {
            q.First->data.Amount-=am;
            q.payment += am * (pr - q.First->data.Price);
            q.full -= am;
            am=0;
        }
        else
            {
            am-=q.First->data.Amount;
            q.payment += q.First->data.Amount * (pr - q.First->data.Price);
            q.full -= q.First->data.Amount;
            q.First->data.Amount=0;
        }
        if (q.First->data.Amount==0)
        {
            q.Pop(a);
            q.MinPrice=q.First->data.Price;
        }
    }
}
