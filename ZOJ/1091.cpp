#include <iostream>
using namespace std;


int main()
{
    string start;
    string end;
    while (cin >> start >> end)
    {
        int s_x = start[0] - 'a';
        int s_y = start[1] - '1';
        int e_x = end[0] - 'a';
        int e_y = end[1] - '1';
        cout << s_x << s_y << endl << e_x << e_y << endl;
        
    }
    return 0;
}

