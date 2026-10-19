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
    string palavra;
    bool palindrome = true;

    cout << "Digite uma palavra: ";
    cin >> palavra;

    for (char c : palavra) {
        stack.push(c);
    }

    for (char c : palavra) {
        if (c != stack.pop()) {
            palindrome = false;
            break;
        }
    }

    if (palindrome) {
        cout << "A palavra e um palindromo!" << endl;
    } else {
        cout << "A palavra nao e um palindromo!" << endl;
    }

    return 0;
}