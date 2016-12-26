/*
 * Copyright (C) 
 *
 * USER claviering 
 *
 * DATE 2016-12-22
 *
 * Distributed under terms of the WTFPL license.
 */

#include <iostream>
#include "matrix.h"
#include "table.h"
using namespace std;

int main()
{
    Matrix m;
    cout << "Matrix" << endl;
    cout << "DFS" << endl;
    m.DFS(14);
    cout << "BFS" << endl;
    m.BFS(14);

    Table t;
    cout << "Table" << endl;
    cout << "DFS" << endl;
    t.DFS(14);
    cout << "BFS" << endl;
    t.BFS(14);
    return 0;
}

