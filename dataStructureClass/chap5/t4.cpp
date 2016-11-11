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
#include <iostream>
#include <vector>
using namespace std;

template<typename T>
TreeNode<T> *CopyTree(TreeNode<T>* p_root)
{
    TreeNode<T> *new_tree = new TreeNode<T>();
    if (p_root == 0)
        return 0;
    new_tree -> data = p_root -> data;
    new_tree -> p_left = CopyTree(p_root -> p_left);
    new_tree -> p_right = CopyTree(p_root -> p_right);
    return new_tree;
}

int main()
{
    
    return 0;
}
