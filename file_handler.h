/*
** EPITECH PROJECT, 2024
** file handler
** File description:
** header for a file handler object
*/

#ifndef FILE_HANDLER_H_
    #define FILE_HANDLER_H_
    #include <stdbool.h>
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
    buffer_t *content;
} file_t;


#endif /* !FILE_HANLDER_H_ */
