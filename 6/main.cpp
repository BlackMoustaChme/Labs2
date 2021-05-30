#include <iostream>
#include <fstream>
#include <string>
#include <dos.h>
using namespace std;


struct Tree
{
    int data;
    Tree* left;
    Tree* right;
};
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
/*void Add (Tree*& T, int data)
{
    if(!T)
    {
        T = new Tree;
        T->data = data;
        T->left = NULL;
        T->right = NULL;
        return;
    }
    if (data < T->data)
    {
        Add(T->left, data);
    }
    else
        Add(T->right, data);
}*/
void Add (Tree** T, int data)
{
    if(!(*T))
    {
        *T = new Tree;
        (*T)->data = data;
        (*T)->left = NULL;
        (*T)->right = NULL;
        return;
    }
    if (data < (*T)->data)
    {
        Add(&(*T)->left, data);
        cout<<"Added to left "<<endl;
    }
    else
    {Add(&(*T)->right, data);cout<<"Added to right "<<endl;}
}
void PrintLRR (Tree* T)
{
    if (!T) return;
    PrintLRR (T->left);
    cout<<T->data<<" ";
    PrintLRR (T->right);
}
Tree* Search (Tree*& T, int data)
{
    if (!T) return NULL;

    while (T->data !=data)
    {
        if (data<T->data)
        {
            T=T->left;
        }
        else T=T->right;
        if (!T) break;
    }
    return T;
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

int main ()
{
    int n=5;
    int mas[]={2,5,3,4,1};

    Tree* T=NULL;

    for (int i=0;i<n;i++)
    {
        Add(&T,mas[i]);
    }
    PrintLRR(T);
    cout<<endl;
    cout<<" Tree size = "<<GetTreeSize(T)<<endl;
}
