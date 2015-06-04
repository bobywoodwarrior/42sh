/*
** segfault.c for 42sh in /home/bauer_a/rendu/PSU_2014_42sh
** 
** Made by Hugo Bauer
** Login   <bauer_a@epitech.net>
** 
** Started on  Fri May 22 13:31:48 2015 Hugo Bauer
** Last update Sat May 23 16:43:12 2015 Hugo Bauer
*/

#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>

int		segfault(int return_exe)
{
  if (!WIFEXITED(return_exe) &&
      WIFSIGNALED(return_exe) &&
      WTERMSIG(return_exe) == 11)
    fprintf(stderr, "Segmentation fault (core dumped)\n");
  return (0);
}
