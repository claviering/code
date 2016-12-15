/*
 * Copyright (C) 
 *
 * USER claviering 
 *
 * DATE 2016-12-15
 *
 * Distributed under terms of the WTFPL license.
 */

#include <iostream>
using namespace std;

bool BinaryFind(int ar[], int length, int target)
{
    int head = 0;
    int tail = length;
    while (head < tail)
    {
        int mid = (tail - head) / 2;
        if (target == ar[mid])
            return true;
        else if (target < ar[mid])
            tail = mid;
        else if (target > ar[mid])
            head = mid;
    }
    return false;

}
int main()
{
    int ar[] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18};
    int length = 18;
    int target = 10;
    bool is_find = BinaryFind(ar, length, target);
    if (is_find)
        cout << "TRUE" << endl;
    else
        cout << "FALSE" << endl;
    return 0;
}
