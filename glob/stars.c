/*
** stars.c for glob in /home/dubosc_a/rendu/PSU_2014_42sh/glob
**
** Made by Valentin Duboscq
** Login   <dubosc_a@epitech.net>
**
** Started on  Tue Apr 21 16:00:38 2015 Valentin Duboscq
** Last update Fri May 22 13:44:47 2015 Valentin Duboscq
*/

#include <string.h>
#include "shell.h"

int	is_stars(char *path)
{
  int	i;

  i = 0;
  while (path[i])
    {
      if (path[i] == '*')
	return (1);
      else
	i++;
    }
  return (0);
}

int	if_stars(char **res, char **str, int i, int k)
{
  char	**tmp;
  int	j;

  j = 0;
  tmp = return_globing(str[i]);
  while (tmp[j])
    {
      res[k] = strdup(tmp[j]);
      j++;
      k++;
    }
  return (k);
}
