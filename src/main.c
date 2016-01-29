/*
** main.c for main in /home/kerebe_p/Documents/PSU_2015_malloc/src
** 
** Made by kerebe_p
** Login   <paul.kerebel@epitech.eu>
** 
** Started on  Wed Jan 27 21:08:54 2016 kerebe_p
** Last update Wed Jan 27 21:08:54 2016 kerebe_p
*/

#include <stdlib.h>
#include "struct.h"

int	main(void)
{
  char	*str;
  char	*end;

  str = my_malloc(8);
  end = my_malloc(16);
  my_free(end);
  show_alloc_pro();
  my_free(str);
  show_alloc_pro();
}
