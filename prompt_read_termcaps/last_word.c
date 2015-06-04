/*
** last_word.c for 42sh in /home/blanqu_a/Workspace/rendu/PSU_2014_42sh
** 
** Made by Adrien Blanquer
** Login   <blanqu_a@epitech.net>
** 
** Started on  Sat May 23 15:10:11 2015 Adrien Blanquer
** Last update Sat May 23 16:53:58 2015 Adrien Blanquer
*/

#include <stdlib.h>
#include "lib.h"
#include "shell.h"

char	*last_word(char *str, int pos)
{
  char	*tmp;
  int	i;
  int	j;

  i = 0;
  j = pos;
  if ((tmp = malloc(sizeof(char) * (my_strlen(str) + 1))) == NULL)
    return (NULL);
  while (pos > 0 && str[pos] != ' ')
    pos--;
  if (str[pos] == ' ')
    pos++;
  while (pos < j)
    tmp[i++] = str[pos++];
  tmp[i] = '\0';
  return (tmp);
}
