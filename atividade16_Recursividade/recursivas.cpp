#include <iostream>
#include <string>
using namespace std;

int soma(int n) {
    if (n == 1) {
        return 1;
    }

    return n + soma(n - 1);
}

bool palindromo(string palavra, int inicio, int fim) {
    if (inicio >= fim) {
        return true;
    }

    if (palavra[inicio] != palavra[fim]) {
        return false;
    }

    return palindromo(palavra, inicio + 1, fim - 1);
}

string inverter(string palavra) {
    if (palavra.empty()) {
        return "";
    }

    return inverter(palavra.substr(1)) + palavra[0];
}

int fibonacci(int n) {
    if (n == 0) {
        return 0;
    }

    if (n == 1) {
        return 1;
    }

    return fibonacci(n - 1) + fibonacci(n - 2);
}

int main() {

    cout << "Soma: " << soma(5) << endl;

    cout << "Palindromo: " << palindromo("arara", 0, 4) << endl;

    cout << "String invertida: " << inverter("casa") << endl;

    cout << "Fibonacci: " << fibonacci(5) << endl;

    return 0;
}