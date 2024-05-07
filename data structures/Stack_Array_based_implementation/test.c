#include <stdio.h>
#define MAX_SIZE 101

int top = -1;
int A[MAX_SIZE];

void Push(int x);
void Pop(void);
int Top(void);
void Print(void);

int main (void)
{
    Push(2);Print();
    Push(5);Print();
    Push(10);Print();
    Pop();Print();
    Push(12);Print();
    return 0;
}

void Push(int x)
{
    if(top ==MAX_SIZE-1)
    {
        printf("Error:stack overflow\n");
        return;
    }
    A[++top] = x;
}
void Pop(void)
{
    if(top ==-1)
    {
        printf("Error:No element to pop\n");
        return;
    }
    top--;
}

int Top(void)
{
    return A[top];
}

void Print(void)
{
    int i;
    printf("Stack: ");
    for ( i = 0; i <= top; i++)
    {
        printf("%3d",A[i]);
    }
    printf("\n");    
}