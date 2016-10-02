#include <iostream>
using namespace std;
const int number = 100;

//时间复杂度O(log2 )
//最好O(1)
bool del(int *p, int x)
{
    int head = 0;
    int tail = number;
    bool flag = 0;
    while (head < tail && p[x] > 0)
    {
        int mid = (head + tail) / 2; 
        if (x > mid)
            head = mid;
        else if (x < mid)
           tail = mid; 
        else
        {
            p[x] = 0;
            flag = 1;
        }
    }
    return flag;
}

int main()
{
    int *ar = new int[number];
    for (int i = 1; i < number; i++)
        ar[i] = i;
    int x;
    cin >> x;
    if (del(ar,x)) 
        cout << "TURE "<< endl;
    else 
        cout << "FALSE "<< endl;
    delete []ar;
    return 0;
}

