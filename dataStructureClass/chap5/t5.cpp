/*
 * Copyright (C) 
 *
 * claviering 
 *
 * 2016-11-10
 *
 * Distributed under terms of the WTFPL license.
 */

/*
 *思路：
 *进栈，出队列，访问，左孩子进队列，右孩子进队列
 */

#include "Tree.h"
#include <list>
#include <iostream>
#include <queue>
using namespace std;

TreeNode *ChangeTreeToList(TreeNode *p_root)
{
    if (p_root == 0)    
        return 0;

    queue<int> q_list; //当链表用

    queue<TreeNode*> q;
    q.push(p_root);

    while (!q.empty())
    {
        TreeNode *tmp = q.front();
        q.pop();
        q_list.push(tmp -> data); //没有建链,用加入队列

        if (tmp -> lson_ != 0)
            q.push(tmp -> lson_);
        if (tmp -> rson_ != 0)
            q.push(tmp -> rson_);
    }

    while (!q_list.empty())
    {
        cout << q_list.front() << " ";
        q_list.pop();
    }
}

int main()
{
    Tree t;
    t.Creat();
    ChangeTreeToList(t.GetRoot());
    return 0;
}
