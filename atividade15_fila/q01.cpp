#include <iostream>
#include <string>
using namespace std;

struct Conteudo {
    string nome;
    Conteudo* proximo;
};

struct Disciplina {
    string nome;
    int creditos;
    Conteudo* inicioConteudos;
    Disciplina* proxima;
};

struct Aluno {
    string nome;
    string cpf;
    int idade;
    string matricula;
    Disciplina* inicioDisciplinas;
    Aluno* proximo;
};

struct Fila {
    Aluno* inicio;
    Aluno* fim;
};

void inicializarFila(Fila &fila) {
    fila.inicio = nullptr;
    fila.fim = nullptr;
}

void adicionarAluno(Fila &fila) {
    Aluno* novo = new Aluno;

    cout << "Nome: ";
    getline(cin >> ws, novo->nome);

    cout << "CPF: ";
    getline(cin, novo->cpf);

    cout << "Idade: ";
    cin >> novo->idade;

    cout << "Matricula: ";
    getline(cin >> ws, novo->matricula);

    novo->inicioDisciplinas = nullptr;
    novo->proximo = nullptr;

    if (fila.inicio == nullptr) {
        fila.inicio = novo;
        fila.fim = novo;
    } else {
        fila.fim->proximo = novo;
        fila.fim = novo;
    }

    cout << "Aluno adicionado!\n";
}

void removerAluno(Fila &fila) {
    if (fila.inicio == nullptr) {
        cout << "Fila vazia!\n";
        return;
    }

    Aluno* auxiliar = fila.inicio;
    fila.inicio = fila.inicio->proximo;

    if (fila.inicio == nullptr) {
        fila.fim = nullptr;
    }

    cout << "Aluno removido da fila: " << auxiliar->nome << endl;
    delete auxiliar;
}

Aluno* buscarAluno(Fila &fila, string matricula) {
    Aluno* auxiliar = fila.inicio;

    while (auxiliar != nullptr) {
        if (auxiliar->matricula == matricula) {
            return auxiliar;
        }

        auxiliar = auxiliar->proximo;
    }

    return nullptr;
}

Disciplina* buscarDisciplina(Aluno* aluno, string nome) {
    Disciplina* auxiliar = aluno->inicioDisciplinas;

    while (auxiliar != nullptr) {
        if (auxiliar->nome == nome) {
            return auxiliar;
        }

        auxiliar = auxiliar->proxima;
    }

    return nullptr;
}

void adicionarDisciplina(Fila &fila) {
    string matricula;

    cout << "Matricula do aluno: ";
    getline(cin >> ws, matricula);

    Aluno* aluno = buscarAluno(fila, matricula);

    if (aluno == nullptr) {
        cout << "Aluno nao encontrado!\n";
        return;
    }

    Disciplina* nova = new Disciplina;

    cout << "Nome da disciplina: ";
    getline(cin >> ws, nova->nome);

    if (buscarDisciplina(aluno, nova->nome) != nullptr) {
        cout << "Essa disciplina ja esta cadastrada!\n";
        delete nova;
        return;
    }

    cout << "Quantidade de creditos: ";
    cin >> nova->creditos;

    nova->inicioConteudos = nullptr;
    nova->proxima = aluno->inicioDisciplinas;
    aluno->inicioDisciplinas = nova;

    cout << "Disciplina adicionada!\n";
}

void removerDisciplina(Fila &fila) {
    string matricula, nome;

    cout << "Matricula do aluno: ";
    getline(cin >> ws, matricula);

    Aluno* aluno = buscarAluno(fila, matricula);

    if (aluno == nullptr) {
        cout << "Aluno nao encontrado!\n";
        return;
    }

    cout << "Nome da disciplina: ";
    getline(cin >> ws, nome);

    Disciplina* atual = aluno->inicioDisciplinas;
    Disciplina* anterior = nullptr;

    while (atual != nullptr && atual->nome != nome) {
        anterior = atual;
        atual = atual->proxima;
    }

    if (atual == nullptr) {
        cout << "Disciplina nao encontrada!\n";
        return;
    }

    if (anterior == nullptr) {
        aluno->inicioDisciplinas = atual->proxima;
    } else {
        anterior->proxima = atual->proxima;
    }

    Conteudo* conteudo = atual->inicioConteudos;

    while (conteudo != nullptr) {
        Conteudo* temporario = conteudo;
        conteudo = conteudo->proximo;
        delete temporario;
    }

    delete atual;

    cout << "Disciplina removida!\n";
}

void listarDisciplinas(Fila &fila) {
    string matricula;

    cout << "Matricula do aluno: ";
    getline(cin >> ws, matricula);

    Aluno* aluno = buscarAluno(fila, matricula);

    if (aluno == nullptr) {
        cout << "Aluno nao encontrado!\n";
        return;
    }

    Disciplina* auxiliar = aluno->inicioDisciplinas;

    if (auxiliar == nullptr) {
        cout << "Aluno sem disciplinas.\n";
        return;
    }

    while (auxiliar != nullptr) {
        cout << "Disciplina: " << auxiliar->nome
             << " | Creditos: " << auxiliar->creditos << endl;

        auxiliar = auxiliar->proxima;
    }
}

void adicionarConteudo(Fila &fila) {
    string matricula, nome;

    cout << "Matricula do aluno: ";
    getline(cin >> ws, matricula);

    Aluno* aluno = buscarAluno(fila, matricula);

    if (aluno == nullptr) {
        cout << "Aluno nao encontrado!\n";
        return;
    }

    cout << "Nome da disciplina: ";
    getline(cin >> ws, nome);

    Disciplina* disciplina = buscarDisciplina(aluno, nome);

    if (disciplina == nullptr) {
        cout << "Disciplina nao encontrada!\n";
        return;
    }

    Conteudo* novo = new Conteudo;

    cout << "Descricao do conteudo: ";
    getline(cin >> ws, novo->nome);

    novo->proximo = disciplina->inicioConteudos;
    disciplina->inicioConteudos = novo;

    cout << "Conteudo adicionado!\n";
}

