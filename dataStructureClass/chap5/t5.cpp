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

#include <iostream>
#include <queue>
using namespace std;

template<typename T>
TreeNode<T> *ChangeTreeToList(TreeNode<T> *p_root)
{
    if (p_root == 0)    
        return 0;

    queue<TreeNode<T>*> q;
    q.push(p_root);

    while (!q.empty())
    {
        TreeNode<T> *tmp = q.front();
        AddList(tmp -> data); //建链函数
        q.pop();
        if (tmp -> p_left != 0)
            q.push(tmp -> p_left);
        lf (tmp -> p_right != 0)
            q.push(tmp -> p_right);
    }
}

int main()
{
    
    return 0;
}
