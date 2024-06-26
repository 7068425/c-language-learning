#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#define ALLOC_SIZE (256)
static char *st_line_buffer = NULL;      //在st_line_buffer 前方被分配的内存区域的大小。
static int st_current_buffer_size = 0;    //st_line_buffer 中现在保存的字符的大小。
static int st_current_used_size = 0;      //如有必要,扩展st_line_buffer 前方的内存区域。在st_line_buffer 末尾追加一个字符。
static void add_character(int ch)
{
    //此函数每次被调用,st_current_used_size 都必定会增加1,正常的情况下,下面的断言肯定不会出错。
    assert(st_current_buffer_size >=st_current_used_size);      //st_current_used_size 达到 st_current_buffer_size 的时候，扩展缓冲区的内存区域。
    if (st_current_buffer_size ==st_current_used_size) 
    {
        st_line_buffer = realloc(st_line_buffer,(st_current_buffer_size +ALLOC_SIZE)* sizeof(char));
        st_current_buffer_size += ALLOC_SIZE;
    }
    st_line_buffer[st_current_used_size] = ch;     //在缓冲区末尾追加一个字符
    st_current_used_size++;
}
//从fp 读取一行字符，一旦读到文件末尾，就返回NULL。
char *read_line(FILE *fp)
{
    int  ch;
    char *ret;
    st_current_used_size = 0;
    while ((ch = getc(fp)) != EOF) 
    {
        if (ch == '\n') 
        {
            add_character('\0');
            break;
        }
        add_character(ch);
    }
    if (ch == EOF) 
    {
        if (st_current_used_size > 0) 
        {
            add_character('\0');    //如果最终行后面没有换行
        } 
        else 
        {
            return NULL;
        }
    }
    ret = malloc(sizeof(char) *st_current_used_size);
    strcpy(ret, st_line_buffer);
    return ret;
}
char **add_line(char **text_data,char*line,int *line_alloc_num, int *line_num)
{
    assert(*line_alloc_num >= *line_num);
    if (*line_alloc_num == *line_num) 
    {
        text_data = realloc(text_data,(*line_alloc_num + ALLOC_SIZE) *sizeof(char*));
        *line_alloc_num += ALLOC_SIZE;
    }
    text_data[*line_num] = line;
    (*line_num)++;
    return text_data;
}

char **read_file(FILE *fp, int *line_num_p)
{
    char **text_data = NULL;
    int line_num = 0;
    int line_alloc_num = 0;
    char *line;
    while ((line = read_line(fp)) != NULL) 
    {
        text_data = add_line(text_data,line, &line_alloc_num, &line_num);
    }
    /*将text_data 缩小到实际需要的大小 */
    text_data = realloc(text_data, line_num *sizeof(char*));
    *line_num_p = line_num;
    return text_data;
}

int main(void)
{
    char **text_data;
    int line_num;
    int i;
    text_data = read_file(stdin, &line_num);
    for (i = 0; i < line_num; i++) 
    {
        printf("%s\n", text_data[i]);
    }
    return 0;
}