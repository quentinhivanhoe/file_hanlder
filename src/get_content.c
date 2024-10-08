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

buffer_t *get_content(int fd, size_t *nb_node, size_t *max_size)
{
    buffer_t *content = allocate_buffer(NULL, (*nb_node));
    int size = read(fd, content->buffer, BUFFER_SIZE);
    void *save_ptr = content;

    content->buffer[size] = '\0';
    content->size = size;
    (*max_size) += size;
    for ((*nb_node) += 1; size == BUFFER_SIZE; (*nb_node)++) {
        content->next = allocate_buffer(content, (*nb_node));
        content = content->next;
        size = read(fd, content->buffer, BUFFER_SIZE);
        content->buffer[size] = '\0';
        content->size = size;
        (*max_size) += size;
    }
    return save_ptr;
}
