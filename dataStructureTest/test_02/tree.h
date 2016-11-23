/*
 * tree.h
 * Copyright (C) 2016 claviering <claviering@sunn>
 *
 * Distributed under terms of the WTFPL license.
 */

#ifndef TREE_H
#define TREE_H

template<typename T>
class TreeNode
{
    public:
        T data_;
        TreeNode<T> *lson_;
        TreeNode<T> *rson_;
};

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
        void ChangeLeftRight(TreeNode *root);
    private:
        TreeNode<T> *root_;
        TreeNode<T> *CreatTree();
        void DestroyTree(TreeNode<T> *root);
        void PreOrderVisit(TreeNode<T> *root);
        void InOrderVisit(TreeNode<T> *root);
        void PostOrderVisit(TreeNode<T> *root);
};

Tree::~Tree()
{
    DestroyTree();
}

void Tree::DestroyTree()
{
    DestroyTree(root_);
}

void Tree::DestroyTree(TreeNode<T> *root)
{
    if (root != NULL)
    {
        DestroyTree(root -> lson);
        DestroyTree(root -> rson);
        delete root;
    }
}

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
TreeNode<T> *Tree::CreatTree()
{
    TreeNode<T> *tmp_node = new TreeNode<T>;
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

void Tree::PreOrderVisit(TreeNode<T> *root)
{
    cout << root -> data << endl;;
    PreOrderVisit(root -> lson);
    PreOrderVisit(root -> rson);
}

void Tree::InOrderVisit(TreeNode<T> *root)
{
    PreOrderVisit(root -> lson);
    cout << root -> data << endl;;
    PreOrderVisit(root -> rson);
}

void Tree::PostOrderVisit(TreeNode<T> *root)
{
    PreOrderVisit(root -> lson);
    PreOrderVisit(root -> rson);
    cout << root -> data << endl;;
}

void Tree::PreOrderUnRec(TreeNode<T> *root)
{
    TreeNode<T> *tmp = root;
    stack<TreeNode<T>*> s;
    while (!s.empty() || tmp != NULL)
    {
        while (tmp != NULL)
        {
            cout << tmp -> data << endl;
            s.push(tmp);
            tmp = tmp -> lson;
        }

        if (!s.empty())
        {
            tmp = s.top();
            s.pop();
            tmp = tmp -> lson;
        }
    }
}

void Tree::InOrderUnRec(TreeNode<T> *root)
{
    TreeNode<T> *tmp = root;
    stack<TreeNode<T>*> s;
    while (!s.empty() || tmp != NULL)
    {
        while (tmp != NULL)
        {
            s.push(tmp);
            tmp = tmp -> lson;
        }

        if (!s.empty())
        {
            tmp = s.top();
            cout << tmp -> data << endl;
            s.pop();
            tmp = tmp -> lson;
        }
    }
}

// 根节点要进栈两次才访问
void PostOrderVisitUnRec(TreeNode<T> *root)
{
    stack< BinTreeNode<T>*> s1; 
    stack<int> s2;
    TreeNode<T> *t = root;
    while(!s1.IsEmpty()|| t != 0) 
    { 
        while (t!= 0) 
        {
            s1.push(t);
            s2.push(0); 
            t = t -> lson_;
        }
        if (!s.IsEmpty())
        { 
            t = s1.top();
            s1.pop();
            int flag = s2.top();
            s2.pop();
            if (flag == 1)
            { 
                cout << t -> data << endl;
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

int Tree::CalcSize(TreeNode<T> *root)
{
    if (root == NULL)
        return 0;
    else
        return 1 + CalcSize(root -> lson_) + CalcSize(root -> rson_)
}

int Tree::CalcDepth(TreeNode<T> *root)
{
    int left_depth = 0;
    int right_depth = 0;
    if (root == NULL)
        return 0;
    else
    {
        left_depth = CalcDepth(root -> lson_);
        right_depth = CalcDepth(root -> sson_);
        if (left_depth > right_depth)
            return left_depth;
        else
            return right_depth;
    }
}

void Tree::DisplayTree()
{

}

void Tree::ChangeLeftRight(TreeNode *root)
{
    if (root)
    {
        if (root -> lson_)
            ChangeLeftRight(root -> lson_);
        if (root -> rson_)
            ChangeLeftRight(root -> rson_);

        TreeNode *tmp_p = new TreeNode;
        tmp_p = root -> lson_;
        root -> lson_ = root -> rson_;
        root -> rson_ = tmp_p;
        tmp_p = 0;
        delete tmp_p;
    }
}
#endif /* !TREE_H */
