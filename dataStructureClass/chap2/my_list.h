/**********************************************************************
	> File Name: my_list.h
	> Author:lin wei ye 
	> Mail: 
	> Created Time: Sun 02 Oct 2016 02:22:46 PM CST
 *********************************************************************/
/*
 *链表头文件
 *              
 *方法：
 * MyList(); 构造函数
 * int length(); 返回链表长度
 * void add_node(int x); 添加一个节点，参数x是整数，返回空
 * void add_node_head(int x); 头插入
 * void init_list(int number_of_node); 初始化一条链，0->1->2->...
 * void delete_node(int x); 删除一个节点
 * void display_my_list(); 输出链
 * MyList reverse_list(); 逆转链表

 *属性：
 * 链表长度 list_length
 * 链头指针 *head_node
 * 链尾指针 *last_node
 * 辅助指针 *node
 *
 *
 */           
#ifndef _MY_LIST_H
#define _MY_LIST_H
#endif
#include <iostream>
using namespace std;

class ListNode
{
    public:
        ListNode()
        {
            next = NULL;
        }
        int data;
        ListNode *next;
};

class MyList
{
    public:
        MyList();
        int length();
        void add_node(int x);
        void add_node_head(int x);
        void init_list(int number_of_node);
        void delete_node(int x);
        void display_my_list();
        MyList reverse_list();
    private:
        int list_length;
        ListNode *node;
        ListNode *last_node;
        ListNode *head_node;
    
};

MyList MyList::reverse_list()
{
    MyList new_list;
    node = head_node;
    while (head_node != NULL)
    {
        new_list.add_node_head(head_node -> data);
        head_node = node -> next;
        delete node;
        node = head_node;
    }
    return new_list;
}

//O(n)
void MyList::display_my_list()
{
    node = head_node;
    while (node -> next != NULL)
    {
        cout << node -> data << " ";
        node = node -> next;
    }
    cout << node -> data << endl;;

}
void MyList::init_list(int number_of_node)
{
    for (int i = 0; i < number_of_node; i++)
        add_node(i);
}

MyList::MyList()
{
    node = NULL;
    last_node = NULL;
    head_node = NULL;
    list_length = 0;
}

void MyList::add_node_head(int x)
{
    node = new ListNode;
    node -> data = x;
    if (last_node == NULL)
    {
        head_node = node;
        last_node = node;
    }
    else
    {
        node -> next = head_node;
        head_node = node;        
    }
    ++list_length;
}

void MyList::add_node(int x)
{
    node = new ListNode;
    node -> data = x;
    if (last_node == NULL)
    {
        head_node = node;
        last_node = node;
    }
    else
    {
        last_node -> next = node;
        last_node = node;
    }
    ++list_length;
}

void MyList::delete_node(int x)
{
    ListNode *tmp = head_node;
    if (tmp == NULL)
        return;
    if (tmp -> data == x)
    {
        head_node = tmp -> next;
        if (tmp -> next == NULL)
            last_node = NULL;
        delete tmp;
        return;
    }

    while (tmp -> next != NULL && tmp -> next -> data != x)
    {
        tmp = tmp -> next;
    }

    if (tmp -> next == NULL)
        return;
    
    if (tmp -> next == last_node)
    {
        last_node = tmp;
        delete (tmp -> next);
        tmp -> next = NULL;
    }
    else
    {
        node = tmp -> next;
        tmp -> next = node -> next;
        delete  node;
        node = NULL;
    }
}
