#include <iostream>
#include <string>
using namespace std;

int main() {

    string vetor[4] = {"Maria", "Bruna", "Alberto", "Joao"};

    string aux;

    for (int i = 0; i < 3; i++) {

        for (int j = 0; j < 3 - i; j++) {

            if (vetor[j] > vetor[j + 1]) {

                aux = vetor[j];
                vetor[j] = vetor[j + 1];
                vetor[j + 1] = aux;
            }
        }
    }

    cout << "Vetor ordenado:" << endl;

    for (int i = 0; i < 4; i++) {
        cout << vetor[i] << endl;
    }

    return 0;
}