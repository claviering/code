#include <iostream>
using namespace std;
int main()
{
    const int UP = 1000000 + 1;
    int num[UP] = {0};
    for (int i = 1; i < UP; i++)
    {
        if (num[i] > -1)
            num[i] = i;
        int temp = i;
        int dig = i;
        while(dig)
        {
            temp += dig % 10;
            dig /= 10;
        }
        if (temp <= UP)
            num[temp] = -1;
    }
    for (int i = 1; i < UP; i++)
    {
        if (num[i] > 0)
            cout << num[i] << endl;
    }
    return 0;
}

