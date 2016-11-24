/*
 * tree.h
 * Copyright (C) 2016 claviering <claviering@sunn>
 *
 * Distributed under terms of the WTFPL license.
 */

/*
 * 二叉树
 * 属性：
 * root_ 根节点
 * 方法：
 * void Creat(); // 新建二叉树
 * void DestroyTree(); // 删除二叉树
 * int CalcSize(TreeNode<T> *root); // 计算叶子节点
 * int CalcDepth(TreeNode<T> *root); // 计算二叉树深度
 * void DisplayTree(); // 输出二叉树
 * void ChangeLeftRight(TreeNode *root); // 左右子树交换
 * void PreOrderVisit(TreeNode<T> *root); // 前序遍历
 * void InOrderVisit(TreeNode<T> *root); // 中序遍历
 * void PostOrderVisit(TreeNode<T> *root); // 后序遍历
 *
 */

#ifndef TREE_H
#define TREE_H

#include <iostream>
#include <stack>
using namespace std;

template<typename T>
class TreeNode
{
    public:
        T data_;
        TreeNode<T> *lson_;
        TreeNode<T> *rson_;
        TreeNode();
};

template<typename T>
TreeNode<T>::TreeNode()
{
    lson_ = NULL;
    rson_ = NULL;
}

template<typename T>
class Tree
{
    public:
        Tree();
        ~Tree();
        void Creat();
        void DestroyTree();
        int CalcSize(TreeNode<T> *root);
        int CalcDepth(TreeNode<T> *root);
        void DisplayTree();
        void PreOrderVisit(TreeNode<T> *root);
        void PreOrderUnRec(TreeNode<T> *root);
        void InOrderVisit(TreeNode<T> *root);
        void InOrderUnRec(TreeNode<T> *root);
        void PostOrderVisit(TreeNode<T> *root);
        void PostOrderVisitUnRec(TreeNode<T> *root);
        void ChangeLeftRight(TreeNode<T> *root);
        TreeNode<T> *GetRoot();
    private:
        TreeNode<T> *root_;
        TreeNode<T> *CreatTree();
        void DestroyTree(TreeNode<T> *root);
};

template<typename T>
Tree<T>::~Tree()
{
    DestroyTree();
}

template<typename T>
void Tree<T>::DestroyTree()
{
    DestroyTree(root_);
}

template<typename T>
TreeNode<T> *Tree<T>::GetRoot()
{
    return root_;
}

template<typename T>
void Tree<T>::DestroyTree(TreeNode<T> *root)
{
    if (root != NULL)
    {
        DestroyTree(root -> lson_);
        DestroyTree(root -> rson_);
        delete root;
    }
}

template<typename T>
Tree<T>::Tree()
{
    root_ = NULL;
}

template<typename T>
void Tree<T>::Creat()
{
    root_ = CreatTree();
}

/*
 *前序遍历建树，用-1标志break
 */
template<typename T>
TreeNode<T> *Tree<T>::CreatTree()
{
    TreeNode<T> *tmp_node = new TreeNode<T>;
    int input = -1;
    while (cin >> input)
    {
        if (input == -1)
            return 0;
        tmp_node -> data_ = input;
        tmp_node -> lson_ = CreatTree();
        tmp_node -> rson_ = CreatTree();
        return tmp_node;
    }
}

template<typename T>
void Tree<T>::PreOrderVisit(TreeNode<T> *root)
{
    if (root != NULL)
    {
        cout << root -> data_ << endl;;
        PreOrderVisit(root -> lson_);
        PreOrderVisit(root -> rson_);
    }
}

template<typename T>
void Tree<T>::InOrderVisit(TreeNode<T> *root)
{
    if (root != NULL)
    {
        PreOrderVisit(root -> lson_);
        cout << root -> data_ << endl;;
        PreOrderVisit(root -> rson_);
    }
}

template<typename T>
void Tree<T>::PostOrderVisit(TreeNode<T> *root)
{
    if (root != NULL)
    {
        PreOrderVisit(root -> lson_);
        PreOrderVisit(root -> rson_);
        cout << root -> data_ << endl;;
    }
}

template<typename T>
void Tree<T>::PreOrderUnRec(TreeNode<T> *root)
{
    TreeNode<T> *tmp = root;
    stack<TreeNode<T>*> s;
    while ((!s.empty()) || (tmp != NULL))
    {
        while (tmp != NULL)
        {
            cout << tmp -> data_ << endl;
            s.push(tmp);
            tmp = tmp -> lson_;
        }

        if (!s.empty())
        {
            tmp = s.top();
            s.pop();
            tmp = tmp -> rson_;
        }
    }
}

template<typename T>
void Tree<T>::InOrderUnRec(TreeNode<T> *root)
{
    TreeNode<T> *tmp = root;
    stack<TreeNode<T>*> s;
    while ((!s.empty()) || (tmp != NULL))
    {
        while (tmp != NULL)
        {
            s.push(tmp);
            tmp = tmp -> lson_;
        }

        if (!s.empty())
        {
            tmp = s.top();
            cout << tmp -> data_ << endl;
            s.pop();
            tmp = tmp -> rson_;
        }
    }
}

// 根节点要进栈两次才访问
template<typename T>
void Tree<T>::PostOrderVisitUnRec(TreeNode<T> *root)
{
    stack< TreeNode<T>*> s1; 
    stack<int> s2;
    TreeNode<T> *t = root;
    while(!s1.empty()|| t != 0) 
    { 
        while (t!= 0) 
        {
            s1.push(t);
            s2.push(0); 
            t = t -> lson_;
        }
        if (!s1.empty())
        { 
            t = s1.top();
            s1.pop();
            int flag = s2.top();
            s2.pop();
            if (flag == 1)
            { 
                cout << t -> data_ << endl;
                t = 0;
            }
            else
            {
                s1.push(t);
                s2.push(1);
                t = t -> rson_;
            } 
        } 
    } 
}

template<typename T>
int Tree<T>::CalcSize(TreeNode<T> *root)
{
    if (root == NULL)
        return 0;
    else
        return 1 + CalcSize(root -> lson_) + CalcSize(root -> rson_);
}

template<typename T>
int Tree<T>::CalcDepth(TreeNode<T> *root)
{
    int left_depth;
    int right_depth;
    if (root == NULL)
        return 0;
    else
    {
        left_depth = CalcDepth(root -> lson_);
        right_depth = CalcDepth(root -> rson_);
        if (left_depth > right_depth)
            return left_depth + 1;
        else
            return right_depth + 1;
    }
}

template<typename T>
void Tree<T>::DisplayTree()
{

}

template<typename T>
void Tree<T>::ChangeLeftRight(TreeNode<T> *root)
{
    if (root)
    {
        if (root -> lson_)
            ChangeLeftRight(root -> lson_);
        if (root -> rson_)
            ChangeLeftRight(root -> rson_);

        TreeNode<T> *tmp_p = new TreeNode<T>;
        tmp_p = root -> lson_;
        root -> lson_ = root -> rson_;
        root -> rson_ = tmp_p;
        tmp_p = 0;
        delete tmp_p;
    }
}
#endif /* !TREE_H */
