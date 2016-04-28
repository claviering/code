#include <iostream>
using namespace std;

class Node
{
    private:
        Node *_next;
        int _data;
};

class Link
{
    private:
        Node *head;
    public:
        Node *creat(Node *h);
        void display(Node *h);
        void bubbleSort(Node *h);
        void inverseLink(Node *h);
        void insert(Node *h);
        Link();

};

Link :: Link()
{
    head = NULL;
}

Node Node :: *creat(Node *h)
{
    Node *p = new Node; 
}

int main()
{
     
    return 0;
}

