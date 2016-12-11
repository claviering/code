/*
 * huffman_code.h
 * Copyright (C) 2016 claviering <claviering@sunn>
 *
 * Distributed under terms of the WTFPL license.
 */

#ifndef _HUFFMAN_CODE_H_
#define _HUFFMAN_CODE_H_

#include <iostream>
#include <vector>
#include <cstring>
#include <fstream>
using namespace std;

class HuffmanCode
{
    public:
        char c;
        char code[256];
        HuffmanCode(char c_, string s);
        HuffmanCode(){}
        void write(map<char, string> result);
        void read(map<char,string> &result);
        void encoding(map<char,string> &result);
        void decoding(map<char,string> &result);
        void print();
};

HuffmanCode::HuffmanCode(char c_, string s)
{
    c = c_;
    s.copy (code, s.length(), 0);
}

/*
 * 把Huffman编码写到文件
 */
void HuffmanCode::write(map<char, string> result)
{
    fstream write_file;
    write_file.open("hfmTree", ios::out | ios::binary);

    map<char, string>::const_iterator it = result.begin();  
    while (it != result.end()) 
    {  
        HuffmanCode *p = new HuffmanCode(it->first, it->second);
        write_file.write((char *)p, sizeof(HuffmanCode));
        ++it;  
    }
    write_file.close();
}

/*
 * 如果map为空
 * 把Huffman编码从文件hfmTree里读出来，保存到map里
 */
void HuffmanCode::read(map<char,string> &result)
{
    fstream read_file;
    read_file.open("hfmTree", ios::in | ios::binary);
    HuffmanCode *p = new HuffmanCode;
    while (read_file)
    {
        read_file.read((char *)p, sizeof(HuffmanCode));
        string s(p->code);
        result[p->c] = s;
    }
    read_file.close();
}

/*
 * 编码ToBeTran --> CodeFile
 */
void HuffmanCode::encoding(map<char,string> &result)
{
    ofstream out("CodeFile");
    fstream read_file("ToBeTran");

    if (result.empty())
    {
        read(result);
    }
    string contents((istreambuf_iterator<char>(read_file)), istreambuf_iterator<char>());
    for (int i = 0; i < contents.length(); i++)
    {
        string coding = result[contents[i]];
        out << coding << endl;;
    }
}

void HuffmanCode::decoding(map<char,string> &result)
{
    if (result.empty())
        read(result);

    ifstream in("CodeFile");
    ofstream out("TextFile");
    char buffer[256];
    while (!in.eof())
    {
        in.getline(buffer,256);
        string s(buffer);

        map<char, string>::const_iterator it = result.begin();  
        while (it != result.end()) 
        {  
            if (s.compare(it->second) == 0)
            {
                out << it->first;
            }
            ++it;  
        }
    }
}

void HuffmanCode::print()
{
    ifstream in("CodeFile");
    ofstream out("CodePrint");

    char buffer[256];
    string s_single_line = "";
    while (!in.eof())
    {
        in.getline(buffer,256);
        string tmp(buffer);
        s_single_line += tmp;
    }
    for (int p = 0; p < s_single_line.length(); p++)
    {
        out << s_single_line[p];
        cout << s_single_line[p];
        if (((p+1) % 50) == 0)
        {
            out << endl;
            cout << endl;
        }
    }
    cout << endl;
}
#endif /* !HUFFMAN_CODE_H */
