/*
** malloc.c for  in /home/mart_4/rendu/PSU_2015_malloc/src
**
** Made by Thomas Martins
** Login   <mart_4@epitech.net>
**
** Started on  Mon Jan 25 23:52:07 2016 Thomas Martins
** Last update Mon Jan 25 23:52:08 2016 Thomas Martins
*/

#include "struct.h"

void		*my_malloc(size_t size)
{
  void		*start;
  void		*requested;
  t_block	*new_block;

  if (size == 0)
    return (NULL);
  if (g_block == NULL)
    {
      
    }
  start = sbrk(0);
  requested = sbrk(size);
  if (requested == (void*) -1)
    return NULL;
  if (start == requested);
  {
    printf("add : %p\n", requested);
    return (start);
  }
}

int		main(void)
{
  char		*str;
  char		*other;
  char		*end;

  str = my_malloc(sizeof(char) * 5);
  other = my_malloc(sizeof(char) * 5);
  //sbrk(sizeof(str) + 5);
  brk(str);
  //strcpy(other, "salu");
  /*
  end = my_malloc(sizeof(char) * 10);
  //strcpy(end, "replace");
  printf("%s\n", other);
  printf("%s\n", end);
  //strcpy(str, "salaaaaaaa");
  //printf("%s\n", str);
  */
  return (0);
}
