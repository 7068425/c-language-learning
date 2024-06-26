#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(void)
{
    int *variable_array = NULL;
    int size = 0;
    char buf[256];
    int i;
    while (fgets(buf, 256, stdin) != NULL) 
    {
        buf[strcspn(buf, "\n")] = '\0';        //消除buf中的换行符"\n"

        if (strcmp(buf, "exit") == 0 || strcmp(buf, "quit") == 0) 
        {
            break;
        }
        size++;
        variable_array = realloc(variable_array,sizeof(int) * size);
        sscanf(buf, "%d",&variable_array[size-1]);
    }
    for (i = 0; i < size; i++) 
    {
        printf("variable_array[%d]..%d\n", i,variable_array[i]);
    }
    return 0;
}