
#include "pch.h"
#include <iostream>

int newGap(int gap)
{
	gap = gap / 1.3;
	if (gap == 9 || gap == 10)
		gap = 11;
	if (gap < 1)
		return 1;
	return gap;
}

void combSort(int array[], int length)
{
	int gap = length;
	bool swapped;
	do
	{
		swapped = false;
		gap = newGap(gap);
		for (int i = 0; i < length - gap; ++i)
		{
			if (array[i] > array[i + gap])
			{
				swapped = true;
				int temp = array[i];
				array[i] = array[i + gap];
				array[i + gap] = temp;
			}
		}
	} while (gap > 1 || swapped);
}

void swap(int *xp, int *yp) 
{
	int temp = *xp;
	*xp = *yp;
	*yp = temp;
}

void swapI(int xp, int yp)
{
	int temp = xp;
	xp = yp;
	yp = temp;
}
void selectionSort(int arr[], int n)
{
	int i, j, min_idx;

	// One by one move boundary of unsorted subarray  
	for (i = 0; i < n - 1; i++)
	{
		// Find the minimum element in unsorted array  
		min_idx = i;
		for (j = i + 1; j < n; j++)
			if (arr[j] < arr[min_idx])
				min_idx = j;

		// Swap the found minimum element with the first element  
		swap(&arr[min_idx], &arr[i]);
	}
}

void bubbleSort(int arr[], int n)
{
	int i, j;
	for (i = 0; i < n - 1; i++)

		// Last i elements are already in place  
		for (j = 0; j < n - i - 1; j++)
			if (arr[j] > arr[j + 1])
				swap(&arr[j], &arr[j + 1]);
}

void CocktailSort(int a[], int n)
{
	bool swapped = true;
	int start = 0;
	int end = n - 1;

	while (swapped) {
		// reset the swapped flag on entering 
		// the loop, because it might be true from 
		// a previous iteration. 
		swapped = false;

		// loop from left to right same as 
		// the bubble sort 
		for (int i = start; i < end; ++i) {
			if (a[i] > a[i + 1]) {
				swapI(a[i], a[i + 1]);
				swapped = true;
			}
		}

		// if nothing moved, then array is sorted. 
		if (!swapped)
			break;

		// otherwise, reset the swapped flag so that it 
		// can be used in the next stage 
		swapped = false;

		// move the end point back by one, because 
		// item at the end is in its rightful spot 
		--end;

		// from right to left, doing the 
		// same comparison as in the previous stage 
		for (int i = end - 1; i >= start; --i) {
			if (a[i] > a[i + 1]) {
				swapI(a[i], a[i + 1]);
				swapped = true;
			}
		}

		// increase the starting point, because 
		// the last stage would have moved the next 
		// smallest number to its rightful spot. 
		++start;
	}
}

void insertionSort(int arr[], int n)
{
	int i, key, j;
	for (i = 1; i < n; i++)
	{
		key = arr[i];
		j = i - 1;

		/* Move elements of arr[0..i-1], that are
		greater than key, to one position ahead
		of their current position */
		while (j >= 0 && arr[j] > key)
		{
			arr[j + 1] = arr[j];
			j = j - 1;
		}
		arr[j + 1] = key;
	}
}

int shellSort(int arr[], int n)
{
	// Start with a big gap, then reduce the gap 
	for (int gap = n / 2; gap > 0; gap /= 2)
	{
		// Do a gapped insertion sort for this gap size. 
		// The first gap elements a[0..gap-1] are already in gapped order 
		// keep adding one more element until the entire array is 
		// gap sorted  
		for (int i = gap; i < n; i += 1)
		{
			// add a[i] to the elements that have been gap sorted 
			// save a[i] in temp and make a hole at position i 
			int temp = arr[i];

			// shift earlier gap-sorted elements up until the correct  
			// location for a[i] is found 
			int j;
			for (j = i; j >= gap && arr[j - gap] > temp; j -= gap)
				arr[j] = arr[j - gap];

			//  put temp (the original a[i]) in its correct location 
			arr[j] = temp;
		}
	}
	return 0;
}