#include <iostream>
#include <string>
using namespace std;

int main() {

    string vetor[4] = {"Maria", "Bruna", "Alberto", "Joao"};

    string aux;

    for (int i = 1; i < 4; i++) {

        aux = vetor[i];

        int j = i - 1;

        while (j >= 0 && vetor[j] > aux) {

            vetor[j + 1] = vetor[j];

            j--;
        }

        vetor[j + 1] = aux;
    }

    cout << "Vetor ordenado:" << endl;

    for (int i = 0; i < 4; i++) {
        cout << vetor[i] << endl;
    }

    return 0;
}