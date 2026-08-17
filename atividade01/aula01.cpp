#include <iostream>

int main(){
    
    int idade;
    int anoAtual;

    std::cout << "Digite seu ano de nascimento: ";
    std::cin >> idade;

    std::cout << "Digite o ano Atual: ";
    std::cin >> anoAtual;

    int soma = anoAtual - idade;

    std::cout << "SOMA : " << soma << std::endl;

    return 0;
}