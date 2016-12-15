/*
 * Copyright (C) 
 *
 * USER claviering 
 *
 * DATE 2016-12-06
 *
 * Distributed under terms of the WTFPL license.
 */

#include "huffman.h"
#include "huffman_code.h"
#include <iostream>
#include <string>
#include <queue>
#include <vector>
using namespace std;

int main()
{
    char ch[27] = {' ','A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
    int weight[27] = {186,64,13,22,32,103,21,15,47,57,1,5,32,20,57,63,15,1,48,51,80,23,8,18,1,16,1};
    int nodeNum = 27;
    priority_queue<HuffmanNode*, vector<HuffmanNode*>, Cmp> q;
    map<char, string> result;
    string prefix = "";

    HuffmanTree tree;
    HuffmanCode code;
    while (1)
    {
        cout << "input n" << endl;
        cout << "1. Init" << endl;
        cout << "2. Encoding" << endl;
        cout << "3. Decoding" << endl;
        cout << "4. Print" << endl;
        cout << "5. Tree painting" << endl;
        int n;
        cin >> n;
        switch (n)
        {
            case 1:
                tree.init_HuffmanNode(q,nodeNum,ch,weight);
                tree.creat_HuffmanTree(q);
                tree.creat_HuffmanCode(prefix,result);
                code.write(result);
                break;
            case 2:
                code.encoding(result);
                break;
            case 3:
                code.decoding(result);
                break;
            case 4:
                code.print();
                break;
            case 5:
                tree.display();
                break;
        }
    }

    return 0;
}
