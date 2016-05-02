#include <iostream>
#include <string>

using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string st;
        cin >> st;
        int num = 0;
        for (int i=0, j=1; j < st.size(); i++, j++)
        {
            if (st[i] != st[j]) num++;
        }
        cout << st.size() - num - 1 << endl;
    }
    return 0;
}

