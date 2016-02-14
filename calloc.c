/*
** calloc.c for  in /home/mart_4/PSU_2015_malloc
**
** Made by Thomas Martins
** Login   <mart_4@epitech.net>
**
** Started on  Sun Feb 14 16:40:32 2016 Thomas Martins
** Last update Sun Feb 14 19:22:28 2016 Thomas Martins
*/

#include "malloc.h"

void		*calloc(size_t nb, size_t size)
{
  void		*ptr;

  if (nb == 0 || size == 0)
    return (NULL);
  if ((ptr = malloc((nb * size))) == NULL)
    return (NULL);
  return (memset(ptr, 0, (nb * size)));
}
