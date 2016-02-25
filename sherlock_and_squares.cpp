#include <iostream>
#include <cmath>

using namespace std;
int is_squrt(int a,int b);
int num = 0;
int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int a;
        int b;
        cin >> a >> b;
        num = 0;
        is_squrt(a,b);
        cout << num << endl;
    }
    return 0;
}
int is_squrt(int a,int b)
{
    if (a == b)
    {
        int squrtRoot = sqrt (a);
        if (squrtRoot * squrtRoot == a) 
            num++;
        return 0;
    }
    else
    {
        is_squrt(a,(a + b) / 2);
        is_squrt((a + b) / 2 + 1,b);
    }
}

