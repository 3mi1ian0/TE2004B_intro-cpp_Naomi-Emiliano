// =================================================================
//
// File: exercise01.cpp
// Author(s):
// Description: This file contains the code to count the number of
//				even numbers within an array. The time this implementation
//				takes will be used as the basis to calculate the
//				improvement obtained with parallel technologies.
//
// Copyright (c) 2022 by Tecnologico de Monterrey.
// All Rights Reserved. May be reproduced for any non-commercial
// purpose.
//
// =================================================================

#include <iostream>
#include <iomanip>
#include <climits>
#include <algorithm>
#include "utils.h"

const int SIZE = 100000000; //1e8

using namespace std;

// implement your code here
//***************************************************
double countEven(int arr[], int size){

    int cont = 0;

    for (int i=1; i<=size; i++) {

      if(arr[i]%2 == 0) {

        cont = cont + 1;
      }
    }

return cont;
}
//***************************************************


int main(int argc, char* argv[]) {
	int *a;
	double ms;
	int result = 0;

	a = new int[SIZE];
	fill_array(a, SIZE);
	display_array("a", a);

	cout << "Starting..." << endl;
	ms = 0;
	for (int i = 0; i < N; i++) {
		start_timer();

		// call your code here
		result = countEven(a, SIZE);

		ms += stop_timer();
	}
	cout << "result = " << setprecision(5) << result << "\n";
	cout << "avg time = " << setprecision(5) << (ms / N) << " ms" << endl;

	delete [] a;
	return 0;
}
