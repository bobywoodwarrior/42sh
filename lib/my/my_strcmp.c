/*
** my_strcmp.c for 42sh in /home/bauer_a/rendu/PSU_2014_42sh
** 
** Made by Hugo Bauer
** Login   <bauer_a@epitech.net>
** 
** Started on  Thu May 21 15:10:29 2015 Hugo Bauer
** Last update Sun May 24 16:58:05 2015 anthony geiger
*/

#include <unistd.h>

int		my_strcmp(char *s1, char *s2)
{
  if (s1 == NULL || s2 == NULL)
    return (-1);
  while (*s1 != '\0' && *s2 != '\0' && *s1 == *s2)
    {
      s1++;
      s2++;
    }
  return (*s1 - *s2);
}
