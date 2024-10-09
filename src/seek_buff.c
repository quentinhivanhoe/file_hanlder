/*
**          QH DEV PROJECT 
**          10/07/2024
**
**  Project : file_handler
**  Description : concatenate two file
**  Date last update : 
**  Subject last update :
*/

#include "file_handler.h"

void __seek_end_buff(buffer_t **buff)
{
    if (!(*buff))
        return;
    while ((*buff)->index < (*buff)->next->index)
        (*buff) = (*buff)->next;
}

// void file_cat(file_t *dst, file_t *src)
// {
//     buffer_t *dst_buff = dst->content;
//     buffer_t *src_buff = src->content;

//     while (src_buff)
// }