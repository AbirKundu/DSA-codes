// Circular Queue implementation in C++

#include <iostream>
#define SIZE 5 /* Size of Circular Queue */

using namespace std;

  int items[SIZE];

    int front = -1;
    int rear = -1;

  // Check if the queue is full
  bool isFull() {
    if (front == 0 && rear == SIZE - 1) {
      return true;
    }
    if (front == rear + 1) {
      return true;
    }
    return false;
  }
  // Check if the queue is empty
  bool isEmpty() {
    if (front == -1)
      return true;
    else
      return false;
  }
  // Adding an element
  void enQueue(int element) {
    if (isFull()) {
      cout << "Queue is full"<<endl;
    } else {
      if (front == -1)
            front = 0;
      rear = (rear + 1) % SIZE;
      items[rear] = element;
      cout <<"Inserted " << element << endl;
    }
  }
  // Removing an element
  int deQueue() {
    int element;
    if (isEmpty()) {
      cout << "Queue is empty" << endl;
      return (-1);
    } else {
      element = items[front];
      if (front == rear) {
        front = -1;
        rear = -1;
      }
      // Q has only one element,
      // so we reset the queue after deleting it.
      else {
        front = (front + 1) % SIZE;
      }
      return (element);
    }
  }

  void display() {
    
    int i;
    if (isEmpty()) {
      cout << endl
         << "Empty Queue" << endl;
    } else {
      for (i = front; i != rear; i = (i + 1) % SIZE){
        cout << items[i]<<" ";
        }
      cout << items[i]<<endl;
    }
  }


int main() {


  
  deQueue(); // Fails because front = -1

  enQueue(1);
  enQueue(20);
  enQueue(3);
  enQueue(40);
  enQueue(5);
  display();
 
  enQueue(6);  // Fails to enqueue because front == 0 && rear == SIZE - 1

  display();

  int elem = deQueue();

  if (elem != -1)
    cout << "Deleted Element is " << elem<<endl;

  display();

  enQueue(7);

  display();

  
  enQueue(8); // Fails to enqueue because front == rear + 1

  return 0;
}
