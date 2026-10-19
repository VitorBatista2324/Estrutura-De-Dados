#include <iostream>
using namespace std;

void bubbleSort(double vetor[], int tamanho) {
    int operacoes = 0;

    for(int i = 0; i < tamanho - 1; i++) {
        for(int j = 0; j < tamanho - 1 - i; j++) {
            operacoes++;
            if(vetor[j] > vetor[j + 1]) {
                
                double aux = vetor[j];
                vetor[j] = vetor[j + 1];
                vetor[j + 1] = aux;
            }
        }
    }

    for(int i = 0; i < tamanho; i++) {
        cout << vetor[i];

        if(i < tamanho - 1){
            cout << ", ";
        }
    }
    cout << endl;
    cout << "Numero de operacoes: " <<"[" << operacoes << "]" << endl;
}

int main() {

    int tamanho = 10;
    double vetor[10];

    for(int i = 0; i < tamanho; i++) {
        cout << "Digite um valor: R$ ";
        cin >> vetor[i];
    }

    cout << "\nVetor Antes da Ordenacao: \n" << endl;
    for(int i = 0; i < tamanho; i++) {
        cout << vetor[i];

        if(i < tamanho - 1) {
            cout << ", ";
        }
    }
    cout << endl;
    cout << "\nVetor Apos Bubble Sort: \n" << endl;
    bubbleSort(vetor, tamanho);

    cout << endl;


    return 0;
}