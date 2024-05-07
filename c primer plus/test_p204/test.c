#include <stdio.h>
#include<ctype.h>
char get_choice (void);
char get_first (void);
int get_int (void);
void count (void);

int main (void)
{
    int choice;
    while ((choice = get_choice()) != 'q')
    {
        switch (choice)
        {
        case 'a':printf("Buy low,sell high.\n");
            break;
        case 'b':putchar('\a');
            break;
        case 'c':count ();
            break;
        default:printf("Progress error!\n");
            break;
        }
    }
    printf("Bye.\n");
    return 0;

}

void count (void)
{
    int n,i;
    printf("Count haw far?Enter an integer:\n");
    n = get_int();
    for (i=1;i<=n;i++)
        printf("%d\n",i);
    //  while (getchar() !='\n')   //跳过输入行的其余部分
    //      continue;

}

char get_choice (void)
{
    int ch;

    printf("Enter the letter of your choice:\n");
    printf("a.advice            b.bell\n");
    printf("c.count             q.quit\n");
    ch = get_first();
    while ((ch<'a'||ch>'c')&&ch!='q')
    {
        printf("Please respond with a,b,c,or q.\n");
        ch = get_first();

    }
    return ch;
}


/*char get_first (void)
{
    int ch;
    ch = getchar();
    while(getchar()!= '\n')
      continue;
    
    return ch;

}*/



char get_first(void)
{
	int ch;
	
	ch=getchar();
	/*while(isspace(ch))   //  若判断字符ch为空格、制表符或换行符，函数返回非零值，否则返回零值。
	 ch=getchar();*/

    if (ch == '\n')
      ch =getchar();

	while(getchar()!='\n')
	 continue;
	 
	return ch;
}



int get_int (void)
{
    int input;
    char ch;

    while (scanf("%d",&input)!=1)
    {
        while ((ch = getchar())!='\n')
            putchar (ch);
        printf(" is not an integer.\nPlease enter an ");
        printf("integer value, such as 25,-178,or 3:");

    }

    return input;
}
