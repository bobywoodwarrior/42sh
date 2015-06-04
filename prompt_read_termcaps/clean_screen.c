/*
** clear_screen.c for prompt in /home/blanqu_a/Workspace/rendu/PSU_2014_42sh/prompt_read_termcaps
** 
** Made by Adrien Blanquer
** Login   <blanqu_a@epitech.net>
** 
** Started on  Mon May 18 17:18:49 2015 Adrien Blanquer
** Last update Sat May 23 16:55:36 2015 Adrien Blanquer
*/

#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include "lib.h"
#include "shell.h"

int	clean_screen(char *cmd)
{
  pid_t	pid;
  char	**argv;

  if ((argv = malloc(sizeof(char *) * 1)) == NULL)
    return (-1);
  argv[0] = NULL;
  if ((pid = fork()) == -1)
    return (-1);
  if (pid == 0)
    {
      if (execve("/usr/bin/clear", argv, g_data->env) == -1)
	my_putchar('\n', 1);
    }
  else
    wait(NULL);
  my_putchar('\r', 1);
  pars_ps1(g_data->env);
  my_putstr(cmd, 1);
  return (0);
}
