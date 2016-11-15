/*
 * Tree.h
 * Copyright (C) 2016 claviering <claviering@sunn>
 *
 * Distributed under terms of the WTFPL license.
 */

/* 
 * 二叉树类
 * 属性 root_
 * 方法
 * Tree() 构造函数root_ = null;
 * Creat() 新建一颗二叉树
 * DisplayInOrder() 前序输出二叉树
 * GetRoot() 返回root_
 */
#ifndef TREE_H
#define TREE_H

#include <iostream>
using namespace std;

class TreeNode
{
    public:
        int data; 
        TreeNode *lson_;
        TreeNode *rson_;
};

class Tree
{
    public:
        Tree();
        void Creat();
        void DisplayInOrder(TreeNode *root);
        TreeNode *GetRoot();
    private:
        TreeNode *CreatTree();
        TreeNode *root_;
};

Tree::Tree()
{
    root_ = NULL;
}

void Tree::Creat()
{
    root_ = CreatTree();
}
/*
 *前序遍历建树，用-1标志break
 */
TreeNode *Tree::CreatTree()
{
    TreeNode *tmp_node = new TreeNode;
    int input = -1;
    while (cin >> input)
    {
        if (input == -1)
            return 0;
        tmp_node -> data = input;
        tmp_node -> lson_ = CreatTree();
        tmp_node -> rson_ = CreatTree();
        return tmp_node;
    }
}

//前序输出
void Tree::DisplayInOrder(TreeNode *root)
{
    TreeNode *tmp = root;
    if (tmp)
    {
        cout << tmp -> data << " ";
        DisplayInOrder(tmp -> lson_);
        DisplayInOrder(tmp -> rson_);
    }
}

//返回root指针
TreeNode *Tree::GetRoot()
{
    return root_;
}
#endif /* !TREE_H */
