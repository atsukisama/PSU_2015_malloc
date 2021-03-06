/*
** block.c for block in /home/kerebe_p/Documents/Epitech/malloc
** 
** Made by kerebe_p
** Login   <paul.kerebel@epitech.eu>
** 
** Started on  Sun Jan 31 03:35:35 2016 kerebe_p
** Last update Sun Feb 14 20:32:59 2016 Thomas Martins
*/

#include "malloc.h"

size_t		aligned_size(size_t size, size_t align)
{
  if (size % align == 0)
    return (size);
  size = size + (align - (size % align));
  return (size);
}

t_block		*check_block(size_t size, t_block *mem)
{
  t_block	*tmp;
  t_block	*ret;

  ret = NULL;
  tmp = mem;
  while (tmp != NULL)
    {
      if ((tmp->p_size >= size) && (tmp->is_free == TRUE))
	{
	  if (((ret != NULL) && (ret->p_size > tmp->p_size)) ||
	      (ret == NULL))
	    ret = tmp;
	}
      tmp = tmp->next;
    }
  return (ret);
}

t_block		*ask_mem(size_t size)
{
  t_block	*block;

  block = sbrk(0);
  if (sbrk(aligned_size(size + B_SIZE, P_SIZE)) == (void*)-1)
    {
      if (sbrk(size + B_SIZE) == (void*)-1)
	return (NULL);
      block->p_size = size;
      return (block);
    }
  block->p_size = aligned_size(size + B_SIZE, P_SIZE) - B_SIZE;
  return (block);
}

t_block		*create_block(size_t size, t_block **mem)
{
  t_block	*new_block;
  t_block	*tmp;

  tmp = *mem;
  new_block = ask_mem(size);
  if (new_block == NULL)
    return (NULL);
  while (tmp != NULL && tmp->next != NULL)
    tmp = tmp->next;
  if (*mem == NULL)
    {
      *mem = new_block;
      new_block->prev = NULL;
    }
  else
    {
      tmp->next = new_block;
      new_block->prev = tmp;
    }
  new_block->next = NULL;
  new_block->m_key = MAGIC;
  return (new_block);
}
