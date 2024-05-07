#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node* next;
};

struct  Node* head;

void Insert (int x);
void Print(void);

int main (void)
{
    head = NULL;
    printf("How many numbers?\n");
    int n,i,x;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        printf("Enter the number \n");
        scanf("%d",&x);
        Insert(x);
        Print();
    }

    return 0;
}

void Insert (int x)
{
    struct Node*temp=(struct Node*)malloc(sizeof(struct Node));
    (*temp).data = x;  //temp->data = x;
    /*temp->next = head;
    head = temp;*/
//先把头指针中的地址取出，再重新设置头指针中的地址。在头部插入节点是指在头指针后插入。
    temp->next = NULL;
    if (head != NULL)
    {
        temp->next = head;
    }
    head = temp;

}

void Print(void)
{
    struct Node * temp = head;
    printf("List is:");
    while (temp != NULL)
    {
        printf("%2d",temp->data);
        temp = temp->next;
    }
    printf("\n");   
}