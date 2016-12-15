/*
 * Copyright (C) 
 *
 * USER claviering 
 *
 * DATE 2016-12-15
 *
 * Distributed under terms of the WTFPL license.
 */

#include <iostream>
#include "AVLTree.h"
using namespace std;

int main()
{
    AVLTree<int> tree;
    for (int i = 0; i < 20; i++)
        tree.insert(i);

    bool is_find = tree.Find(80);
    if (is_find)
        cout << "TRUE" << endl;
    else
        cout << "FALSE" << endl;
    return 0;
}
