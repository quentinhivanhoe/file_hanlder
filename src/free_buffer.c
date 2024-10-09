/*
** EPITECH PROJECT, 2024
** file_hanlder
** File description:
** free the buffer of the file
*/
#include <stdlib.h>
#include <stdio.h>
#include "./file_handler.h"

void free_buffer(buffer_t *buffer)
{
    unsigned int begin = 0;

    if (!buffer)
        return;
    begin = buffer->index;
    buffer = buffer->next;
    while (buffer->index != begin) {
        buffer = buffer->next;
        free(buffer->prev);
    }
    free(buffer);
}