/*
 * 主函数
 * @Author lin wei ye
 */
#include "slist.h"
#include "student.h"

#include <iostream>
using namespace std;

    /*
     *功能选择函数
     *@param object 链表对象
     *@param n 功能选择序号
     */
template<typename T>
void choose(Mylist<T> &object)
{
    cout << "1.初始化(删除全部节点)" << endl 
         << "2.头插入建链(输入节点个数和每个数据)" << endl 
         << "3.尾插入建链" << endl 
         << "4.插入" << endl 
         << "5.删除" << endl 
         << "6.查找" << endl 
         << "7.输出表长" << endl
         << "8.链表元素逆置" << endl 
         << "9.退出" << endl; 
    cout << "input choose" << endl;
    int n;
    cin >> n;

    if(n == 1) //初始化
    {
        while (object.length())
        {
            SlistNode<T> *tmp_list_node = object.return_headnode_point();
            object.Delete(tmp_list_node -> data);
        }
    }
    else if (n == 2) //头插入建链
    {
        HeadCreatList(object);
        object.traversal();
    }
    else if (n == 3) //尾插入建链
    {
        TailCreatList(object);
        object.traversal();
    }
    else if (n == 4) //插入
    {
        object.traversal();
        InsertLocal_i(object);
        object.traversal();
    }
    else if (n == 5) //删除
    {
        object.traversal();
        DeleteLocal_i(object);
        object.traversal();
    }
    else if (n == 6) //查找
    {
        if (FindLocal_i(object)) 
            cout << "TRUE" << endl;
        else
            cout << "FALSE" << endl;
    }
    else if (n == 7) //输出表长
        cout << "list length is:" << object.length() << endl;
    else if (n == 8) //链表元素的逆置
    {
        object.reverse_list();
        object.traversal();
    }
    else if (n == 9) //退出
        exit(1);
    else 
    {
        cout << "input error" << endl;
        cout << "TRY AGAIN" << endl;
        cin >> n;
        choose(object);
        return;
    }
    choose(object);
}

    /*
     * 头插入函数
     * 输入:1.建链个数
     *      2.输入每个值
     * 输出:输出建链后的序列
     * @param:链表对象
     */
template<typename T>
void HeadCreatList(Mylist<T> &object)
{
    cout << "node numbers" << endl;
    int node_num;
    cin >> node_num; 
    for (int i = 0; i < node_num; i++)
    {
        int data;
        cin >> data;
        object.insertHead(data);
    }
}

    /*
     * 尾插入函数
     * 输入:1.建链个数
     *      2.输入每个值
     * 输出:输出建链后的序列
     * @param:链表对象
     */
template<typename T>
void TailCreatList(Mylist<T> &object)
{
    cout << "node numbers" << endl;
    int node_num;
    cin >> node_num; 
    for (int i = 0; i < node_num; i++)
    {
        int data;
        cin >> data;
        object.add(data);
    }
}

    /*
     * 插入操作
     * 开始位置为0
     * 输入：1.插入位置i
     *       2.插入元素值
     * 输出：1.插入前的序列
     *       2.插入后的序列
     * 
     * @param:链表对象
     */
template<typename T>
void InsertLocal_i(Mylist<T> &object)
{
    cout << "input local i to insert and data (start local is 0)" << endl;
    int i;
    int data;
    cin >> i >> data;
    int list_length = object.length();
    if (i < 0 || i > list_length)
        return;
    SlistNode<T> *tmp_list_node = object.return_headnode_point();
    while (i--)
    {
        tmp_list_node = tmp_list_node-> next;
    }
    object.insert(data, tmp_list_node);
}

    /*
     * 删除操作
     * 开始位置为0
     * 输入: 1.删除位置i
     *
     * 输出: 1.删除前的序列
     *       2.删除后的序列
     *
     * @param:链表对象
     */
template<typename T>
void DeleteLocal_i(Mylist<T> &object)
{
    cout << "input local i (start is 0)" << endl;
    int i;
    cin >> i;
    int list_length = object.length();
    if (i < 0 || i > list_length)
        return;
    SlistNode<T> *tmp_list_node = object.return_headnode_point();
    while (i--)
    {
        tmp_list_node = tmp_list_node -> next;
    }
    object.Delete(tmp_list_node -> data);
}

    /*
     *查找操作
     *输入: 待查找的元素
     *输出: 查找成功与否
     *
     *@param:链表对象
     */
template<typename T>
bool FindLocal_i(Mylist<T> &object)
{
    cout << "input find data" << endl;
    int data;
    cin >> data;
    if (object.find(data) != 0)
        return true;
    else
        return false;
}

int main()
{
     
    Mylist<int> list;
    choose(list);
    return 0;
}

