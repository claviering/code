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

void *ChangeTreeToArray(TreeNode<T>* p_root,int ar[],int i)
{
    ar[i] = p_root -> data;
    ChangeTreeToArray(p_root -> p_left,ar,2 * i + 1);
    ChangeTreeToArray(p_root -> p_right,ar,2 * i + 2);
}
int main()
{
    
    return 0;
}
