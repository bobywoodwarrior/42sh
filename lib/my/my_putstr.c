/*
** my_putstr.c for 42sh in /home/bauer_a/rendu/PSU_2014_42sh/lib/my
** 
** Made by Hugo Bauer
** Login   <bauer_a@epitech.net>
** 
** Started on  Mon Apr 20 15:10:09 2015 Hugo Bauer
** Last update Wed May 20 17:58:57 2015 anthony geiger
*/

#include <string.h>
#include <unistd.h>

void	my_putstr(char *str, int fd)
{
  if (str == NULL)
    return ;
  write(fd, str, strlen(str));
}
