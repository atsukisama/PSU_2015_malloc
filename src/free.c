/*
** free.c for  in /home/mart_4/rendu/PSU_2015_malloc/src
**
** Made by Thomas martin
** Login   <mart_4@epitech.net>
**
** Started on  Wed Jan 27 09:37:38 2016 Thomas martin
** Last update Wed Jan 27 16:03:25 2016 Thomas Martins
*/

#include "struct.h"

void		check(void)
{
  t_block	*tmp;

  tmp = g_block;

  while (tmp)
    {
      printf("%d\n", tmp->block_size);
      tmp = tmp->next;
    }
}

t_block		*merge_block(void *ptr)
{
  char		*reset;
  t_block	*tmp;

  tmp = (t_block*)ptr - 1;
   if (tmp->next != NULL && tmp->next->is_free == true)
  {
      printf("MERGE\n");
      tmp->block_size += sizeof(t_block) + tmp->next->block_size;
      if (tmp->next->next != NULL)
	tmp->next = tmp->next->next;
      else
	tmp->next = NULL;
  }
   merge_block(ptr);
  return (tmp);
}

void		free(void *ptr)
{
  t_block	*tmp;

  tmp = (t_block *)ptr - 1;
  tmp->is_free = true;
}

 // merge block
// brk on end block
