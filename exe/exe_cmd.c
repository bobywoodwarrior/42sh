/*
** exe_cmd.c for 42sh in /home/bauer_a/rendu/PSU_2014_42sh/exe
** 
** Made by Hugo Bauer
** Login   <bauer_a@epitech.net>
** 
** Started on  Mon Apr 20 13:44:36 2015 Hugo Bauer
** Last update Sat May 23 17:57:59 2015 Hugo Bauer
*/

#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include "shell.h"
#include "builtin.h"
#include "lib.h"

int		exe_function(t_data *data, t_cmd *cmd, char *cmd1, int pipe)
{
  pid_t		pid;
  int		fd;

  pid = 0;
  if (!is_exe(cmd1))
    return (1);
  if (!pipe)
    if ((pid = fork()) < 0)
      return (1);
  if (pid == 0)
    {
      setsid();
      if ((fd = redirection_right(cmd->redi_r)) > 0)
	dup2(fd, 1);
      if ((fd = redirection_left(cmd->redi_l)) > 0)
	dup2(fd, 0);
      else if (fd == -1)
	return (-1);
      if ((execve(cmd1, cmd->tab, data->env)) < 0)
	return (-1);
    }
  waitpid(pid, &(data->return_exe), WUNTRACED | WCONTINUED);
  segfault(data->return_exe);
  return (0);
}

char		*make_path(char *path, char *str)
{
  char		*path_cmd;

  if ((path_cmd = malloc_str(my_strlen(path) + my_strlen(str) + 2)) == NULL)
    return (NULL);
  my_strcat(path_cmd, path);
  my_strcat(path_cmd, "/");
  my_strcat(path_cmd, str);
  return (path_cmd);
}

int		loop_exe_path(t_data *data, t_cmd *cmd, char *paths, int pipe)
{
  char		*path;
  int		return_exe;

  if ((path = make_path(paths, cmd->tab[0])) == NULL)
    return (0);
  if ((return_exe = exe_function(data, cmd, path, pipe)) == 0)
    return (1);
  else if (return_exe == -1)
    return (-1);
  free(path);
  return (0);
}

int		exe_path(t_data *data, t_cmd *cmd, int pipe)
{
  char		**paths;
  int		i;
  int		i_path;
  int		return_exe;

  if (cmd->tab[0][0] == '.' || cmd->tab[0][0] == '/')
    return (1);
  if ((get_env_value(data->env, "PATH", &i_path)) == NULL)
    {
      if ((paths = default_path()) == NULL)
	return (1);
    }
  else
    if ((paths = str_to_word_tab(data->env[i_path] + 5, ":")) == NULL)
      return (1);
  i = 0;
  while (paths[i] != NULL)
    {
      if ((return_exe = loop_exe_path(data, cmd, paths[i], pipe)) == -1)
	return (return_exe);
      else if (return_exe == 1)
	return (0);
      i++;
    }
  return (1);
}

int		exe_cmd(t_data *data, t_cmd *cmd, int pipe)
{
  int		return_exe;

  return_exe = 0;
  if (cmd->tab == NULL || cmd->tab[0] == NULL || my_strlen(cmd->tab[0]) == 0)
    return (1);
  if ((cmd->tab = parsing_globing(cmd->tab)) == NULL)
    return (-1);
  cmd->tab = pars_tilde(data, cmd->tab);
  if ((return_exe = my_redir_builtin(data, cmd)) == EXIT ||
      ((return_exe == SUCCESS || return_exe == FAILURE) && pipe))
    return (-1);
  else if (return_exe == SUCCESS || return_exe == FAILURE)
    return (0);
  if ((return_exe = exe_path(data, cmd, pipe)) == -1)
    return (-1);
  else if (return_exe == 0)
    return (0);
  else if ((return_exe = exe_function(data, cmd, cmd->tab[0], pipe)) == -1)
    return (-1);
  else if (return_exe == 0)
    return (0);
  return (error_cmd_not_found(cmd->tab[0], 1));
}
