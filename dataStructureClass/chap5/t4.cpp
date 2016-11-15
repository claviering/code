/*
 * Copyright (C) 
 *
 * claviering 
 *
 * 2016-11-09
 *
 * Distributed under terms of the WTFPL license.
 */

/*复制一课树
 *思路：
 *前序遍历复制，访问一个节点，复制data，对左子树，右子树，做一样的，返回指针
 */
#include "Tree.h"
#include <iostream>
#include <vector>
using namespace std;

TreeNode *CopyTree(TreeNode* p_root)
{
    TreeNode *new_tree = new TreeNode();
    if (p_root == 0)
        return 0;
    new_tree -> data = p_root -> data;
    new_tree -> lson_ = CopyTree(p_root -> lson_);
    new_tree -> rson_ = CopyTree(p_root -> rson_);
    return new_tree;
}

int main()
{
    Tree t;
    t.Creat();
    TreeNode *new_t = CopyTree(t.GetRoot());
    cout << "copy tree node" << endl;
    t.DisplayInOrder(new_t);
    cout << endl;
    
    return 0;
}
