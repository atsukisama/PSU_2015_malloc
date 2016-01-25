/*
** struct.h for  in /home/mart_4/rendu/PSU_2015_malloc/src
**
** Made by Thomas Martins
** Login   <mart_4@epitech.net>
**
** Started on  Mon Jan 25 23:48:39 2016 Thomas Martins
** Last update Mon Jan 25 23:52:54 2016 Thomas Martins
*/

#ifndef STRUCT_H_
# define STRUCT_H_

#include <stdbool.h>

typedef struct	header	t_header;

struct		header
{
  struct header	*first;
};

#endif		/* struct */
