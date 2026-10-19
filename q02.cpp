#include <iostream>
#include <string>
using namespace std;

struct Node {
    char data;
    Node* next;
};

class Stack {
public:
    Node* top;

    Stack() {
        top = nullptr;
    }

    void push(char value) {
        Node* newNode = new Node;
        newNode->data = value;
        newNode->next = top;
        top = newNode;
    }

    char pop() {
        if (top == nullptr)
            return '\0';

        Node* temp = top;
        char value = temp->data;
        top = top->next;
        delete temp;

        return value;
    }

    bool empty() {
        return top == nullptr;
    }
};

int main() {
    Stack stack;
    string texto;
    string invertida = "";

    cout << "Digite uma palavra: ";
    cin >> texto;

    for (char c : texto) {
        stack.push(c);
    }

    while (!stack.empty()) {
        invertida += stack.pop();
    }

    cout << "String invertida: " << invertida << endl;

    return 0;
}