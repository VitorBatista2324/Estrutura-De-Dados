#include <iostream>
#include <string>
using namespace std;

struct No {
    char dado;
    No *proximo;
};

void empilhar(No *&topo, char valor) {
    No *novo = new No;
    novo->dado = valor;
    novo->proximo = topo;
    topo = novo;
}

char desempilhar(No *&topo) {
    if (topo == NULL) {
        cout << "Nao tem nada para desempilhar";
        return 0;
    }

    No *aux = topo;
    char valor = aux->dado;

    topo = topo->proximo;
    delete aux;

    return valor;
}

void mostrarPilha(No *topo) {
    while (topo != NULL) {
        cout << topo->dado << " ";
        topo = topo->proximo;
    }

    cout << endl;
}

void removerMeio(No *&topo) {
    if (topo == NULL) {
        return;
    }

    int tamanho = 0;
    No *aux = topo;

    while (aux != NULL) {
        tamanho++;
        aux = aux->proximo;
    }

    int meio = (tamanho - 1) / 2;

    if (meio == 0) {
        desempilhar(topo);
        return;
    }

    aux = topo;

    for (int i = 0; i < meio - 1; i++) {
        aux = aux->proximo;
    }

    No *remover = aux->proximo;
    aux->proximo = remover->proximo;

    delete remover;
}

string reverterString(string palavra) {
    No *topo = NULL;

    for (int i = 0; i < palavra.size(); i++) {
        empilhar(topo, palavra[i]);
    }

    string invertida = "";

    while (topo != NULL) {
        invertida += desempilhar(topo);
    }

    return invertida;
}

void removerDuplicados(No *&topo) {
    No *atual = topo;

    while (atual != NULL) {
        No *anterior = atual;
        No *aux = atual->proximo;

        while (aux != NULL) {
            if (aux->dado == atual->dado) {
                anterior->proximo = aux->proximo;
                delete aux;
                aux = anterior->proximo;
            } else {
                anterior = aux;
                aux = aux->proximo;
            }
        }

        atual = atual->proximo;
    }
}

bool ehPalindromo(string palavra, int tamanho) {
    No *topo = NULL;

    for (int i = 0; i < tamanho; i++) {
        empilhar(topo, palavra[i]);
    }

    for (int i = 0; i < tamanho; i++) {
        if (palavra[i] != desempilhar(topo)) {
            while (topo != NULL) {
                desempilhar(topo);
            }

            return false;
        }
    }

    return true;
}

int main() {

    No *pilha1 = NULL;

    empilhar(pilha1, 'A');
    empilhar(pilha1, 'B');
    empilhar(pilha1, 'C');
    empilhar(pilha1, 'D');
    empilhar(pilha1, 'E');

    cout << "Antes de remover o meio: ";
    mostrarPilha(pilha1);

    removerMeio(pilha1);

    cout << "Depois de remover o meio: ";
    mostrarPilha(pilha1);

    cout << endl;

    string palavra = "CASA";

    cout << "Original: " << palavra << endl;
    cout << "Invertida: " << reverterString(palavra) << endl;

    cout << endl;

    No *pilha3 = NULL;

    empilhar(pilha3, 'A');
    empilhar(pilha3, 'B');
    empilhar(pilha3, 'A');
    empilhar(pilha3, 'C');
    empilhar(pilha3, 'B');

    cout << "Antes de remover duplicados: ";
    mostrarPilha(pilha3);

    removerDuplicados(pilha3);

    cout << "Depois de remover duplicados: ";
    mostrarPilha(pilha3);

    cout << endl;

    string palavraPali = "ARARA";
    string palavra2 = "CASA";

    cout << palavraPali << ": ";

    if (ehPalindromo(palavraPali, 5)) {
        cout << "E palindromo" << endl;
    } else {
        cout << "Nao e palindromo" << endl;
    }

    cout << palavra2 << ": ";

    if (ehPalindromo(palavra2, 4)) {
        cout << "E palindromo" << endl;
    } else {
        cout << "Nao e palindromo" << endl;
    }

    return 0;
}