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

void		*my_malloc(size_t size)
{
  void		*start;
  void		*requested;
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
  return (new_block->adr_start);
}

int		main(void)
{
  char		*free;
  char		*str;
  char		*other;
  char		*end;

  str = my_malloc(sizeof(char) * 5);
  other = my_malloc(sizeof(char) * 3);
  g_block->is_free = true;
  g_block->next->is_free = true;
  other = my_malloc(sizeof(char) * 5);
  str = my_malloc(sizeof(char) * 3);
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
