#ifndef INC_3_DLLIST_H
#define INC_3_DLLIST_H

#include "Datetime.h"

class DLList
{
public:

    class Node
    {
    public:
        Datetime data;
        Node *next;
        Node *prev;
    };
    Node *F = NULL;
    Node *L = NULL;
    Node *C = NULL;
    int Count;
    void Out();//UI
    void Info();//UI
    void Clear();

    bool MoveNext();
    bool MovePrev();
    bool MoveFirst();
    bool MoveLast();

    bool Init(Datetime);
    bool AddNext(Datetime);
    bool AddPrev(Datetime);
    bool AddFirst(Datetime);
    bool AddLast(Datetime);

    bool Del(Datetime&);
    bool DelNext(Datetime&);
    bool DelPrev(Datetime&);
    bool DelFirst(Datetime&);
    bool DelLast(Datetime&);

};

#endif //INC_3_DLLIST_H
