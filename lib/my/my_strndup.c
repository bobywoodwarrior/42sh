/*
** my_strndup.c for my_strndup in /home/geiger_a/rendu/PSU_2014_minishell1/lib/my/src/str
**
** Made by Anthony Geiger
** Login   <geiger_a@epitech.net>
**
** Started on  Tue Jan  6 19:35:50 2015 Anthony Geiger
** Last update Sat May 23 15:08:10 2015 anthony geiger
*/

#include <stdlib.h>
#include "lib.h"

char    *my_strndup(char *src, int nb)
{
  char  *new_str;
  int   size;

  if (src == NULL)
    return (NULL);
  size = my_strlen(src);
  new_str = malloc(sizeof(char) * size + 3);
  if (new_str == 0)
    return (0);
  my_strncpy(new_str, src, nb);
  return (new_str);
}
