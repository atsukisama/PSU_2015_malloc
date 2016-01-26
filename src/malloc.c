/*
** malloc.c for  in /home/mart_4/rendu/PSU_2015_malloc/src
**
** Made by Thomas Martins
** Login   <mart_4@epitech.net>
**
** Started on  Mon Jan 25 23:52:07 2016 Thomas Martins
** Last update Tue Jan 26 13:44:24 2016 Thomas Martins
*/

#include "struct.h"
#include <stdlib.h>

void		check_split(t_block *current, size_t size)
{
  t_block	*new_block;

  if (current->block_size > (size + sizeof(t_block)))
    {
      new_block = (current->adr_start) + size + 1;
      new_block->adr_start = (new_block) + 1;
      new_block->block_size = current->block_size - sizeof(t_block) - size;
      current->block_size = size;
      new_block->next = current->next;
      current->next = new_block;
      new_block->is_free = true;
    }
}

void		*my_malloc(size_t size)
{
  t_block	*new_block;

  if (size == 0)
    return (NULL);
  if ((new_block = check_block(size)) == NULL)
    new_block = check_mem(size);
  if (new_block == NULL)
    return (NULL);
  new_block->adr_start = (new_block)+1;
  printf("MALLOC\n");
  new_block->is_free = false;
  check_split(new_block, size);
  return (new_block->adr_start);
}

int		main(void)
{
  char		*free;
  char		*str;
  char		*other;
  char		*end;

  str = my_malloc(sizeof(char) * 120);
  g_block->is_free = true; //free imitation
  other = my_malloc(sizeof(char) * 20);
  end = my_malloc(sizeof(char) * 60);
  free = my_malloc(sizeof(char) * 20);
  /*
  other = my_malloc(sizeof(char) * 50);
  end = my_malloc(sizeof(int*) * 51);
  g_block->is_free = false;
  g_block->next->is_free = true;
  g_block->next->next->is_free = true;
  brk(end-(sizeof(t_block)));
  other = my_malloc(sizeof(char) * 50);
  */
  //str = my_malloc(sizeof(char) * 3);
  //strcpy(str, "OK");
  //strcpy(other, "salut");
  /*
  //free start
  g_block->is_free = true;
  free = (char*)(g_block->adr_start);
  free[0] = 0;
  //free end
  */
  //str = my_malloc(sizeof(char) * 3);
  //strcpy(str, "salut");
  //strcpy(other, "test");
  //printf("%s\n%s\n", g_block->adr_start+1, other);
  show_alloc_mem();
  return (true);
}
