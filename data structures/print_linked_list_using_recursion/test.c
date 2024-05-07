#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node* next;
}Node;

Node* Insert(Node*head,int data);
void Print (Node*p);

int main (void)
{
     Node* head = NULL;
     head = Insert(head,2);
     head = Insert(head,4);
     head = Insert(head,6);
     head = Insert(head,5);
     Print(head);
     return 0 ;
}

Node* Insert(Node*head,int data)
{
    Node *temp = (Node*)malloc (sizeof(Node));
    temp->data = data;
    temp->next = NULL;
    if(head ==NULL)
    {
        head = temp;
    }
    else
    {
        Node*temp1 = head;
        while(temp1->next != NULL)
        {
            temp1 = temp1->next;
        }
        temp1->next = temp;    
    }
    return head;

}
void Print (Node*p)
{
    if(p == NULL)
    return;
    printf("%2d",p->data);
    Print(p->next);   //顺序打印
    /* Print(p->next);
     printf("%2d",p->data);*/ //逆序打印
 
}
