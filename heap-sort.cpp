#include <iostream>
#include <utility>
using namespace std;
int parent(int i)
{
    return i / 2;
}
int left(int i)
{
    return i * 2;
}
int right(int i)
{
    return i * 2 + 1;
}
void maxHeapify(int a[],int i)
{
    int l = left(i);
    int r = right(i);
    int larger = i;
    a[l] > a[i] ? larger = l : larger = i;
    if (a[r] > a[larger])
        larger = r;
    if (larger != r)
    {
        swap (a[i], a[larger]);
        maxHeapify(a,larger);
    }
}
void buildMaxHeap(int a[])
{
    int aLength = sizeof (a) / sizeof (int);
    for (int  i = aLength / 2; aLength > 0; aLength--)
        maxHeapify(a,i);
}
void heapSort(int a[])
{
    buildMaxHeap(a);
    int a_heap_size = sizeof (a) / sizeof (int);
    int aLength = a_heap_size;
    for (int i = aLength - 1; aLength > 0; aLength--)
    {
        swap (a[0],a[i]);
        a_heap_size--;
        maxHeapify(a,1);
    }
}
int main()
{
    int a[5] = {3,5,6,7,1};
    heapSort(a);
    for (int i=0;i<5;i++)
        cout << a[i] << endl;
    return 0;
}

