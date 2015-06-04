/*
** get_bin_path.c for 42sh in /home/bauer_a/rendu/PSU_2014_42sh
** 
** Made by Hugo Bauer
** Login   <bauer_a@epitech.net>
** 
** Started on  Wed May 20 17:37:44 2015 Hugo Bauer
** Last update Wed May 20 18:01:32 2015 Hugo Bauer
*/

#include <stdlib.h>
#include <unistd.h>
#include <builtin.h>
#include "shell.h"

char		*get_bin_path(t_data *data, char *bin)
{
  char		**paths;
  char		*path_bin;
  int		i_path;
  int		i;

  i = 0;
  if ((get_env_value(data->env, "PATH", &i_path)) == NULL ||
      bin == NULL || bin[0] == '.' || bin[0] == '/')
    return (bin);
  if ((paths = str_to_word_tab(data->env[i_path] + 5, ":")) == NULL)
    return (bin);
  while (paths[i] != NULL)
    {
      if ((path_bin = make_path(paths[i], bin)) == NULL)
        return (bin);
      if (!access(path_bin, F_OK | X_OK))
	return (path_bin);
      free(path_bin);
      i++;
    }
  return (bin);
}
