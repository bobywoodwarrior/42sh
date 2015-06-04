/*
** print_cursor.c for 42sh in /home/blanqu_a/Workspace/rendu/PSU_2014_42sh
** 
** Made by Adrien Blanquer
** Login   <blanqu_a@epitech.net>
** 
** Started on  Wed May 20 17:49:36 2015 Adrien Blanquer
** Last update Sat May 23 16:47:36 2015 Adrien Blanquer
*/

#include "shell.h"
#include "lib.h"

void	print_cursor_left(const int nb)
{
  int	i;
  char	c[4];

  c[0] = 27;
  c[1] = 91;
  c[2] = 68;
  c[3] = '\0';
  i = 0;
  while (i < nb)
    {
      my_putstr(c, 1);
      i++;
    }
}

void	print_cursor_right(const int nb)
{
  int	i;
  char	c[4];

  c[0] = 27;
  c[1] = 91;
  c[2] = 67;
  c[3] = '\0';
  i = 0;
  while (i < nb)
    {
      my_putstr(c, 1);
      i++;
    }
}
