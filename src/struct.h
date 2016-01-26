/*
** struct.h for  in /home/mart_4/rendu/PSU_2015_malloc/src
**
** Made by Thomas Martins
** Login   <mart_4@epitech.net>
**
** Started on  Mon Jan 25 23:48:39 2016 Thomas Martins
** Last update Tue Jan 26 14:17:20 2016 Thomas Martins
*/

#ifndef STRUCT_H_
# define STRUCT_H_

#include <sys/types.h>
#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <unistd.h>
#include <stdbool.h>

typedef struct	s_block	t_block;

t_block	*g_block;

struct			s_block
{
  size_t		block_size;
  int			is_free;
  void			*adr_start;
  struct s_block	*next;
};

#endif		/* struct */
