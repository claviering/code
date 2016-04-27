#include <iostream>
using namespace std;

class Node
{
    private:
        node *_next;
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

};

int main()
{
     
    return 0;
}

