#include <iostream>
using namespace std;
int StraightInsertionSort(int array[],int length);
int bubbleSort(int array[],int length);
int selectionSort(int array[],int length);
int shellSort(int array[],int length);
int main()
{
    int length=20;
    int array[length]={99,94,84,82,74,71,65,61,59,53,42,49,32,31,29,24,11,10,9,12};
    cout<<"old"<<endl;
    for(int i=0; i < length; i++)   cout<<array[i]<<" ";
    cout<<endl;
    shellSort(array,length);
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
    int gap,i,j;
    int temp;
    for(gap = length >> 1; gap > 0; gap >>= 1)
    {
        for(i = gap; i < length; i++)
        {
            temp = array[i];
            for(j = i - gap; j >= 0 && array[j] > temp; j-= gap)
                array[j + gap] = array[j];
            array[j + gap] = temp;
        }
    }
}
