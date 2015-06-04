/*
** prompt.c for minishell1 in /home/bauer_a/Unix/minishell1
** 
** Made by Hugo Bauer
** Login   <bauer_a@epitech.net>
** 
** Started on  Fri Jan  9 14:45:07 2015 Hugo Bauer
** Last update Sat May 23 16:41:20 2015 Adrien Blanquer
*/

#include <unistd.h>
#include <stdlib.h>
#include "lib.h"
#include "shell.h"

char		*clear_str(char *str, int l)
{
  int		i;

  i = 0;
  while (i < l)
    {
      str[i] = '\0';
      i++;
    }
  return (str);
}

char		*epure_str(char *str)
{
  int		i;

  i = 0;
  while (str[i] != '\0')
    {
      if (str[i] == '\t')
	str[i] = ' ';
      i++;
    }
  return (str);
}

char		*read_cmd()
{
  char		*buff;
  char		*cmd;
  int		l;

  if ((cmd = malloc_str(1)) == NULL)
    return (NULL);
  if ((buff = malloc_str(3)) == NULL)
    return (NULL);
  while ((l = read(0, buff, 2)) > 0)
    {
      buff[l] = '\0';
      if ((cmd = realloc(cmd, sizeof(char)
			 * (my_strlen(cmd) + l + 1))) == NULL)
	return (NULL);
      my_strncat(cmd, buff, l);
      if (my_strlen(cmd) > 0 && cmd[my_strlen(cmd) - 1] == '\n')
	{
	  cmd[my_strlen(cmd) - 1] = '\0';
	  return (cmd);
	}
    }
  if (my_strlen(cmd) == 0)
    return (NULL);
  return (cmd);
}
