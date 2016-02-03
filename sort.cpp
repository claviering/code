#include <iostream>
using namespace std;
int StraightInsertionSort(int array[],int length);
int main(){
    int length;
    cin>>length;
    int array[length];
    for(int i=0;i<length;i++){
        cin>>array[i];
    }
    StraightInsertionSort(array,length);
    return 0;
}
int StraightInsertionSort(int array[],int length){
    int j=0,temp=0;
    for(int i=1;i<length;i++){
        temp=array[i];
        for(j=i-1;j>=0 && temp<array[j];j--)    array[j+1]=array[j];
        array[j+1]=temp;
    }
    for(int i=0;i<length;i++)   cout<<array[i];
    cout<<endl;
    return 0;
}


