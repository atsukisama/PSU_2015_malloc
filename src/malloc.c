/*
** malloc.c for  in /home/mart_4/rendu/PSU_2015_malloc/src
**
** Made by Thomas Martins
** Login   <mart_4@epitech.net>
**
** Started on  Mon Jan 25 23:52:07 2016 Thomas Martins
** Last update Tue Jan 26 13:44:24 2016 Thomas Martins
*/

#include <stdlib.h>
#include "struct.h"

t_block	*g_block = NULL;
/*
void		check_split(t_block *current, size_t size)
{
  t_block	*new_block;

  if (current->block_size > (size + sizeof(t_block)))
    {
      printf("-----SPLIT-----\n");
      //printf("%p - %p\n", (void*)current + size + sizeof(t_block), current->adr_start + size);
      //new_block = current->adr_start + size;
      new_block = (void*)current + size + sizeof(t_block);
      //new_block->adr_start = (new_block) + 1;
      new_block->block_size = current->block_size - sizeof(t_block) - size;
      current->block_size = size;
      new_block->next = current->next;
      current->next = new_block;
      new_block->prev = current;
      new_block->magic = MAGIC;
      new_block->is_free = true;
      printf("-----SPLIT-----\n");
    }
}
*/

t_block		*check_split(t_block *current, size_t size)
{
  t_block	*new_block;

  if (current->block_size > (size + sizeof(t_block)))
    {
      current->block_size = current->block_size - sizeof(t_block) - size;
      new_block = (void*)current + current->block_size + sizeof(t_block);
      new_block->block_size = size;
      new_block->next = current->next;
      current->next = new_block;
      new_block->prev = current;
      new_block->magic = MAGIC;
      new_block->is_free = true;
      return (new_block);
    }
  return (current);
}

void		*my_malloc(size_t size)
{
  t_block	*new_block;

  new_block = NULL;
  if ((intptr_t)size <= 0)
    return (NULL);
  if ((new_block = check_block(size)) == NULL)
    new_block = ask_mem(size);
  if (new_block == NULL)
    return (NULL);
  //new_block->adr_start = (new_block)+1;
  new_block = check_split(new_block, size);
  new_block->is_free = false;
  return (new_block + 1);
}
