#include <iostream>
#include <fstream>
#include <string>
using namespace std;




struct  Bunny {
    string name;
    double weight;
    int age;
    bool hunger;
    void out();
};

void Bunny::out() {
    cout << "Weight: " <<weight <<endl<< " " << "Age: " << age<<endl<< "Name: " << name <<endl<< "Hungry?: " << hunger <<endl;
}

struct MyQueue
{
    struct Node
    {
        //Bunny data;
        char* data;
        int n;
        Node* next;
    };
    Node* First = NULL;
    int Count;

    bool Push(char* data, int n);
    bool Pop(char*& data, int& n);
    void Info();
};
bool MyQueue::Push( char* data, int n)
{
    if (!First)
    {
        First = new Node;
        First->next = NULL;
        First->data = new char [n];
        First->n = n;
        for (int i=0;i<n;i++)
        {
            First->data[i] = data[i];
        }
        Count = 1;
    }
    else
    {
        Node* temp;
        temp = First;
        while (temp->next != NULL) temp = temp->next;
        temp->next = new Node;
        temp->next->data =new char [n];
        temp->next->n=n;
        for (int i=0;i<n;i++)
        {
            temp->next->data[i] = data[i];
        }
        temp->next->next = NULL;
        Count++;
    }
    return true;
}
bool MyQueue::Pop(char*& data, int& n)
{
    if (!First) return false;
    Node* temp = First->next;
    //data = First->data;
    n=First->n;
    for(int i=0;i<n;i++)
    {
        data[i]=First->data[i];
    }
    delete First->data;
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
        //First->data.out();
    }
}
void GetDeSeria(char* , int , Bunny& );
void GetSeria(char*& , int &, Bunny );
int main()
{
    Bunny d={"Bun",5.6,3,0};
    Bunny d1;
    d.out();
    int n;
    char* data;
    GetSeria(data,n,d);
    GetDeSeria(data,n,d1);
    d1.out();
    delete[] data;
    return 0;
}
void GetSeria(char*& data, int &n, Bunny A)
{
    size_t s1 = A.name.size();
    int n1_size = sizeof(size_t);
    int n2 = s1;
    int n3 = sizeof(double);
    int n4 = sizeof(int);
    int n5 = sizeof(bool);
    n = n1_size + n2 + n3+ n4 + n5;
    data = new char [n];
    char* d1 = reinterpret_cast<char*> (&s1);
    char* d2 = const_cast<char*> (A.name.c_str());
    char* d3 = reinterpret_cast<char*> (&A.weight);
    char* d4 = reinterpret_cast<char*> (&A.age);
    char* d5 = reinterpret_cast<char*> (&A.hunger);
    for(int i = 0; i <= n1_size; i++) data[i] = d1[i];
    for(int i = 0; i <= n2; i++) data[i + n1_size] = d2[i];
    for(int i = 0; i <= n3; i++) data[i + n1_size + n2] = d3[i];
    for(int i = 0; i <= n4; i++) data[i + n1_size + n2 + n3] = d4[i];
    for(int i = 0; i <= n5; i++) data[i + n1_size + n2 + n3 + n4] = d5[i];
}
void GetDeSeria(char* data, int n, Bunny& A)
{
    int n1_size, n2, n3, n4, n5;
    n1_size = sizeof(size_t);
    n3 = sizeof(double);
    n4 = sizeof(int);
    n5 = sizeof(bool);
    size_t p = *reinterpret_cast<size_t*> (data);
    n2 = p;
    string s1(data + n1_size, p);
    A.name= s1;
    A.weight = *reinterpret_cast<double*> (data + n1_size+n2);
    A.age = *reinterpret_cast<int*> (data + n1_size+n2+n3);
    A.hunger = *reinterpret_cast<bool*> (data + n1_size+n2+n3+n4);
}
/*bool InputBinaryFile(MyQueue &Q)
{
  fstream f_in("out.dat", ios::in | ios::binary);
  if(!f_in)
  {
    return false;
  }
   A;
  int n = 0;
  while(!f_in.eof())
  {
    if(f_in.read((char*) &n, sizeof(int)))
    {
      char* data = new char[n];
      f_in.read(data, n);
      GetDeSeria(data, n, A);
      delete[] data;
      GetSeria(data, n, A);
      Q.Push(data, n);
    }
  }
  f_in.close();
  return true;
}*/

