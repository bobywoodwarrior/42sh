/*
** my_put_nbr.c for my_put_nbr in /home/bauer_a/day03_piscine
** 
** Made by Hugo Bauer
** Login   <bauer_a@epitech.net>
** 
** Started on  Wed Oct  1 14:22:01 2014 Hugo Bauer
** Last update Thu May 21 16:24:26 2015 Hugo Bauer
*/

#include "lib.h"

int	power_10(int nb)
{
  int	i;

  i = 1;
  while (nb > 9 || nb < -9)
    {
      nb = nb / 10;
      i = i * 10;
    }
  return (i);
}

void	my_put_nbr(int nb)
{
  int	i;

  if (nb < 0)
    my_putchar('-', 1);
  i = power_10(nb);
  while (i != 0)
    {
      if (nb < 0)
	my_putchar(48 - (nb / i), 1);
      else
	my_putchar(48 + (nb / i), 1);
      nb = nb % i;
      i = i / 10;
    }
}
