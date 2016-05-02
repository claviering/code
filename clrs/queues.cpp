#include <iostream>
using namespace std;

template <typename T>
T pop(T q[],T &head)
{
   return q[head++]; 
}

template <typename T>
T push(T q[],T &tail)
{
    return q[tail--];
}

int main()
{
     
    return 0;
}

