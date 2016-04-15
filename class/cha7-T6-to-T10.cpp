#include <iostream>
using namespace std;

class Listnode
{
    public:
        int date;
        Listnode *next;
};

class List
{
    private:
        Listnode *node;
        Listnode *headnode;
        Listnode *lastnode;
    public:
        List();
        void creat(int x);
        void print();
        void del(int x);
        void insert(int x);
};

List :: List()
{
    node = NULL;
    headnode = NULL;
}

void List :: creat(int x)
{
    node = new Listnode;
    node -> date = x;
    if (headnode == NULL)
    {
        headnode = node;
        lastnode = node;
    }
    else
    {
        lastnode -> next = node;
        lastnode = node;
    }
}

void List :: print()
{
    node = headnode;
    while (node != NULL)
    {
        cout << node -> date << endl;
        node = node -> next;
    }
    cout << endl;
}

void List :: del(int x)
{
    node = headnode;
    if (node == NULL)
        return;

    if (node -> date == x)
    {
        headnode = node ->  next;
        if (node -> next == NULL)
            lastnode = NULL;
        delete (node);
        return;
    }


    while (node -> next -> date != x && node -> next != NULL)
    {
        node = node -> next;
    }

    if (node -> next == NULL)
        return;
    
    if (node -> next == lastnode)
    {
        lastnode = node;
        delete (node -> next);
        node -> next = NULL;
    }
    else
    {
        Listnode *temp = node -> next;
        node -> next = node -> next -> next;
        delete(temp);
        node = NULL;
    }
}

void List :: insert(int x)
{
    node = new Listnode;
    node -> date = x;
    node -> next = headnode;
    headnode = node;
}

int main()
{
    List myGirlFriend;
    int a;
    while (cin >> a && a > 0) 
    {
        myGirlFriend.creat(a);
    }
    myGirlFriend.print();

    int d;
    cin >> d;
    cout << endl;
    myGirlFriend.del(d);

    myGirlFriend.print();

    int i;
    cin >> i;
    cout << endl;
    myGirlFriend.insert(i);
    myGirlFriend.print();
    return 0;
}

