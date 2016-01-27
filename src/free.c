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
      tmp->next = tmp->next->next;
    }
  return (tmp);
}

void		free(void *ptr)
{
  t_block	*tmp;

  tmp = (t_block *)ptr - 1;
  tmp->is_free = true;
  tmp = g_block;
  while (tmp)
    {
      while (tmp->is_free == true && tmp->next != NULL)
	tmp = merge_block(tmp->adr_start);
      tmp = tmp->next;
    }
  //  if (tmp->is_free == true && tmp->next == NULL)
  //brk(tmp);
}

 // merge block
// brk on end block
