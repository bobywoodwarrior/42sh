/*
** builtin.c for bultin in /home/rouss_p/rendu/42
** 
** Made by pierre rousselle
** Login   <rouss_p@epitech.net>
** 
** Started on  Mon Apr 20 13:13:23 2015 pierre rousselle
** Last update Sun May 24 17:59:43 2015 pierre rousselle
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "builtin.h"
#include "lib.h"

int	my_unsetenv(char **expr, t_data *data)
{
  int	keyoffset;
  int	i;

  i = 1;
  if (data->env == NULL || (expr[1] && expr[1][0] == '*'))
    {
      data->env = NULL;
      return (SUCCESS);
    }
  keyoffset = 0;
  while (expr && expr[0] && expr[i] && data->env)
    {
      if (get_env_value(data->env, expr[i], &keyoffset) == NULL)
	{
	  fprintf(stderr, "Key %s is unknown.\n", expr[i]);
	  return (FAILURE);
	}
      data->env[keyoffset][0] = '\0';
      data->env = my_epurtab(data->env);
      if (keyoffset == 0)
	data->env = NULL;
      ++i;
    }
  return (SUCCESS);
}

int     my_setenv(char **expr, t_data *data)
{
  int	i;
  char	*str;

  if (!expr || !expr[0] || !expr[1])
    return (my_cd_error("usage: setenv key [value]\n"));
  i = 0;
  while (expr[1][i])
    {
      if ((expr[1][i] < 'a' || expr[1][i] > 'z')
	  && (expr[1][i] < 'A' || expr[1][i] > 'Z')
	  && (expr[1][i] < '0' || expr[1][i] > '9') && expr[1][i] != '_')
	{
	  fprintf(stderr, "Invalid key, must contain only alphanueric char\n");
	  return (FAILURE);
	}
      ++i;
    }
  str =  my_cstrconcat(expr[1], (expr[2] ? my_cstrconcat("=", expr[2]) : "="));
  if (get_env_value(data->env, expr[1], &i) != NULL)
    (data->env)[i] = str;
  else if ((data->env = my_cattab(data->env, str)) == NULL)
    return (FAILURE);
  return (SUCCESS);
}

int	my_env(char **expr, t_data *data)
{
  int	i;
  char	**env;

  env = data->env;
  if (!expr || !expr[0] || (expr[1] && !my_strcmp(expr[1], "help")))
    {
      fprintf(stderr, "usage: env\n");
      return (FAILURE);
    }
  i = 0;
  if (env)
    while (env[i])
      {
	printf("%s\n", env[i]);
	++i;
      }
  return (SUCCESS);
}

int	my_exit(char **expr, t_data *data)
{
  if (expr[1])
    data->return_exit = my_getnbr(expr[1]);
  else
    data->return_exit = 0;
  return (EXIT);
}

int	my_echo(char **expr, t_data *data)
{
  int	i;
  char	interpret;
  char	noret;
  char	ret;

  i = 1;
  ret = -2;
  interpret = 0;
  noret = 0;
  while (expr[i] && data)
    {
      if (my_strcmp(expr[i], "-e") == 0)
	interpret = 1;
      else if (my_strcmp(expr[i], "-n") == 0)
	noret = 1;
      else if (my_strcmp(expr[i], "-E") == 0)
	interpret = 0;
      else
	if ((ret = my_print(expr[i], interpret,
			    (expr[i + 1] ? 1 : noret), expr[i + 1])) == -1)
	  break ;
      ++i;
    }
  write(1, "\n", (ret == -2 ? 1 : 0));
  return (SUCCESS);
}
