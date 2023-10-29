// #include<bits/stdc++.h>
// using namespace std;

// struct Node{
//     int data;
//     struct Node *link;
// };

// void counters(struct Node *head){
//     int count = 0;
//     if(head == NULL){
//         cout<<"Is Empty"<<endl;
//     }
//     else{
//     struct Node *ptr;
//         ptr = head;
//         while( ptr != NULL){
//                 count++;
//                 ptr = ptr->link;
//         }
//         }
//     cout<<count<<endl;

// }

// void printers(struct Node* head){
//     if(head==NULL){
//         cout<<" NO value"<<endl;}
//     else{
//         struct Node* ptr = head;
//         {
//            while(ptr!= NULL){
//             cout<<ptr->data;
//             ptr = ptr->link;
//            } /* data */
//         };
        
//     }
//     }

// void add_at_beg(struct Node* head, int value){
//     struct Node *beg=(struct Node*)malloc(sizeof(struct Node));
//     beg->data = value;
//     beg->link = head;

//     head = beg;


// }
// void insert_at_end(struct Node *head, int value){
//     struct Node *ptr,*temp;
//     temp = (struct Node*)malloc(sizeof(struct Node));
//         temp->data = value;
//         temp->link = NULL;

//     ptr = head;
//     while(ptr->link != NULL){
//         ptr = ptr->link;
//         }
//         ptr->link = temp;

//     }
// void insert_at_pos(struct Node* head,int value,int pos){
//     struct Node *ptr = head;
//     struct Node *New=(struct Node*)malloc(sizeof(struct Node));
//     new ->data = value;
//     new ->link = NULL; 

    
//     while(pos != 2){
//         ptr = ptr->link;
        
//     }
//     New->link = ptr->link;
//     ptr->link = New;
// }

// int main(){
// struct Node* head = nullptr;
// head = (struct Node*)malloc(sizeof(struct Node));

// head ->data = 45;
// head->link = NULL;

// // cout<<head->data<<" "<<head->link<<endl;;

// struct Node* cur=(struct Node*)malloc(sizeof(struct Node));
// cur->data = 50;
// cur->link = nullptr;
// head->link = cur;

// // cout<<head->link<<endl;
// // cout<<cur->data<<" "<<cur->link;

// struct Node* cur2=(struct Node*)malloc(sizeof(struct Node));
// cur2->data = 55;
// cur2->link = nullptr;
// cur->link = cur2;

// // cout<<head->link->link<<endl;
// // cout<<cur2->data<<" "<<cur2->link;

// insert_at_end(head,68);
// add_at_beg(head,10);

// counters(head);
// printers(head);
// }

//reverse a LL
void reverse(){
    struct Node *current,*next,*prev;
    current = head;
    prev = NULL;

    while(current != NULL){
        next = current->link;
        current->link = prev;
        prev = current;
        current = next;
    }
    head = prev;
    

}