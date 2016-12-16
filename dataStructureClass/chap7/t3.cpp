/*
 * Copyright (C) 
 *
 * USER claviering 
 *
 * DATE 2016-12-16
 *
 * Distributed under terms of the WTFPL license.
 */

#include <iostream>
#include "list.h"
using namespace std;

const int SIZE = 11;
/*
 * 哈希函数
 */
void HashFunction(int &x)
{
    x %= SIZE;
}

int main()
{
    Mylist<int> list[SIZE];
    for (int i = 0; i < 100; i++)
    {
        int x = i;
        HashFunction(x);
        list[x].add(i);
    }

    int f = 13;
    int tmp = f;
    HashFunction(f);
    SlistNode<int> *p = list[f].find(tmp);
    if (p)
        cout << p -> data << endl;
    else
        cout << "NULL" << endl;
    return 0;
}
