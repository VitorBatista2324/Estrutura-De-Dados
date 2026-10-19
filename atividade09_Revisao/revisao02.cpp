#include <iostream>
using namespace std;

void buscaBinaria(int vetor[], int tamanho, int numero) {
    int comparacoes = 0;
    int inicio = 0;
    int fim = tamanho - 1;
    bool encontrado = false;

    while(inicio <= fim) {
        comparacoes++;
        int meio = (inicio + fim) / 2;

        if(vetor[meio] == numero) {
            cout << "Matricula encontrada!" << endl;
            cout << "Posicao: " << meio << endl;
            cout << "Numero de comparacoes: " << comparacoes << endl;
            encontrado = true;
            break;
        }

        else if(vetor[meio] < numero) {
            inicio = meio + 1;
        }

        else {
            fim = meio - 1;
        }
    }

    if(encontrado == false) {

        cout << "Matricula nao encontrada!" << endl;
        cout << "Numero de comparacoes: " << comparacoes << endl;
    }
}

int main() {

    int tamanho = 15;
    int vetor[15] = {10,20,30,40,50,60,70,80,90,100,110,120,130,140,150};
    int matricula;

    cout << "Qual o numero da matricula: ";
    cin >> matricula;
    cout << "\n";

    buscaBinaria(vetor, tamanho, matricula);






    return 0;
}