/*
** EPITECH PROJECT, 2024
** file handler
** File description:
** get the content of a file
*/

#include "./file_handler.h"
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

buffer_t *allocate_buffer(buffer_t *prev, int idx)
{
    buffer_t *buffer = malloc(sizeof(buffer_t));

    buffer->index = idx;
    buffer->size = 0;
    buffer->next = NULL;
    buffer->prev = prev;
    return buffer;
}

buffer_t *get_content(char *filepath, int *nb_node, int *max_size)
{
    int fd = open(filepath, O_RDONLY);
    buffer_t *content = allocate_buffer(NULL, 0);
    int size = read(fd, content->buffer, BUFFER_SIZE);
    buffer_t *first = content;

    content->buffer[size] = '\0';
    content->size = size;
    (*max_size) += size;
    for (; size == BUFFER_SIZE; (*nb_node)++) {
        content->next = allocate_buffer(content, (*nb_node));
        content = content->next;
        size = read(fd, content->buffer, BUFFER_SIZE);
        content->buffer[size] = '\0';
        content->size = size;
        (*max_size) += size;
    }
    content->next = first;
    close(fd);
    return content->next;
}

int main(int argc, char **argv)
{
    int nb_node = 1;
    int size = 0;
    buffer_t *content = get_content(argv[1], &nb_node, &size);

    while (content->index < content->next->index) {
        printf("%s", content->buffer);
        content = content->next;
    }
    printf("%s", content->buffer);
    printf("index:size : [%i]\nnb_node : [%i]\n", size, nb_node);
    free(content);
    return 0;
}
