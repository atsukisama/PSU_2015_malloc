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
  int	i = 0;

  str = my_malloc(98347);
  str = my_malloc(5);
  /*
  while (i < 100000 && str != NULL)
    {
      //printf("loop : %d\r", i);
      str = my_malloc(1);
      i++;
      }*/
  //printf("%p\n", MAGIC);
  if ((intptr_t)str % sizeof(void*) == 0)
    {
      printf("%d\n", sizeof(void*));
      printf("SUCCESS!\n");
    }
  show_alloc_pro();
}
