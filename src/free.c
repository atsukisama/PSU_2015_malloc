
/*
** free.c for  in /home/mart_4/rendu/PSU_2015_malloc/src
**
** Made by Thomas martin
** Login   <mart_4@epitech.net>
**
** Started on  Wed Jan 27 09:37:38 2016 Thomas martin
** Last update Wed Jan 27 17:51:52 2016 Thomas Martins
*/

#include "struct.h"

void		check(void)
{
  t_block	*tmp;

  tmp = g_block;

  while (tmp)
    {
      tmp = tmp->next;
    }
}

t_block		*merge_block(void *ptr)
{
  t_block	*tmp;

  tmp = (t_block*)ptr - 1;
  if (tmp->next != NULL && tmp->next->is_free == true)
    {
      tmp->block_size += sizeof(t_block) + tmp->next->block_size;
      tmp->next = tmp->next->next;
    }
  return (tmp);
}

void		reduce_mem(t_block *delete)
{
  if (delete != NULL && delete->is_free == true && delete->next == NULL)
    {
      brk(delete);
      if (delete == g_block)
	g_block = NULL;
    }
}

void		my_free(void *ptr)
{
  (void)ptr;
}
