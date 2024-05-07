#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node* next;
    struct Node* prev;
}Node;

Node*GetNewNode(int x);
void InsertAtHead(int x);
void Print(void);
void ReversePrint(void);
void InsertAtTail(int x);

Node* head;

int main (void)
{
    head = NULL;
    InsertAtTail(2);
    Print();
    ReversePrint();
    InsertAtTail(4);
    Print();
    ReversePrint();
    InsertAtTail(6);
    Print();
    ReversePrint();
}

Node*GetNewNode(int x)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = x;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

/*void InsertAtHead(int x)
{
    Node *newNode = GetNewNode(x);
    if(head == NULL)
    {
        head = newNode;
        return;
    }
    head->prev = newNode;
    newNode->next = head;
    head = newNode;
}*/

void InsertAtTail(int x)
{
    Node*temp = head;
    Node*newNode = GetNewNode(x);
    if(head == NULL)
    {
        head = newNode;
        return;
    }
    while(temp->next!=NULL)
    {
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->prev = temp;
}
void Print(void)
{
    Node * temp = head;
    printf("Forward: ");
    while (temp != NULL)
    {
        printf("%2d",temp->data);
        temp = temp->next;
    }
    printf("\n");   
}

void ReversePrint(void)
{
   Node * temp = head;
   if (temp ==NULL)
   {
        return;
   }
   while(temp->next!=NULL)
   {
    temp = temp->next;
   }
   printf("Reverse: ");
   while(temp!=NULL)
   {
    printf("%2d",temp->data);
    temp=temp->prev;
   }
   printf("\n");  
}
