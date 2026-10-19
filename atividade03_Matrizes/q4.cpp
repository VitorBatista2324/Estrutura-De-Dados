#include <iostream>

int main() {

    int matriz[3][4];

    int maior;
    int linhaMaior = 0;
    int colunaMaior = 0;

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 4; j++) {

            std::cout << "Digite um numero: ";
            std::cin >> matriz[i][j];
        }
    }

    maior = matriz[0][0];

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 4; j++) {

            if (matriz[i][j] > maior) {

                maior = matriz[i][j];

                linhaMaior = i;
                colunaMaior = j;
            }
        }
    }

    std::cout << "\nMaior valor: " << maior << std::endl;
    std::cout << "Linha: " << linhaMaior << std::endl;
    std::cout << "Coluna: " << colunaMaior << std::endl;

    return 0;
}