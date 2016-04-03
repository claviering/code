//输出组合
#include   <iostream>
using namespace std;
void  jisuan(int a[],int m,int n,int k,int temp);
int numOfComb(int m, int n);
int main()
{
    int  m,n;
    cout<<"请输入M和N："<<endl;
    cin>>m>>n;
    cout<<"一共  "<<numOfComb(m,n)<<"  种组合"<<endl;
    int   a[100];
    jisuan(a,m,n,-1,-1);
    return 0;
}
void  jisuan(int a[],int m,int n,int k,int temp)
{
    temp++;
    if(temp<n)
        for(int i=k+1;i<m;i++)
        {
            a[temp]=i+1;       //赋值
            jisuan(a,m,n,i,temp);    //递归调用
        }
    else
    {
        for(int j=0;j<n;j++)
        {
            cout<<"\t"<<a[j];  //输出
        }
        cout<<endl;
    }
}
//计算个数
int numOfComb(int m, int n)
{
    int r=1;
    int i;
    for(i=1; i<=n; ++i)
    {
        r *= (m-i+1);
        r /= i;
    }
    return r;
}
