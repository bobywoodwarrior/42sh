/*
** redirection.c for 42sh in /home/bauer_a/rendu/PSU_2014_42sh/parsing
** 
** Made by Hugo Bauer
** Login   <bauer_a@epitech.net>
** 
** Started on  Sat Mar 28 18:48:03 2015 Hugo Bauer
** Last update Fri May 22 16:31:49 2015 Hugo Bauer
*/

#include <string.h>
#include <stdlib.h>
#include "shell.h"

void		set_last_in_list(t_list *redi_r_l, t_list *new)
{
  t_list	*tmp;

  tmp = redi_r_l;
  while (tmp->next != NULL)
    tmp = tmp->next;
  tmp->next = new;
}

int		set_redi(t_list *redi, t_cmd *cmd, char c, char c2)
{
  if (c == '>')
    {
      if (cmd->redi_r == NULL)
	cmd->redi_r = redi;
      else
	set_last_in_list(cmd->redi_r, redi);
      cmd->redi_r->double_redi = (c == c2);
    }
  else if (c == '<')
    {
      if (cmd->redi_l == NULL)
	cmd->redi_l = redi;
      else
	set_last_in_list(cmd->redi_l, redi);
      cmd->redi_l->double_redi = (c == c2);
    }
  return (0);
}

int		add_redi(char *str_cmd, t_cmd *cmd, int *i)
{
  t_list	*redi;
  int		j;
  int		verif;

  if ((redi = malloc(sizeof(t_list))) == NULL)
    return (1);
  set_redi(redi, cmd, str_cmd[*i], str_cmd[*i + 1]);
  redi->next = NULL;
  verif = 0;
  while (is_redi(str_cmd[*i]))
    {
      verif++;
      *i += 1;
    }
  if (verif > 2)
    return (error_syntax_error(1));
  while (str_cmd[*i] == ' ' && str_cmd[*i] != '\0')
    *i += 1;
  j = index_end_word(str_cmd, i);
  if ((redi->file = strndup(str_cmd + *i, j - *i)) == NULL)
    return (1);
  *i = j;
  return (0);
}
