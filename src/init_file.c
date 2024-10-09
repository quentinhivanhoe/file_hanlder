/*
**          QH DEV PROJECT 
**          10/07/2024
**
**  Project : file_handler
**  Description : allocate a file_t and fill it with filepath
**  Date last update : 10/07/2024
**  Subject last update : initialize nb_node ande the size of the file
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
    file->nb_node = 0;
    file->size = 0;
    file->content = get_content(fd, &file->nb_node, &file->size);
    return file;
}