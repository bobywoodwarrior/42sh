/*
** move.c for prompt in /home/blanqu_a/Workspace/rendu/PSU_2014_42sh/prompt_read_termcaps
** 
** Made by Adrien Blanquer
** Login   <blanqu_a@epitech.net>
** 
** Started on  Sat May 16 16:04:26 2015 Adrien Blanquer
** Last update Sat May 23 17:47:28 2015 Adrien Blanquer
*/

#include "shell.h"
#include "lib.h"

char	*up(char *cmd, t_history **tmp, int *cpt, char **c)
{
  clean(*c, 7);
  clean_line();
  my_putchar('\r', 1);
  pars_ps1(g_data->env);
  my_putstr((*tmp)->data, 1);
  my_strcpy(cmd, (*tmp)->data);
  if ((*tmp)->next)
    (*tmp) = (*tmp)->next;
  *cpt = my_strlen(cmd);
  return (cmd);
}

char	*down(char *cmd, t_history **tmp, int *cpt, char **c)
{
  clean(*c, 7);
  if ((*tmp)->prev)
    {
      clean_line();
      my_putchar('\r', 1);
      pars_ps1(g_data->env);
      *tmp = (*tmp)->prev;
      my_putstr((*tmp)->data, 1);
      my_strcpy(cmd, (*tmp)->data);
      *cpt = my_strlen(cmd);
    }
  else
    {
      clean(cmd, 4096);
      *cpt = 0;
      clean_line();
      my_putchar('\r', 1);
      pars_ps1(g_data->env);
    }
  return (cmd);
}
