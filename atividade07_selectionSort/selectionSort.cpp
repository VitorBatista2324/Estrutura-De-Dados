#include <iostream>
using namespace std;

int main() {

    int vetor[5];

    for (int i = 0; i < 5; i++) {
        cin >> vetor[i];
    }

    for (int i = 0; i < 4; i++) {

        int menor = i;

        for (int j = i + 1; j < 5; j++) {

            if (vetor[j] < vetor[menor]) {
                menor = j;
            }
        }

        int aux = vetor[i];
        vetor[i] = vetor[menor];
        vetor[menor] = aux;
    }

    for (int i = 0; i < 5; i++) {
        cout << vetor[i] << " ";
    }

    return 0;
}