#include <iostream>

using namespace std;
int main()
{
    int n;
    int m;
    int save = 0;
    cin >> n >> m;
    for (int j = 2; j <= n; j++)
        save = (save + m) % j;
    cout << save + 1 << endl;
    return 0;
}

