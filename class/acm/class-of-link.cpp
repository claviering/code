#include <iostream>
using namespace std;

class Node
{
    public:
        Node *_next;
        int _data;
};

class Link
{
    private:
        Node *head;
    public:
        Node *creat(Node *head,int data);
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

Node Link:: *creat(Node *head,int data)
{
    if (head == NULL)
    {
        Node *p = new Node; 
        p -> _data = data;
        head = p;
    }
    else
    {
        Node *p = new Node; 
        p -> _data = data;
        p -> _next = head;
        head = p;
    }
}

void display(Node *h)
{
    while (h != NULL)
    {
        cout << h -> _data << endl;
        h = h -> _next;
    }
}

int main()
{
    return 0;
}

