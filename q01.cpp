#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

class Stack {
public:
    Node* top;

    Stack() {
        top = nullptr;
    }

    void push(int value) {
        Node* newNode = new Node;
        newNode->data = value;
        newNode->next = top;
        top = newNode;
    }

    int pop() {
        if (top == nullptr)
            return -1;

        Node* temp = top;
        int value = temp->data;
        top = top->next;
        delete temp;

        return value;
    }

    bool empty() {
        return top == nullptr;
    }

    void print() {
        Node* aux = top;

        while (aux != nullptr) {
            cout << aux->data << " ";
            aux = aux->next;
        }

        cout << endl;
    }
};

void deleteMiddle(Stack& stack, int size) {
    Stack aux;
    int middle = size / 2;

    for (int i = 0; i < middle; i++) {
        aux.push(stack.pop());
    }

    stack.pop();

    while (!aux.empty()) {
        stack.push(aux.pop());
    }
}

int main() {
    Stack stack;

    stack.push(5);
    stack.push(4);
    stack.push(3);
    stack.push(2);
    stack.push(1);

    cout << "Pilha original: ";
    stack.print();

    deleteMiddle(stack, 5);

    cout << "Pilha sem o meio: ";
    stack.print();

    return 0;
}