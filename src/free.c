
/*
** free.c for  in /home/mart_4/rendu/PSU_2015_malloc/src
**
** Made by Thomas martin
** Login   <mart_4@epitech.net>
**
** Started on  Wed Jan 27 09:37:38 2016 Thomas martin
** Last update Wed Jan 27 17:51:52 2016 Thomas Martins
*/

#include "struct.h"

void		check(void)
{
  t_block	*tmp;

  tmp = g_block;

  while (tmp)
    {
      printf("%d\n", tmp->block_size);
      tmp = tmp->next;
    }
}

t_block		*merge_block(void *ptr)
{
  char		*reset;
  t_block	*tmp;

  tmp = (t_block*)ptr - 1;
  if (tmp->next != NULL && tmp->next->is_free == true)
    {
      tmp->block_size += sizeof(t_block) + tmp->next->block_size;
      tmp->next = tmp->next->next;
    }
  return (tmp);
}

void		reduce_mem(t_block *delete)
{
  if (delete != NULL && delete->is_free == true && delete->next == NULL)
    {
      brk(delete);
      if (delete == g_block)
	g_block = NULL;
    }
}

void		my_free(void *ptr)
{
  /*
  t_block	*tmp;
  t_block	*temp;
  t_block	*delete;

  delete = NULL;
  temp = NULL;
  tmp = g_block;
  if ((tmp + 1) == ptr)
    tmp->is_free = true;
  while (tmp)
    {
      if (tmp->next != NULL && (tmp->next + 1) == ptr)
	tmp->next->is_free = true;
      while (tmp->is_free == true && tmp->next != NULL && tmp->next->is_free == true)
	tmp = merge_block(tmp + 1);
      if (tmp->next == NULL)
	delete = tmp;
      if (tmp->next != NULL && tmp->next->is_free == true && tmp->next->next == NULL)
	temp = tmp;
      tmp = tmp->next;
    }
  if (temp != NULL)
    temp->next = NULL;
  if (delete != NULL && delete->is_free == true && delete->next == NULL)
    {
      brk(delete);
      if (delete == g_block)
	g_block = NULL;
    }
  */
}
