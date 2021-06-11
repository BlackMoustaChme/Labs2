#include <iostream>
#define _USE_MATH_DEFINES
#include <cmath>
#include <math.h>
#include <ctime>
#include <fstream>
#include <algorithm>
#include <iomanip>

struct MyQueue
{
    struct Node {
        int val, cost;
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
void NewMatr(double **& , int , int );
bool GetFileMatr(double ** , int , int , const char* );


int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}


void NewMatr (double **& M, int n, int m)
{
    cout<<"\t -New double Matr-"<<endl;
    M=new double* [n];
    for (int i=0;i<n;i++)
    {
        M[i]=new double [m];
    }
}
bool GetFileMatr (double ** M, int n, int m, const char* name)
{
    ifstream f(name);
    if (!f)
    {
        cout<<"--->Error, no input file"<<endl;
        return false;
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(!(f>>M[i][j]))
            {
                cout<<"--->Error, the file data is not enough"<<endl;
                f.close();
                return false;
            }
        }
    }
    f.close();
    return true;
}