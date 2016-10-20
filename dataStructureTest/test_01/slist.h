/*
 * @version 1.0.0
 * @File Name: slist.h
 * @Author: claviering
 * @Complete Time: Wed Oct 19 20:28:07 CST 2016
 * 
 * @接口说明：
 * unsigned int length() 返回链表长度
 * void add(T x) 尾插入x到链表
 * @param 数值x
 * void traversal() 遍历链表，输出数据到控制台
 * bool isEmpty() 返回bool类型
 * SlistNode *find(T x) 查找x返回指向x的指针
 * @param 数值x
 * void Delete(T x) 没有返回值
 * @param x 数值x
 * void insert(T x, SlistNode<T> *p) 在节点*P的后面插入一个节点x,可以做为尾插入
 * @param x 数值x
 * @param *p 插入前节点的指针
 * void insertHead(T x) 头插入
 * @param 数值x
 * void reverse_list() 链表的逆置
 * return_headnode_point() //返回链表头指针
 *
 * @属性说明：
 * listlength
 * *node 辅助节点
 * *lastnode 头节点
 * *headnode 尾节点
 */
#ifndef _SLIST_H_
#define _SLIST_H_

    #include <cstdlib>
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
            void reverse_list();
            SlistNode<T> *return_headnode_point();
    };

    template<typename T>
    unsigned int Mylist<T> :: length()
    {
        return listlength;
    }

    template<typename T>
    SlistNode<T> *Mylist<T> :: return_headnode_point()
    {
        return headnode;
    }

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
        node -> next = NULL;
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
        if (temp -> data == x)
        {
            headnode = temp -> next;
            if (temp -> next == NULL)
                lastnode = NULL;
            delete(temp);
            --listlength;
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
            delete (temp -> next);
            --listlength;
            temp -> next = NULL;
        }
        else
        {
            node = temp -> next;
            temp -> next = node -> next;
            delete (node);
            --listlength;
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
        listlength++;
    }
    template<typename T>
    void Mylist<T> :: insertHead(T x)
    {
        node = new SlistNode<T>();
        node -> data = x;
        node -> next = headnode;
        headnode = node;
        listlength++;
    }

    template<typename T>
    void Mylist<T> :: reverse_list()
    {
        if (headnode == NULL)
            return;

        SlistNode<T> tmp_node = new SlistNode<T>();
        lastnode = headnode;
        while (headnode -> next != NULL)
        {
            node = headnode;
            headnode = headnode -> next;
            tmp_node = headnode -> next;
            headnode -> next = node;
        }
        delete tmp_node;
        delete node;
    }

#endif 
