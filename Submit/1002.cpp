#include <iostream>
using namespace std;
int inputMatrix();
int outputMatrix(int n,int array[]);
int main(){
    inputMatrix();
    return 0;
}
int inputMatrix(){
    int n,matrix[10][10]={0};
    cin>>n;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>matrix[i][j];
        }
    }
    outputMatrix(n,matrix[]);
    return 0;
}
int outputMatrix(int n,int matrix[]){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<matrix[i][j];
        }
        cout<<endl;
    }
    return 0;
}


