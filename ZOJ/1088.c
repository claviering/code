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

//#include <algorithm>
//#include <iostream>
//
//using namespace std;
//
//int main()
//{
//    int n;
//    while (cin >> n && n > 2)
//    {
//        int building[n];
//        int temp[n];
//        int i;
//        for (i = 1; i <= n; i++)
//        {
//            building[i-1] = i;
//        }
//
//        building[0] = 0;
//        int step = 1;
//        int ok = 0;
//        while (!ok)
//        {
//            step++;
//            for (i = 0; i < n; i++)
//            {
//                temp[i] = building[i];
//            }
//            int index = step;
//            int timeOfCut = 1;
//            while (temp[1])
//            {
//                index %= n;
//
//                while (!temp[index])
//                {
//                    index++;
//                    index %= n;
//                }
//
//                temp[index] = 0;
//                timeOfCut++;
//                if (temp[1] == 0)
//                    break;
//                int p =1;
//                while (p <= step)
//                {
//                    index++;
//                    index %= n;
//                    if (temp[index] > 0)
//                        p++;
//                }
//            }
//            ok = timeOfCut == n ? 1 : 0;
//        }
//        cout << step << endl;
//    }
//    return 0;
//}
//
