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

const int SIZE = 10000; //1e4

using namespace std;

// implement your code here
//***************************************************
int* sort(int *array, int size){

	int *temp = new int[size];
	int cont;

	for(int i = 0; i < size; i++) {
		cont = 0;

		for(int j = 0; j < size; j++) {

			if(array[j] < array[i]){
				cont++;
				} else if (array[i] == array[j] && j < i) {
				      cont++;
        }
			}
		temp[cont] = array[i];
	}
	return temp;
}
//***************************************************

int main(int argc, char* argv[]) {
	int *a, *next;
	double ms;

	a = new int[SIZE];

	random_array(a, SIZE);
	display_array("before", a);

	cout << "Starting..." << endl;
	ms = 0;
	// create object here
  next = new int[SIZE];

	for (int i = 0; i < N; i++) {
		start_timer();

		// call your code here.
		next = sort(a, SIZE-1);

		ms += stop_timer();
	}
	display_array("after", next);
	cout << "avg time = " << setprecision(5) << (ms / N) << " ms" << endl;

	delete [] a;
	return 0;
}
