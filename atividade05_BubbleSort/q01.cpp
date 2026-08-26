#include <iostream>
using namespace std;

int main() {
    int vetor[5];

    for (int i = 0; i < 5; i++) {
        cout << "Digite o " << i + 1 << " numero: ";
        cin >> vetor[i];
    }

    for (int i = 0; i < 5 - 1; i++) {
        for (int j = 0; j < 5 - 1 - i; j++) {

            if (vetor[j] > vetor[j + 1]) {
                int aux = vetor[j];

                vetor[j] = vetor[j + 1];

                vetor[j + 1] = aux;
            }
        }
    }

    cout << "\nNumeros em ordem crescente:\n";

    for (int i = 0; i < 5; i++) {
        cout << vetor[i] << " " << endl;
    }

    return 0;
}