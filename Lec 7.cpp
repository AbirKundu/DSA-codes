#include <iostream>
#include <string>
using namespace std;

const int SIZE = 100;
char arr[SIZE];
int top = -1;

// check if stack is full
bool isFull() {
    return top == SIZE - 1;
}

// check if stack is empty
bool isEmpty() {
    return top == -1;
}

// push value
void push(char val) {
    if (isFull()) {
        cout << "Overflow!\n";
    }
    else {
        arr[++top] = val;
    }
}

// pop the top value and return it
char pop() {
    if (isEmpty()) {
        cout << "Underflow!\n";
    }
    else {
        return arr[top--];
    }
}

// return the top value
char peek() {
    if (isEmpty()) {
        cout << "\nStack is empty!";
        return '\0';
    }
    return arr[top];
}

void display() {
    if (isEmpty()) {
        cout << "Stack is empty!\n";
    }
    else {
        cout << "Stack: ";
        for (int i = top; i >= 0; i--) {
            cout << arr[i] << " ";
        }
        cout << "\n";
    }
}

// check if the bracket pairs are valid
bool checkPair(char First, char Second) {
    return ((Second == ')' && First == '(') ||
        (Second == '}' && First == '{') ||
        (Second == ']' && First == '['));
}

bool isBalanced(const string& expr) {
    for (char c : expr) {
        if (c == '(' || c == '{' || c == '[') {
            push(c);
        }
        else if (c == ')' || c == '}' || c == ']') {
            if (isEmpty()) {
                return false;
            }
            char topChar = peek();
            pop();
            // or, char topChar() = pop();
            if (!checkPair(topChar, c)) {
                return false; 
            }
        }
        display();
    }
    return isEmpty();
}

int main() {
    string s;
    cin >> s;
    if (isBalanced(s)) {
        cout << "Balanced\n";
    }
    else {
        cout << "Not balanced\n";
    }
    return 0;
}