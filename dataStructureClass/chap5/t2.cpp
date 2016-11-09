/*
 * t2.cpp
 * Copyright (C) 2016 sunn <sunn@sunn>
 *
 * Distributed under terms of the MIT license.
 *
 * 思路：
 * 当前指针不为空，把节点push到栈，往作走，
 * 当前指针为空了，从栈top一个，输出，往右走，
 * 直到栈为空
 */

#include <iostream>
#include <stack>
using namespace std;

void InOrder(TreeNode* p_root)
{
    stack<TreeNode*> s;
    TreeNode *tmp_p = p_root;

    while (!s.isEmpty() || tmp_p != 0)
    {
        while (!tmp_p)
        {
            s.pop(tmp_p);
            tmp_p = tmp_p -> p_left;
        }

        if (!s.isEmpty())
        {
            tmp_p = s.top();
            s.pop();
            display(tmp_p);
            tmp_p = tmp_p -> p_right;
        }
    }
}

int main()
{
    
    return 0;
}
