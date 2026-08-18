#include <iostream>
using namespace std;

void tabuada(int numero) {

cout << "\n------SOMA------\n" << endl;
for(int i = 1; i <= 10; i++) {
    
    cout << numero << " + " << i << " = " << numero + i << endl;
}
cout << "\n------SUBTRACAO------\n" << endl;
for(int i = 1; i <= 10; i++) {
    if(numero > i) {
        cout << numero << " - " << i << " = " << numero - i << endl;
    }
    else {
        cout << numero << " - " << i << " = " << i - numero << endl;
    }
}
cout << "\n------MULTIPLICACAO------\n" << endl;
for(int i = 1; i <= 10; i++) {
    
    cout << numero << " * " << i << " = " << numero * i << endl;
}

}

int main() {

    int numero;

    cout << "Digite um numero de 1 a 10: ";
    cin >> numero;

    tabuada(numero);



    return 0;
}