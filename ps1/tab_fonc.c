/*
** tab_fonc.c for tab in /home/geiger_a/PSU_2014_42sh/PS1
** 
** Made by anthony geiger
** Login   <geiger_a@epitech.net>
** 
** Started on  Thu May 21 17:07:16 2015 anthony geiger
** Last update Sat May 23 14:50:14 2015 anthony geiger
*/

#include <stdlib.h>
#include "builtin.h"
#include "lib.h"
#include "shell.h"

void	case_name(char **env)
{
  my_putstr(get_env_value(env, "USER", NULL), 1);
}

void	case_host(char **env)
{
  my_putstr(get_env_value(env, "HOST", NULL), 1);
}

void	case_pwd(char **env)
{
  char	*pwd;
  int	i;

  if ((pwd = get_env_value(env, "PWD", NULL)) == NULL)
    return ;
  if (my_strncmp("/home/", pwd, 6) == 0 && pwd[6] == '\0')
    {
      my_putstr(pwd, 1);
      return ;
    }
  else if (my_strncmp("/home/", pwd, 6) == 0)
    {
      i = 7;
      while (pwd[i] && pwd[i] != '/')
  	++i;
      pwd = my_strdup(pwd + i);
      pwd = my_strconcat("~", pwd);
    }
  my_putstr(pwd, 1);
}

void	case_last_dir(char **env)
{
  my_putstr(get_env_value(env, "OLD_PWD", NULL), 1);
}

void	case_term(char **env)
{
  my_putstr(get_env_value(env, "TERM", NULL), 1);
}
