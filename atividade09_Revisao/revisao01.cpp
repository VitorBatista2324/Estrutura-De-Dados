#include <iostream>
using namespace std;

void buscaSequencial(int vetor[], int tamanho, int numero, bool encontrado) {
    
    int operacoes = 0;

    for(int i = 0; i < tamanho; i++) {
        
        operacoes++;

        if(vetor[i] == numero) {
            cout << "Codigo encontrado na posicao: " << i << endl;
            cout << "Operacoes Realizadas: " << operacoes << endl;
            encontrado = true;
            break;
        }
    }

    if(encontrado == false) {
        cout << "Codigo nao encontrado!" << endl;
        cout << "Numero de Operacoes: " << operacoes << endl;
    }
}

int main() {

    int tamanho = 10;
    int vetor[tamanho];
    int encontrado = false;
    int numero;

    for(int i = 0; i < tamanho; i++) {

        cout << "Digite um codigo: ";
        cin >> vetor[i];
    }

    for(int i = 0; i < tamanho; i++) {
        cout << vetor[i];

        if(i < tamanho - 1) {
            cout << ", ";
        }
    }
    cout << endl;

    cout << "Digite o valor a ser buscado: ";
    cin >> numero;

    buscaSequencial(vetor, tamanho, numero, encontrado);

    return 0;
}