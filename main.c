/*
** main.c for main in /home/kerebe_p/Documents/Epitech/malloc
** 
** Made by kerebe_p
** Login   <paul.kerebel@epitech.eu>
** 
** Started on  Sun Jan 31 14:40:19 2016 kerebe_p
** Last update Sun Jan 31 14:40:19 2016 kerebe_p
*/

#include "malloc.h"

int		main(void)
{
  char		*start;
  char		*middle;
  char		*end;

  (void)start;
  (void)middle;
  (void)end;
  start = malloc(8);
  middle = malloc(4025);
  show_alloc_mem();
}
