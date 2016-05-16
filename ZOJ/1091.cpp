#include <iostream>
#include <cstring>
using namespace std;

const string display0 = "To get from ";
const string display1 = " to ";
const string display2 = " takes ";
const string display3 = " knight moves";
int xMove[] = {1,1,2,2,-1,-1,-2,-2};
int yMove[] = {2,-2,1,-1,2,-2,1,-1};

int move[8][8];

void bfs(int x,int y,int step,int xExit,int yExit)
{
    if (x<0 || y<0 || x>8 || y>8 || move[x][y] <= step || x == xExit || y == yExit)
        return;
    move[x][y] = step++;
    for (int i = 0; i < 8; i++)
        bfs(x + xMove[i],y + yMove[i],step,xExit,yExit);

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
        memset (move,10,sizeof (move));
        bfs(x,y,0,xExit,yExit);
        int knightMoves = move[xExit][yExit];
        cout << display0 << a << display1 << b << display2 << knightMoves << display3 << endl;
    }
     
    return 0;
}

