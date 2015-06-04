/*
** make_env.c for 42sh in /home/bauer_a/rendu/PSU_2014_42sh
** 
** Made by Hugo Bauer
** Login   <bauer_a@epitech.net>
** 
** Started on  Mon Apr 20 14:18:23 2015 Hugo Bauer
** Last update Sat May 23 16:42:04 2015 Adrien Blanquer
*/

#include <stdlib.h>
#include "shell.h"
#include "lib.h"

int		return_index(char **env, char *str)
{
  int		i;

  i = 0;
  if (env == NULL)
    return (-1);
  while (env[i] != 0)
    {
      if (my_strncmp(env[i], str, my_strlen(str)) == 0)
	return (i);
      i++;
    }
  return (-1);
}

char		**make_env(char **argp)
{
  char		**env;
  int		i;

  i = 0;
  if (argp == NULL || argp[0] == NULL)
    return (NULL);
  while (argp[i] != 0)
    i++;
  if ((env = malloc(sizeof(char *) * (i + 1))) == NULL)
    return (NULL);
  i = 0;
  while (argp[i] != 0)
    {
      env[i] = my_strdup(argp[i]);
      i++;
    }
  env[i] = NULL;
  return (env);
}
