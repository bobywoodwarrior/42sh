/*
** my_strcpy_from.c for 42sh in /home/blanqu_a/Workspace/rendu/PSU_2014_42sh
** 
** Made by Adrien Blanquer
** Login   <blanqu_a@epitech.net>
** 
** Started on  Wed May 20 17:01:07 2015 Adrien Blanquer
** Last update Fri May 22 16:03:52 2015 Hugo Bauer
*/

#include "lib.h"

char	*my_strcpy_from(char *dest, char *src, int nb)
{
  int	i;
  int	j;

  i = nb;
  j = 0;
  while (src[i])
    dest[j++] = src[i++];
  dest[j] = '\0';
  return (0);
}
