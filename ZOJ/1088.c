#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{
  int n,m,i,j,k,t,flag;   
  while(scanf("%d",&n),n){
     flag=1;
     i=1;
     while(flag){
       m=0;
       i++;
       for(j=2;j<n;j++)
         m=(m+i)%j;
       if(m==0)  flag=0;                 
     }
     printf("%d\n",i);                      
  }
  return 0;    
}
