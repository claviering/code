#include <iostream>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int firstData[n];
        int secondDate[n];

        for (int i = 0; i < n; i++)
        {
            cin >> firstData[i];
        }

        for (int j = 0; j < n; j++)
        {
            cin >> secondDate[j];
        }

        int index = 0;
        bool isStack = 0;
        bool isQueue = 0;
        while (index < n)
        {
            if (firstData[index] == secondDate[index])
            {
                isQueue = 1;
            }
            else
            {
                isQueue = 0;
                break;
            }
            index++;
        }

        index = 0;
        while (index < n)
        {
            if (firstData[index] == secondDate[n - index - 1])
            {
                isStack = 1;
            }
            else
            {
                isStack = 0;
                break;
            }
            index++;
        }

        if (isStack && isQueue)
            cout << "both" << endl;
        else if (isStack)
            cout << "stack" << endl;
        else if (isQueue)
            cout << "queue" << endl;
        else
            cout << "neither" << endl;

    }
    return 0;
}

