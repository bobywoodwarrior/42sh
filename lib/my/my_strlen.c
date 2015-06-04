/*
** my_strlen.c for lib in /home/bauer_a/rendu/PSU_2014_42sh/lib/my
** 
** Made by Hugo Bauer
** Login   <bauer_a@epitech.net>
** 
** Started on  Sun May 17 17:45:32 2015 Hugo Bauer
** Last update Sun May 17 17:45:58 2015 Hugo Bauer
*/

#include <stdlib.h>

int		my_strlen(char *str)
{
  int		i;

  if (str == NULL)
    return (0);
  i = 0;
  while (str[i] != '\0')
    i++;
  return (i);
}
