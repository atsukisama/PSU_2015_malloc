/*
** malloc.c for  in /home/mart_4/rendu/PSU_2015_malloc/src
**
** Made by Thomas Martins
** Login   <mart_4@epitech.net>
**
** Started on  Mon Jan 25 23:52:07 2016 Thomas Martins
** Last update Sat Jan 30 04:26:56 2016 Thomas martin
*/

#include "struct.h"

//t_block	*g_block = NULL;

// DEBUT DE PLAGE
void		check_split(t_block *current, size_t size)
{
  t_block	*new_block;

  if (current->block_size > (size + sizeof(t_block)))
    {
      new_block = (void*)current + size + sizeof(t_block);
      new_block->block_size = current->block_size - sizeof(t_block) - size;
      current->block_size = size;
      new_block->next = current->next;
      current->next = new_block;
      new_block->prev = current;
      new_block->magic = MAGIC;
      new_block->is_free = true;
    }
}

/* FIN DE PLAGE*/
/* t_block		*check_split(t_block *current, size_t size) */
/* { */
/*   t_block	*new_block; */

/*   if (current->block_size > (size + sizeof(t_block))) */
/*     { */
/*       current->block_size = current->block_size - sizeof(t_block) - size; */
/*       new_block = (void*)current + current->block_size + sizeof(t_block); */
/*       new_block->block_size = size; */
/*       new_block->next = current->next; */
/*       current->next = new_block; */
/*       new_block->prev = current; */
/*       new_block->magic = MAGIC; */
/*       new_block->is_free = true; */
/*       return (new_block); */
/*     } */
/*   return (current); */
/* } */

void		*grow_mem(t_block *block, size_t size)
{
  if (block->block_size >= size)
    return (block + 1);
  if (size > block->block_size && sbrk(size - block->block_size) != (void*)-1)
    {
      block->block_size = size;
      return (block + 1);
    }
  return (NULL);
}

size_t		aligned_size(size_t size, int align)
{
  if (size % align != 0)
    size = size + (align - size % align);
  return (size);
}

void		*malloc(size_t size)
{
  t_block	*new_block;
  void		*pointer;

  new_block = NULL;
  pointer = NULL;
  if ((intptr_t)size <= 0)
    return (NULL);
  size = aligned_size(size, sizeof(void*));
  if ((new_block = check_block(size)) == NULL)
    new_block = ask_mem(size);
  if (new_block == NULL)
    return (NULL);
  //new_block = check_split(new_block, size); FIN DE PLAGE
  check_split(new_block, size);
  new_block->is_free = false;
  pointer = new_block + 1;
  pointer = grow_mem(new_block, size);

  return (pointer);
}

void		*realloc(void *ptr, size_t size)
{
  t_block    *block;
  size_t     rsize;
  void               *new;

  //(void)rsize;
  if (!ptr)
    return (malloc(size));
  //printf("TEST\n");
  if (g_block != NULL && (intptr_t)ptr < (intptr_t)sbrk(0) && (intptr_t)ptr > (intptr_t)g_block)
    {
      block = ptr - sizeof(t_block);
      //printf("TEST1\n");
      if ((intptr_t)block >= (intptr_t)g_block && block->magic == MAGIC)
     {
       rsize = block->block_size;
       //block->is_free = true;
       free(ptr);
       //printf("TEST2\n");
       if ((new = malloc(size)) != NULL)
         {
	   //           printf("HERE\n");
           memcpy(new, ptr, rsize);
           //printf("END\n");
           //free(ptr);
         }
       return (new);
     }
      return (ptr);
    }
  return (NULL);
}
