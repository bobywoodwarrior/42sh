/*
** malloc.c for 4ésh in /home/geiger_a/PSU_2014_42sh
** 
** Made by anthony geiger
** Login   <geiger_a@epitech.net>
** 
** Started on  Mon May 18 11:19:26 2015 anthony geiger
** Last update Mon May 18 18:29:09 2015 Hugo Bauer
*/

#include <time.h>
#include <stdlib.h>

void	*malloc(size_t size)
{
  int	i = time(NULL) * rand();

  if (!(i % 50))
    return (NULL);
  return (realloc(NULL, size));
}
