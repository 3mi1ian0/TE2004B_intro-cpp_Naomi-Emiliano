// =================================================================
//
// File: exercise03.cpp
// Author(s):
//            Naomi Estefanía Nieto Vega - A01706095
//            Emiliano Mendoza Nieto - A01706083
//
// Description: This file contains the code that implements the
//				enumeration sort algorithm. The time this implementation
//				takes ill be used as the basis to calculate the
//				improvement obtained with parallel technologies.
//
// Copyright (c) 2022 by Tecnologico de Monterrey.
// All Rights Reserved. May be reproduced for any non-commercial
// purpose.
//
// =================================================================

#include <iostream>
#include <iomanip>
#include <cstring>
#include "utils.h"

const int SIZE = 200000; //1e4

using namespace std;

// implement your code here
//***************************************************
// A utility function to swap two elements
void swap(int* a, int* b) {
    int t = *a;
    *a = *b;
    *b = t;
}

/* This function takes last element as pivot, places
the pivot element at its correct position in sorted
array, and places all smaller (smaller than pivot)
to left of pivot and all greater elements to right
of pivot */
int partition(int arr[], int low, int high) {
    int pivot = arr[high]; // pivot
    int i
        = (low
           - 1); // Index of smaller element and indicates
                 // the right position of pivot found so far

    for (int j = low; j <= high - 1; j++) {
        // If current element is smaller than the pivot
        if (arr[j] < pivot) {
            i++; // increment index of smaller element
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

/* The main function that implements QuickSort
arr[] --> Array to be sorted,
low --> Starting index,
high --> Ending index */
void quickSort(int arr[], int low, int high) {
    if (low < high) {
        /* pi is partitioning index, arr[p] is now
        at right place */
        int pi = partition(arr, low, high);

        // Separately sort elements before
        // partition and after partition
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

/* Function to print an array */
void printArray(int arr[], int size) {
    int i;
    for (i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
}
//***************************************************

int main(int argc, char* argv[]) {
	int *a;
	double ms;

	a = new int[SIZE];
	random_array(a, SIZE);
	display_array("before", a);

	cout << "Starting..." << endl;
	ms = 0;
	// create object here
	for (int i = 0; i < N; i++) {
		start_timer();

		// call your code here.
		quickSort(a, 0, SIZE - 1);

		ms += stop_timer();
	}
	display_array("after", a);
	cout << "avg time = " << setprecision(5) << (ms / N) << " ms" << endl;

	delete [] a;
	return 0;
}
