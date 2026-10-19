#include <iostream>
using namespace std;

struct Node {
    int valor;
    Node* proximo;
};

int meio(Node* inicio) {
    int tamanho = 0;
    Node* atual = inicio;

    while (atual != NULL) {
        tamanho++;
        atual = atual->proximo;
    }

    atual = inicio;

    for (int i = 0; i < tamanho / 2; i++) {
        atual = atual->proximo;
    }

    return atual->valor;
}

bool procurar(Node* inicio, int valor) {
    Node* atual = inicio;

    while (atual != NULL) {
        if (atual->valor == valor) {
            return true;
        }

        atual = atual->proximo;
    }

    return false;
}

int main() {

    Node* inicio = NULL;

    Node* novo = new Node();
    novo->valor = 1;
    novo->proximo = NULL;
    inicio = novo;

    novo = new Node();
    novo->valor = 2;
    novo->proximo = NULL;
    inicio->proximo = novo;

    novo = new Node();
    novo->valor = 3;
    novo->proximo = NULL;
    inicio->proximo->proximo = novo;

    novo = new Node();
    novo->valor = 4;
    novo->proximo = NULL;
    inicio->proximo->proximo->proximo = novo;

    novo = new Node();
    novo->valor = 5;
    novo->proximo = NULL;
    inicio->proximo->proximo->proximo->proximo = novo;

    novo = new Node();
    novo->valor = 6;
    novo->proximo = NULL;
    inicio->proximo->proximo->proximo->proximo->proximo = novo;

    cout << "Valor do meio: " << meio(inicio) << endl;

    cout << boolalpha;

    cout << "Existe 4? " << procurar(inicio, 4) << endl;
    cout << "Existe 10? " << procurar(inicio, 10) << endl;

    return 0;
}
