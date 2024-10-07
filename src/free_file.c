/*
**          QH DEV PROJECT 
**          10/07/2024
**
**  Project : file_handler
**  Description : free a file_t structure
**  Date last update : 10/07/2024
**  Subject last update : free a file_t
*/
#include "file_handler.h"
#include <stdlib.h>

void free_file(file_t *file)
{
    if (!file)
        return;
    if (file->file_name)
        free(file->file_name);
    if (file->content)
        free_buffer(file->content);
    free(file);
}