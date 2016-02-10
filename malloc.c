/*
** malloc.c for malloc in /home/kerebe_p/Documents/Epitech/malloc
** 
** Made by kerebe_p
** Login   <paul.kerebel@epitech.eu>
** 
** Started on  Sun Jan 31 03:21:51 2016 kerebe_p
** Last update Sun Jan 31 03:21:51 2016 kerebe_p
*/

#include "malloc.h"

t_block		*g_mem = NULL;
pthread_mutex_t	g_lock = PTHREAD_MUTEX_INITIALIZER;

void		*malloc(size_t size)
{
  t_block	*new;

  new = NULL;
  if ((intptr_t)size <= 0)
    return (NULL);
  size = aligned_size(size, sizeof(void*));
  pthread_mutex_lock(&g_lock);
  if ((new = check_block(size, g_mem)) == NULL)
    new = create_block(size, &g_mem);
  if (new == NULL)
    {
      pthread_mutex_unlock(&g_lock);
      return (NULL);
    }
  new->is_free = FALSE;
  split_block(size, new);
  pthread_mutex_unlock(&g_lock);
  return (new + 1);
}

void		free(void *ptr)
{
  t_block	*block;

  if (is_valid(ptr, g_mem) == TRUE)
    {
      pthread_mutex_lock(&g_lock);
      block = (t_block*)((intptr_t)ptr - sizeof(t_block));
      block->is_free = TRUE;
      while (block->prev != NULL && block->prev->is_free == TRUE)
	block = block->prev;
      merge_block(block);
      if (block->prev == NULL && block->next == NULL)
      	{
      	  g_mem = NULL;
      	  brk(block);
      	}
      pthread_mutex_unlock(&g_lock);
    }
}

void		*realloc(void *ptr, size_t size)
{
  t_block	*block;
  void		*new;

  if (!ptr)
    return (malloc(size));
  if (is_valid(ptr, g_mem) == TRUE)
    {
      block = ptr - sizeof(t_block);
      if ((new = malloc(size)) != NULL)
	{
	  memcpy(new, ptr, block->p_size);
	  free(ptr);
	}
      return (new);
    }
  return (ptr);
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
