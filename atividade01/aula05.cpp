#include <iostream>

using namespace std;

int main(){

    int numeros;
    int maior;
    
    for(int i = 1; i <= 8; i++){
        cout << "Digite o " << i << " número: ";
        cin >> numeros;

        if(numeros > maior){
            maior = numeros;
        }


        
    }

    cout << endl << "O Maior Número foi : " << maior << endl;

    if(maior % 2 == 0){
            cout << endl << "O número é PAR!" << endl;
        }
        else{
            cout << endl << "O número é IMPAR" << endl;
        }


    return 0;
}