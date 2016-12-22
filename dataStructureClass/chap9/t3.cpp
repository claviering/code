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

int StraightInsertionSort(int array[],int length)
{
    int j = 0;
    int temp = 0;
    for (int i = 1; i < length; i++)
    {
        temp = array[i];
        for (j = i - 1; j >= 0 && temp < array[j]; j--)
            array[j+1] = array[j];
        array[j+1] = temp;
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

    StraightInsertionSort(array,length);

    cout << "new" << endl;
    for (int i = 0; i < length; i++)   
        cout << array[i] << " ";
    cout << endl;
    return 0;
}
