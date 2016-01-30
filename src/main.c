/*
** main.c for main in /home/kerebe_p/Documents/Epitech/PSU_2015_malloc/src
** 
** Made by kerebe_p
** Login   <paul.kerebel@epitech.eu>
** 
** Started on  Sat Jan 30 05:57:06 2016 kerebe_p
** Last update Sat Jan 30 05:57:06 2016 kerebe_p
*/

#include "struct.h"

int	main()
{
  char	*str;

  str = malloc(getpagesize());
  show_alloc_pro();
}
