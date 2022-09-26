#include <iostream>
#include<bits/stdc++.h>

using namespace std;

double countEven(int N){

    int cont = 0;

    for (int i=1; i<=N; i++) {

      if(i%2 == 0) {

        cont = cont + 1;
        cout << cont << endl;
      }
    }

return cont;
}

int main(void)
{
    int N;
    cout <<"Introduzca el número de terminos: ";
    cin >> N;
    int par=countEven(N);
    cout << "El total de pares son: " << par << endl << endl;
    //cout << "Valor exacto de PI es " <<
    return 0;
}
