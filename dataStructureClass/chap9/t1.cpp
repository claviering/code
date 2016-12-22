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

void quickSortRecursive(int arr[], int start, int end)
{
	if (start >= end) 
        return;

	int mid = arr[end];
	int left = start; 
    int right = end - 1;

	while (left < right) 
    {
		while (arr[left] < mid && left < right) 
            left++;
		while (arr[right] >= mid && left < right) 
            right--;

		swap(arr[left], arr[right]);
	}

	if (arr[left] >= arr[end])
		swap(arr[left], arr[end]);
	else
		left++;

	quickSortRecursive(arr, start, left - 1);
	quickSortRecursive(arr, left + 1, end);
}

void quickSort(int arr[], int len) 
{
	quickSortRecursive(arr, 0, len - 1);
}

int main()
{
    int length = 20;
    int array[length] = {99,94,84,82,74,71,65,61,59,53,42,49,32,31,29,24,11,10,9,12};
    cout << "old" << endl;
    for (int i = 0; i < length; i++)   
        cout << array[i] << " ";
    cout << endl;

    quickSort(array,length);

    cout << "new" << endl;
    for (int i = 0; i < length; i++)   
        cout << array[i] << " ";
    cout << endl;
    return 0;
}
