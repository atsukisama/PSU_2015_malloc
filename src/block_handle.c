/*
** block_handle.c for block_handle in /home/kerebe_p/Documents/PSU_2015_malloc/src
** 
** Made by kerebe_p
** Login   <paul.kerebel@epitech.eu>
** 
** Started on  Tue Jan 26 13:09:58 2016 kerebe_p
** Last update Tue Jan 26 14:52:24 2016 Thomas Martins
*/

#include "struct.h"

t_block		*check_block(size_t size)
{
  t_block	*tmp;
  t_block	*ret;
  size_t	i;

  i = 0;
  tmp = g_block;
  while (tmp != NULL)
    {
      if (i >= size && i < tmp->block_size && tmp->is_free == true)
	{
	  i = tmp->block_size;
	  ret = tmp;
	}
      tmp = tmp->next;
    }
  if (i == 0)
    return (NULL);
  return (ret);
}

t_block		*check_mem(t_block *block, size_t size)
{
  t_block	*new_block;
  void		*request;

  new_block = sbrk(0);
  request = sbrk(sizeof(t_block) + size);
  if (request == (void *) -1)
    return (NULL);
  if (block != NULL)
    block->next = new_block;
  block->block_size = size;
  block->next = NULL;
  block->is_free = true;
  return (new_block);
}
