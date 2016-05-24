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
        Knight()
        {
            here = 0;
        }
};

queue<Knight> q;

int bfs(Knight start,Knight end)
{
    if (start.x == end.x && start.y == end.y)
        return start.step;

    for (int i = 0; i < 8; i++)
    {
        Knight now;
        now.x = start.x + x[i];
        now.y = start.y + y[i];
        if (now.here || now.x < 0 || now.y < 0 || now.x > 7 || now.y > 7)
            continue;
        now.step = start.step + 1;
        now.here = 1;

        if (start.x == end.x && start.y == end.y)
            return now.step;

        q.push (now);
    }

    Knight first = q.front ();
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
        kStart.step = 0;
        kStart.here = 1;

        kEnd.x = xEnd;
        kEnd.y = yEnd;

        int anw = bfs(kStart,kEnd);
        cout << anw << endl;
    } 
    return 0;
}

