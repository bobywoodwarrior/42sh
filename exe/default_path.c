/*
** default_path.c for 42sh in /home/bauer_a/rendu/PSU_2014_42sh
** 
** Made by Hugo Bauer
** Login   <bauer_a@epitech.net>
** 
** Started on  Sat May 23 14:23:13 2015 Hugo Bauer
** Last update Sat May 23 14:28:19 2015 Hugo Bauer
*/

#include <stdlib.h>

char		**default_path()
{
  char		**tab;

  if ((tab = malloc(sizeof(char *) * 2)) == NULL)
    return (NULL);
  tab[0] = "/bin";
  tab[1] = NULL;
  return (tab);
}
