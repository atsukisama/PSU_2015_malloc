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

t_block		*merge_block(t_block *tmp)
{
  if (tmp->next != NULL && tmp->next->is_free == true)
    {
      tmp->block_size += sizeof(t_block) + tmp->next->block_size;
      tmp->next = tmp->next->next;
    }
  return (tmp);
}

void		reduce_mem(t_block *delete)
{
  if (delete != NULL && delete->prev == NULL
      && delete->is_free == true && delete->next == NULL)
    {
      brk(delete);
      if (delete == g_block)
	g_block = NULL;
      else
	delete->prev->next = NULL;
    }
}

void		my_free(void *ptr)
{
  t_block	*block;

  if (g_block != NULL && (intptr_t)ptr < (intptr_t)sbrk(0))
    {
      block = ptr - sizeof(t_block);
      if (block->magic == MAGIC)
	{
	  block->is_free = true;
	  if (block->prev != NULL && block->prev->is_free == true)
	    block = block->prev;
	  while (block->next != NULL && block->next->is_free == true)
	    block = merge_block(block);
	  reduce_mem(block);
	}
    }
}
