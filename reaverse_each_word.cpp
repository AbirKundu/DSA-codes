#include<bits/stdc++.h>
using namespace std;

#define size 10

int top = -1; // Initialized top to -1
char str[size];

void push(char x){
    if(top == size-1){
        cout<<"Stack overflow\n";
    }
    else{
        str[++top] = x; // Incremented top and then assigned x
    }
}

void pop(){
    if(top == -1){
        cout<<"Stack is Empty\n";
    }
    else{
        top--;
    }
}

void reverse_word(string s){
    for(int i = 0; i < s.length(); i++){
        if(s[i] != ' ')
            push(s[i]);
        else{
            while(top != -1){
                cout << str[top--]; // Pop and print characters until the stack is empty
            }
            cout << " "; // Print a space after reversing a word
        }
    }
    while(top != -1){
        cout << str[top--]; // Print the remaining characters
    }
    cout << endl; // Print a newline character to end the reversed string
}

int main(){
    string s = "BUP IS A GOOD UNIVERSITY";
    reverse_word(s);
    return 0;
}
