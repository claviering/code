#include <iostream>
using namespace std;

void dfs(int a[], int n, int depth)
{
    if (depth)
    {
        for (int i = 0; i < n; i++)
        {
            cout << a[i] << "-";
            dfs(a,n,depth-1);
        }
        cout << endl;
    }
    else
        return;
}

void dfs_1(int a[], int n, int depth)
{
    if (depth)
    {
        for (int i = 0; i < n; i++)
        {
            cout << a[0] << "-";
            dfs_1(a,n,depth-1);
        }
        cout << endl;
    }
    else
        return;
    //cout << a[1] << "-";
    //cout << a[2] << "-";
    
}

int main()
{
    int a[5] = {1,2,3,4,5};
    dfs_1(a,2,2);
    return 0;
}

