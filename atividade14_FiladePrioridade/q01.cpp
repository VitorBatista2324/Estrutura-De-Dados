#include <iostream>
#include <queue>
#include <string>
using namespace std;

struct Pessoa {
    string nome;
    int prioridade;
};

struct Comparar {
    bool operator()(Pessoa a, Pessoa b) {
        return a.prioridade < b.prioridade;
    }
};

int main() {
    priority_queue<Pessoa, vector<Pessoa>, Comparar> fila;

    int opcao;

    do {
        cout << "\n--- BANCO ---\n";
        cout << "1 - Adicionar pessoa na fila\n";
        cout << "2 - Atender proxima pessoa\n";
        cout << "3 - Sair\n";
        cout << "Escolha: ";
        cin >> opcao;

        if (opcao == 1) {
            Pessoa pessoa;
            int tipo;

            cout << "\nNome da pessoa: ";
            cin >> pessoa.nome;

            cout << "\nTipo de atendimento:\n";
            cout << "1 - Idoso (prioridade 4)\n";
            cout << "2 - PCD (prioridade 3)\n";
            cout << "3 - Gestante (prioridade 3)\n";
            cout << "4 - Pessoa autista (prioridade 2)\n";
            cout << "5 - Demais pessoas (prioridade 1)\n";
            cout << "Escolha: ";
            cin >> tipo;

            if (tipo == 1) {
                pessoa.prioridade = 4;
            } else if (tipo == 2 || tipo == 3) {
                pessoa.prioridade = 3;
            } else if (tipo == 4) {
                pessoa.prioridade = 2;
            } else if (tipo == 5) {
                pessoa.prioridade = 1;
            } else {
                cout << "Tipo invalido!\n";
                continue;
            }

            fila.push(pessoa);

            cout << "Pessoa adicionada a fila!\n";

        } else if (opcao == 2) {
            if (fila.empty()) {
                cout << "Nao ha pessoas na fila!\n";
            } else {
                cout << "Atendendo: " << fila.top().nome << endl;
                fila.pop();
            }
        }

    } while (opcao != 3);

    return 0;
}
