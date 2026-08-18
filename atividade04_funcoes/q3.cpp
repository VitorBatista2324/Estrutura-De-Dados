#include <iostream>
using namespace std;

double calcularMedia(double a, double b, double c){

    double resultado = (a + b + c) / 3;

    return resultado;
}



int main(){

    double n1,n2,n3;

    cout << "Digite a primeira nota: ";
    cin >> n1;

    cout << "Digite a segunda nota: ";
    cin >> n2;

    cout << "Digite a terceira nota: ";
    cin >> n3;

    if(calcularMedia(n1,n2,n3) >= 7) {
        cout << "O Aluno foi Aprovado!" << endl;
    }
    else if(calcularMedia(n1,n2,n3) < 5.5){
        cout << "O Aluno foi reprovado!" << endl;
    }
    else {
        cout << "O Aluno está de recuperacao!" << endl;
    }

    return 0;
}