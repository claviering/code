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
    cout << "1." << endl 
         << "2." << endl 
         << "3." << endl 
         << "4." << endl 
         << "5." << endl 
         << "6." << endl 
         << "7." << endl
         << "8." << endl 
         << "9." << endl 
         << "10." << endl 
         << "11." << endl 
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
            object.CalcDepth(object.GetRoot());
            break;
        case 9:
            object.CalcSize(object.GetRoot());
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
    choose(my_tree);
    return 0;
}
