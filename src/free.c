/*
** free.c for  in /home/mart_4/rendu/PSU_2015_malloc/src
**
** Made by Thomas martin
** Login   <mart_4@epitech.net>
**
** Started on  Wed Jan 27 09:37:38 2016 Thomas martin
** Last update Wed Jan 27 10:41:10 2016 Thomas martin
*/

#include "struct.h"

void		merge_block(void)
{
  t_block	*tmp;
  char		*reset;

  tmp = g_block;
  while (tmp != NULL && tmp->next != NULL)
    {
      if (tmp->is_free == true && tmp->next->is_free == true)
	{
	  if (tmp->next->next != NULL)
	    tmp->next = tmp->next->next;
	  else
	    tmp->next = NULL;
	}
      tmp = tmp->next;
    }
}

void		free(void *ptr)
{
  t_block	*tmp;
  t_block	*cast;

  tmp = g_block;
  if (ptr == NULL)
    return ;
  while (tmp != NULL)
    {
      cast = (t_block*)ptr - 1;
      printf("%p && %p\n", cast, ptr);
      if (cast->adr_start == ptr)
	{
	  printf("oui\n");
	}
      tmp = tmp->next;
    }
}
