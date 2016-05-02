#include <iostream>
using namespace std;
int main()
{
    int n;
    cin >> n;
    long long num = 1;
    for (int i = 0; i <= n; i++)
    {
        num <<= 1;
    }
    cout << num - 2 << endl;
    return 0;
}

