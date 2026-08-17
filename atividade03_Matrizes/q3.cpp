#include <iostream>

int main() {

    int matriz[4][4];

    int pares = 0;
    int impares = 0;

    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {

            std::cout << "Digite um numero: ";
            std::cin >> matriz[i][j];

            if (matriz[i][j] % 2 == 0) {
                pares++;
            } else {
                impares++;
            }
        }
    }

    std::cout << "\nQuantidade de pares: " << pares << std::endl;
    std::cout << "Quantidade de impares: " << impares << std::endl;

    return 0;
}