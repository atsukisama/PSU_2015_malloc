##
## Makefile<2> for  in /home/mart_4/rendu/PSU_2015_malloc
##
## Made by Thomas Martins
## Login   <mart_4@epitech.net>
##
## Started on  Mon Jan 25 23:08:27 2016 Thomas Martins
## Last update Sun Feb 14 20:36:32 2016 Thomas Martins
##

NAME 	= libmy_malloc_$(HOSTTYPE).so

LINK	= libmy_malloc.so

CC      = gcc

SRC	= malloc.c 		\
	  block.c 		\
	  block_manip.c		\
	 calloc.c		\

RM      = rm -f

OBJ	= $(SRC:.c=.o)

RM	= rm -f

CFLAGS	+= -W -Wall -Wextra -Werror -fPIC
LDFLAGS	+= -shared

CC	= gcc

all:	$(NAME)

$(NAME): $(OBJ)
	$(CC) -o $(NAME) $(LDFLAGS) $(OBJ)
	ln -sf $(NAME) $(LINK)


%.o : %.c
	$(CC) -c $(CFLAGS) -o $@ $^

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(LINK)
	$(RM) $(NAME)

re: fclean all
