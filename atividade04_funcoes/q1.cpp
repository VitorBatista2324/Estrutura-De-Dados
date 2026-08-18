#include <iostream>
using namespace std;

int soma(int num1, int num2){
    int resultado = num1 + num2;
    return resultado;
}

int main(){
    int a,b;

    cout << "Digite o primeiro numero: ";
    cin >> a;

    cout << "Digite o segundo numero: ";
    cin >> b;

    cout << "Resultado = " << soma(a,b) << endl;

    return 0;
}