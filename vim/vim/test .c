#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node *head;

void Insert(int data, int n);
void Print(void);

int main(void)
{
    head = NULL;
    Insert(2, 1);
    Insert(3, 2);
    Insert(4, 1);
    Insert(5, 2);
    Insert(8, 3);
    Print();
    return 0;
}

void Insert(int data, int n)
{
    struct Node *temp1 = (struct Node *)malloc(sizeof(struct Node));
    temp1->data = data;
    temp1->next = NULL;
    if (n == 1)
    {
        temp1->next = head;
        head = temp1;
        // return;
    }
    else
    {
        struct Node *temp2 = head;
        for (int i = 0; i < n - 2; i++) // 遍历节点，temp2到达插入节点的前一节点
        {
            temp2 = temp2->next;
        }
        temp1->next = temp2->next; // temp1是插入节点，指向上一节点指向的下一节点
        temp2->next = temp1;       // 上一个节点指向插入节点    //temp1与temp2不能一样，会造成节点的指向还是本身，会陷入死循环
    }
}

void Print(void)
{
    struct Node *temp = head;
    while (temp != NULL)
    {
        printf("%2d", temp->data);
        temp = temp->next;
    }
    printf("\n");
}



