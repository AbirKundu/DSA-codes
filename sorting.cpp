#include <iostream>
using namespace std;

// void bubble_sort(int a[], int n) {
//     int counter = 1;
//     while (counter < n) {
//         for (int i = 0; i < n - counter; i++) {
//             if (a[i] > a[i + 1]) {
//                 // int temp = a[i];
//                 // a[i] = a[i + 1];
//                 // a[i + 1] = temp;
//                 //or

//                 swap(a[i],a[i+1]);
//             }
//         }
//         counter++;
//     }
//     for (int i = 0; i < n; i++) {
//         cout << a[i] << " ";
//     }
// }

// int main() {
//     int size;
//     cin >> size;
//     int a[size];
//     for (int i = 0; i < size; i++) {
//         cin >> a[i];
//     }
//     bubble_sort(a, size); // Pass the array 'a' and its size 'size' as arguments
// }
//#include <iostream>
//using namespace std;
// void selection_sort(int a[],int n){

//     for(int i =0;i<n-1;i++){
//         int min_pos = i;
//     for(int j = i+1 ; j<n;j++){
//         if(a[j]<a[min_pos]){
//             min_pos = j;
//         }
//     }
//     swap(a[i],a[min_pos]);
    

//     }
//     for(int i=0;i<n;i++){
//         cout<<a[i]<<" ";
//     }
// }
// int main() {
//     int size;
//     cin >> size;
//     int a[size];
//     for (int i = 0; i < size; i++) {
//         cin >> a[i];
//     }
//     selection_sort(a, size);

// }

//insertion 
// int main(){
//     int n;cin>>n;
//     int a[n];
//     for(int i=0;i<n;i++){
//         a[i]=2*i;
//     }
//     for(int i=0;i<n;i++){
//         cout<<a[i]<<" ";
//     }
//     int num,pos;
//     cout<<"Enter a Num and pos between "<<n<<" :";
//     cin>>num>>pos;
//     n++;
//     for(int i = n-1;i >= pos;i--){
//         a[i] = a[i-1];
//     }
//     a[pos] = num;

    // for(int i=0;i<n;i++){
    //     cout<<a[i]<<" ";
    // }}


int deleteElement(int arr[], int n, int x) //{11, 15, 6, 8, 9, 10}
{
int i;
for (i=0; i<n; i++)
	if (arr[i] == x)
		break;
if (i < n)
{
	n = n - 1;
	for (int j=i; j<n; j++)
		arr[j] = arr[j+1];
}
return n;
}
int main()
{
	int arr[] = {11, 15, 6, 8, 9, 10};
	int n = sizeof(arr)/sizeof(arr[0]);
	int x = 6;
	n = deleteElement(arr, n, x);

	for (int i=0; i<n; i++){
        printf("%d ",arr[i]);
	}
	return 0;
}
