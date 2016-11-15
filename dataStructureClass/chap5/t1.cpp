/*
 * t1.cpp
 * Copyright (C) 2016 sunn <sunn@sunn>
 *
 * Distributed under terms of the MIT license.
 */

#include "Tree.h"
#include <iostream>
using namespace std;

void ChangeLeftRight(TreeNode* p_tree)
{
    if (p_tree)
    {
        if (p_tree -> lson_)
            ChangeLeftRight(p_tree -> lson_);
        if (p_tree -> rson_)
            ChangeLeftRight(p_tree -> rson_);

        TreeNode *tmp_p = new TreeNode;
        tmp_p = p_tree -> lson_;
        p_tree -> lson_ = p_tree -> rson_;
        p_tree -> rson_ = tmp_p;
        tmp_p = 0;
        delete tmp_p;
    }
}

int main()
{
    Tree t;
    t.Creat();
    t.DisplayInOrder(t.GetRoot());
    cout << endl;
    ChangeLeftRight(t.GetRoot());
    cout << endl;
    t.DisplayInOrder(t.GetRoot());
    return 0;
}
