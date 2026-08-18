#include <iostream>
using namespace std;

void verificarPar(int num){

    if(num % 2 == 0){
         cout << "O valor é par!" << endl;
    }
    else{
        cout << "O valor é impar!" << endl;
    }
}

int main(){
    int a;

    cout << "Digite um numero: ";
    cin >> a;

    verificarPar(a);

    return 0;
}