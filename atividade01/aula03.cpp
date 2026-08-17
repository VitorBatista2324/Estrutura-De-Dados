#include <iostream>
using namespace std;

int main(){

    int numeros;
    int pares = 0;
    int impares = 0;
    int soma = 0;

    for(int i = 1; i <= 10; i++){
        cout << "Digite o número " << i << " : ";
        cin >> numeros;

        soma += numeros;

        if(numeros % 2 == 0){
            pares++;
        }
        else{
            impares++;
        }
    }

        cout << endl << "Quantidade de numeros pares: " << pares << endl;
        cout << "Quantidade de numeros impares: " << impares << endl;
        cout << "Soma de todos os numeros: " << soma << endl;

    



    return 0;
}