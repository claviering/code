/*
 * Copyright (C) 
 *
 * USER claviering 
 *
 * DATE 2016-11-10
 *
 * Distributed under terms of the WTFPL license.
 */

#include <iostream>
using namespace std;

template<typename T>
TreeNode<T> *ChangeArratToTree(int ar[],int i)
{
    TreeNode<T> *p_root = new <TreeNode<T>();

    if (i > ar.lenght)
        return 0;
    p_root -> data = ar[i];
    p_root -> p_left = ChangeArratToTree(ar,2 * i + 1);
    p_root -> p_right = ChangeArratToTree(ar,2 * i + 2);
    return p_root;
}
int main()
{
    
    return 0;
}
