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
    buffer_t *buff = NULL;

    if (!file)
        return NULL;
    str = malloc(sizeof(char) * (file->size + 1));
    if (!str)
        return NULL;
    str[0] = '\0';
    buff = file->content;
    if (!buff)
        return NULL;
    while (buff) {
        str = strcat(str, buff->buffer);
        buff = buff->next;
    }
    return str;
}