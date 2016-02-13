/*
** main.c for main in /home/kerebe_p/Documents/Epitech/malloc
** 
** Made by kerebe_p
** Login   <paul.kerebel@epitech.eu>
** 
** Started on  Sun Jan 31 14:40:19 2016 kerebe_p
** Last update Sun Feb  7 21:33:33 2016 Thomas Martins
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

int		main(void)
{
  int		i = 0;
  char		*str;

  str = NULL;
  while (10)
    {
      str = malloc(sizeof(char) * 2000000000);
      if (str == NULL)
	{
	  printf("BREAK MALLOC!\n");
	  break;
	}
      while (i < 19999)
	{
	  str[i] = '0';
	  ++i;
	}
      str[i] = '\0';
      printf("%s", str);
      free(str);
      str = NULL;
      i = 0;
    }
  return 0;
}
