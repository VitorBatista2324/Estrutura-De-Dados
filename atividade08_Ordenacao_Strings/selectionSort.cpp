#include <iostream>
#include <string>
using namespace std;

int main() {

    string vetor[4] = {"Maria", "Bruna", "Alberto", "Joao"};

    string aux;

    for (int i = 0; i < 3; i++) {

        int menor = i;

        for (int j = i + 1; j < 4; j++) {

            if (vetor[j] < vetor[menor]) {
                menor = j;
            }
        }

        aux = vetor[i];
        vetor[i] = vetor[menor];
        vetor[menor] = aux;
    }

    cout << "Vetor ordenado:" << endl;

    for (int i = 0; i < 4; i++) {
        cout << vetor[i] << endl;
    }

    return 0;
}