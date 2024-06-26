#include <stdlib.h>
#include "word_manage_p.h"

//管理单词部分的结束处理
void word_finalize(void)
{
    Word *temp;
    //将所有登录的单词free()
    while (word_header != NULL) 
    {
        temp = word_header;
        word_header = word_header->next;
        free(temp->name);
        free(temp);
    }
}