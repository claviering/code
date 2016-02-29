#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        bool ok = 1;
        int len = s.size();
        for (int i=1, j=len-1; i < len; i++, j--)
        {
            int d_s =abs ((int)s[i] - (int)s[i-1]);
            int d_r =abs ((int)s[j-1] - (int)s[j]);
            if (d_s != d_r) 
            {
                ok = 0;
                break;
            }
        }
        if (ok)
            cout << "Funny" << endl;
        else
            cout << "Not Funny" << endl;
    }
    return 0;
}

