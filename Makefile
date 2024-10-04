##
## EPITECH PROJECT, 2024
## Makefile
## File description:
## Makefile
##

CC	=	gcc

MAIN	=	main.c

EXEC 	=	file_handler

CS 		=	./coding_style/coding-style.sh

LOG		=	./coding_style/coding-style-reports.log

REPORTS =	./coding_style/

SRC 	=	$(wildcard ./src/*.c)

OBJ 	=	$(SRC:.c=.o)

RM 	=	rm -f

INCLUDE	=	-I src

CFLAGS	=	-W -Wall -Wextra -Werror

all: $(OBJ)
	$(CC) -g3 $(MAIN) $(OBJ) $(INCLUDE) $(CFLAGS) -o $(EXEC)

debug:
	$(CC) -g3 $(MAIN) $(SRC) $(INCLUDE) $(CFLAGS) -o $(EXEC)


.PHONY: clean fclean norm

clean:
	$(RM) $(OBJ)
	$(RM) *~
	$(RM) vgcore*

fclean: clean
	$(RM) $(EXEC)
	$(RM) *.out

norm: fclean
	$(CS) . $(REPORTS)
	cat $(LOG)

re: clean all
