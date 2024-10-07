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
    if (buffer == NULL)
        return;
    buffer = buffer->next;
    if (buffer->index == buffer->next->index) {
        free(buffer);
        return;
    }
    while (buffer->index < buffer->next->index) {
        buffer = buffer->next;
        free(buffer->prev);
    }
    free(buffer->next);
    free(buffer);
    return;
}
