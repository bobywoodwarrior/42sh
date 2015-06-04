/*
** redirection_right.c for 42sh in /home/bauer_a/rendu/PSU_2014_42sh/exe
** 
** Made by Hugo Bauer
** Login   <bauer_a@epitech.net>
** 
** Started on  Tue Apr 21 10:54:25 2015 Hugo Bauer
** Last update Thu May 21 16:42:12 2015 Hugo Bauer
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include "shell.h"
#include "lib.h"

int		open_file_rd(char *name)
{
  return (open(name, O_RDONLY));
}

t_list_line	*add_end_list(t_list_line *list, char *str)
{
  t_list_line	*new;
  t_list_line	*tmp;

  if ((new = malloc(sizeof(t_list))) == NULL)
    return (list);
  new->line = str;
  new->next = NULL;
  if (list == NULL)
    return (new);
  tmp = list;
  while (tmp->next != NULL)
    tmp = tmp->next;
  tmp->next = new;
  return (list);
}

int		write_list_redi(t_list_line *list)
{
  pid_t		pid;
  int		pipefd[2];

  if (pipe(pipefd) == -1)
    return (0);
  if ((pid = fork()) == -1)
    return (0);
  if (pid == 0)
    {
      close(pipefd[0]);
      while (list != NULL)
	{
	  my_putstr(list->line, pipefd[1]);
	  my_putchar('\n', pipefd[1]);
	  list = list->next;
	}
      return (-1);
    }
  close(pipefd[1]);
  return (pipefd[0]);
}

int		double_redi_left(char *stop)
{
  t_list_line	*list;
  char		*str;

  list = NULL;
  my_putstr("> ", 1);
  while ((str = read_cmd()) != NULL)
    {
      if (!my_strcmp(str, stop))
	break ;
      list = add_end_list(list, str);
      my_putstr("> ", 1);
   }
  return (write_list_redi(list));
}

int		redirection_left(t_list *list_r)
{
  t_list	*tmp;
  int		fd;

  fd = 0;
  tmp = list_r;
  while (tmp != NULL)
    {
      if (tmp->double_redi)
	return (double_redi_left(tmp->file));
      else if ((fd = open_file_rd(tmp->file)) == -1)
	return (0);
      tmp = tmp->next;
    }
  return (fd);
}
