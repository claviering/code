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

void InOrder(int ar[],int lenght)
{
    int i = 0;
    stack<int> s;
    while (!s.empty() || i < lenght)
    {
        while (i < lenght)
        {
            s.push(i);
            i = 2 * i + 1;
        }

        if (!s.empty())
        {
            i = s.top();
            cout << ar[i] << endl;
            s.pop();
            i = 2 * i + 2;
        }
    }
}

int main()
{
    int ar[] = {1,2,3,4,5,6,9};    
    InOrder(ar,7);
    return 0;
}
