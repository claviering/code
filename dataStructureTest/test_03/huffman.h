/*
 * huffman-node.h
 * Copyright (C) 2016 claviering <claviering@sunn>
 *
 * Distributed under terms of the WTFPL license.
 */

#ifndef _HUFFMAN_NODE_H_
#define _HUFFMAN_NODE_H_
/*
 * 初始化，把节点指针放到优先队列
 * void init_HuffmanNode(priority_queue<HuffmanNode*, vector<HuffmanNode*>, Cmp> &q, int nodeNum, char ch[], int weight[]);
 * 创建Huffman树，利用优先队列的节点指针
 * void creat_HuffmanTree(priority_queue<HuffmanNode*, vector<HuffmanNode*>, Cmp> &q);
 * 生成Huffman编码，保存到map
 * void creat_HuffmanCode(string &prefix, map<char, string> &result);
 * 输出Huffman编码到控制台
 * void display_HuffmanCode(map<char, string> &result);
 * 输出Huffman树 根(左孩子，右孩子)
 * void display();
 */

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

/*
 * 优先队列的重载运算符
 */
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
        void display_HuffmanTree(HuffmanNode *root);
    public:
        void init_HuffmanNode(priority_queue<HuffmanNode*, vector<HuffmanNode*>, Cmp> &q, int nodeNum, char ch[], int weight[]);
        void creat_HuffmanTree(priority_queue<HuffmanNode*, vector<HuffmanNode*>, Cmp> &q);
        void creat_HuffmanCode(string &prefix, map<char, string> &result);
        void display_HuffmanCode(map<char, string> &result);
        void display();
};


/*
 * 输出Huffman树接口
 */
void HuffmanTree::display()
{
    display_HuffmanTree(root);
}

/*
 * 输出Huffman树
 */
void HuffmanTree::display_HuffmanTree(HuffmanNode *root)
{
    if (root != NULL)
    {
        cout << root->c << "(";
        display_HuffmanTree(root->lson);
        cout << ",";
        display_HuffmanTree(root->rson);
        cout << ")";
    }
}
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
 * 建立Huffman树,root指向根节点
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
 * 初始化Huffman树,把节点push到优先队列
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
