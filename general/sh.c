/*
** sh.c for 42sh in /home/bauer_a/rendu/PSU_2014_42sh
** 
** Made by Hugo Bauer
** Login   <bauer_a@epitech.net>
** 
** Started on  Tue Mar 31 17:19:45 2015 Hugo Bauer
** Last update Sat May 23 18:04:56 2015 Hugo Bauer
*/

#include <stdlib.h>
#include "lib.h"
#include "ps1.h"
#include "shell.h"

int		count_pipe(t_cmd *cmd)
{
  int		i;

  i = 0;
  while (cmd != NULL)
    {
      i++;
      cmd = cmd->next;
    }
  return (i);
}

int		check_exe(int return_exe, char sep)
{
  if (return_exe == 0 && sep == '|')
    return (0);
  else if (return_exe != 0 && sep == '&')
    return (0);
  return (1);
}

int		call_exe(t_data *data)
{
  if (count_pipe(data->cmds->cmd) > 1)
    {
      if ((exe_pipe(data, data->cmds)))
	return (-1);
    }
  else
    if ((exe_cmd(data, data->cmds->cmd, 0)) == -1)
      return (-1);
  return (0);
}

int		sh(t_data *data)
{
  char		*str;
  char		prev_sep;

  if ((data->list = malloc(sizeof(t_history))) == NULL)
    return (1);
  data->list = NULL;
  while (1)
    {
      pars_ps1(data->env);
      if (data->dynam_prompt == 0 && (str = read_cmd()) == NULL)
	return (1);
      if (data->dynam_prompt == 1 && (str = get_cmd(&data->list)) == NULL)
	if ((str = read_cmd()) == NULL)
	  return (1);
      prev_sep = '\0';
      if ((data->cmds = parsing_general(epure_str(str))) != NULL)
	while (data->cmds != NULL)
	  {
	    if (check_exe(data->return_exe, prev_sep) && call_exe(data) == -1)
	      return (-1);
	    prev_sep = data->cmds->sep;
	    data->cmds = data->cmds->next;
	  }
    }
  return (0);
}
