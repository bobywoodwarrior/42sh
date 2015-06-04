/*
** malloc_str.c for 42sh in /home/bauer_a/rendu/PSU_2014_42sh/lib/my
** 
** Made by Hugo Bauer
** Login   <bauer_a@epitech.net>
** 
** Started on  Mon Apr 20 15:01:21 2015 Hugo Bauer
** Last update Mon Apr 20 15:09:53 2015 Hugo Bauer
*/

#include <stdlib.h>

char		*malloc_str(int l)
{
  char		*str;
  int		i;

  if ((str = malloc(sizeof(char) * (l + 1))) == NULL)
    return (NULL);
  i = 0;
  while (i < (l + 1))
    {
      str[i] = '\0';
      i++;
    }
  return (str);
}
