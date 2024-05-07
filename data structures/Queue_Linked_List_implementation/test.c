/*Queue - Linked List implementation*/
#include<stdio.h>
#include<stdlib.h>

typedef struct Node 
{
    int data;
    struct Node* next;
}Node;

Node* front = NULL;
Node* rear = NULL;   //有了尾节点，就不用遍历了。

void Enqueue(int x); 
void Dequeue(void); 
int Front(void);
void Print(void); 

int main(void)
{
    Enqueue(2); Print();
    Enqueue(4); Print();
    Enqueue(6); Print();
    Dequeue(); Print();
    Enqueue(8); Print();
    return 0;
}

void Enqueue(int x) 
{
    Node* temp =(Node*)malloc(sizeof(Node));
    temp->data =x;
    temp->next = NULL;
    if(front == NULL && rear == NULL)
    {
        front = rear = temp;
        return;
    }
    rear->next = temp;
    rear = temp;
}
void Dequeue(void) 
{
    Node* temp = front;
    if(front == NULL) 
    {
        printf("Queue is Empty\n");
        return;
    }
    if(front == rear) 
    {
        front = rear = NULL;
    }
    else 
    {
        front = front->next;
    }
    free(temp);
}

int Front(void) 
{
    if(front == NULL) 
    {
        printf("Queue is empty\n");
    }
    else
        return front->data;
}

void Print(void) 
{
    Node* temp = front;
    while(temp != NULL) 
    {
        printf("%d ",temp->data);
        temp = temp->next;
    }
    printf("\n");
}
