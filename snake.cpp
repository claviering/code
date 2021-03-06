/* 
**input a number n output n by n like a snake
**input
**4
**output
**10  11  12   1
** 9  16  13   2
** 8  15  14   3
** 7   6   5   4
*/

#include<iostream>
#include<iomanip>
using namespace std;
int main(){
    int n;
    cin>>n;
    const int MAX=256; //the size of array
    int array[MAX][MAX]={0};//array
    if(n%2>0)   array[n/2][n/2]=n*n;
    int r_down=0,r_up=n-1,c_left=n-1,c_right=0,i=1;
    for(int g=0;g<n/2;g++){//contral the number,n*n
        for(int j=r_down;j<c_left;j++){//full up the n-1 rank
            array[j][c_left]=i;   
            i++;//number add one
        }
        for(int k=c_left;k>r_down;k--){//full up the n-1 column
            array[r_up][k]=i;
            i++;
        }
        for(int c=r_up;c>r_down;c--){//full up the 0 rank
            array[c][r_down]=i;
            i++;
        }   
        for(int b=c_right;b<c_left;b++){//full up the 0 column
            array[r_down][b]=i;
            i++;
        }   
        r_down++;c_left--;r_up--;c_right++;//go inside
    }
    for(int p=0;p<n;p++){//output the snake
        for(int q=0;q<n;q++){
            cout<<setw(4)<<array[p][q];
        }
        cout<<endl;
    }
    return 0;
}
