#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int maxValue, minValue;
    int numeros[5];

    for (int i = 0; i < 5; i++) {

        cout << "Digite o valor para a posição " << i << ": ";

        cin >> numeros[i];
    }

    // Sort "manual"
    for (int i = 0; i < 5; i++){
        for (int j = i + 1; j < 5; j++){
            if(numeros[i] > numeros[j]) {
                int temp = numeros[i];
                numeros[i] = numeros[j];
                numeros[j] = temp;
            }
        }
    }

    //sort(numeros, numeros + 5);

    cout << endl;
    
    for (int i = 0; i < 5; i++){
        cout << numeros[i] << "\n";
    }

    cout << endl;
    
    maxValue = *max_element(numeros, numeros + 5);
    minValue = *min_element(numeros, numeros + 5);

    cout << "Maior elemento: " << maxValue << endl;
    cout << "Menor elemento: " << minValue << endl;
    
    return 0;
}
