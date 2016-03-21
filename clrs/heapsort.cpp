#include <iostream>
#include <algorithm>
using namespace std;

void maxHeapify(int a[],int &size,int i)
{
    int l = 2 * i + 1;
    int r = 2 * i + 2;
    int larger;
    if (l <= size && a[l] > a[i])
        larger = l;
    else
        larger = i;
    if (r <= size && a[r] > a[larger])
        larger = r;
    else
        larger = i;
    if (larger != i)
    {
        swap (a[larger],a[i]);
        maxHeapify(a,size,larger);
    }
}

void buildMaxHeap(int a[],int &size,int len)
{
    for (int i = len / 2; i >= 0; i--)
        maxHeapify(a,size,i);
}

void heapsort(int a[],int &size)
{
    int len = size - 1;
    buildMaxHeap(a,size,len);
    for (int i = len; i >= 0; i--)
    {
        swap (a[0],a[i]);
        size--;
        maxHeapify(a,size,len);
    }
}
int main()
{
    int a[10] = {0,1,2,3,4,5,6,7,8,9};
    int size = sizeof (a) / sizeof (int);
    heapsort(a,size);
    for (int k = 0; k < 10; k++)
        cout << a[k] << endl;
    return 0;
}

