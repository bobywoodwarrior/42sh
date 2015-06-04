/*
** pipe.c for 42sh in /home/bauer_a/rendu/PSU_2014_42sh
** 
** Made by Hugo Bauer
** Login   <bauer_a@epitech.net>
** 
** Started on  Mon Apr 20 18:46:01 2015 Hugo Bauer
** Last update Sat May 23 14:03:07 2015 Hugo Bauer
*/

#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>
#include "shell.h"
#include "lib.h"

int		check_cmd(t_data *data, t_cmds *cmds)
{
  if (cmds != NULL && cmds->cmd != NULL &&
      cmds->cmd->tab != NULL && cmds->cmd->tab[0] != NULL)
    {
      if (access(get_bin_path(data, cmds->cmd->tab[0]), F_OK | X_OK) &&
	  !is_builtin(cmds->cmd->tab[0]))
  	return (error_cmd_not_found(cmds->cmd->tab[0], 1));
      return (0);
    }
  return (1);
}

int		last_pipe(t_data *data, int pipefd[2], t_cmds *cmds)
{
  if (check_cmd(data, cmds))
    return (1);
  close(pipefd[1]);
  if (dup2(pipefd[0], 0) == -1)
    return (0);
  if (exe_cmd(data, cmds->cmd, 1))
    return (1);
  return (0);
}

int		loop_pipe(t_data *data, int pipefd[2], t_cmds *cmds)
{
  pid_t		pid;

  while (cmds->cmd->next != NULL)
    {
      if (check_cmd(data, cmds))
	return (1);
      close(pipefd[1]);
      dup2(pipefd[0], 0);
      if (pipe(pipefd) == -1)
	return (1);
      if ((pid = fork()) == -1)
	return (1);
      if (pid == 0)
	{
	  close(pipefd[0]);
	  if (dup2(pipefd[1], 1) == -1)
	    return (1);
	  if (exe_cmd(data, cmds->cmd, 1))
	    return (1);
	}
      cmds->cmd = cmds->cmd->next;
    }
  return (0);
}

int		first_pipe(t_data *data, int pipefd[2], t_cmds *cmds)
{
  pid_t		pid;

  if (check_cmd(data, cmds))
    return (1);
  if ((pid = fork()) == -1)
    return (1);
  if (pid == 0)
    {
      close(pipefd[0]);
      if (dup2(pipefd[1], 1) == -1)
	return (1);
      if (exe_cmd(data, cmds->cmd, 1))
	return (1);
    }
  cmds->cmd = cmds->cmd->next;
  return (0);
}

int		exe_pipe(t_data *data, t_cmds *cmds)
{
  pid_t		pid_general;
  int		pipefd[2];

  if ((pid_general = fork()) == -1)
    return (1);
  if (pid_general == 0)
    {
      if (pipe(pipefd) == -1)
	return (1);
      if (first_pipe(data, pipefd, cmds))
	return (1);
      if (loop_pipe(data, pipefd, cmds))
	return (1);
      if (last_pipe(data, pipefd, cmds))
	return (1);
    }
  wait(&(data->return_exe));
  segfault(data->return_exe);
  return (0);
}
