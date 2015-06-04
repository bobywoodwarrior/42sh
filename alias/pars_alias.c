/*
** pars_alias.c<2> for pas in /home/geiger_a/rendu/PSU_2014_42sh/alias
** 
** Made by anthony geiger
** Login   <geiger_a@epitech.net>
** 
** Started on  Sun May 17 21:23:37 2015 anthony geiger
** Last update Sat May 23 16:01:44 2015 Adrien Blanquer
*/

#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include "builtin.h"
#include "shell.h"
#include "lib.h"

char	**get_bash()
{
  int	fd;
  char	*s;
  int	line;
  char	**bash;
  int	x;

  x = 0;
  if ((line = get_line_file()) == -1)
    return (NULL);
  if ((fd = open(RCNAME, O_RDONLY)) == -1)
    return (NULL);
  if ((bash = malloc(sizeof(char **) * (line + 1))) == NULL)
    return (NULL);
  while ((s = gnl(fd)))
    {
      bash[x] = my_strdup(s);
      free(s);
      ++x;
    }
  close(fd);
  bash[x] = NULL;
  return (bash);
}

char	*get_old(char *str, int x, int i)
{
  char	*old;
  int	start_old;

  ++i;
  if (str[i] != '\'')
    {
      printf("\033[31m");
      printf("Rc error \033[0m at line : %i, collumn %i : %s\n", x, i, str);
      return (NULL);
    }
  ++i;
  start_old = i;
  while (str[i] != '\'')
    {
      if (str[i] == '\0')
	{
	  printf("\033[31m");
	  printf("Rc error \033[0m at line : %i, collumn %i : %s\n", x, i, str);
	  return (NULL);
	}
      ++i;
    }
  if ((old = my_strndup(str + start_old, i - start_old)) == NULL)
    return (NULL);
  return (old);
}

t_data	*get_old_new(char *str, t_data *data, int x)
{
  int	i;
  char	*old;
  char	*new;

  i = 6;
  if (str[i] == ' ')
    {
      printf("\033[31m");
      printf("Rc error \033[0m at line : %i, collumn 6 : %s\n", x, str);
      return (NULL);
    }
  while (str[i] && (str[i] != ' '))
    ++i;
  if ((new = my_strndup(str + 6, i - 6)) == NULL)
    return (NULL);
  if ((old = get_old(str, x, i)) == NULL)
    return (NULL);
  if ((data = check_recur(data, old, new)) == NULL)
    return (NULL);
  return (data);
}

t_data	*get_all_alias(t_data *data, char **bash, int x)
{
  while (bash[x])
    {
      if (my_strncmp("alias ", bash[x], 6) == 0)
      	{
      	  if ((data = get_old_new(bash[x], data, x)) == NULL)
      	    return (NULL);
      	}
      if (my_strncmp("setenv ", bash[x], 7) == 0)
      	{
	  if (bashset(bash[x], data) == -1)
      	    return (NULL);
      	}
      ++x;
    }
  return (data);
}

int	pars_alias(t_data *data)
{
  char	**bash;

  if ((bash = get_bash()) == NULL)
    return (-1);
  if ((get_all_alias(data, bash, 0) == NULL))
    return (-1);
  return (0);
}
