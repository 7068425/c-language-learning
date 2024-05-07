#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node* Link;
}Node;

Node*top ;

void Push (int x);
void Pop(void);
void Print(void);
int Top(void);
int IsEmpty(void);

int main (void)
{
    top = NULL;
    Push(2);Print();
    Push(5);Print();
    Push(10);Print();
    Pop();Print();
    Push(12);Print();
    int head=Top();
    printf("%d\n",head);
    int n = IsEmpty();
    printf("%d\n",n);
    return 0;
}

void Push (int x)
{
    Node*temp = (Node*)malloc(sizeof(Node));
    temp->data = x;
    temp->Link = top;
    top = temp;
}

void Pop(void)
{
    Node*temp;
    if (top==NULL)
    {
        return;
    }
    temp = top;
    top = top->Link;
    free(temp);
    
}
void Print(void)
{
    Node * temp = top;
    while (temp != NULL)
    {
        printf("%2d",temp->data);
        temp = temp->Link;
    }
    printf("\n");   
}

int Top(void)
{
    Node *temp = top;
    return temp->data;
}
int IsEmpty(void)
{
     Node *temp = top;
     if(temp == NULL)
     return 1;
     else
     return 0;

}