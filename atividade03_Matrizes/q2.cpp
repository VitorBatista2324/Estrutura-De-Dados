#include <iostream>

int main() {

    int matriz[3][3];
    int soma = 0;

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            std::cout << "Digite um numero: ";
            std::cin >> matriz[i][j];

            soma += matriz[i][j];
        }
    }

    std::cout << "\nSoma dos elementos: " << soma << std::endl;

    return 0;
}