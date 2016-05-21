#include <iostream>
#include <queue>
using namespace std;

int x[8] = {1,1,2,2,-1,-1,-2,-2};
int y[8] = {2,-2,1,-1,-2,2,-1,1};

class point
{
    public:
        int step;
        bool here;
};

void bfs(point &poi)
{
    walk.push (poi);
    point tmp = walk.front();
        
        
}

int main()
{
    string a;
    string b;
    while (cin >> a >> b)
    {
        int x = a[0] - 'a';
        int y = a[1] - '1';
        int xExit = b[0] - 'a';
        int yExit = b[1] - '1';

        queue<point> walk;

        point poi[8][8];

        for (int i = 0; i < 8; i++)
        {
            for (int j = 0; j < 8; j++)
                poi[i][j].here = 1;
        }

        bfs(poi[x][y]);

    } 
    return 0;
}

