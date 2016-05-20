#include <iostream>
#include <queue>
using namespace std;

class point
{
    public:
        int step;
        bool here;
};

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

        walk.push(point[x][y]);

    } 
    return 0;
}

