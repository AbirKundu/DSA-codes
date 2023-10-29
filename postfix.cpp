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

int check_operator(char ch){
    return ((ch >='a' and ch <= 'z') or (ch >= 'A' and ch <= 'Z'));
}

int precedence(char ch){
    switch (ch)
    {
    case '+':
    case '-':
        return 1;
        break;
    case '*':
    case '/':
        return 2;
        break;
    case '^':
        return 3;
        break;
     
    default:
        return -1;
        
    }
}

int convert(char *arr){
    int i,j;
    for(i = 0 , j = -1 ; arr[i] ; i++){
        if(check_operator(arr[i])){
            arr[++j] = arr[i];
        }
        else if (check_operator(arr[i]) == '(')
            push(arr[i]);
        else if( check_operator(arr[i]) == ')'){
            while(!isEmpty() and peek() != '('){
                    
                    arr[++j] = pop();
            }

        }
        else if(!isEmpty() and peek() == '('){
            pop(); 
        }
        else{
            while(!isEmpty() and precedence(arr[i]) <= precedence(peek())){
                arr[++j] == pop();
                push(arr[i]);
            }
        
        while (!isEmpty){
            arr[++j] = pop();
            arr[++j] ='\o';
            cout<<arr;
        }
    }
}}


int main(){
    char arr[SIZE] = "((x+(y*z))-w)";
    convert(arr);
}