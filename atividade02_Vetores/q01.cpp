#include <iostream>
using namespace std;

int main(){

    int tamanho = 15;
    int vetor[tamanho];

    cout << "\n---Insira os inteiros no vetor---" << endl;
    cout << endl;
    
    for(int i = 0; i < tamanho; i++){
        cout << "Digite o inteiro posicao " << i + 1 << ": ";
        cin >> vetor[i];
    }

    cout << "\n---Vetor invertido --- :" << endl;
    for(int i = tamanho - 1; i >= 0; i--){
        cout << "Vetor posicao: " << vetor[i] << endl;
    }




    return 0;
}