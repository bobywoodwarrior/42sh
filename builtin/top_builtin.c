/*
** top_builtin.c for 42sh in /home/rouss_p/rendu/PSU_2014_42sh/builtin
** 
** Made by pierre rousselle
** Login   <rouss_p@epitech.net>
** 
** Started on  Tue May  5 15:39:26 2015 pierre rousselle
** Last update Sat May 23 15:34:37 2015 pierre rousselle
*/

#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "builtin.h"

int			my_redir_builtin(t_data *data, t_cmd *cmd)
{
  int			ret;
  int			savein;
  int			saveout;
  int			fd;

  if ((savein = dup(0)) == -1 || (saveout = dup(1)) == -1)
    return (FAILURE);
  if ((fd = redirection_right(cmd->redi_r)) > 0)
    dup2(fd, 1);
  if ((fd = redirection_left(cmd->redi_l)) > 0)
    dup2(fd, 0);
  ret = builtin(data, cmd->tab);
  dup2(saveout, 1);
  dup2(savein, 0);
  return (ret);
}

int			builtin(t_data *data, char **cmd)
{
  int			i;
  int			ret;
  static t_bref		builtin_ref[] = {
    {"cd", &my_cd}, {"exit", &my_exit},
    {"env", &my_env}, {"setenv", &my_setenv},
    {"unsetenv", &my_unsetenv}, {"echo", &my_echo}, {NULL, NULL}};

  ret = 0;
  i = 0;
  my_replace_key(cmd, data);
  while (builtin_ref[i].ref && cmd && cmd[0])
    {
      if (strcmp(cmd[0], builtin_ref[i].ref) == 0)
	{
	  ret = builtin_ref[i].builtin(cmd, data);
	  break ;
	}
      ++i;
    }
  data->return_exe = 0;
  if (ret == FAILURE)
    data->return_exe = 256;
  if (!builtin_ref[i].ref)
    return (NO_MATCH);
  return (ret);
}
