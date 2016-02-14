/*
** malloc.c for malloc in /home/kerebe_p/Documents/Epitech/malloc
** 
** Made by kerebe_p
** Login   <paul.kerebel@epitech.eu>
** 
** Started on  Sun Jan 31 03:21:51 2016 kerebe_p
** Last update Sun Feb 14 18:16:04 2016 Thomas Martins
*/

#include "malloc.h"

t_block		*g_mem = NULL;

void		*malloc(size_t size)
{
  t_block	*new;

  new = NULL;
  if ((intptr_t)size <= 0)
    return (NULL);
  size = aligned_size(size, sizeof(void*));
  if ((new = check_block(size, g_mem)) == NULL)
    new = create_block(size, &g_mem);
  if (new == NULL)
    {
      return (NULL);
    };
  new->is_free = FALSE;
  split_block(size, new);
  return (new + 1);
}

void		free(void *ptr)
{
  t_block	*block;
  size_t	rez;

  rez = 0;
  if (is_valid(ptr, g_mem) == TRUE)
    {
      block = (t_block*)((intptr_t)ptr - B_SIZE);
      block->is_free = TRUE;
      while (block->prev != NULL && block->prev->is_free == TRUE)
	block = block->prev;
      merge_block(block);
      if (block->next == NULL)
	{
	  rez = (block->p_size / P_SIZE) * P_SIZE;
	  sbrk(-rez);
	  block->p_size -= rez;
	}
      if (block->prev == NULL && block->next == NULL)
      	{
      	  g_mem = NULL;
      	  brk(block);
      	}
    }
}

void		*realloc(void *ptr, size_t size)
{
  t_block	*block;
  void		*new;

  if (ptr == NULL)
    return (malloc(size));
  if (is_valid(ptr, g_mem) == TRUE)
    {
      block = ptr - B_SIZE;
      if (size == 0)
	free(ptr);
      else if (block->p_size < size && (new = malloc(size)) != NULL)
  	{
  	  memcpy(new, ptr, block->p_size);
  	  free(ptr);
	  return (new);
  	}
      return (ptr);
    }
  return (NULL);
}

void		show_alloc_mem()
{
  t_block	*tmp;

  tmp = g_mem;
  printf("break : %p\n", sbrk(0));
  while (tmp != NULL)
    {
      printf("%p - %p : %zu bytes", (void*)(tmp + 1),
	     (void*)((intptr_t)tmp + B_SIZE + tmp->p_size), tmp->p_size);
      tmp = tmp->next;
    }
}
