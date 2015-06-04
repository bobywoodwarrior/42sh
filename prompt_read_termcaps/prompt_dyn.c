/*
** main.c for prompt in /home/blanqu_a/Workspace/rendu/PSU_2014_42sh/prompt_read_termcaps
** 
** Made by Adrien Blanquer
** Login   <blanqu_a@epitech.net>
** 
** Started on  Sat May 16 10:46:28 2015 Adrien Blanquer
** Last update Sat May 23 16:53:24 2015 Adrien Blanquer
*/

#include <termios.h>
#include <stdlib.h>
#include "shell.h"
#include "lib.h"

static int		mod_raw(struct termios *t)
{
  t->c_lflag &= ~(ECHO | ICANON);
  t->c_cc[VMIN] = 1;
  t->c_cc[VTIME] = 0;
  if (tcsetattr(0, TCSANOW, t) == -1)
    return (-1);
  return (0);
}

static char		*my_read_dyn(t_history *list)
{
  struct termios	save;
  struct termios	t;
  char			*cmd;

  if (tcgetattr(0, &save) == -1)
    return (NULL);
  t = save;
  if (mod_raw(&t) == -1)
    return (NULL);
  cmd = loop(list);
  if (tcsetattr(0, TCSANOW, &save) == -1)
    return (NULL);
  my_putchar('\r', 1);
  pars_ps1(g_data->env);
  return (cmd);
}

char	*get_cmd(t_history **list)
{
  char	*ret;

  if ((ret = my_read_dyn(*list)))
    {
      if (my_strlen(ret) > 0)
	*list = insert_list_double(*list, ret);
      my_putstr(ret, 1);
      my_putchar('\n', 1);
    }
  return (ret);
}
