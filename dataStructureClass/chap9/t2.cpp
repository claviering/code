/*
 * Copyright (C) 
 *
 * USER claviering 
 *
 * DATE 2016-12-22
 *
 * Distributed under terms of the WTFPL license.
 */

#include <iostream>
using namespace std;

int bubbleSort(int array[],int length)
{
    while (--length)
    {
        for (int cur = 1; cur < length + 1; cur++)
        {
            if (array[cur-1] > array[cur])
            {
                array[cur-1] ^= array[cur];
                array[cur]   ^= array[cur-1];
                array[cur-1] ^= array[cur];
            }
        }
    }
    return 0;
}
int main()
{
    
    int length = 20;
    int array[length] = {99,94,84,82,74,71,65,61,59,53,42,49,32,31,29,24,11,10,9,12};
    cout << "old" << endl;
    for (int i = 0; i < length; i++)   
        cout << array[i] << " ";
    cout << endl;

    bubbleSort(array,length);

    cout << "new" << endl;
    for (int i = 0; i < length; i++)   
        cout << array[i] << " ";
    cout << endl;
    return 0;
}
