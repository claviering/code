#include <iostream>
using namespace std;
int StraightInsertionSort(int array[],int length);
int bubbleSort(int array[],int length);
int main(){
    int length;
    cin>>length;
    int array[length];
    for(int i=0;i<length;i++){
        cin>>array[i];
    }
    cout<<"old"<<endl;
    for(int i=0;i<length;i++)   cout<<array[i]<<" ";
    cout<<endl;
    bubbleSort(array,length);
    cout<<"new"<<endl;
    for(int i=0;i<length;i++)   cout<<array[i]<<" ";
    cout<<endl;
    return 0;
}
int StraightInsertionSort(int array[],int length){
    int j=0,temp=0;
    for(int i=1;i<length;i++){
        temp=array[i];
        for(j=i-1;j>=0 && temp<array[j];j--)    array[j+1]=array[j];
        array[j+1]=temp;
    }
    return 0;
}
int bubbleSort(int array[],int length){
    while(--length){
        for(int cur=1;cur<length+1;cur++){
            if(array[cur-1] > array[cur]){
                array[cur-1] ^= array[cur];
                array[cur]   ^= array[cur-1];
                array[cur-1] ^= array[cur];
            }
        }
    }
    return 0;
}
