/*
** parsing_general.c for parsing_general.c in /home/bauer_a/rendu/PSU_2014_42sh
** 
** Made by Hugo Bauer
** Login   <bauer_a@epitech.net>
** 
** Started on  Tue Mar 31 17:21:19 2015 Hugo Bauer
** Last update Thu May 21 16:56:56 2015 Hugo Bauer
*/

#include <string.h>
#include <stdlib.h>
#include "shell.h"

int		is_sep_cmd(char *str, int i)
{
  if (str[i] == ';')
    return (1);
  else if (!strncmp(str + i, "&&", 2) || !strncmp(str + i, "||", 2))
    {
      if (strncmp(str + i, "&&&", 3) && strncmp(str + i, "|||", 3))
	return (1);
      return (error_syntax_error(-1));
    }
  return (0);
}

t_cmds		*new_cmds(char *new_str, char sep)
{
  t_cmds	*new;

  if (new_str == NULL)
    return (NULL);
  if ((new = malloc(sizeof(t_cmds))) == NULL)
    return (NULL);
  if ((new->cmd = parsing_pipe(new_str)) == NULL)
    return (NULL);
  new->sep = sep;
  new->next = NULL;
  return (new);
}

t_cmds		*add_cmds(char *new_str, t_cmds **cmds, t_cmds **tmp, char sep)
{
  if (new_str == NULL)
    return (NULL);
  if (*cmds == NULL)
    {
      if ((*cmds = new_cmds(new_str, sep)) == NULL)
	return (NULL);
      (*cmds)->next = NULL;
      *tmp = *cmds;
      return (*tmp);
    }
  if (((*tmp)->next = new_cmds(new_str, sep)) == NULL)
    return (NULL);
  *tmp = (*tmp)->next;
  return (*cmds);
}

void		go_next_cmds(char *str, int *i, int *i_save)
{
  *i_save = *i + 1;
  if (str[*i_save] == '&' || str[*i_save] == '|')
    *i_save += 1;
}

t_cmds		*parsing_general(char *str)
{
  t_cmds	*cmds;
  t_cmds	*tmp;
  int		i;
  int		i_save;
  int		ret;

  i = 0;
  i_save = 0;
  cmds = NULL;
  tmp = NULL;
  while (str[i] != '\0')
    {
      if ((ret = is_sep_cmd(str, i)) == -1)
	return (NULL);
      else if (ret > 0)
	{
	  if (add_cmds(calc_new_str(str, i, i_save),
		       &cmds, &tmp, str[i]) == NULL)
	    return (NULL);
	  go_next_cmds(str, &i, &i_save);
	}
      i++;
    }
  return (add_cmds(calc_new_str(str, i, i_save), &cmds, &tmp, str[i]));
}
