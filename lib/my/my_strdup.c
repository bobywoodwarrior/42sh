/*
** my_strdup.c for strdup in /home/geiger_a/lib/lib/my/src/str
**
** Made by anthony geiger
** Login   <geiger_a@epitech.net>
**
** Started on  Mon Jan  5 19:51:23 2015 anthony geiger
** Last update Sat May 23 15:07:51 2015 anthony geiger
*/

#include <stdlib.h>
#include "lib.h"

char    *my_strdup(char *src)
{
  char  *new_str;
  int   size;

  if (src == NULL)
    return (NULL);
  size = my_strlen(src);
  new_str = malloc(sizeof(char) * size + 1);
  if (new_str == 0)
    return (0);
  my_strcpy(new_str, src);
  return (new_str);
}
