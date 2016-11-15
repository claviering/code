/*
 * t3.cpp
 * Copyright (C) 2016 sunn <sunn@sunn>
 *
 * Distributed under terms of the MIT license.
 *
 * 思路：
 * 当前指针不为空，把节点push到栈，往左走，
 * 当前指针为空了，从栈top一个，输出，往右走，
 * 直到栈为空
 */


#include "Tree.h"
#include <iostream>
#include <stack>
using namespace std;

bool InOrderCompare(TreeNode *p_root1,TreeNode *p_root2)
{
    stack<TreeNode*> s1;
    stack<TreeNode*> s2;
    TreeNode *tmp_p1 = p_root1;
    TreeNode *tmp_p2 = p_root2;


    while ((!s1.empty() || tmp_p1) && (!s2.empty() || tmp_p2))
    {
        while (tmp_p1 && tmp_p2)
        {
            /*
             *前序遍历 比较两个节点
             */
            if (tmp_p1 -> data != tmp_p2 -> data)
                return 0;

            s1.push(tmp_p1);
            tmp_p1 = tmp_p1 -> lson_;

            s2.push(tmp_p2);
            tmp_p2 = tmp_p2 -> lson_;
        }

        /*
         *一个指针为空跳出循环，两棵树不相同
         */
        if (tmp_p1 != tmp_p2)
        {
            return 0;
        }

        if (!s1.empty() && !s2.empty() )
        {
            tmp_p1 = s1.top();
            tmp_p1 = tmp_p1 -> rson_;
            s1.pop();

            tmp_p2 = s2.top();
            tmp_p2 = tmp_p2 -> rson_;
            s2.pop();
        }
    }
    if (tmp_p1 || tmp_p2)
        return 0;
    else
        return 1;
}

int main()
{
    Tree t1;
    t1.Creat();
    Tree t2;
    t2.Creat();
    bool same = InOrderCompare(t1.GetRoot(),t2.GetRoot());    
    if (same)
        cout << unix << endl;
    else
        cout << -unix << endl;

    return 0;
}
