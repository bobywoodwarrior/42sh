/*
** parsing_general.c for 42sh in /home/bauer_a/rendu/PSU_2014_42sh/parsing
** 
** Made by Hugo Bauer
** Login   <bauer_a@epitech.net>
** 
** Started on  Tue Mar 31 10:47:56 2015 Hugo Bauer
** Last update Sun May 24 16:56:03 2015 Hugo Bauer
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "shell.h"

void		next_cmd(char *str, int *i, int *i_save)
{
  while (str[*i] != '|' && str[*i] != '\0')
    *i += 1;
  while (str[*i + 1] == ' ' && str[*i] != '\0')
    *i += 1;
  *i_save = *i + 1;
}

char		*calc_new_str(char *str, int i, int i_save)
{
  char		*new_str;

  while (i > 0 && str[i - 1] == ' ')
    i--;
  if ((new_str = strndup(str + i_save, (i - i_save))) == NULL)
    return (NULL);
  return (new_str);
}

t_cmd		*add_cmd(char *new_str, t_cmd **cmd, t_cmd **tmp)
{
  if (new_str == NULL)
    return (NULL);
  if ((new_str = concat_alias(new_str, g_data->alias)) == NULL)
    return (NULL);
  if (*cmd == NULL)
    {
      if ((*cmd = parsing_cmd(new_str)) == NULL)
	return (NULL);
      return (*cmd);
    }
  if (((*tmp)->next = parsing_cmd(new_str)) == NULL)
    return (NULL);
  return ((*tmp)->next);
}

t_cmd		*parsing_pipe(char *str)
{
  t_cmd		*cmd;
  t_cmd		*tmp;
  int		i;
  int		i_save;

  if (str == NULL)
    return (NULL);
  i = 0;
  i_save = 0;
  cmd = NULL;
  while (str[i] != '\0')
    {
      if (str[i] == '|')
	{
	  if ((tmp = add_cmd(calc_new_str(str, i, i_save), &cmd, &tmp)) == NULL)
	    return (NULL);
	  next_cmd(str, &i, &i_save);
	}
      i++;
    }
  if ((tmp = add_cmd(calc_new_str(str, i, i_save), &cmd, &tmp)) == NULL)
    return (NULL);
  return (cmd);
}
