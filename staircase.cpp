#include <iostream>

using namespace std;
int main()
{
    int n;
    cin >> n;
    for(int i = 0, j = n; i < n; i++, j--)
    {
        for(int p = 1; p < j; p++)  cout << " ";
        for(int p = 0; p <= i; p++)  cout << "#";
        cout << endl;
    }
    return 0;
}

