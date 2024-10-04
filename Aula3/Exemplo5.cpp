#include <iostream>
#include <cmath> //Biblioteca para operações matemáticas

using namespace std;



int main() {

    int numero;

    cout << "Digite um número inteiro: ";

    cin >> numero;

    //numero = numero * numero; -> Sem utilizar a biblioteca cmath.
    numero = pow(numero, 2); //Utilizado a biblioteca.

    cout << numero;
  
    return 0;

}
