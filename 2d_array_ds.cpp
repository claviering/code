#include <iostream>

using namespace std;
int main()
{
    int arr[6][6]={0};
    for (int i = 0; i < 6; i++) 
    {
        for (int k = 0; k < 6; k++)
        {
            cin >> arr[i][k];
        }
    }
    int max = -10000;
    for (int y = 0; y < 4; y++)
    {
        for (int x = 0; x < 4; x++)
        {
            int temp= arr[y][x] + arr[y][x+1] + arr[y][x+2] + arr[y+1][x+1] + arr[y+2][x] + arr[y+2][x+1] + arr[y+2][x+2]; 
            if (max < temp) swap (max,temp);
        }
    }
    cout << max << endl;
    return 0;
}

