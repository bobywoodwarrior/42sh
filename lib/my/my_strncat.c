/*
** my_strncat.c for lib in /home/bauer_a/rendu/PSU_2014_42sh/lib/my
** 
** Made by Hugo Bauer
** Login   <bauer_a@epitech.net>
** 
** Started on  Sun May 17 17:44:50 2015 Hugo Bauer
** Last update Sun May 17 17:47:27 2015 Hugo Bauer
*/

#include "lib.h"

char		*my_strncat(char *s1, char *s2, int l)
{
  int		i;
  int		i2;

  i = my_strlen(s1);
  i2 = 0;
  while (i2 < l && s2[i2] != '\0')
    {
      s1[i] = s2[i2];
      i2++;
      i++;
    }
  s1[i] = '\0';
  return (s1);
}
