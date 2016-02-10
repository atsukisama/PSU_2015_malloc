/*
** block_manip.c for manip in /home/kerebe_p/Documents/Epitech/malloc
** 
** Made by kerebe_p
** Login   <paul.kerebel@epitech.eu>
** 
** Started on  Sun Jan 31 16:26:56 2016 kerebe_p
** Last update Sun Jan 31 16:26:56 2016 kerebe_p
*/

#include "malloc.h"

int		is_valid(void *ptr, t_block *g_mem)
{
  t_block	*block;

  if (g_mem == NULL)
    return (FALSE);
  if ((intptr_t)ptr > (intptr_t)g_mem && (intptr_t)ptr < (intptr_t)sbrk(0))
    {
      block = (t_block*)((intptr_t)ptr - sizeof(t_block));
      if ((intptr_t)block >= (intptr_t)g_mem && block->m_key == MAGIC)
	return (TRUE);
    }
  return (FALSE);
}

void		split_block(size_t size, t_block *current)
{
  t_block	*new_block;

  if (current != NULL && current->p_size > (size + sizeof(t_block)))
    {
      new_block = (t_block*)((intptr_t)current + size + sizeof(t_block));
      new_block->p_size = current->p_size - sizeof(t_block) - size;
      current->p_size = size;
      new_block->next = current->next;
      current->next = new_block;
      new_block->prev = current;
      new_block->m_key = MAGIC;
      new_block->is_free = TRUE;
    }
}

void		merge_block(t_block *current)
{
  t_block	*tmp;

  tmp = current->next;
  while (tmp != NULL && tmp->is_free == TRUE)
    {
      tmp->m_key = 0;
      current->p_size += tmp->p_size + sizeof(t_block);
      tmp = tmp->next;
    }
  current->next = tmp;
  if (tmp != NULL)
    tmp->prev = current;
}