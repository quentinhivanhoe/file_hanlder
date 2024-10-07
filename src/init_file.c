/*
**          QH DEV PROJECT 
**          10/07/2024
**
**  Project : file_handler
**  Description : transform the file into a string
**  Date last update : 
**  Subject last update :
*/
#include "file_handler.h"
#include <fcntl.h>
#include <stdlib.h>
#include <string.h>

file_t *init_file(char *filepath)
{
    file_t *file = NULL;
    int fd = 0;

    if (filepath == NULL)
        return NULL;
    fd = open(filepath, O_RDONLY);
    if (fd < 0)
        return NULL;
    file = malloc(sizeof(file_t));
    if (file == NULL)
        return NULL;
    file->file_name = strdup(filepath);
    file->content = get_content(fd, &file->nb_node, &file->size);
    return file;
}