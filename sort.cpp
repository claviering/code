#include <iostream>
using namespace std;
int StraightInsertionSort(int array[],int length);
int bubbleSort(int array[],int length);
int selectionSort(int array[],int length);
int main()
{
    int length;
    cin>>length;
    int array[length];
    for(int i = 0; i < length; i++)
    {
        cin>>array[i];
    }
    cout<<"old"<<endl;
    for(int i=0; i < length; i++)   cout<<array[i]<<" ";
    cout<<endl;
    selectionSort(array,length);
    cout<<"new"<<endl;
    for(int i = 0; i < length; i++)   cout<<array[i]<<" ";
    cout<<endl;
    return 0;
}
int StraightInsertionSort(int array[],int length)
{
    int j=0,temp=0;
    for(int i = 1; i < length; i++)
    {
        temp=array[i];
        for(j = i - 1; j >= 0 && temp<array[j]; j--)    array[j+1]=array[j];
        array[j+1]=temp;
    }
    return 0;
}
int bubbleSort(int array[],int length)
{
    while(--length){
        for(int cur = 1; cur < length + 1; cur++)
        {
            if(array[cur-1] > array[cur]){
                array[cur-1] ^= array[cur];
                array[cur]   ^= array[cur-1];
                array[cur-1] ^= array[cur];
            }
        }
    }
    return 0;
}
int selectionSort(int array[],int length)
{
    for(int i = 0; i < length - 1; length--)
    {
        int bigger=0;
        for(int cur = 1; cur < length; cur++)
        {
            if(array[bigger] < array[cur])  bigger=cur; 
        }
        if(bigger < length - 1){
            array[bigger]   ^= array[length-1];
            array[length-1] ^= array[bigger];
            array[bigger]   ^= array[length-1];
        }
    }
    return 0;
}
int shellSort(int array[],int length)
{
    for(int gap = length >> 2; gap > 0; gap >>= 2)
    {
        for(int i=gap; i < n; i++)
        {
            for(int j = i - gap; j >= 0 && array[j] > array[i]; j-=gap)
            {
                array[j] ^= array[i];
                array[i] ^= array[j];
                array[j] ^= array[i];
            }
        }
    }
}
