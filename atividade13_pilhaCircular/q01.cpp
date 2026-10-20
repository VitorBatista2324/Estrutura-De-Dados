#include <iostream>
using namespace std;

struct No {
    char dado;
    No *proximo;
};

void enfileirar(No *&inicio, No *&fim, char valor) {
    No *novo = new No;
    novo->dado = valor;

    if (inicio == NULL) {
        inicio = novo;
        fim = novo;
        fim->proximo = inicio;
    } else {
        fim->proximo = novo;
        fim = novo;
        fim->proximo = inicio;
    }
}

char desenfileirar(No *&inicio, No *&fim) {
    if (inicio == NULL) {
        cout << "Fila vazia!" << endl;
        return 0;
    }

    No *aux = inicio;
    char valor = aux->dado;

    if (inicio == fim) {
        inicio = NULL;
        fim = NULL;
    } else {
        inicio = inicio->proximo;
        fim->proximo = inicio;
    }

    delete aux;
    return valor;
}

void printar(No *inicio) {
    if (inicio == NULL) {
        cout << "Fila vazia!" << endl;
        return;
    }

    No *aux = inicio;

    do {
        cout << aux->dado << " ";
        aux = aux->proximo;
    } while (aux != inicio);

    cout << endl;
}

int main() {
    No *inicio = NULL;
    No *fim = NULL;

    enfileirar(inicio, fim, 'A');
    enfileirar(inicio, fim, 'B');
    enfileirar(inicio, fim, 'C');
    enfileirar(inicio, fim, 'D');
    enfileirar(inicio, fim, 'E');

    cout << "Fila completa: ";
    printar(inicio);

    cout << "Elemento removido: " << desenfileirar(inicio, fim) << endl;

    cout << "Fila depois de desenfileirar: ";
    printar(inicio);

    return 0;
}