/*
** gere_key.c for 42sh in /home/blanqu_a/Workspace/rendu/PSU_2014_42sh
** 
** Made by Adrien Blanquer
** Login   <blanqu_a@epitech.net>
** 
** Started on  Wed May 20 18:01:51 2015 Adrien Blanquer
** Last update Sat May 23 17:48:18 2015 Adrien Blanquer
*/

#include <stdlib.h>
#include <unistd.h>
#include "shell.h"
#include "lib.h"

void		*gere_history(char *cmd, char *c, t_history *list, t_stock *ptr)
{
  static int	cpt;
  t_history	*tmp;

  tmp = list;
  while (tmp && c[1] == '[' && (c[2] == 'A' || c[2] == 'B'))
    {
      clean(cmd, 4096);
      if (c[2] == 'A')
	cmd = up(cmd, &tmp, &cpt, &c);
      else if (c[2] == 'B')
	cmd = down(cmd, &tmp, &cpt, &c);
      if (read(0, c, 7) <= 0)
	break;
    }
  ptr->cmd = cmd;
  ptr->c = c;
  ptr->pos = my_strlen(ptr->cmd);
  return (ptr);
}

void	*gere_char(t_stock *ptr)
{
  if (ptr->c[0] == '\n')
    ptr->pos = 0;
  else if (ptr->c[0] == 12)
    clean_screen(ptr->cmd);
  else if (ptr->c[0] == 4)
    return (NULL);
  else if (my_strlen(ptr->c) == 4)
    ptr = delete_backward(ptr);
  else if (ptr->c[0] == 127)
    ptr = delete_char(ptr);
  else if (ptr->c[0] == 9)
    gere_tab(ptr);
  else
    ptr = add_char(ptr);
  return (ptr);
}

void	*gere_arrow(t_stock *ptr)
{
  if (ptr->c[2] == 'D' && my_strlen(ptr->cmd) > 0 && ptr->pos > 0)
    {
      ptr->pos--;
      print_cursor_left(1);
    }
  if (ptr->c[2] == 'C' && my_strlen(ptr->cmd) > 0 &&
      ptr->pos < my_strlen(ptr->cmd))
    {
      ptr->pos++;
      print_cursor_right(1);
    }
  return (ptr);
}

static void	*complete_cmd(t_stock *ptr, char *complete, char *tmp)
{
  if (my_strcmp(tmp, complete))
    {
      my_strcat_from(ptr->cmd, complete, my_strlen(tmp));
      ptr->pos = my_strlen(ptr->cmd);
    }
  my_putchar('\r', 1);
  pars_ps1(g_data->env);
  my_putstr(ptr->cmd, 1);
  ptr->pos++;
  my_putchar(' ', 1);
  return (ptr);
}

void	gere_tab(t_stock *ptr)
{
  char	*tmp;
  char	*complete;

  if ((tmp = last_word(ptr->cmd, ptr->pos)) != NULL)
    {
      if ((complete = auto_complete(tmp)) != NULL)
	ptr = complete_cmd(ptr, complete, tmp);
      else
      	{
	  my_putchar('\r', 1);
	  pars_ps1(g_data->env);
      	  my_putstr(ptr->cmd, 1);
      	  print_cursor_left(my_strlen(ptr->cmd) - ptr->pos);
      	}
    }
}
