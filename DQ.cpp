// Deque implementation in C++

#include <iostream>
using namespace std;

#define MAX 10


  int arr[MAX];
  int front =-1;
  int rear=-1;
  int size=MAX;

   

  void insertfront(int key);
  void insertrear(int key);
  void deletefront();
  void deleterear();
  bool isFull();
  bool isEmpty();
  int getFront();
  int getRear();


bool isFull() {
  return ((front == 0 && rear == size - 1) ||
      front == rear + 1);
}

bool isEmpty() {
  return (front == -1);
}

void insertfront(int key) {
  if (isFull()) {
    cout << "Overflow\n"
       << endl;
    return;
  }

  if (front == -1) {
    front = 0;
    rear = 0;
  }

  else if (front == 0)
    front = size - 1;

  else
    front = front - 1;

  arr[front] = key;
}

void insertrear(int key) {
  if (isFull()) {
    cout << " Overflow\n " << endl;
    return;
  }

  if (front == -1) {
    front = 0;
    rear = 0;
  }

  else if (rear == size - 1)
    rear = 0;

  else
    rear = rear + 1;

  arr[rear] = key;
  cout<<" Inserted "<<arr[rear]<<endl;
}

void deletefront() {
  if (isEmpty()) {
    cout << "Queue Underflow\n"
       << endl;
    return;
  }

  if (front == rear) {
    front = -1;
    rear = -1;
  } else if (front == size - 1)
    front = 0;

  else
    front = front + 1;
}

void deleterear() {
  if (isEmpty()) {
    cout << " Underflow\n"
       << endl;
    return;
  }

  if (front == rear) {
    front = -1;
    rear = -1;
  } else if (rear == 0)
    rear = size - 1;
  else
    rear = rear - 1;
}

int getFront() {
  if (isEmpty()) {
    cout << " Underflow\n"
       << endl;
    return -1;
  }
  return arr[front];
}

int getRear() {
  if (isEmpty() || rear < 0) {
    cout << " Underflow\n"
       << endl;
    return -1;
  }
  return arr[rear];
}
void display() {
  if (isEmpty()) {
    cout << "Deque is Empty" << endl;
  } else {
    int current = front; // Start from the front of the deque
    while (current != rear) {
      cout << arr[current] << " ";
      current = (current + 1) % MAX; // Move to the next element (considering circular deque)
    }
    cout << arr[rear] << endl;
  }
}


int main() {
  

  cout << "insert element at rear end => \n";
  insertrear(5);
  insertrear(6);
  insertrear(7);
  insertrear(8);
  insertrear(9);
  insertrear(10);
  display();
  cout << "rear element => "<< getRear() << endl;
  cout << "Front element => "<< getFront() << endl;

  deleterear();
  cout << "after deletion of the rear element, the new rear element => " << getRear() << endl;

  cout << "insert element at front is => ";

  insertfront(8);
  display();
  cout << "front element => " << getFront() << endl;

 deletefront();
  display();
  cout << "after deletion of front element new front element => " << getFront() << endl;
}