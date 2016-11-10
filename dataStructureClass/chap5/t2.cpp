/*
 * t2.cpp
 * Copyright (C) 2016 sunn <sunn@sunn>
 *
 * Distributed under terms of the MIT license.
 *
 * 思路：
 * 当i不超过数组长度，访问，进栈往左走
 * 栈不为空，就出栈，往右走
 */

#include <iostream>
#include <stack>
using namespace std;

void InOrder(int[] ar)
{
    int i = 0;
    stack<int> s;
    while (!s.isEmpty() || i < ar.lenght)
    {
        while (i < ar.lenght)
        {
            cout << ar[i] << endl;
            s.push(i);
            i = 2 * i + 1；
        }

        if (!s.isEmpty())
        {
            i = s.top();
            s.pop();
            i = 2 * i + 2;
        }
    }
}

int main()
{
    
    return 0;
}
