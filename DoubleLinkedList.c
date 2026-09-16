#include<stdio.h>
#include<stdlib.h>

struct  Node{
    int data;
    struct Node*prev;
    struct Node*next;

};

//Creating node
struct Node* createNode(int data){
    struct Node* newNode=(struct Node*)malloc(sizeof(struct Node));
    newNode->data=data;
    newNode->prev=NULL;
    newNode->next=NULL;
    return newNode;
}

//Insert at Begining
struct Node* insertBegin(struct Node*head, int data){
    struct Node* newNode=createNode(data);
    newNode->next=head;
    if(head!=NULL)
    head->prev=newNode;
    return newNode;
}
//Insert at End
void insertEnd(struct Node**head, int data){
    struct Node* newNode=createNode(data);
    if(*head!=NULL){
       *head=newNode;
       return;
    }

    struct Node*temp=*head;
    while(temp->next!=NULL)
       temp=temp->next;
       temp->next=newNode;
       newNode->prev=temp;
}

//INSERT AT POITION
void insertpos(struct Node** head,int data, it pos)


int main(){
    struct Node* head=NULL;
    insertEnd(&head,10);
    insertEnd(&head,20);
    insertEnd(&head,30);
    insertEnd(&head,40);
    head=insertBegin(head,5);
}