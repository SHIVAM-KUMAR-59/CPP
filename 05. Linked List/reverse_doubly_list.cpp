// Reverse a diubly linked list
// Time complexity: O(n)

#include <iostream>
using namespace std;

struct Node{
    int data;
    struct Node* next;
    struct Node* prev;
};

void createLinkedList(struct Node ** head, int n){
    struct Node* temp;
    struct Node* last = NULL;
    for(int i=0; i<n; i++){
        temp = (struct Node*)malloc(sizeof(struct Node));
        temp->data = i + 1;
        temp->next = NULL;
        temp->prev = NULL;
        if(*head == NULL){
            *head = temp;
            last = temp;
        }
        else{
            last->next = temp;
            temp->prev = last;
            last = temp;
        }
    }
}

void reverseLinkedList(struct Node **head){
    struct Node *back = NULL,  *current = *head, *front;
    while(current != NULL){
        front = current->next;
        current->next = back;
        current->prev = front;
        back = current;
        current = front;
    }
    *head = back;
}

void displayLinkedList(struct Node *head){
    struct Node *temp = head;
    while(temp != NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
}

int main() {

    struct Node * head = NULL;
    createLinkedList(&head, 10);
    cout<<"Original Linked List: ";
    displayLinkedList(head);
    reverseLinkedList(&head);
    cout<<"\nReversed Linked List: ";
    displayLinkedList(head);

    return 0;
}