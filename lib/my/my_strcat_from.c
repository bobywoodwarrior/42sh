/*
** my_strcat_from.c for 42sh in /home/blanqu_a/Workspace/rendu/PSU_2014_42sh
** 
** Made by Adrien Blanquer
** Login   <blanqu_a@epitech.net>
** 
** Started on  Thu May 21 16:57:50 2015 Adrien Blanquer
** Last update Thu May 21 16:58:05 2015 Adrien Blanquer
*/

#include "lib.h"

void	my_strcat_from(char *dest, char *src, int nb)
{
  int	i;
  int	j;

  j = 0;
  i = my_strlen(dest);
  while (src[nb])
    {
      dest[i + j] = src[nb];
      j++;
      nb++;
    }
  dest[i + j] = '\0';
}
