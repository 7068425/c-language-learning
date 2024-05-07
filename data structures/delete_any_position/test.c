#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node* next;
}Node;

 Node* head;

void Insert (int data);
void Print(void);
void Delete(int n);
int main (void)
{
    head = NULL;
    Insert(2);   
    Insert(4);
    Insert(6);
    Insert(5);
    Print();
    int n;
    printf("Enter a position\n");
    scanf("%d",&n);
    Delete(n);
    Print();
}

void Delete(int n)
{
    Node * temp1 = head;
    if(n==1)
    {
        head = temp1->next;
        free(temp1);
        return;
    }
    int i;
    for (i=0;i<n-2;i++)
    {
        temp1 = temp1->next;
    }
     Node * temp2 = temp1->next;
    temp1->next = temp2->next;
    free(temp2);
}

void Print(void)
{
    Node * temp = head;
    while (temp != NULL)
    {
        printf("%2d",temp->data);
        temp = temp->next;
    }
    printf("\n");   
}

void Insert (int data)  //首插法
{
    Node*temp=( Node*)malloc(sizeof( Node));
    temp->data = data;
    temp->next = head;
    head = temp;

}

//尾插法
/*void Insert(int data)
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
*/
