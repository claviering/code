/*
 * huffman-node.h
 * Copyright (C) 2016 claviering <claviering@sunn>
 *
 * Distributed under terms of the WTFPL license.
 */

#ifndef _HUFFMAN_NODE_H_
#define _HUFFMAN_NODE_H_

#include <iostream>
#include <queue>
#include <vector>
#include <map>
#include <string>
using namespace std;

class HuffmanNode
{
    public:
        char c;
        int weight;
        HuffmanNode *lson;
        HuffmanNode *rson;
        HuffmanNode(char tmp_c, int tmp_weight, HuffmanNode *l, HuffmanNode *r):c(tmp_c), weight(tmp_weight), lson(l), rson(r){}
        HuffmanNode(char tmp_c, int tmp_weight):c(tmp_c), weight(tmp_weight), lson(NULL), rson(NULL){}
};

class Cmp
{
    public:
        bool operator() (HuffmanNode *&p1, HuffmanNode *&p2)
        {
            return p1->weight > p2->weight;
        }
};

class HuffmanTree
{
    private:
        HuffmanNode *root;
        void creat(HuffmanNode *root, string &prefix, map<char, string> &result);
    public:
        void init_HuffmanNode(priority_queue<HuffmanNode*, vector<HuffmanNode*>, Cmp> &q, int nodeNum, char ch[], int weight[]);
        void creat_HuffmanTree(priority_queue<HuffmanNode*, vector<HuffmanNode*>, Cmp> &q);
        void creat_HuffmanCode(string &prefix, map<char, string> &result);
        void display_HuffmanCode(map<char, string> &result);
};

/*
 * 输出Huffman编码
 * @param result map变量
 */
void HuffmanTree::display_HuffmanCode(map<char, string> &result)
{
    map<char, string>::const_iterator it = result.begin();  
    while (it != result.end()) 
    {  
        cout << it->first << ": " << it->second << endl;  
        ++it;  
    }
}

/*
 * 生成Huffman编码，保存到map
 * @param *root 根节点指针
 * @param prefix Huffman编码
 * @param result map变量
 */
void HuffmanTree::creat(HuffmanNode *root, string &prefix, map<char, string> &result)
{
    string m_prefix = prefix;

    if (root->lson == NULL)
        return;

    //处理左子树
    prefix += "0";
    if (root->lson->lson == NULL)
        result[root->lson->c] = prefix;
    else
        creat(root->lson, prefix, result);

    //还原原来的路径,回溯 
    prefix = m_prefix;

    //处理右子树
    prefix += "1";
    if (root->rson->rson == NULL)
        result[root->rson->c] = prefix;
    else
        creat(root->rson, prefix, result);
}

/*
 * 接口：生成Huffman编码，保存到map
 */
void HuffmanTree::creat_HuffmanCode(string &prefix, map<char, string> &result)
{
    creat(root,prefix,result);
}

/*
 * 建立Huffman树
 * @param q 优先队列
 */
void HuffmanTree::creat_HuffmanTree(priority_queue<HuffmanNode*, vector<HuffmanNode*>, Cmp> &q)
{
    while (q.size() > 1)
    {
        HuffmanNode *tmp_lson = q.top();
        q.pop();
        HuffmanNode *tmp_rson = q.top();
        q.pop();

        HuffmanNode *tmp_p = new HuffmanNode('#', tmp_lson->weight + tmp_rson->weight, tmp_lson, tmp_rson);
        q.push(tmp_p);
    }
    root = q.top();
}

/*
 * 初始化Huffman树
 * @param q 优先队列q
 * @param nodeNum 节点数量
 * @param ch[] 字符数组
 * @param weight 权重数组
 */
void HuffmanTree::init_HuffmanNode(priority_queue<HuffmanNode*, vector<HuffmanNode*>, Cmp> &q, int nodeNum, char ch[], int wei[])
{
    for (int i = 0; i < nodeNum; i++)
    {
        HuffmanNode *p = new HuffmanNode(ch[i], wei[i]);
        q.push(p);
    }
}

#endif /* !HUFFMAN_NODE_H */
