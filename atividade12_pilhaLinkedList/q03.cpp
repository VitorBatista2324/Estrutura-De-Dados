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

void removeDuplicates(Stack& stack) {
    Stack aux;
    Stack result;

    while (!stack.empty()) {
        int value = stack.pop();
        bool duplicate = false;

        Stack temp;

        while (!aux.empty()) {
            int x = aux.pop();

            if (x == value)
                duplicate = true;

            temp.push(x);
        }

        while (!temp.empty()) {
            aux.push(temp.pop());
        }

        if (!duplicate) {
            aux.push(value);
        }
    }

    while (!aux.empty()) {
        result.push(aux.pop());
    }

    while (!result.empty()) {
        stack.push(result.pop());
    }
}

int main() {
    Stack stack;

    stack.push(2);
    stack.push(3);
    stack.push(2);
    stack.push(4);
    stack.push(3);
    stack.push(1);

    cout << "Pilha original: ";
    stack.print();

    removeDuplicates(stack);

    cout << "Pilha sem duplicados: ";
    stack.print();

    return 0;
}