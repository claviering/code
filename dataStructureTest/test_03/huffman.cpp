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
#include <iostream>
#include <string>
using namespace std;

int main()
{
    char ch[27] = {' ','A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
    int weight[27] = {186,64,13,22,32,103,21,15,47,57,1,5,32,20,57,63,15,1,48,51,80,23,8,18,1,16,1};
    int nodeNum = 27;
    priority_queue<HuffmanNode*> q;
    map<char, string> result;
    string prefix = "";

    HuffmanTree tree;
    tree.init_HuffmanNode(q,nodeNum,ch,weight);
    tree.creat_HuffmanTree(q);
    tree.creat_HuffmanCode(prefix,result);
    tree.display_HuffmanCode(result);

    return 0;
}
