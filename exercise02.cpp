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

#define MAXIMUM 1000000 //1e6

using namespace std;

// implement your code here
//***************************************************
typedef unsigned long long int ulli;

vector<ulli> sieve(ulli n) {
    // Create a boolean vector "prime[0..n]" and
    // initialize all entries it as true. A value
    // in prime[i] will finally be false if i is
    // Not a prime, else true.
    vector<bool> prime(n+1,true);
    prime[0] = false;
    prime[1] = false;
    int m = sqrt(n);

    for (ulli p=2; p<=m; p++) {
        // If prime[p] is not changed, then it
        // is a prime
        if (prime[p]) {
            // Update all multiples of p
            for (ulli i=p*2; i<=n; i += p)
            prime[i] = false;
        }
    }

    // push all the primes into the vector ans
    vector<ulli> ans;
    for (int i=0;i<n;i++) {
      if (prime[i]) {
        ans.push_back(i);
      }
    }
    return ans;
}

// Used to remove zeros from a vector using
// library function remove_if()
bool isZero(ulli i) {
    return i == 0;
}

vector<ulli> sieveRange(ulli start,ulli end) {
    // find primes from [0..start] range
    vector<ulli> s1 = sieve(start);

    // find primes from [0..end] range
    vector<ulli> s2 = sieve(end);
    vector<ulli> ans(end-start);

    // find set difference of two vectors and
    // push result in vector ans
    // O(2*(m+n)-1)
    set_difference(s2.begin(), s2.end(), s1.begin(),
                      s2.end(), ans.begin());

    // remove extra zeros if any. O(n)
    vector<ulli>::iterator itr =
                    remove_if(ans.begin(),ans.end(),isZero);

    // resize it. // O(n)
    ans.resize(itr-ans.begin());

    return ans;
}
//***************************************************

int main(int argc, char* argv[]) {
	int i;
	double ms;

	unsigned long long int result = 2;
	ulli start = 3;
	ulli end = MAXIMUM;

	cout << "Starting..." << endl;
	ms = 0;
	for (int i = 0; i < N; i++) {
		start_timer();
		// call your code here.
		vector<ulli> ans = sieveRange(start,end);
		for (auto i:ans) {
      //cout<<i<<"\n";
      result = result + i;
    }

		ms += stop_timer();
	}
	result = result + (N-1)*2;
	cout << "result = " << setprecision(5) << result << "\n";
	cout << "avg time = " << setprecision(5) << (ms / N) << " ms" << endl;

	return 0;
}
