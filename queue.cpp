#include <cstdlib>

template<typename T>
class queueNode
{
    public:
        queueNode():next(NULL){}
        T data;
        queueNode *next;
};
template<typename T>
class myqueue
{
    private:
        unsigned int queuelength;
        queueNode<T> *node;
        queueNode<T> *rear;
        queueNode<T> front;
    public:
        myqueue();
        unsigned int length();
        void push(T x);
        bool isEmpty();
        void pop();
        T getHead();
};
template<typename T>
myqueue<T> :: myqueue()
{
    node = NULL;
    rear = NULL;
    front = NULL;
    queuelength = 0;
}
template<typename T>
inline unsigned int myqueue<T> :: length()
{
    return queuelength;
}
template<typename T>
void myqueue<T> :: push(T x)
{
    node = new queueNode<T>();
    node -> data = x;
    if (rear == NULL)
    {
        front = node;
        rear = node;
    }
    else
    {
        rear -> next = node;
        rear = node;
    }
    ++queuelength;
}
template<typename T>
bool myqueue<T> :: isEmpty()
{
    return queuelength == 0;
}
template<typename T>
void myqueue<T> :: pop()
{
    if (queuelength == 0)
        return
    node = front;
    front = front -> next;
    delete (node);
    --queuelength;
}
template<typename T>
T myqueue<T> :: getHead()
{
    return front -> data;
}
int main()
{
     
    return 0;
}

