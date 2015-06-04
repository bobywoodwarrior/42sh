/*
** parsing_cmd.c for 42sh in /home/bauer_a/rendu/PSU_2014_42sh
** 
** Made by Hugo Bauer
** Login   <bauer_a@epitech.net>
** 
** Started on  Sat Mar 28 14:22:25 2015 Hugo Bauer
** Last update Fri May 22 16:58:19 2015 Hugo Bauer
*/

#include <string.h>
#include <stdlib.h>
#include "shell.h"
#include "lib.h"

int		is_redi(char c)
{
  if (c == '>' || c == '<')
    return (1);
  return (0);
}

int		index_end_word(char *str_cmd, int *i)
{
  int		j;

  j = *i;
  if (str_cmd[j] == '"')
    {
      *i += 1;
      j++;
      while (str_cmd[j] != '"' && !is_redi(str_cmd[j]) && str_cmd[j] != '\0')
	j++;
      if (str_cmd[j] == '\0')
	{
	  *i = j;
	  return (-1);
	}
      return (j);
    }
  while (str_cmd[j] != ' ' && !is_redi(str_cmd[j]) && str_cmd[j] != '\0')
    j++;
  return (j);
}

int		add_word_to_tab(char *str_cmd, t_cmd *cmd, int *i)
{
  char		*new;
  int		j;

  if ((j = index_end_word(str_cmd, i)) == -1)
    return (0);
  if ((new = strndup(str_cmd + *i, j - *i)) == NULL)
    return (1);
  if (cmd->tab == NULL)
    {
      if ((cmd->tab = malloc(sizeof(char *) * 2)) == NULL)
	return (1);
      cmd->tab[0] = new;
      cmd->tab[1] = NULL;
    }
  else
    {
      if ((cmd->tab = realloc(cmd->tab, sizeof(char *)
			      * (len_tab(cmd->tab) + 2))) == NULL)
	return (1);
      cmd->tab[len_tab(cmd->tab) + 1] = NULL;
      cmd->tab[len_tab(cmd->tab)] = new;
    }
  *i = j;
  return (0);
}

t_cmd		*init_parsing()
{
  t_cmd		*cmd;

  if ((cmd = malloc(sizeof(t_cmd))) == NULL)
    return (NULL);
  cmd->redi_r = NULL;
  cmd->redi_l = NULL;
  cmd->next = NULL;
  cmd->tab = NULL;
  return (cmd);
}

t_cmd		*parsing_cmd(char *str_cmd)
{
  t_cmd		*cmd;
  int		i;

  i = 0;
  if ((cmd = init_parsing()) == NULL)
    return (NULL);
  while (str_cmd[i] != '\0')
    {
      while (str_cmd[i] == ' ' && str_cmd[i] != '\0')
	i++;
      if (is_redi(str_cmd[i]))
	{
	  if (add_redi(str_cmd, cmd, &i))
	    return (NULL);
	}
      else
	if (add_word_to_tab(str_cmd, cmd, &i))
	  return (NULL);
    }
  return (cmd);
}
