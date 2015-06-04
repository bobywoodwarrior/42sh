/*
** redirection_right.c for 42sh in /home/bauer_a/rendu/PSU_2014_42sh/exe
** 
** Made by Hugo Bauer
** Login   <bauer_a@epitech.net>
** 
** Started on  Tue Apr 21 10:54:25 2015 Hugo Bauer
** Last update Sat May 23 16:31:47 2015 Adrien Blanquer
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include "shell.h"

int		open_file_wr(char *name, int double_redi)
{
  if (double_redi)
    return (open(name, O_CREAT | O_WRONLY | O_APPEND, S_IRUSR | S_IWUSR));
  return (open(name, O_CREAT | O_WRONLY | O_TRUNC, S_IRUSR | S_IWUSR));
}

int		redirection_right(t_list *list_r)
{
  t_list	*tmp;
  int		fd;

  fd = 0;
  tmp = list_r;
  while (tmp != NULL)
    {
      if ((fd = open_file_wr(tmp->file, tmp->double_redi)) == -1)
	return (-1);
      tmp = tmp->next;
    }
  return (fd);
}
