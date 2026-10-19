#include <iostream>

using namespace std;

struct Node {
    int valor;
    Node* anterior;
    Node* proximo;
};

Node* inicio = nullptr;
Node* fim = nullptr;
int tamanho = 0;

void inserirInicio(int valor) {

    Node* novo = new Node();

    novo->valor = valor;
    novo->anterior = nullptr;
    novo->proximo = inicio;

    if (inicio == nullptr) {
        inicio = novo;
        fim = novo;
    } else {
        inicio->anterior = novo;
        inicio = novo;
    }

    tamanho++;
}

void inserirFim(int valor) {

    Node* novo = new Node();

    novo->valor = valor;
    novo->proximo = nullptr;
    novo->anterior = fim;

    if (fim == nullptr) {
        inicio = novo;
        fim = novo;
    } else {
        fim->proximo = novo;
        fim = novo;
    }

    tamanho++;
}

void inserirPosicao(int valor, int posicao) {

    if (posicao == 0) {
        inserirInicio(valor);
        return;
    }

    if (posicao == tamanho) {
        inserirFim(valor);
        return;
    }

    Node* atual = inicio;

    for (int i = 0; i < posicao; i++) {
        atual = atual->proximo;
    }

    Node* novo = new Node();

    novo->valor = valor;
    novo->anterior = atual->anterior;
    novo->proximo = atual;

    atual->anterior->proximo = novo;
    atual->anterior = novo;

    tamanho++;
}

void removerInicio() {

    if (inicio == nullptr) {
        cout << "Lista vazia!" << endl;
        return;
    }

    Node* removido = inicio;

    inicio = inicio->proximo;

    if (inicio == nullptr) {
        fim = nullptr;
    } else {
        inicio->anterior = nullptr;
    }

    delete removido;

    tamanho--;
}

void removerFim() {

    if (fim == nullptr) {
        cout << "Lista vazia!" << endl;
        return;
    }

    Node* removido = fim;

    fim = fim->anterior;

    if (fim == nullptr) {
        inicio = nullptr;
    } else {
        fim->proximo = nullptr;
    }

    delete removido;

    tamanho--;
}

void removerPosicao(int posicao) {

    if (inicio == nullptr) {
        cout << "Lista vazia!" << endl;
        return;
    }

    if (posicao == 0) {
        removerInicio();
        return;
    }

    if (posicao == tamanho - 1) {
        removerFim();
        return;
    }

    Node* atual = inicio;

    for (int i = 0; i < posicao; i++) {
        atual = atual->proximo;
    }

    atual->anterior->proximo = atual->proximo;
    atual->proximo->anterior = atual->anterior;

    delete atual;

    tamanho--;
}

int getTamanho() {
    return tamanho;
}

void imprimir() {

    Node* atual = inicio;

    while (atual != nullptr) {
        cout << atual->valor << " ";
        atual = atual->proximo;
    }

    cout << endl;
}

bool buscar(int valor) {

    Node* atual = inicio;

    while (atual != nullptr) {

        if (atual->valor == valor) {
            return true;
        }

        atual = atual->proximo;
    }

    return false;
}

int main() {

    inserirInicio(20);
    inserirInicio(10);

    inserirFim(40);
    inserirFim(50);

    inserirPosicao(30, 2);

    cout << "Lista: ";
    imprimir();

    cout << "Tamanho: " << getTamanho() << endl;

    if (buscar(30)) {
        cout << "30 encontrado!" << endl;
    } else {
        cout << "30 nao encontrado!" << endl;
    }

    removerInicio();

    cout << "Depois de remover inicio: ";
    imprimir();

    removerPosicao(1);

    cout << "Depois de remover posicao 1: ";
    imprimir();

    removerFim();

    cout << "Depois de remover fim: ";
    imprimir();

    return 0;
}