#include <iostream>

int main(){

    double nota1;
    double nota2;
    double nota3;

    std::cout << "Digite a primeira Nota: ";
    std::cin >> nota1;
    
    std::cout << "Digite a segunda Nota: ";
    std::cin >> nota2;

    std::cout << "Digite a terceira Nota: ";
    std::cin >> nota3;

    double media = (nota1 + nota2 + nota3) / 3;


    if(media >= 7){
        std::cout << "Aluno Aprovado!" << std::endl;
    }
    else if(media < 5){
        std::cout << "Aluno Reprovado!" << std::endl;
    }
    else{
        std::cout << "Aluno em recuperação!" << std::endl;
    }



    return 0;
}