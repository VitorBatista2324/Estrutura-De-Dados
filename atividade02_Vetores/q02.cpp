#include <iostream>

int main(){

    int vetor[5];
    int subtracao;
    int soma = 0;
    int multiplicacao = 1;

    for(int i = 0; i < 5; i++){
         std::cout << "Digite cinco números inteiros: ";
        std::cin >> vetor[i];
    }

    for(int i = 0; i < 5; i++){
        soma += vetor[i];
        multiplicacao *= vetor[i];
        subtracao -= vetor[i];
    }

    subtracao = vetor[0];

    std::cout << "Soma: " << soma << std::endl;
    std::cout << "Multiplicacao: " << multiplicacao << std::endl;
    std::cout << "Subtracao: " << subtracao << std::endl;

    return 0;


}