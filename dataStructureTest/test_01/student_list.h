/*
 * @version 1.0.0
 * @File Name: student.h
 * @Author: claviering
 * @Complete Time: Wed Oct 19 20:28:07 CST 2016
 * 
 * @接口说明：
 *     unsigned int length() 返回链表长度
 *
 *     void add(T x) 尾插入x到链表
 *     @param 数值x
 *
 *     void traversal() 遍历链表，输出数据到控制台
 *
 *     bool isEmpty() 返回bool类型
 *
 *     StudentNode *find(T x) 按学号查找x返回指向x的指针
 *     @param 数值x
 *     @return node
 *
 *     void Delete(T x) 按学号查找没有返回值
 *     @param x 数值x
 *
 *     void insert(T x, StudentNode<T> *p) 在节点*P的后面插入一个节点x,可以做为尾插入
 *     @param x 数值x
 *     @param *p 插入前节点的指针
 *
 *     void insertHead(T x) 头插入
 *     @param 数值x
 *
 *     void reverse_list() 链表的逆置
 *
 *     return_headnode_point() //返回链表头指针
 * 
 *     StudentNode<T> *Findlocation(int x); //返回位置x的指针
 *     *@param x 位置x,x为整数
 *
 *     void SortList(); //链表排序
 *
 * @属性说明：
 *     Student stu
 *     list_length
 *     *node 辅助节点
 *     *lastnode 头节点
 *     *headnode 尾节点
 */
#ifndef _SLIST_H_
#define _SLIST_H_

    #include <cstdlib>
    #include <cstring>
    #include <iostream>
    #include "student.h"
    
    using namespace std;
    
    template<typename T>
    class StudentNode
    {
        public:
            StudentNode()
            {
                next = NULL;
            }
            T data;
            StudentNode *next;
    };

    template<typename T>
    class StudentList
    {
        private:
            T stu;
            unsigned int list_length;
            StudentNode<T> *node;
            StudentNode<T> *lastnode;
            StudentNode<T> *headnode;
        public:
            StudentList();
            unsigned int length();
            void add(T x);
            void traversal();
            bool isEmpty();
            StudentNode<T> *find(T x);
            void Delete(T x);
            void insert(T x,StudentNode<T> *p);
            void insertHead(T x);
            void reverse_list();
            void SortList();
            StudentNode<T> *return_headnode_point();
            StudentNode<T> *Findlocation(int x);
    };

    template<typename T>
    unsigned int StudentList<T> :: length()
    {
        return list_length;
    }

    template<typename T>
    StudentNode<T> *StudentList<T> :: return_headnode_point()
    {
        return headnode;
    }

    template<typename T>
    StudentList<T> :: StudentList()
    {
        node = NULL;
        lastnode = NULL;
        headnode = NULL;
        list_length = 0;
    }

    /*
     * 尾插入
     * T 是 Student
     * x 是Student的一个对象
     */
    template<typename T>
    void StudentList<T> :: add(T x)
    { 
        node = new StudentNode<T>(); 
        node -> data.number_ = x.number_;
        strncpy(node -> data.name_, x.name_, 256);
        strncpy(node -> data.birthday_, x.birthday_, 256);
        strncpy(node -> data.sex_, x.sex_, 256);
        strncpy(node -> data.condition_, x.condition_, 256);
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
        ++list_length;
    }

    template<typename T>
    void StudentList<T> :: traversal()
    {
        node = headnode;
        while (node != NULL)
        {
            cout << node -> data.number_ << " " << node -> data.name_ << " " << node -> data.birthday_ << " " << node -> data.sex_ << " " << node -> data.condition_ << " " << endl;
            node = node -> next;
        }
        cout << endl;
    }

    template<typename T>
    bool StudentList<T> :: isEmpty()
    {
        return list_length == 0;
    }

    template<typename T>
    StudentNode<T> *StudentList<T> :: find(T x)
    {
        node = headnode;
        while (node != NULL && node -> data.number_ != x.number_)
        {
            node = node -> next;
        }
        return node;
    }

    template<typename T>
    void StudentList<T> :: Delete(T x)
    {
        StudentNode<T> *temp = headnode;
        if (temp == NULL)   
            return;
        if (temp -> data.number_ == x.number_)
        {
            headnode = temp -> next;
            if (temp -> next == NULL)
                lastnode = NULL;
            delete(temp);
            --list_length;
            return;
        }
        while (temp -> next != NULL && temp -> next -> data.number_ != x.number_)
        {
            temp = temp -> next;
        }
        if (temp -> next == NULL) 
            return;
        if (temp -> next == lastnode)
        {
            lastnode = temp;
            delete (temp -> next);
            --list_length;
            temp -> next = NULL;
        }
        else
        {
            node = temp -> next;
            temp -> next = node -> next;
            delete (node);
            --list_length;
            node = NULL;
        }
    }

    template<typename T>
    void StudentList<T> :: insert(T x,StudentNode<T> *p)
    {
        if (p == NULL)
            return;
        node = new StudentNode<T>();
        node -> data.number_ = x.number_;
        strncpy(node -> data.name_, x.name_, 256);
        strncpy(node -> data.birthday_, x.birthday_, 256);
        strncpy(node -> data.sex_, x.sex_, 256);
        strncpy(node -> data.condition_, x.condition_, 256);
        node -> next = p -> next;
        p -> next = node;
        if (node -> next == NULL)
            lastnode == node;
        list_length++;
    }

    template<typename T>
    void StudentList<T> :: insertHead(T x)
    {
        node = new StudentNode<T>();
        node -> data.number_ = x.number_;
        strncpy(node -> data.name_, x.name_, 256);
        strncpy(node -> data.birthday_, x.birthday_, 256);
        strncpy(node -> data.sex_, x.sex_, 256);
        strncpy(node -> data.condition_, x.condition_, 256);
        node -> next = headnode;
        headnode = node;
        list_length++;
    }

    /*
     *逆置
     *改变头尾指针和指针方向
     */
    template<typename T>
    void StudentList<T> :: reverse_list()
    {
        if (headnode == NULL || headnode -> next == NULL)
            return;

        StudentNode<T> *tmp_node = new StudentNode<T>;
        node = headnode;
        tmp_node = headnode -> next;
        lastnode = headnode;
        while (tmp_node != NULL)
        {
            headnode = tmp_node;
            tmp_node = tmp_node -> next;
            headnode -> next = node;
            node = headnode;
        }
        lastnode -> next = NULL;
        delete tmp_node;
    }

    /*
     *返回位置x的指针
     *@param x 位置x,x为整数
     */
    template<typename T>
    StudentNode<T> *StudentList<T> :: Findlocation(int x)
    {
        if (x < 0)
            return 0;
        node = headnode;
        while (x--)
        {
            node = node -> next;    
        }
        return node;
    }

    template<typename T>
    void StudentList<T> :: SortList()
    {
        StudentNode<T> *move_node = new StudentNode<T>();
        move_node = headnode -> next;
        node = headnode;
        int length = list_length;

        while (length--)
        {
            while (move_node != NULL)
            {
                if (node -> data.number_ > move_node -> data.number_)
                {
                    Student tmp_data;
                    tmp_data = node -> data;
                    node -> data = move_node -> data;
                    move_node -> data = tmp_data;
                }

                node = node -> next;
                move_node = move_node -> next;
            }
        }

    }

#endif 
