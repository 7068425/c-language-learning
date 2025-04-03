#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int compare(int a,int b) 
{
    if(a > b) 
        return 1;
    else
        return -1;   
}

int absolute_compare(int a, int b)
{
    if(abs(a) > abs(b))
        return 1;
    else
        return -1;
}

int compare_pro(const void* a,const void* b)
{
    int A =*((int*)a);
    int B =*((int*)b);
    return A-B;
}

void BubbleSort(int *A,int n, int (*compare)(int,int))
{
    int i,j, temp;
    for(i = 0;i<n;i++)
    {
        for(j = 0;j<n-1-i;j++)
        {
            if(compare(A[j],A[j+1]) > 0) 
            { 
                temp = A[j];
                A[j] = A[j+1];
                A[j+1] = temp;
            }
        }
    }
}

int main(void) 
{
    /*int i, A[] ={2,4,3,7,5,6};
    BubbleSort(A, 6, compare);*/

    int i ,A[] = {-31,22,-1,50,-6,4}; 
    /*BubbleSort(A, 6, absolute_compare);*/
    qsort(A,6,sizeof(int),compare_pro);

    for(i =0;i<6;i++)
    {
        printf("%d " ,A[i]);
    }
}
