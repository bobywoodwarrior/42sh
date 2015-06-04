/*
** str_to_word_tab.c for 42sh in /home/bauer_a/rendu/PSU_2014_42sh
** 
** Made by Hugo Bauer
** Login   <bauer_a@epitech.net>
** 
** Started on  Sat Mar 28 14:23:18 2015 Hugo Bauer
** Last update Sat May 23 15:08:33 2015 anthony geiger
*/

#include <stdlib.h>
#include <string.h>
#include "lib.h"

int		is_sep(char *seps, char c)
{
  while (*seps)
    {
      if (c == *seps)
	return (1);
      seps++;
    }
  return (0);
}

int		how_many_words(char *str, char *seps)
{
  int		i;
  int		c;

  i = 0;
  c = 0;
  while (is_sep(seps, str[i]) && str[i] != '\0')
    i++;
  while (str[i] != '\0')
    {
      c++;
      while (!is_sep(seps, str[i]) && str[i] != '\0')
	i++;
      while (is_sep(seps, str[i]) && str[i] != '\0')
	i++;
    }
  return (c);
}

char		**str_to_word_tab(char *str, char *seps)
{
  char		**tab;
  int		i;
  int		i_min;
  int		c;

  if ((tab = malloc(sizeof(char *) * (how_many_words(str, seps) + 1))) == NULL)
    return (NULL);
  tab[how_many_words(str, seps)] = '\0';
  i = 0;
  c = 0;
  while (c < how_many_words(str, seps) && str[i] != '\0')
    {
      while (is_sep(seps, str[i]) && str[i] != '\0')
	i++;
      i_min = i;
      while (!is_sep(seps, str[i]) && str[i] != '\0')
	i++;
      if ((tab[c] = malloc_str(i - i_min + 1)) == NULL)
	return (NULL);
      my_strncat(tab[c], str + i_min, (i - i_min));
      c++;
    }
  return (tab);
}
