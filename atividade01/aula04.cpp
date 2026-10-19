#include <iostream>

using namespace std;

int main(){


    int numero;

    cout << "Digite um número inteiro: ";
    cin >> numero;

    cout << "\nTabuada do número: " << numero << "\n";

    for(int i = 1; i <= 10; i++){
        
        cout << numero << " + " << i << " = " << numero + i << endl;


        
    }


    return 0;
}