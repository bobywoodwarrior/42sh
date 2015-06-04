/*
** is_builtin.c for 42sh in /home/bauer_a/rendu/PSU_2014_42sh/exe
** 
** Made by Hugo Bauer
** Login   <bauer_a@epitech.net>
** 
** Started on  Sat May 23 14:02:29 2015 Hugo Bauer
** Last update Sat May 23 14:03:13 2015 Hugo Bauer
*/

#include "lib.h"

int		is_builtin(char *cmd)
{
  if (!my_strcmp(cmd, "cd") || !my_strcmp(cmd, "exit") ||
      !my_strcmp(cmd, "env") || !my_strcmp(cmd, "setenv") ||
      !my_strcmp(cmd, "unsetenv") || !my_strcmp(cmd, "echo"))
    return (1);
  return (0);
}
