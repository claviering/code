/*
 * t3.cpp
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

template<typename T>
bool InOrderCompare(TreeNode<T>* p_root1,TreeNode<T>* p_root2)
{
    stack<TreeNode<T>*> s1;
    stack<TreeNode<T>*> s2;
    TreeNode<T> *tmp_p1 = p_root1;
    TreeNode<T> *tmp_p2 = p_root2;

    bool tree1 = !s1.isEmpty() || tmp_p1;
    bool tree2 = !s2.isEmpty() || tmp_p2;
    while (tree1 && tree2)
    {
        while (!tmp_p1 && !tmp_p2)
        {
            /*
             *前序遍历 比较两个节点
             */
            if (tmp_p1 -> data != tmp_p2 -> data)
                return 0;

            s1.pop(tmp_p1);
            tmp_p1 = tmp_p1 -> p_left;

            s2.pop(tmp_p2);
            tmp_p1 = tmp_p2 -> p_left;
        }

        /*
         *一个指针为空跳出循环，两棵树不相同
         */
        if (tmp_p1 != tmp_p2)
        {
            return 0;
        }

        if (!s1.isEmpty() && !s2.isEmpty() )
        {
            tmp_p1 = s1.top();
            tmp_p1 = tmp_p1 -> p_right;
            s1.pop();

            tmp_p2 = s2.top();
            tmp_p2 = tmp_p2 -> p_right;
            s2.pop();
        }
    }
}

int main()
{
    
    return 0;
}
