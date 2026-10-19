#include <iostream>
using namespace std;

int main() {

    int vetor[5];

    for (int i = 0; i < 5; i++) {
        cin >> vetor[i];
    }

    for (int i = 1; i < 5; i++) {

        int atual = vetor[i];
        int j = i - 1;

        while (j >= 0 && vetor[j] > atual) {
            vetor[j + 1] = vetor[j];
            j--;
        }

        vetor[j + 1] = atual;
    }

    for (int i = 0; i < 5; i++) {
        cout << vetor[i] << " ";
    }

    return 0;
}