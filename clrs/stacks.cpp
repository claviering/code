#include <iostream>
using namespace std;

template <typename T>
T stackEmpty(T &top)
{
    if (top == 0)
        return 1;
    else
        return 0;
}

template <typename T>
T push(T s[],T x,int &top)
{
    top++;
    s[top] = x;
}

template <typename T>
T pop(T s[],int &top)
{
    if (stackEmpty(top))
        cout << "ERROR UNDERFLOW" << endl;
    else
    {
        top--;
        return s[top];
    }

}

int main()
{
    int ar[9] = {
        0,1,2,3,4,5,6,7,8
    };
    int top = sizeof (ar) / sizeof (int);
    int n = pop(ar,top);
    cout << n << endl;
    n = pop(ar,top);
    cout << n << endl;
    return 0;
}

