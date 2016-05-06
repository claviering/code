#include <iostream>
#include <cmath>
using namespace std;

const char NEGA = '-';
const char POSI = '+';
const char SPAC = ' ';
const string POLY[8] = {"x^8","x^7","x^6","x^5","x^4","x^3","x^2","x^1"};

int main()
{
    int input[9];
    while (cin >> input[0] >> input[1] >> input[2] >> input[3] >> input[4] >> input[5] >> input[6] >> input[7] >> input[8])
    {
        string output;
        bool firstCout = 1;
        for (int i = 0; i < 8; i++)
        {
            int tmp = input[i];
            if (tmp < 0)
            {
               if (firstCout) 
               {
                    cout << NEGA << SPAC << abs (input[i]) << POLY[i];
                    firstCout = 0;
               }
               else
               {
                    cout << SPAC << NEGA << SPAC << abs (input[i]) << POLY[i];
               }
            }
            else if (tmp == 0)
            {
                continue;
            }
            else if (tmp == 1)
            {
               if (firstCout) 
               {
                    cout << POLY[i];    
                    firstCout = 0;
               }
               else
               {
                    cout << SPAC << POSI << SPAC << POLY[i];    
               }
            }
            else 
            {
               if (firstCout) 
               {
                    cout << input[i] << POLY[i];
                    firstCout = 0;
               }
               else
               {
                    cout << SPAC << POSI << SPAC << input[i] << POLY[i];
               }

            }
        }
        if (firstCout)
        {
            if (input[8] < 0)
                cout << NEGA << abs(input[8]) << endl;
            else if (input[8] == 0)
                cout << endl;
            else if (input[8] == 1)
                cout << input[8] << endl;
            else 
                cout << input[8] << endl;
        }
        else
        {
            if (input[8] < 0)
                cout << SPAC << NEGA  << SPAC << abs(input[8]) << endl;
            else if (input[8] == 0)
                cout << endl;
            else if (input[8] == 1)
                cout << SPAC << POSI << SPAC << input[8] << endl;
            else 
                cout << SPAC << POSI << SPAC << input[8] << endl;
            
        }
    }
    
    return 0;
}

