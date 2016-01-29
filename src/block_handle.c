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

void		*check_mem(size_t *size, int supp)
{
  void		*request;

  request = NULL;
  if ((request = sbrk(sizeof(t_block) + *size + supp)) != (void *)-1)
    {
      *size += supp;
      return (request);
    }
  if ((request = sbrk(sizeof(t_block) + *size)) != (void *)-1)
    return (request);
  return (NULL);
}

t_block		*check_block(size_t size)
{
  t_block	*tmp;
  t_block	*ret;

  ret = NULL;
  tmp = g_block;
  while (tmp != NULL && tmp->next != NULL)
    {
      if (tmp->is_free == true && tmp->block_size >= size)
	{
	  if ((ret != NULL && tmp->block_size < ret->block_size) || ret == NULL)
	    ret = tmp;
	}
      tmp = tmp->next;
    }
  if (tmp != NULL && tmp->is_free == true)
    ret = tmp;
  return (ret);
}

t_block		*ask_mem(size_t size)
{
  t_block	*new_block;
  t_block	*tmp;
  void		*request;

  tmp = g_block;
  new_block = sbrk(0);
  if ((request = check_mem(&size, SUPPLEMENT)) == NULL)
    return (NULL);
  while (tmp != NULL && tmp->next != NULL)
    tmp = tmp->next;
  if (tmp != NULL)
    {
      tmp->next = new_block;
      new_block->prev = tmp;
    }
  else
    {
      g_block = new_block;
      new_block->prev = NULL;
    }
  new_block->block_size = size;
  new_block->next = NULL;
  new_block->is_free = true;
  new_block->magic = MAGIC;
  return (new_block);
}

void		show_alloc_mem()
{
  void		*b;
  t_block	*tmp;

  b = sbrk(0);
  tmp = g_block;
  printf("break : %p\n", b);
  while (tmp != NULL)
    {
      printf("%p - %p : %ld bytes\n", tmp + 1,
	     (void*)tmp + sizeof(t_block) + tmp->block_size, tmp->block_size);
      tmp = tmp->next;
    }
}

void		show_alloc_pro()
{
  void		*b;
  t_block	*tmp;

  b = sbrk(0);
  tmp = g_block;
  printf("Block size : %ld\n", sizeof(t_block));
  printf("break : %p\n", b);
  while (tmp != NULL)
    {
      if (tmp->is_free == false)
	printf("%p - %p : %ld bytes (used)\n", tmp + 1,
	       (void*)tmp + sizeof(t_block) + tmp->block_size, tmp->block_size);
      if (tmp->is_free == true)
	printf("%p - %p : %ld bytes (unused)\n", tmp + 1,
	       (void*)tmp + sizeof(t_block) + tmp->block_size, tmp->block_size);
      tmp = tmp->next;
    }
}
