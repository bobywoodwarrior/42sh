/*
** str_cat.c for lol in /home/geiger_a/HOME/PSU_2014_minishell1
**
** Made by Anthony Geiger
** Login   <geiger_a@epitech.net>
**
** Started on  Tue Jan 13 11:10:43 2015 Anthony Geiger
** Last update Sat May 23 15:59:44 2015 Adrien Blanquer
*/

#include <stdlib.h>
#include "lib.h"

char	*my_strconcat(char *s1, char *s2)
{
  char	*ret;
  int	i;
  int	j;

  i = 0;
  j = 0;
  if ((ret = malloc(sizeof(char)
		    * (my_strlen(s1) + my_strlen(s2)) + 1)) == NULL)
    return (NULL);
  if (s1 != NULL)
    while (s1[i])
      {
	ret[j] = s1[i];
	++j;
	++i;
      }
  i = 0;
  while (s2[i])
    {
      ret[j] = s2[i];
      ++j;
      ++i;
    }
  ret[j] = '\0';
  return (ret);
}
