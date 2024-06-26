/*#include<stdio.h>
int main()
{
	int arr[10] = { 2,34,51,2,3,10,9,11,21,0 };
	int* p = arr;
	int i;
	for (i = 0; i < 10; i++)
	{
		printf("%d ", *(p+i));
	}
	return 0;
}

#include<stdio.h>
int main()
{
	int arr[10] = { 2,34,51,2,3,10,9,11,21,0 };
	int(*pa)[10] = &arr;
	int i;
	for (i = 0; i < 10; i++)
	{
		printf("%d ", (*pa)[i]);
		//printf("%d ",*(*pa+i));
		//(*pa)[i],*pa==arr先对指针进行解引用操作，再找数组中的元素
	}
	return 0;
}*/

#include<stdio.h>
void print1(int arr[][5], int x, int y)//传递数组形式，行，列，参数是数组
{
	int i, j;
	for (i = 0; i < x; i++)
	{
		for (j = 0; j < y; j++)
		{
			printf("%d ", arr[i][j]);
		}
		printf("\n");
	}
}
int main()
{
	int arr[3][5] = { {1,2,3,4,5},{6,7,8,9,0},{0,9,8,7,6} };
	print1(arr, 3, 5);//传递数组名，行，列
	return 0;
}

/*#include<stdio.h>
void print2(int(*p)[5], int x, int y)//参数是指针，传递的为第一行的地址
{
	int i = 0;
	
	for (i = 0; i < x; i++)
	{
		int j = 0;
		for (j = 0; j < y; j++)
		{
			printf("%d ", *(*(p + i) + j));//*（p+i)找到该二维数组的确定的行，+j之后才能找到每行的每个元素
			//printf("%d ", *(p + i) [j]);
		}
		printf("\n");
	}
}
int main()
{
	int arr[3][5] = { {1,2,3,4,5},{6,7,8,9,0},{0,9,8,7,6} };
	print2(arr, 3, 5);
	return 0;
}*/


/*int arr[5];//arr是含有5个元素的整型数组
int* parr1[5];//parr1是一个数组，数组有10个元素，每个元素的类型是int*,parr1是指针数组
int(*parr2)[10];//parr2是一个指针，该指针指向了一个数组
			   //数组中有10个元素，其类型为int,parr2为数组指针
int(*parr3[10])[5];//parr3是一个数组，该数组有10个元素，每个元素是一个数组指针
				   //该数组指针指向的数组有5个元素，每个元素是int
*/