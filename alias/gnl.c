/*
** gnl.c for gnl in /home/geiger_a/rendu/gnl
** 
** Made by anthony geiger
** Login   <geiger_a@epitech.net>
** 
** Started on  Wed May  6 14:59:58 2015 anthony geiger
** Last update Tue May 19 15:11:54 2015 anthony geiger
*/

#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include "shell.h"

static char	*my_spstrconcat(char *s1, char *s2)
{
  char          *ret;
  int           i;
  int           j;

  i = 0;
  j = 0;
  if ((ret = malloc(sizeof(char) * (strlen(s1)
				    + strlen(s2)) + 1)) == NULL)
    return (NULL);
  while (s1[i])
    {
      ret[j] = s1[i];
      ++j;
      ++i;
    }
  i = 0;
  while (s2[i])
    {
      ret[j] = s2[i];
      ++j;
      ++i;
    }
  ret[j] = '\0';
  free(s1);
  return (ret);
}

static char	*get_new_line(char **all)
{
  char		*line;
  static int	i;
  int		start;

  start = i;
  if (*all == NULL)
    return (NULL);
  while ((*all)[i] != '\n')
    {
      if ((*all)[i] == '\0')
	{
	  line = strndup((*all) + start, i - start);
	  *all = NULL;
	  i = 0;
	  return (line);
	}
      ++i;
    }
  line = strndup((*all) + start, i - start);
  i++;
  return (line);
}

char		*gnl(const int fd)
{
  static char	*all = NULL;
  int		ret;
  char		buff[READ_SIZE + 1];
  static int	pass;
  char		*line;

  if (pass == 1 && all == NULL)
    {
      pass = 0;
      return (NULL);
    }
  if (pass == 0)
    {
      while ((ret = read(fd, buff, READ_SIZE + 1)) > 0)
	{
	  buff[ret] = '\0';
	  if (all == NULL)
	    all = strdup(buff);
	  else
	    all = my_spstrconcat(all, buff);
	}
      pass = 1;
    }
  line = get_new_line(&all);
  return (line);
}
