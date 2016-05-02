#include <cstdlib>

template<typename T>
class stackNode
{
    public:
        stackNode():next(NULL){}
        T data;
        stackNode *next;
};
template<typename T>
class mystack
{
    private:
        unsigned int stacklength;
        stackNode<T> *node;
        stackNode<T> *headnode;
    public:
        mystack();
        unsigned int length;
        void push(T x);
        bool isEmpty();
        void pop();
        T top();
        void clear();
};
template<typename T>
mystack<T> :: mystack()
{
    node = NULL;
    headnode = NULL;
    stacklength = 0;
}
template<typename T>
inline unsigned int mystack<T> :: length()
{
    return stacklength;
}
template<typename T>
void mystack<T> :: push()
{
    node = new stackNode<T>();
    node -> data = x;
    node -> next = headnode;
    headnode = node;
    ++stacklength;
}
template<typename T>
bool mystack<T> :: isEmpty()
{
    return stacklength == 0;
}
template<typename T>
void mystack<T> :: pop()
{
    if (isEmpty())
        return;
    node = headnode;
    headnode = headnode -> next;
    delete (node);
    --stacklength;
}
template<typename T>
T mystack<T> :: top()
{
    if (!isEmpty())
        return headnode -> data;
}
template<typename T>
void mystack<T> :: clear()
{
    while (headnode != NULL)
    {
        node = headnode;
        headnode = headnode -> next;
        delete (node);
    }
    node = NULL;
    headnode = NULL;
    stacklength = 0;
}
int main()
{
    return 0;
}

