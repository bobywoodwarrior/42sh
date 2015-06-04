/*
** glob.c for glob in /home/dubosc_a/rendu/PSU_2014_42sh/glob
** 
** Made by Valentin Duboscq
** Login   <dubosc_a@epitech.net>
** 
** Started on  Tue Apr 21 16:00:38 2015 Valentin Duboscq
** Last update Fri May 22 13:51:08 2015 Valentin Duboscq
*/

#include <stdlib.h>
#include <glob.h>
#include <string.h>
#include "shell.h"

static int	length_double_array(char **tab)
{
  int	i;

  i = 0;
  while (tab[i])
    i++;
  return (i);
}

char	**return_globing(char *stars)
{
  glob_t	globbuf;

  globbuf.gl_offs = 0;
  glob(stars, GLOB_DOOFFS, NULL, &globbuf);
  return (globbuf.gl_pathv);
}

static int	length_malloc_globing(char **str)
{
  int	i;
  int	cpt;
  char	**tmp;

  i = 0;
  cpt = 0;
  while (str[i])
    {
      if (is_stars(str[i]) == 1)
	{
	  tmp = return_globing(str[i]);
	  cpt += length_double_array(tmp);
	}
      else
	cpt++;
      i++;
    }
  return (cpt);
}

char	**parsing_globing(char **str)
{
  int	i;
  int	k;
  char	**res;

  i = 0;
  k = 0;
  if (strcmp(str[0], "unsetenv") == 0)
    return (str);
  if ((res = malloc(sizeof(char *)
		    * (length_malloc_globing(str) + 1))) == NULL)
    return (NULL);
  res[length_malloc_globing(str)] = NULL;
  while (str[i])
    {
      if (is_stars(str[i]) == 1)
	k = if_stars(res, str, i, k);
      else
	{
	  res[k] = str[i];
	  k++;
	}
      i++;
    }
  return (res);
}
