/*
** len_tab.c for lib in /home/bauer_a/rendu/PSU_2014_42sh
** 
** Made by Hugo Bauer
** Login   <bauer_a@epitech.net>
** 
** Started on  Sun May 17 18:03:17 2015 Hugo Bauer
** Last update Sun May 17 18:03:52 2015 Hugo Bauer
*/

#include <stdlib.h>

int		len_tab(char **tab)
{
  int		i;

  i = 0;
  while (tab[i] != NULL)
    i++;
  return (i);
}
