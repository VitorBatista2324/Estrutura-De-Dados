#include <iostream>
using namespace std;

struct Node {

    int valor;
    Node* proximo;

};

class Lista {

private:

    Node* inicio;

public:

    Lista() {
        inicio = NULL;
    }

    int tamanho() {

        int cont = 0;

        Node* atual = inicio;

        while (atual != NULL) {

            cont++;

            atual = atual->proximo;
        }

        return cont;
    }

    void inserir(int valor) {

        Node* novo = new Node();

        novo->valor = valor;
        novo->proximo = NULL;

        if (inicio == NULL) {

            inicio = novo;

        } else {

            Node* atual = inicio;

            while (atual->proximo != NULL) {

                atual = atual->proximo;
            }

            atual->proximo = novo;
        }
    }

    void remover(int posicao) {

        if (inicio == NULL) {
            return;
        }

        if (posicao == 0) {

            Node* aux = inicio;

            inicio = inicio->proximo;

            delete aux;

            return;
        }

        Node* atual = inicio;

        for (int i = 0; i < posicao - 1; i++) {

            if (atual->proximo == NULL) {
                return;
            }

            atual = atual->proximo;
        }

        if (atual->proximo == NULL) {
            return;
        }

        Node* aux = atual->proximo;

        atual->proximo = aux->proximo;

        delete aux;
    }

    void mostrar() {

        Node* atual = inicio;

        while (atual != NULL) {

            cout << atual->valor << " ";

            atual = atual->proximo;
        }

        cout << endl;
    }
};

int main() {

    Lista lista;

    lista.inserir(10);
    lista.inserir(20);
    lista.inserir(30);
    lista.inserir(40);

    lista.mostrar();

    cout << "Tamanho: " << lista.tamanho() << endl;

    lista.remover(2);

    lista.mostrar();

    cout << "Tamanho: " << lista.tamanho() << endl;

    return 0;
}