/*
 * Copyright (C) 
 *
 * USER claviering 
 *
 * DATE 2016-11-24
 *
 * Distributed under terms of the WTFPL license.
 */

#include <iostream>
#include "tree.h"
#include <stdlib.h>
using namespace std;

/*
 * 输出选择菜单
 * 
 */
void ShowMenu()
{
    cout << "1.建立一棵二叉树" << endl 
         << "2.前序遍历递归算法" << endl 
         << "3.前序遍历非递归算法" << endl 
         << "4.中序遍历递归算法" << endl 
         << "5.中序遍历非递归算法" << endl 
         << "6.后序遍历递归算法" << endl 
         << "7.后序遍历非递归算法" << endl
         << "8.求树高" << endl 
         << "9.求叶子总数" << endl 
         << "10.输出二叉树" << endl 
         << "11.交换左右子树" << endl 
         << "12.退出" << endl; 
    cout << "input choose" << endl;

}
/*
 * 功能选择函数
 * @param 
 */
template<typename T>
void choose(Tree<T> &object)
{
    ShowMenu();
    int n;
    cin >> n;
    switch(n)
    {
        case 1:
            cout << "input data end with -1" << endl;
            object.Creat();
            break;
        case 2:
            object.PreOrderVisit(object.GetRoot());
            break;
        case 3:
            object.PreOrderUnRec(object.GetRoot());
            break;
        case 4:
            object.InOrderVisit(object.GetRoot());
            break;
        case 5:
            object.InOrderUnRec(object.GetRoot());
            break;
        case 6:
            object.PostOrderVisit(object.GetRoot());
            break;
        case 7:
            object.PostOrderVisitUnRec(object.GetRoot());
            break;
        case 8:
            
            cout << "depth is " << object.CalcDepth(object.GetRoot()) << endl;
            break;
        case 9:
            cout << "size is " << object.CalcSize(object.GetRoot()) << endl;
            break;
        case 10:
            object.DisplayTree();
            break;
        case 11:
            object.ChangeLeftRight(object.GetRoot());
            break;
        case 12:
            exit(0);
            break;
    }
}

int main()
{
    Tree<int> my_tree;
    while (1)
        choose(my_tree);
    return 0;
}
