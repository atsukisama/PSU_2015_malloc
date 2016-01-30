/*
** struct.h for  in /home/mart_4/rendu/PSU_2015_malloc/src
**
** Made by Thomas Martins
** Login   <mart_4@epitech.net>
**
** Started on  Mon Jan 25 23:48:39 2016 Thomas Martins
** Last update Sat Jan 30 21:22:55 2016 Thomas Martins
*/

#ifndef STRUCT_H_
# define STRUCT_H_
# define MAGIC 1120599618
# define SUPPLEMENT 4096

# include <sys/types.h>
# include <stdio.h>
# include <string.h>
# include <assert.h>
# include <unistd.h>
# include <stdbool.h>

typedef struct	s_block	t_block;

t_block	*g_block;

struct			s_block
{
  size_t		block_size;
  int			is_free;
  int			magic;
  struct s_block	*prev;
  struct s_block	*next;
};

typedef struct		s_beta
{
  size_t		block_size;
  short			is_free;
  struct s_beta		*next;
}			t_beta;

void		*malloc(size_t size);
t_block         *check_block(size_t size);
t_block         *ask_mem(size_t size);
size_t		aligned_size(size_t size, int align);
void            show_alloc_mem();
void            show_alloc_pro();
void		free(void *ptr);

#endif		/* struct */
