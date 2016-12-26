/*
 * list.h
 * Copyright (C) 2016 claviering <claviering@sunn>
 *
 * Distributed under terms of the WTFPL license.
 */

#ifndef _LIST_H_
#define _LIST_H_

#include <iostream>
using namespace std;

template<typename T>
class SlistNode
{
    public:
        SlistNode()
        {
            next = NULL;
        }
        T data;
         SlistNode *next;
};

template<typename T>
class Mylist
{
    private:
        unsigned int listlength;
        SlistNode<T> *node;
        SlistNode<T> *lastnode;
        SlistNode<T> *headnode;
    public:
        Mylist();
        unsigned int length();
        void add(T x);
        void traversal();
        bool isEmpty();
        SlistNode<T> *find(T x);
        void Delete(T x);
        void insert(T x,SlistNode<T> *p);
        void insertHead(T x);
};
template<typename T>
Mylist<T> :: Mylist()
{
    node = NULL;
    lastnode = NULL;
    headnode = NULL;
    listlength = 0;
}
template<typename T>
void Mylist<T> :: add(T x)
{ 
    node = new SlistNode<T>(); 
    node -> data = x;
    if (lastnode == NULL)
    {
        headnode = node;
        lastnode = node;
    }
    else
    {
        lastnode->next = node;
        lastnode = node;
    }
    ++listlength;
}

template<typename T>
void Mylist<T> :: traversal()
{
    node = headnode;
    while (node != NULL)
    {
        cout << node -> data << endl;
        node = node -> next;
    }
    cout << endl;
}

template<typename T>
bool Mylist<T> :: isEmpty()
{
    return listlength == 0;
}

template<typename T>
SlistNode<T> *Mylist<T> :: find(T x)
{
    node = headnode;
    while (node != NULL && node -> data != x)
    {
        node = node -> next;
    }
    return node;
}

template<typename T>
void Mylist<T> :: Delete(T x)
{
    SlistNode<T> *temp = headnode;
    if (temp == NULL)   
        return;
    if (temp -> date == x)
    {
        headnode = temp -> next;
        if (temp -> next == NULL)
            lastnode = NULL;
        delete(temp);
        return;
    }
    while (temp -> next != NULL && temp -> next -> data != x)
    {
        temp = temp -> next;
    }
    if (temp -> next == NULL) 
        return;
    if (temp -> next == lastnode)
    {
        lastnode = temp;
        delete (temp -> nextla);
        temp -> next = NULL;
    }
    else
    {
        node = temp -> next;
        temp -> next = node -> next;
        delete (node);
        node = NULL;
    }
}

template<typename T>
void Mylist<T> :: insert(T x,SlistNode<T> *p)
{
    if (p == NULL)
        return;
    node = new SlistNode<T>();
    node -> data = x;
    node -> next = p -> next;
    p -> next = node;
    if (node -> next == NULL)
        lastnode == node;
}

template<typename T>
void Mylist<T> :: insertHead(T x)
{
    node = new SlistNode<T>();
    node -> data = x;
    node -> next = headnode;
    headnode = node;
}

#endif /* !LIST_H */
