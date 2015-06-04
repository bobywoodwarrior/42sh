/*
** alias.c for alias in /home/geiger_a/alias
** 
** Made by anthony geiger
** Login   <geiger_a@epitech.net>
** 
** Started on  Wed May  6 12:55:24 2015 anthony geiger
** Last update Sun May 24 17:34:45 2015 anthony geiger
*/

#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include "shell.h"
#include "lib.h"

t_alias		*new_alias(t_alias *old, char *first, char *sec)
{
  t_alias*	new;
  t_alias*	tmp;

  if ((new = malloc(sizeof(*new))) == NULL)
    return (NULL);
  new->next = NULL;
  new->old = first;
  new->new = sec;
  if (old == NULL)
    return (new);
  tmp = old;
  while (tmp->next != NULL)
    tmp = tmp->next;
  tmp->next = new;
  return (old);
}

char		*alias_finder(t_alias *s, char *alias)
{
  t_alias	*tmp;

  tmp = s;
  if (tmp == NULL)
    return (NULL);
  while (my_strcmp(tmp->new, alias) != 0)
    {
      tmp = tmp->next;
      if (tmp == NULL)
	return (NULL);
    }
  return (tmp->old);
}

int		get_line_file()
{
  int		line;
  int		fd;
  char		*s;

  line = 0;
  if ((fd = open(RCNAME, O_RDONLY)) == -1)
    return (-1);
  while ((s = gnl(fd)))
    {
      ++line;
      free(s);
    }
  close(fd);
  return (line);
}

char		*alias_find(t_alias *alias, char *to_find)
{
  static char	*new;
  char		*old;
  int		pass;
  static char	*prev;

  pass = 0;
  if ((old = alias_finder(alias, to_find)) != NULL)
    {
      if (alias_finder(alias, old) != NULL)
	{
	  if (my_strcmp(new, prev) == 0)
	    return (to_find);
	  if (new == NULL)
	      prev = my_strdup(alias_finder(alias, alias_finder(alias, to_find)));
	    new = alias_finder(alias, alias_finder(alias, to_find));
	    pass = 1;
	  return (alias_find(alias, new));
	}
    }
  if (pass == 1)
    return (end_find(new, prev, to_find));
  if (alias_finder(alias, to_find) == NULL)
    return (to_find);
  return (alias_finder(alias, to_find));
}

t_data		*check_recur(t_data *data, char *old, char *new)
{
  if ((data->alias = new_alias(data->alias, old, new)) == NULL)
    return (NULL);
  return (data);
}
