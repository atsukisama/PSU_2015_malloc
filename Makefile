##
## Makefile<2> for  in /home/mart_4/rendu/PSU_2015_malloc
##
## Made by Thomas Martins
## Login   <mart_4@epitech.net>
##
## Started on  Mon Jan 25 23:08:27 2016 Thomas Martins
## Last update Mon Jan 25 23:38:42 2016 Thomas Martins
##

SRCDIR	= src/

OBJ	= $(SRC:.c=.o)

SRC	= src/malloc.c \

NAME	= libmy_malloc_$(HOSTTYPE).so

LINK	= libmy_malloc.so

RM	= rm -f

CFLAGS	:= -pedantic -shared -fPIC -lpthread
CFLAGS	+= -W -Wall -Werror -Wextra -fPIC

CC	= cc

all:	$(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ)

%.o : %.c
	$(CC) -c $(CFLAGS) -o $@ $^
	ln -sf $(NAME) $(LINK)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)
	$(RM) $(LINK)

re: fclean all
