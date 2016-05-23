#include <iostream>
#include <queue>
using namespace std;

int x[8] = {1,1,2,2,-1,-1,-2,-2};
int y[8] = {2,-2,1,-1,-2,2,-1,1};

class Knight
{
    public:
        int x;
        int y;
        int step;
        bool here;
};

queue<Knight> q;

void bfs(Knight start,Knight end)
{
    if (start.x == end.x && start.y == end.y)
        return;

    for (int i = 0; i < 8; i++)
    {
        Knight now;
        now.x = start.x + x[i];
        now.y = start.y + y[i];
        if (now.x < 0 || now.y < 0 || now.x > 7 || now.y > 7)
            continue;
        q.push (now);
    }

    Knight first;
    first = q.front ();
    q.pop ();
    bfs (first,end);
}

int main()
{
    string a;
    string b;
    while (cin >> a >> b)
    {
        int x = a[0] - 'a';
        int y = a[1] - '1';
        int xEnd = b[0] - 'a';
        int yEnd = b[1] - '1';

        Knight kStart;
        Knight kEnd;


        kStart.x = x;
        kStart.y = y;

        kEnd.x = xEnd;
        kEnd.y = yEnd;

    } 
    return 0;
}

