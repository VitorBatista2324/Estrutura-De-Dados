#include <iostream>
using namespace std;

void insertionSort(int vetor[], int tamanho) {
    
    int operacoes = 0;

    for(int i = 1; i < tamanho; i++) {
        int chave = vetor[i];
        int j = i - 1;

        while(j >= 0 && vetor[j] > chave) {
            operacoes++;

            vetor[j + 1] = vetor[j];
            j--;
        }
            vetor[j + 1] = chave;

            cout << "Insercao: " << i << ": ";

            for(int insercao = 0; insercao < tamanho; insercao++) {
                cout << vetor[insercao];

                if(insercao < tamanho - 1) {
                    cout << ", ";
                }
            }
            cout << endl;
    }
}

int main() {
    
    int tamanho = 10;
    int vetor[10] = {2,1,8,4,5,3,6,7,10,9};

    insertionSort(vetor, tamanho);

    cout << "\nVetor Ordenado com Insertion Sort: \n" << endl;
    for(int i = 0; i < tamanho; i++) {
        cout << vetor[i];

        if(i < tamanho - 1) {
            cout << ", ";
        }
    }

    cout << endl;

    return 0;
}