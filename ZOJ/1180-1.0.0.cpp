#include <iostream>
#include <cstdio>
using namespace std;
int main()
{
    const int UP = 1000000 + 1;
    bool num[UP];
    for (int i = 1; i < UP; i++)
    {
        int temp = i;
        int dig = i;
        while (dig)
        {
            temp += dig % 10;
            dig /= 10;
        }
        if (temp <= UP)
            num[temp] = 1;
    }
    for (int i = 1; i < UP; i++)
    {
        if (!num[i])
            printf ("%d\n",i);
    }
    return 0;
}

