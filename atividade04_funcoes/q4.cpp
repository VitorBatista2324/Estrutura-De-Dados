#include <iostream>
using namespace std;

int maiorNumero(int vetor[10]){
    
    int maior;

    for(int i = 0; i < 10; i++){

        cout << "Digite um valor inteiro: ";
        cin >> vetor[i];

        if(i == 0 || vetor[i] > maior){
            maior = vetor[i];
        }
    }

    return maior;

}
int main(){

    int vetor[10];
    int maiorNum = maiorNumero(vetor);

    cout << "\nO maior valor é: " << maiorNum << endl;



    return 0;
}