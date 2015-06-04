/*
** probably_useless.c for useless in /home/rouss_p/rendu/PSU_2014_42sh/builtin
** 
** Made by pierre rousselle
** Login   <rouss_p@epitech.net>
** 
** Started on  Mon May  4 16:19:00 2015 pierre rousselle
** Last update Fri May 22 18:06:54 2015 Hugo Bauer
*/

#include <string.h>
#include "ps1.h"
#include "shell.h"
#include "builtin.h"
#include "lib.h"

static t_format	g_tab_ptr[] =
  {
    {NAME_CHAR, &case_name},
    {HOST_CHAR, &case_host},
    {PWD_CHAR, &case_pwd},
    {LAST_DIR_CHAR, &case_last_dir},
    {TERM_CHAR, &case_term},
    {BEEP_CHAR, &case_beep},
  };

void		case_beep(char **env)
{
  (void)env;
  my_putchar('\a', 1);
}

int		launch_format(int *i, char *str, char **env)
{
  int		x;

  if ((str[*i] != '\0' && str[*i] == FORMAT_CHAR) &&
      ((str[*i + 1] != '\0' && str[*i + 1] == NAME_CHAR)
       || (str[*i + 1] != '\0' && str[*i + 1] == HOST_CHAR)
       || (str[*i + 1] != '\0' && str[*i + 1] == PWD_CHAR)
       || (str[*i + 1] != '\0' && str[*i + 1] == LAST_DIR_CHAR)
       || (str[*i + 1] != '\0' && str[*i + 1] == TERM_CHAR)
       || (str[*i + 1] != '\0' && str[*i + 1] == BEEP_CHAR)))
    {
      x = 0;
      (*i)++;
      while (str[*i] != g_tab_ptr[x].format)
	++x;
      g_tab_ptr[x].ptr_tab(env);
    }
  else
    my_putchar(str[*i], 1);
  return (0);
}

int		get_ps1(char *str, char **env)
{
  int		i;

  i = 0;
  while (str[i])
    {
      launch_format(&i, str, env);
      i++;
    }
  return (0);
}

char 		*fix_ps1(char *ps1)
{
  int		i;
  int		j;

  i = 0;
  while (ps1[i] != '\0')
    {
      if (ps1[i] == '\\' && ps1[i + 1] == 'e')
	{
	  ps1[i] = 27;
	  j = i + 1;
	  while (ps1[j] != '\0')
	    {
	      ps1[j] = ps1[j + 1];
	      j++;
	    }
	}
      i++;
    }
  return (ps1);
}

int		pars_ps1(char **env)
{
  char		*envps1;

  if (env == NULL)
    my_putstr("$> ", 1);
  else if ((envps1 = get_env_value(env, "PS1", NULL)) == NULL)
    get_ps1("\033[31m%n\033[0m \033[36m[%~]\033[0m $> ", env);
  else
    get_ps1(fix_ps1(envps1), env);
  return (0);
}
