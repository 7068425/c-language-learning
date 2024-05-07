#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node* next;
}Node;

Node *head;
void Reverse(Node *p);
void Insert(int data);
void Print (void);
int main (void)
{
     head = NULL;
     Insert(2);
     Insert(4);
     Insert(6);
     Insert(8);
     Print();
     Reverse(head);
     Print();
     return 0 ;
}

void Reverse(Node *p)
{
    if(p->next == NULL)
    {
        head = p;
        return;
    }
    Reverse(p->next);
    Node *q = p->next;
    q->next = p;
    p->next = NULL;
}

/*Node *Reverse (Node*head)
{
    Node*temp = head;
    if(temp->next == NULL)
    {
        head = temp;
        return head;
    }
    head = Reverse(head->next);
    temp->next->next = temp;
    temp->next = NULL;
    return head;
}局部变量head*/

void Insert(int data)
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
}

void Print(void)
{
    struct Node * temp = head;  //head是全局变量，不要在函数中直接使用，可能会改变head的指向。
    while (temp != NULL)
    {
        printf("%2d",temp->data);
        temp = temp->next;
    }
    printf("\n");   
}


