
#include<iostream>
using namespace std;

struct node{
    int data;
    struct node *next;
    
};

struct node *p;
struct node *q;

struct node *push(struct node *head_ref, int new_data){
    struct node *new_node=(struct node*)malloc(sizeof(struct node));
    new_node->data = new_data;
    new_node->next = head_ref;
    head_ref = new_node;

    return head_ref;
}

void print_list(struct node *head){
    struct node *temp = head;
    while(temp != NULL){
        cout<<temp->data<<" ";

        temp = temp->next;
    }
    cout<<"\n";
    }


void merge(struct node *p, struct node *q)
{
    struct node *p_curr= p, *q_curr= q;
    struct node *p_next, *q_next;

      while (p_curr !=NULL && q_curr !=NULL)
    {
        p_next=p_curr->next;
        q_next=q_curr->next;
        q_curr->next=p_next;
        p_curr->next=q_curr;
        p_curr=p_next;
        q_curr=q_next;

    }
    }
int main(){
    p=push(p,3);
    p=push(p,2);
    p=push(p,1);
    printf("First Linked List;\n");
    print_list(p);
    q=push(q,8);
    q=push(q,7);
    q=push(q,6);
    q=push(q,5);
    q=push(q,4);
    printf("Second Linked List;\n");
    print_list(q);

    merge(p,q);
    printf("Merged Linked List;\n");
    print_list(p);
}