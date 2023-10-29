#include <iostream>
using namespace std;
#define SIZE 10

void swap(int *a, int *b) {
    int temp = *b;
    *b = *a;
    *a = temp;
}

void heapify(int arr[], int size, int i) {
    if (size == 1) {
        cout << "Single element in the heap";
    } else {
        int small = i;
        int l = 2 * i + 1;
        int r = 2 * i + 2;
        if (l < size && arr[l] < arr[small]) // swap the greater th
            small = l;
        if (r < size && arr[r] < arr[small])
            small = r;

        if (small != i) {
            swap(&arr[i], &arr[small]);
            heapify(arr, size, small);
        }
    }
}

void insert(int arr[], int &size, int val) {
   int i = size;
   arr[i] = val;
   size++;

    for(int i = size/2 -1 ; i>=0 ;--i)
      heapify(arr,size,i);
   }

void deleteRoot(int arr[], int& size)
{
    int lastElement = arr[size - 1];
 
    arr[0] = lastElement;
 
    size--;
 
    // heapify the root node
    heapify(arr, size, 0);
}
void print(int arr[], int size) {
    if(size == 0){
        cout<<"The Heap is Empty"<<endl;
        return ;

    }
    else{
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}}

int main() {
    // int arr[SIZE] = {10, 15, 3, 20, 41};
    // int heapSize = 5;
    // print(arr,heapSize);

    int arr[SIZE] = {0};
    int heapSize = 0;

    print(arr,heapSize);

    insert(arr, heapSize, 15);
    insert(arr, heapSize, 45);
    insert(arr, heapSize, 85);
    insert(arr, heapSize, 105);

    print(arr,heapSize);

    insert(arr, heapSize, 25);
    insert(arr, heapSize, 65);
    insert(arr, heapSize, 95);
    insert(arr, heapSize, 100);

    print(arr, heapSize);

    deleteRoot(arr,heapSize);
    print(arr,heapSize);

    deleteRoot(arr,heapSize);
    print(arr,heapSize);

    deleteRoot(arr,heapSize);
    print(arr,heapSize);

    insert(arr,heapSize,50);
    print(arr,heapSize);

    return 0;
}
