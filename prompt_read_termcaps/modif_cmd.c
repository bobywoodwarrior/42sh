/*
** modif_cmd.c for 42sh in /home/blanqu_a/Workspace/rendu/PSU_2014_42sh
** 
** Made by Adrien Blanquer
** Login   <blanqu_a@epitech.net>
** 
** Started on  Thu May 21 14:06:59 2015 Adrien Blanquer
** Last update Sat May 23 15:47:31 2015 Adrien Blanquer
*/

#include "lib.h"
#include "shell.h"

void	*add_char(t_stock *ptr)
{
  char	left[my_strlen(ptr->cmd)];
  char	right[my_strlen(ptr->cmd)];

  if (ptr->pos == my_strlen(ptr->cmd))
    {
      my_putchar(ptr->c[0], 1);
      ptr->cmd[ptr->pos++] = ptr->c[0];
    }
  else
    {
      my_strncpy(left, ptr->cmd, ptr->pos);
      my_strcat(left, ptr->c);
      my_strcpy_from(right, ptr->cmd, ptr->pos);
      my_strcpy(ptr->cmd, left);
      my_strcat(ptr->cmd, right);
      my_putchar('\r', 1);
      pars_ps1(g_data->env);
      my_putstr(ptr->cmd, 1);
      ptr->pos++;
      print_cursor_left(my_strlen(ptr->cmd) - ptr->pos);
    }
  return (ptr);
}

void	*delete_char(t_stock *ptr)
{
  char	left[my_strlen(ptr->cmd)];
  char	right[my_strlen(ptr->cmd)];

  if (ptr->pos > 0 && ptr->pos == my_strlen(ptr->cmd))
    {
      clean_line();
      ptr->cmd[--ptr->pos] = '\0';
      my_putchar('\r', 1);
      pars_ps1(g_data->env);
      my_putstr(ptr->cmd, 1);
    }
  else if (ptr->pos > 0)
    {
      my_strncpy(left, ptr->cmd, ptr->pos - 1);
      my_strcpy_from(right, ptr->cmd, ptr->pos);
      my_strcpy(ptr->cmd, left);
      my_strcat(ptr->cmd, right);
      clean_line();
      my_putchar('\r', 1);
      pars_ps1(g_data->env);
      my_putstr(ptr->cmd, 1);
      ptr->pos--;
      print_cursor_left(my_strlen(ptr->cmd) - ptr->pos);
    }
  return (ptr);
}

void	*delete_backward(t_stock *ptr)
{
  char	left[my_strlen(ptr->cmd)];
  char	right[my_strlen(ptr->cmd)];

  if (ptr->pos < my_strlen(ptr->cmd))
    {
      my_strncpy(left, ptr->cmd, ptr->pos);
      my_strcpy_from(right, ptr->cmd, ptr->pos + 1);
      my_strcpy(ptr->cmd, left);
      my_strcat(ptr->cmd, right);
      clean_line();
      my_putchar('\r', 1);
      pars_ps1(g_data->env);
      my_putstr(ptr->cmd, 1);
      print_cursor_left(my_strlen(ptr->cmd) - ptr->pos);
    }
  return (ptr);
}
