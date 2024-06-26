#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void read_slogan(FILE *fp, char **slogan)
{
    char buf[1024];
    int i;
    for (i = 0; i < 7; i++) 
    {
        fgets(buf, 1024, fp);
        buf[strlen(buf)-1] = '\0';    //消除buf中的换行符"\n"
        slogan[i] = malloc(sizeof(char) *(strlen(buf) + 1));
        strcpy(slogan[i], buf);
    }
}
int main(void)
{
    char *slogan[7];
    int i;
    read_slogan(stdin, slogan);
    for (i = 0; i < 7; i++) 
    {
        printf("%s\n", slogan[i]);
    }
    return 0;
}