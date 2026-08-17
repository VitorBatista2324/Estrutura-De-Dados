#include <iostream>

int main() {

    int matriz[3][3];

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            std::cout << "Digite um numero: ";
            std::cin >> matriz[i][j];
        }
    }

    std::cout << "\nMatriz:\n";

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            std::cout << matriz[i][j] << " ";
        }

        std::cout << std::endl;
    }

    return 0;
}