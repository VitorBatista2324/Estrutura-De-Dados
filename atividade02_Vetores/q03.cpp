#include <iostream>

int main(){

    char vogais[5] = {'a','e','i','o','u'};
    char vetor[10];
    int quantidade = 0;

    for(int i = 0; i < 10; i++){
        std::cout << "Digite uma letra: ";
        std::cin >> vetor[i];
    }

    for(int i = 0; i < 10; i++){
        bool vogal = false;

        for(int j = 0; j < 5; j++){
            
            if(vetor[i] == vogais[j]){
                vogal = true;
            }
        }
            if(vogal == false){
                quantidade++;
            }
    }

    std::cout << "Total de Consoantes: " << quantidade << std::endl;



    return 0;
}