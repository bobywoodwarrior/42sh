/*
** glob.c for autocomplete in /home/dubosc_a/rendu/PSU_2014_42sh/auto_complete
** 
** Made by Valentin Duboscq
** Login   <dubosc_a@epitech.net>
** 
** Started on  Wed May 13 14:22:06 2015 Valentin Duboscq
** Last update Sat May 23 16:15:12 2015 Adrien Blanquer
*/

#include <stdlib.h>
#include <glob.h>
#include "lib.h"
#include "shell.h"

static int	is_stars_at_end(char *str)
{
  int		len;

  len = my_strlen(str);
    return (0);
  if (str[len - 1] == '*')
    return (1);
  return (0);
}

static char	**ret_globing(char *stars)
{
  glob_t	globbuf;

  globbuf.gl_offs = 0;
  glob(stars, GLOB_DOOFFS, NULL, &globbuf);
  return (globbuf.gl_pathv);
}

static char	**add_stars(char *str)
{
  int		len;
  char		*star;

  len = my_strlen(str);
  if (is_stars_at_end(str) == 1)
    return (ret_globing(str));
  else
    {
      if ((star = malloc(sizeof(char) * (len + 2))) == NULL)
	return (NULL);
      star[0] = '\0';
      my_strncat(star, str, len);
      star[len] = '*';
      star[len + 1] = '\0';
      return (ret_globing(star));
    }
  return (NULL);
}

char		*auto_complete(char *str)
{
  char		**tab;

  tab = add_stars(str);
  if (tab[0] == NULL)
    return (NULL);
  if (tab[1])
    {
      my_write_tab(tab);
      return (NULL);
    }
  else
    return (epur_slash(tab[0]));
  return (NULL);
}
