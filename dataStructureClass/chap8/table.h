/*
 * table.h
 * Copyright (C) 2016 claviering <claviering@sunn>
 *
 * Distributed under terms of the WTFPL license.
 */

#ifndef _TABLE_H_
#define _TABLE_H_

#include <iostream>
#include <stack>
#include <queue>
#include <cstring>
#include "list.h"
using namespace std;

/*
 *用树做图模型
 *        0
 *   1          2
 * 3   4     5     6
 *7 8 9 10 11 12 13 14
 */

class Table
{
    public:
        Table();
        void DFS(int start);
        void BFS(int start);
    private:
        Mylist<int> l[15];
};

Table::Table()
{
    for (int i = 0; i < 15; i++)
    {
        l[i].add(i);
    }

    l[0].add(1);
    l[0].add(2);

    for (int i = 1; i < 7; i++)
    {
        l[i].add((i-1) / 2);
        l[i].add(2*i + 1);
        l[i].add(2*i + 2);
    }

    for (int i = 7; i < 15; i++)
    {
        l[i].add((i-1) / 2);
    }
}

void Table::DFS(int start)
{
    bool is_visit[15];
    memset(is_visit,1,sizeof(is_visit));

    stack<int> s;
    s.push(start);
    is_visit[start] = 0;

    while (!s.empty())
    {
        start = s.top();
        s.pop();

        cout << start << " ";

        SlistNode<int> *p = l[start].find(start);

        while (p != NULL)
        {
            if (is_visit[p->data])
            {
                s.push(p->data);
                is_visit[p->data] = 0;
            }
            p = p -> next;
        }
    }
    cout << endl;
}

void Table::BFS(int start = 14)
{
    bool is_visit[15];
    memset(is_visit,1,sizeof(is_visit));

    queue<int> q;
    q.push(start);
    is_visit[start] = 0;

    while (!q.empty())
    {
        start = q.front();
        q.pop();

        cout << start << " ";

        SlistNode<int> *p = l[start].find(start);

        while (p != NULL)
        {
            if (is_visit[p->data])
            {
                q.push(p->data);
                is_visit[p->data] = 0;
            }
            p = p -> next;
        }
    }
    cout << endl;

}
#endif /* !TABLE_H */
