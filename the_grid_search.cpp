#include <iostream>
#include <string>

using namespace std;
int main()
{
    int t;
    cin >>  t;
    while(t--)
    {
        int R,C;
        cin >> R >> C;
        string bigGrid[R];
        for (int j = 0; j < R; j++)
        {
            cin >> bigGrid[j];
        }
        int r,c;
        cin >> r >> c;
        string smallGrid[r];
        for (int j = 0; j < r; j++)
        {
            cin >> smallGrid[j];
        }
        bool ok = 0;
        int small_i = 0;
        int big_i;
        for (int k = 0; k < R; k++)
        {
            size_t found = bigGrid[k].find(smallGrid[small_i]);
            big_i = k;
            if (found != string::npos)
            {
                ok = 1;
                for (int y = 1; y < r; y++)
                {
                    big_i++;
                    size_t nextFound = bigGrid[big_i].find(smallGrid[y]);
                    if (nextFound != string::npos)
                    {
                        small_i++;
                        big_i++;
                        ok = 1;
                    }
                    else
                    {
                        ok = 0;
                        small_i = 0;
                        break;
                    }
                }
                if (ok) break;
            }
            else ok = 0;
        }
        if (ok)  cout << "YES" << endl;
        else    cout << "NO" << endl;
    }
    return 0;
}

