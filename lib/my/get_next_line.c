/*
** get_next_line.c for get_next_line in /home/bauer_a/get_next_line
** 
** Made by Hugo Bauer
** Login   <bauer_a@epitech.net>
** 
** Started on  Thu May 14 15:36:06 2015 Hugo Bauer
** Last update Sun May 17 17:51:48 2015 Hugo Bauer
*/

#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include "get_next_line.h"
#include "lib.h"

char		*my_read(int fd, char *str)
{
  char		buff[BUFF_SIZE];
  int		l;

  buff[0] = '\0';
  if (str == NULL)
    {
      if ((str = malloc(sizeof(char) * 1)) == NULL)
	return (NULL);
      str[0] = '\0';
    }
  if ((l = read(fd, buff, BUFF_SIZE)) <= 0)
    return (str);
  if ((str = realloc(str, sizeof(char) * (my_strlen(str) + l + 1))) == NULL)
    return (str);
  my_strncat(str, buff, l);
  return (str);
}

char		*new_str(char *str, int *i, int j)
{
  char		*new;

  if ((new = malloc(sizeof(char) * (j - *i + 1))) == NULL)
    return (NULL);
  new[0] = '\0';
  strncat(new, str + *i, j - *i);
  *i = j + 1;
  return (new);
}

char		*get_next_line(int fd)
{
  static char	*str = NULL;
  static int	i = 0;
  int		j;
  int		tmp;

  str = my_read(fd, str);
  if (str != NULL && i > 0 && str[i - 1] == '\0')
    return (NULL);
  j = i;
  while (str[j] != '\n' && str[j] != '\0')
    j++;
  if (str[j] == '\n')
    return (new_str(str, &i, j));
  tmp = my_strlen(str);
  if ((str = my_read(fd, str)) == NULL)
    return (NULL);
  if (my_strlen(str) == tmp)
    return (new_str(str, &i, j));
  return (get_next_line(fd));
}
