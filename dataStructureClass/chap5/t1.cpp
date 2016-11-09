/*
 * t1.cpp
 * Copyright (C) 2016 sunn <sunn@sunn>
 *
 * Distributed under terms of the MIT license.
 */

#include <iostream>
using namespace std;

template<typename T>
void ChangeLeftRight(TreeNode<T>* p_tree)
{
    if (p_tree)
    {
        if (p_tree -> p_left)
            ChangeLeftRight(p_tree -> p_left);
        if (p_tree -> p_right
            ChangeLeftRight(p_tree -> p_right);

        TreeNode<T>* tmp_p = new TreeNode<T>();
        tmp_p = p_tree -> p_left;
        p_tree -> p_left = p_tree -> right;
        p_tree -> p_righ = tmp_p;
        delete tmp_P;
    }
}

int main()
{
    
    return 0;
}
