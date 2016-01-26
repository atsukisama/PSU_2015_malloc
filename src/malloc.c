/*
** malloc.c for  in /home/mart_4/rendu/PSU_2015_malloc/src
**
** Made by Thomas Martins
** Login   <mart_4@epitech.net>
**
** Started on  Mon Jan 25 23:52:07 2016 Thomas Martins
** Last update Mon Jan 25 23:52:08 2016 Thomas Martins
*/

#include <sys/types.h>
#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <unistd.h>
#include "struct.h"

void		*my_malloc(size_t size)
{
  void *start;
  void *requested;

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

  str = my_malloc(sizeof(char) * 5);
  other = my_malloc(sizeof(char) * 10);
  strcpy(str, "salaaaaaaa");
  //printf("%s\n", str);
  return (0);
}
