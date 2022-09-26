#include <iostream>
#include<bits/stdc++.h>

double CalculoPi(int N);
using namespace std;

// Función CalculoPi: calcula el número PI a partir de una sucesión de términos
// Parameter: x
//function return PI
// Calculating Pi with Taylor Method C++
// pi = 4 * [ 1 - 1/3 + 1/5 - 1/7 + 1/9 … + ((-1)^n)/(2n + 1) ]
// The program takes an input n that determines the number of terms in
// the approximation of the value of pi and outputs the approximation.

// Include a loop that allows the user to repeat this calculation for
// new values n until the user says she or he wants to end the program.

double CalculoPi(int N)
{
    double sum = 0.0;

    for (int i=1; i<=N; i++)
      sum = sum + 1/pow(i,2);
return sqrt(6*sum);
}

int main(void)
{
    int N;
    double PI;
    cout <<"Introduzca el número de terminos que quiere que tenga la sumatoria, \n" <<
            " a partir de la cual se calcula el numero PI: ";
    cin >> N;
    PI=CalculoPi(N);
    cout << "El valor del numero PI es: " << setprecision(30) << PI << endl << endl;
    //cout << "Valor exacto de PI es " <<
    return 0;
}
