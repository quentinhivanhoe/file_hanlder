/*
**          QH DEV PROJECT 
**          10/07/2024
**
**  Project : file_handler
**  Description : transform the file into a string
**  Date last update : 
**  Subject last update :
*/
#include "./file_handler.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
char *file_to_str(file_t *file)
{
    char *str = NULL;

    if (!file)
        return NULL;
    str = malloc(sizeof(char) * (file->size + 1));
    str[0] = '\0';
    while (file->content->index < file->content->next->index) {
        str = strcat(str, file->content->buffer);
        file->content = file->content->next;
    }
    str = strcat(str, file->content->buffer);
    file->content = file->content->next;
    return str;
}