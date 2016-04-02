#include <iostream>
using namespace std;
int main()
{
    int t;
    while (t--)
    {
        int n;
        int m;
        string a[n];
        string b[m];
        cin >> n >> m;
        for (int i = 0; i < n; i++)
            cin >> a[i];
        for (int j = 0; j < m; j++)
            cin >> b[j];
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                length_of_b = b[j].size();
                find (a[i],a[i] + length_of_b,b[j]);
            }
            
        }
    }
    return 0;
}

