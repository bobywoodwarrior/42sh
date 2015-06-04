/*
** parsing_tilde.c for 42sh in /home/bauer_a/rendu/PSU_2014_42sh
** 
** Made by Hugo Bauer
** Login   <bauer_a@epitech.net>
** 
** Started on  Sat May 23 14:58:08 2015 Hugo Bauer
** Last update Sat May 23 15:02:43 2015 Hugo Bauer
*/

#include <stdlib.h>
#include "shell.h"
#include "builtin.h"
#include "lib.h"

char		**pars_tilde(t_data *data, char **tab)
{
  int		i;
  char		*new;
  char		*home;

  i = 0;
  if ((home = get_env_value(data->env, "HOME", NULL)) == NULL)
    return (tab);
  while (tab[i] != NULL)
    {
      if (tab[i][0] == '~')
	{
	  if ((new = malloc(sizeof(char) *
			    (my_strlen(home) + my_strlen(tab[i])))) == NULL)
	    return (tab);
	  new[0] = '\0';
	  my_strcat(new, home);
	  tab[i] = my_strcat(new, tab[i] + 1);
	}
      i++;
    }
  return (tab);
}
