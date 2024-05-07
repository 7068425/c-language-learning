#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node* next;
}Node;

Node* Reverse(Node*head);
Node* Insert(Node*head,int data);
void Print (Node*head);
int main (void)
{
     Node* head = NULL;
     head = Insert(head,2);
     head = Insert(head,4);
     head = Insert(head,6);
     head = Insert(head,8);
     Print(head);
     head = Reverse(head);
     Print(head);
     return 0 ;
}

Node* Reverse(Node*head)
{
    Node *current,*prev,*next;
    current = head;
    prev = NULL;
    while(current !=NULL)  //next保存下一个节点地址，current保存当前节点地址，prev保存上一个节点地址。
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    head = prev;
    return head;
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

void Print(Node* head)
{
    while (head != NULL)
    {
        printf("%2d",head->data);
        head = head->next;  //head的指向改变了
    }
    printf("\n");   
}


