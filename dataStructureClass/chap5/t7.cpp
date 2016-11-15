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
#include <queue>
#include <iostream>
using namespace std;

// 前序遍历转顺序存储结构
// i从零开始
void ChangeTreeToArray(TreeNode *p_root, queue<int> &q, int i)
{
    if (p_root == 0)
        return;
    q.push(p_root -> data);
    ChangeTreeToArray(p_root -> lson_, q, 2 * i + 1);
    ChangeTreeToArray(p_root -> rson_, q, 2 * i + 2);
}
int main()
{
    
    Tree t;
    t.Creat();
    queue<int> q;
    ChangeTreeToArray(t.GetRoot(), q, 0);
    while (!q.empty())
    {
        cout << q.front() << " ";
        q.pop();
    }
    return 0;
}
