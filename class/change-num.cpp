#include <iostream>
using namespace std;
int main()
{
    int a[10] = {-3,9,5,-10,-4,11,-19,21,50,-95};
    int start = 0;
    int end = 9;
    while (start < end)
    {
        if (a[start] > 0 && a[end] < 0)
        {
            swap (a[start],a[end]);
            start++;
            end--;

        }
        else if (a[start] > 0 && a[end] > 0)
            end--;
        else if (a[start] < 0 && a[end] < 0)
            start++;
        else
        {
            start++;
            end--;

        }
    }
    for (int i = 0; i < 10; i++)
    cout << a[i] << " ";
    cout << endl;
    return 0;
}

