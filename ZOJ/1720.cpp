#include <iostream>
#include <cmath>
using namespace std;

const char space = ' ';
const char nega = '-';
const char zore = '0';

int main()
{
    string input;
    while (getline(cin,input))
    {
        string polynomial[8] = {"x^8","x^7","x^6","x^5","x^4","x^3","x^2","x^1"};
        int coefficients[9];
        int inputSize = input.size();

        int i = 0;
        while (i < inputSize)
        {
            int coeIndex = 0;
            bool  isNegated = 0;
            int coe = 0;

            while (input[i] != space)
            {
                if (input[i] == nega)
                {
                    isNegated = 1;
                    ++i;
                }
                int tmp = input[i++] - zore;
                coe = coe * 10 + tmp;
            }

            if (isNegated)
                coefficients[coeIndex] = -coe;
            else
                coefficients[coeIndex] = coe;
            ++i;
            ++coeIndex;
        }
        
        int k = 0;
        while (k < 8)
        {
            if (coefficients[k] < 0)
            {
                cout << "- " << abs(coefficients[k]); 
                cout << polynomial[k++];
            }
            else if (coefficients[k] == 0)
            {
                continue;
            }
            else if (coefficients[k] == 1)
            {
                cout << polynomial[k++];
            }
            else
            {
                cout << "+ " << abs(coefficients[k]); 
                cout << polynomial[k++];
            }
        }

        if (coefficients[8])
            cout << "+ "<< coefficients[8];
        else
            cout << "- " << abs(coefficients[8]); 
        cout << endl;

    }

    
    return 0;
}

