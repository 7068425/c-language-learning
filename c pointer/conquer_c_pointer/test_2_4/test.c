/*#include <stdio.h>
 
void hello(void)
{
    fprintf(stderr, "hello!\n");
}
 
void func(void)
{
    void *buf[10];
    static int i;
    for (i = 0; i < 100; i++) 
    {
        buf[i] = hello;
    }
    
}
 
int main(void)
{
    int buf[1000];
    func();
    return 0;
}*/


#include <stdio.h>

void hello(void)
{
    fprintf(stderr, "hello!\n");
}

void func(void)
{
    void (*buf[10])(void);      // void *buf[10];
    for (int i = 0; i < 10; i++) 
    {
        buf[i] = hello;
    }
    
    // Optionally, call the function pointers to demonstrate functionality
    for (int i = 0; i < 10; i++)
    {
        buf[i]();     //((void (*)(void))buf[i])();
    }
}

int main(void)
{
    func();
    return 0;
}
