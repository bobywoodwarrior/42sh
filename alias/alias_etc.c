/*
** alias_etc.c for 42sh in /home/bauer_a/rendu/PSU_2014_42sh/alias
** 
** Made by Hugo Bauer
** Login   <bauer_a@epitech.net>
** 
** Started on  Fri May 22 15:58:36 2015 Hugo Bauer
** Last update Sun May 24 18:07:03 2015 pierre rousselle
*/

#include <stdlib.h>
#include "lib.h"
#include "shell.h"
#include "builtin.h"

int	setbashenv(int i, char *str, int start, char **to_set)
{
  while (str[i] && str[i] != '\"' && str[i] != '\'')
    i++;
  start = i;
  while (str[i] != '\0')
    ++i;
  if ((to_set[2] = my_strndup(str + start + 1, (i - 2 - start))) == NULL)
    return (-1);
  to_set[3] = NULL;
  return (0);
}

int	bashset(char *str, t_data *data)
{
  char	**to_set;
  int	i;
  int	start;

  i = 7;
  if ((to_set = malloc(sizeof(char *) * (3 + 1))) == NULL)
    return (-1);
  if ((to_set[0] = my_strndup(str, 6)) == NULL)
    return (-1);
  while (str[i] && (str[i] == ' '))
    i++;
  if (str[i] == '\0')
    return (-1);
  start = i;
  while (str[i] && str[i] != ' ')
    i++;
  if (str[i] == '\0')
    return (-1);
  if ((to_set[1] = my_strndup(str + start, i - start)) == NULL)
    return (-1);
  if (setbashenv(i, str, start, to_set) == -1)
    return (-1);
  if (my_setenv(to_set, data) == FAILURE)
    return (-1);
  return (0);
}

char		*end_find(char *new, char *prev, char *to_find)
{
  (void)prev;
  (void)new;
  prev = NULL;
  new = NULL;
  return (to_find);
}

char	*concat_alias(char *str, t_alias *list_alias)
{
  int	i;
  char	*without;
  char	*with;
  char	*alias;
  int	start;

  i = 0;
  while (str[i] && str[i] == ' ')
    ++i;
  start = i;
  while (str[i] && str[i] != ' ')
    ++i;
  if ((alias = alias_find(list_alias, my_strndup(str + start, i - start)))
      == NULL)
    return (str);
  without = my_strdup(str + i);
  with = my_strconcat(alias, without);
  return (with);
}