void removerConteudo(Fila &fila) {
    string matricula, nome, descricao;

    cout << "Matricula do aluno: ";
    getline(cin >> ws, matricula);

    Aluno* aluno = buscarAluno(fila, matricula);

    if (aluno == nullptr) {
        cout << "Aluno nao encontrado!\n";
        return;
    }

    cout << "Nome da disciplina: ";
    getline(cin >> ws, nome);

    Disciplina* disciplina = buscarDisciplina(aluno, nome);

    if (disciplina == nullptr) {
        cout << "Disciplina nao encontrada!\n";
        return;
    }

    cout << "Conteudo a remover: ";
    getline(cin >> ws, descricao);

    Conteudo* atual = disciplina->inicioConteudos;
    Conteudo* anterior = nullptr;

    while (atual != nullptr && atual->nome != descricao) {
        anterior = atual;
        atual = atual->proximo;
    }

    if (atual == nullptr) {
        cout << "Conteudo nao encontrado!\n";
        return;
    }

    if (anterior == nullptr) {
        disciplina->inicioConteudos = atual->proximo;
    } else {
        anterior->proximo = atual->proximo;
    }

    delete atual;

    cout << "Conteudo removido!\n";
}

void listarConteudos(Fila &fila) {
    string matricula, nome;

    cout << "Matricula do aluno: ";
    getline(cin >> ws, matricula);

    Aluno* aluno = buscarAluno(fila, matricula);

    if (aluno == nullptr) {
        cout << "Aluno nao encontrado!\n";
        return;
    }

    cout << "Nome da disciplina: ";
    getline(cin >> ws, nome);

    Disciplina* disciplina = buscarDisciplina(aluno, nome);

    if (disciplina == nullptr) {
        cout << "Disciplina nao encontrada!\n";
        return;
    }

    Conteudo* auxiliar = disciplina->inicioConteudos;

    if (auxiliar == nullptr) {
        cout << "Disciplina sem conteudos.\n";
        return;
    }

    while (auxiliar != nullptr) {
        cout << "- " << auxiliar->nome << endl;
        auxiliar = auxiliar->proximo;
    }
}

void listarTodosAlunos(Fila &fila) {
    Aluno* aluno = fila.inicio;

    if (aluno == nullptr) {
        cout << "Fila vazia!\n";
        return;
    }

    while (aluno != nullptr) {
        cout << "\n========================\n";
        cout << "Nome: " << aluno->nome << endl;
        cout << "CPF: " << aluno->cpf << endl;
        cout << "Idade: " << aluno->idade << endl;
        cout << "Matricula: " << aluno->matricula << endl;

        Disciplina* disciplina = aluno->inicioDisciplinas;

        while (disciplina != nullptr) {
            cout << "\nDisciplina: " << disciplina->nome << endl;
            cout << "Creditos: " << disciplina->creditos << endl;

            Conteudo* conteudo = disciplina->inicioConteudos;

            while (conteudo != nullptr) {
                cout << "Conteudo: " << conteudo->nome << endl;
                conteudo = conteudo->proximo;
            }

            disciplina = disciplina->proxima;
        }

        aluno = aluno->proximo;
    }
}

void consultarInicio(Fila &fila) {
    if (fila.inicio == nullptr) {
        cout << "Fila vazia!\n";
    } else {
        cout << "Primeiro aluno: " << fila.inicio->nome << endl;
    }
}

void tamanhoFila(Fila &fila) {
    int quantidade = 0;
    Aluno* auxiliar = fila.inicio;

    while (auxiliar != nullptr) {
        quantidade++;
        auxiliar = auxiliar->proximo;
    }

    cout << "Quantidade de alunos na fila: " << quantidade << endl;
}

int main() {
    Fila fila;
    inicializarFila(fila);

    int opcao;

    do {
        cout << "\n===== SISTEMA DE ALUNOS =====\n";
        cout << "1 - Adicionar aluno na fila\n";
        cout << "2 - Remover primeiro aluno da fila\n";
        cout << "3 - Consultar primeiro aluno\n";
        cout << "4 - Quantidade de alunos\n";
        cout << "5 - Adicionar disciplina\n";
        cout << "6 - Remover disciplina\n";
        cout << "7 - Listar disciplinas de um aluno\n";
        cout << "8 - Adicionar conteudo\n";
        cout << "9 - Remover conteudo\n";
        cout << "10 - Listar conteudos de uma disciplina\n";
        cout << "11 - Listar todos os alunos, disciplinas e conteudos\n";
        cout << "0 - Sair\n";
        cout << "Escolha: ";
        cin >> opcao;

        switch (opcao) {
            case 1:
                adicionarAluno(fila);
                break;
            case 2:
                removerAluno(fila);
                break;
            case 3:
                consultarInicio(fila);
                break;
            case 4:
                tamanhoFila(fila);
                break;
            case 5:
                adicionarDisciplina(fila);
                break;
            case 6:
                removerDisciplina(fila);
                break;
            case 7:
                listarDisciplinas(fila);
                break;
            case 8:
                adicionarConteudo(fila);
                break;
            case 9:
                removerConteudo(fila);
                break;
            case 10:
                listarConteudos(fila);
                break;
            case 11:
                listarTodosAlunos(fila);
                break;
            case 0:
                cout << "Encerrando o programa...\n";
                break;
            default:
                cout << "Opcao invalida!\n";
        }

    } while (opcao != 0);

    return 0;
}