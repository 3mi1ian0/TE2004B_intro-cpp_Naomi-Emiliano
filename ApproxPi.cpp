// C++ STL program to print value PI
#include<bits/stdc++.h>

using namespace std;

/*  Calcular PI usando la fórmula de Leibniz
    Recuerda: entre más iteraciones, mayor precisión
*/
double calcularPi(unsigned long long int iteraciones)
{
  double numerador = 4;
  double denominador = 1; // A este lo vamos a ir aumentando de 2 en 2
  double pi = 0;
  int x = 0;
  // Recuerda que es alternar entre negativo y positivo; por eso la bandera.
  // Comenzamos en positivo
  int operador = 1;
  for (x; x < iteraciones; x++)
  {
    pi += operador * (numerador / denominador);
    denominador += 2; // El denominador aumenta de 2 en 2
    operador *= -1;   // Alternamos operador
  }
  return pi;
}
// Driver Program to test above function
int main(void)
{
    unsigned long long int iteraciones;
    cout << "Da el numero de iteraciones para calcular PI ";
    cin >> iteraciones;
    cout << "Numero de iteraciones para calular " << iteraciones << "\n";
    double pi = calcularPi(iteraciones);
    cout << "El valor de PI = " << fixed << setprecision(40) << pi  << " con "
                      << fixed << setprecision(2) << iteraciones << " iteraciones \n";
    cout << "\n\n";
    return 0;
}
