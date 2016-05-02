#include <iostream>
#include <cstdio>
using namespace std;
int main()
{
    int n;
    int m;
    while (cin >> n >> m)
    {
        int maze[n][m];
        int walk = 0;
        int sum = 0;
        char path[10000];
        if (n % 2)
        {
            for (int i = 0; i< n; i++)
            {
                for (int j = 0; j< m; j++)
                {
                    cin >> maze[i][j];
                    sum += maze[i][j];

                }
            }
        }
        else
        {
            for (int i = 0; i< n; i++)
            {
                for (int j = 0; j< m; j++)
                {
                    cin >> maze[i][j];
                }
            }

        }

        if (n % 2)
        {
            for (int i = 0; i< n; i++)
            {
                for (int j = 0; j< m; j++)
                {
                    if (j+1 < m)
                    {
                        if ((i+1) % 2)
                            path[walk++] = 'R';
                        else
                            path[walk++] = 'L';
                    }
                }
                path[walk++] = 'D';
            }

        }

        else
        {
            n -= 2;
            for (int i = 0; i< n; i++)
            {
                for (int j = 0; j< m; j++)
                {
                    if (j+1 < m)
                    {
                        if ((i+1) % 2)
                            path[walk++] = 'R';
                        else
                            path[walk++] = 'L';
                    }
                    sum += maze[i][j];
                }
                path[walk++] = 'D';
            }

            int walkRight = 0;
            for (int r = 0; r < m; r++)
            {
                walkRight += maze[n][r];
            }

            int walkDown = 0;
            for (int d = 0; d < m; d++)
            {
                walkDown += maze[n+1][d];
            }

            if (walkRight > walkDown)
            {
                sum += walkRight;
                for (int y = 0; y < m-1; y++)
                    path[walk++] = 'R';
                path[walk++] = 'D';
                path[walk++] = 'D';
            }
            else
            {
                sum += walkDown;
                path[walk++] = 'D';
                for (int y = 0; y < m-1; y++)
                    path[walk++] = 'R';
            }



        }
        cout << sum << endl;
        if (n % 2)
            walk--;
        for (int w = 0; w < walk; w++)
            printf ("%c",path[w]);
        cout << endl;

    }
    return 0;
}

