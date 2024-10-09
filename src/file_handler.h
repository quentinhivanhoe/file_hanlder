/*
** EPITECH PROJECT, 2024
** file handler
** File description:
** header for a file handler object
*/

#ifndef FILE_HANDLER_H_
    #define FILE_HANDLER_H_
    #include <stdbool.h>
    #include <stddef.h>
    #define BUFFER_SIZE 4096

typedef struct buffer_s {
    unsigned int index;
    unsigned int size;
    char buffer[BUFFER_SIZE + 1];
    struct buffer_s *next;
    struct buffer_s *prev;
} buffer_t;

typedef struct file_s {
    char *file_name;
    unsigned long int size;
    unsigned long int nb_node;
    buffer_t *content;
} file_t;

///////////////////////////////////////////////////////////////////////////////
/// @brief get the content of the file
/// @param filepath the path to the file
/// @param nb_node a pointer to an int that represent the number of node
/// @param max_size a pointer to an int thar represent the maximum
///                 size of the file
/// @return linked list with a part of the file in each node
///////////////////////////////////////////////////////////////////////////////
buffer_t *get_content(int fd, size_t *nb_node, size_t *max_size);

void free_buffer(buffer_t *buffer);

file_t *init_file(char *filepath);

void free_file(file_t *file);

char *file_to_str(file_t *file);

void __seek_end_buff(buffer_t **buff);

#endif /* !FILE_HANLDER_H_ */
