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

void seek_end_file(buffer_t **buff)
{
    if (!(*buff))
        return;
    while ((*buff)->next)
        (*buff) = (*buff)->next;
}

void seek_begin_file(buffer_t **buff)
{
    if (!(*buff))
        return;
    while ((*buff)->prev)
        (*buff) = (*buff)->prev;
}

void seek_in_file(file_t *file, void (*seek)(buffer_t **))
{
    seek(&file->content);
}