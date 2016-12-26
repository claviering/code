/*
 * matrix.h
 * Copyright (C) 2016 claviering <claviering@sunn>
 *
 * Distributed under terms of the WTFPL license.
 */

#ifndef _MATRIX_H_
#define _MATRIX_H_

#include <iostream>
#include <stack>
#include <queue>
#include <cstring>
using namespace std;

/*
 *用树做图模型
 *        0
 *   1          2
 * 3   4     5     6
 *7 8 9 10 11 12 13 14
 */
class Matrix
{
    public:
        Matrix();
        void DFS(int start);
        void BFS(int start);
    private:
        bool graph[15][15];
        bool visit[15];
};

Matrix::Matrix()
{

/*
 *        0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,
 *        1,0,0,1,1,0,0,0,0,0,0,0,0,0,0,
 *        1,0,0,0,0,1,1,0,0,0,0,0,0,0,0,
 *        0,1,0,0,0,0,0,1,1,0,0,0,0,0,0,
 *        0,1,0,0,0,0,0,0,0,1,1,0,0,0,0,
 *        0,0,1,0,0,0,0,0,0,0,0,1,1,0,0,
 *        0,0,1,0,0,0,0,0,0,0,0,0,0,1,1,
 *        0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,
 *        0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,
 *        0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,
 *        0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,
 *        0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,
 *        0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,
 *        0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,
 *        0,0,0,0,0,0,1,0,0,0,0,0,0,0,0
 */

    memset(graph, 0, sizeof(graph));
    memset(visit, 1, sizeof(visit));

    for (int i = 0; i < 7; i++)
    {
        graph[i][2*i+1] = 1;
        graph[i][2*i+2] = 1;

        graph[2*i+1][i] = 1;
        graph[2*i+2][i] = 1;
    }
}

void Matrix::DFS(int start)
{
    bool is_visit[15];
    memcpy(is_visit,visit,sizeof(is_visit));

    stack<int> s;
    s.push(start);
    is_visit[start] = 0;

    while (!s.empty())
    {
        start = s.top();
        s.pop();

        cout << start << " ";

        for (int i = 0; i < 15; i++)
        {
            if (graph[start][i] && is_visit[i])
            {
                s.push(i);
                is_visit[i] = 0;
            }
        }

    }
    cout << endl;
}

void Matrix::BFS(int start)
{
    bool is_visit[15];
    memcpy(is_visit,visit,sizeof(is_visit));

    queue<int> q;
    q.push(start);
    is_visit[start] = 0;

    while (!q.empty())
    {
        start = q.front();
        q.pop();

        cout << start << " ";

        for (int i = 0; i < 15; i++)
        {
            if (graph[start][i] && is_visit[i])
            {
                q.push(i);
                is_visit[i] = 0;
            }
        }

    }
    cout << endl;
}

#endif /* !MATRIX_H */
