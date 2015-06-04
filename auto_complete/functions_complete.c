/*
** functions_complete.c for 42sh in /home/dubosc_a/rendu/PSU_2014_42sh/auto_complete
** 
** Made by Valentin Duboscq
** Login   <dubosc_a@epitech.net>
** 
** Started on  Thu May 21 16:43:42 2015 Valentin Duboscq
** Last update Fri May 22 16:01:37 2015 Hugo Bauer
*/

#include <stdlib.h>
#include "lib.h"
#include "shell.h"

int	is_slash(char *str)
{
  int	i;

  i = 0;
  while (str[i])
    {
      if (str[i] == '/')
	return (1);
      i++;
    }
  return (0);
}

char	*epur_slash(char *str)
{
  int	i;
  char	*tmp;

  if ((tmp = malloc(sizeof(char) * (my_strlen(str) + 1))) == NULL)
    return (NULL);
  i = 0;
  if (is_slash(str) == 1)
    {
      i = my_strlen(str);
      while (str[i] != '/')
	i--;
      i += 1;
    }
  my_strcpy_from(tmp, str, i + 1);
  return (str);
}

void	my_write_tab(char **tab)
{
  int	i;
  int	j;

  i = 0;
  my_putchar('\n', 1);
  while (tab[i])
    {
      j = 0;
      if (is_slash(tab[i]) == 1)
	{
	  j = my_strlen(tab[i]);
	  while (tab[i][j] != '/')
	    j--;
	  j += 1;
	}
      while (tab[i][j])
	my_putchar(tab[i][j++], 1);
      my_putchar('\t', 1);
      i++;
    }
  my_putchar('\n', 1);
}
