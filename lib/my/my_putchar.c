/*
** my_putchar.c for 42sh in /home/bauer_a/rendu/PSU_2014_42sh/lib/my
** 
** Made by Hugo Bauer
** Login   <bauer_a@epitech.net>
** 
** Started on  Mon Apr 20 15:01:08 2015 Hugo Bauer
** Last update Thu May 21 16:26:30 2015 Hugo Bauer
*/

#include <unistd.h>

void	my_putchar(char c, int fd)
{
  write(fd, &c, 1);
}

