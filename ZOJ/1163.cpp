#include<stdio.h>
#include<iostream>
using namespace std;
int main()
{
    double m[501][501];
    for(int i=0;i<501;i++)
    {
         m[0][i] = 1;
    }
    for(int i=1;i<=500;i++)
    {
        for(int j=1;j<=500;j++)
        {
            if(i>=j)
            {
                m[i][j] = m[i-j][j-1]+m[i][j-1];
            }else
            {
                m[i][j] = m[i][j-1];
            }
        }
    }
    int N;
    cin >> N;
    while(N)
    {
        printf("%0.0lf\n",m[N][N]-1);
        cin >>N;
    }
}
