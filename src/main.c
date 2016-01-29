/*
** main.c for main in /home/kerebe_p/Documents/PSU_2015_malloc/src
** 
** Made by kerebe_p
** Login   <paul.kerebel@epitech.eu>
** 
** Started on  Wed Jan 27 21:08:54 2016 kerebe_p
** Last update Wed Jan 27 21:08:54 2016 kerebe_p
*/

#include "struct.h"

int	main(void)
{
  char	*str;

  str = my_malloc(60);
  //g_block->is_free = true;
  //str = my_malloc(58);
  printf("%p\n", MAGIC);
  show_alloc_pro();
}
