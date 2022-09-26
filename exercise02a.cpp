// =================================================================
//
// File: exercise02.cpp
// Author(s):
//            Naomi Estefanía Nieto Vega - A01706095
//            Emiliano Mendoza Nieto - A01706083
//
// Description: This file contains the code that performs the sum of
//				all prime numbers less than or equal to MAXIMUM. The
//				time this implementation takes will be used as the
//				basis to calculate the improvement obtained with
//				parallel technologies.
//
// Copyright (c) 2022 by Tecnologico de Monterrey.
// All Rights Reserved. May be reproduced for any non-commercial
// purpose.
//
// =================================================================

#include <iostream>
#include <iomanip>
#include <cstring>
#include <cmath>
#include <algorithm>
#include "utils.h"
#include<bits/stdc++.h>
#include <bitset>

#define MAXIMUM 1000000 //1e6

using namespace std;

// implement your code here
//***************************************************
bitset<500001> Primes;
unsigned long long int SieveOfEratosthenes(int n) {
    Primes[0] = 1;
    unsigned long long int sum = 2;
    for (int i = 3; i*i <= n; i += 2) {
        if (Primes[i / 2] == 0) {
            for (int j = 3 * i; j <= n; j += 2 * i) {
                Primes[j / 2] = 1;
        }
      }
    }
    for (int i = 1; i <= MAXIMUM; i++) {
		    if (i % 2 == 1 && Primes[i / 2] == 0) {
					sum = sum + i;
				}
		}
    return sum;
}
//***************************************************

int main(int argc, char* argv[]) {
	int i;
	double ms;
  unsigned long long int result = 0;

	cout << "Starting..." << endl;
	ms = 0;
	for (int i = 0; i < N; i++) {
		start_timer();
		// call your code here.
		result = SieveOfEratosthenes(MAXIMUM);
		ms += stop_timer();
	}

	cout << "result = " << setprecision(5) << result << "\n";
	cout << "avg time = " << setprecision(5) << (ms / N) << " ms" << endl;

	return 0;
}
