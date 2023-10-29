#include<iostream>
using namespace std;
#define N 3
int queue[N];
int front=-1;int rear = -1;

int peek(){
    return queue[front];
}

int isfull(){
    if(rear == N-1) 
        return 1;
    else
        return 0;
}

int isempty(){
    if(rear == -1){
        return 1;
    }
    else
        return 0;
}

void enqueue(int value){
    if(rear == N-1)
        cout<<value<<" can't be inserted"<<endl;
    else{
        if (front==-1)
            front = 0;
    rear++;
    queue[rear] = value;
    //cout<<queue[front]<<endl;
}
}

void dequeue(){
    if(front == -1){
        cout<<"Queue is empty"<<endl;}
    else{
        front++;
        if(front>rear)
            rear = front = -1;}

    }

void print(){
    if(isempty()){
        cout<<"Queue is Empty"<<endl;
    }
    else{
    for (int i = front ; i<=rear; i++){
        cout<<queue[i]<<" ";
    }
    cout<<endl;
    }
}

int main(){

    print();
    enqueue(5); //5
    enqueue(6); // 5 6
    enqueue(7); // 5 6 7
    print();
    enqueue(100); // 5 6 7
    print();
    enqueue(8);
    
    dequeue();
    print();
    enqueue(10);
    print();
}