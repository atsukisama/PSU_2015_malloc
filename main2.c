/*
** main.c for main in /home/kerebe_p/Documents/Epitech/malloc
** 
** Made by kerebe_p
** Login   <paul.kerebel@epitech.eu>
** 
** Started on  Sun Jan 31 14:40:19 2016 kerebe_p
** Last update Sat Feb 13 15:04:58 2016 Thomas Martins
*/

#include "malloc.h"

void		print(const char *str)
{
  int		i = 0;

  while (str[i])
    {
      write(1, &str[i], 1);
      i++;
    }
}

int		strL(const char *str)
{
  int		i = 0;

  while (str[i])
    i++;
  return i;
}

int		getMalloc(int *nb)
{
  int		i = 0;
  int		*tab;
  static int	number;
  int		a = 0;


  *nb = 2147483640;
  while (1)
    {
      tab = malloc(sizeof(int) * (*nb));
      if (tab == NULL)
	{
	  printf("ENDOMG\n");
	  break;
	}
      while (i < *(nb) - 1)
	{
	  tab[i] = number;
	  ++i;
	}
      i = 0;
      while (i < *(nb) - 1)
	{
	  printf("%d\n", tab[i]);
	  ++i;
	}
      ++number;
      free(tab);
      tab = NULL;
      i = 0;
    }
  return 1;
}

int		main( void )
{
  int		a = 0;



  a = 2147483647;

  if ((getMalloc(&a)) == 1)
    {
      printf("program is deaaad!\n");
      return 1;
    }

  return 0;


}
