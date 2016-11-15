/*
 * Copyright (C) 
 *
 * USER claviering 
 *
 * DATE 2016-11-10
 *
 * Distributed under terms of the WTFPL license.
 */

#include "Tree.h"
#include <iostream>
using namespace std;

TreeNode *ChangeArratToTree(int ar[],int i,int lenght)
{
    TreeNode *p_root = new TreeNode;

    if (i >= lenght)
        return 0;
    p_root -> data = ar[i];
    p_root -> lson_ = ChangeArratToTree(ar,2 * i + 1,lenght);
    p_root -> rson_ = ChangeArratToTree(ar,2 * i + 2,lenght);
    return p_root;
}

int main()
{
    int ar[] = {1,2,3,4,5,6,9};
    int lenght = 7;
    TreeNode *root = ChangeArratToTree(ar,0,lenght);
    Tree t;
    t.DisplayInOrder(root);
    return 0;
}
