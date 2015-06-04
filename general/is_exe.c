/*
** is_exe.c for 42sh in /home/bauer_a/rendu/PSU_2014_42sh
** 
** Made by Hugo Bauer
** Login   <bauer_a@epitech.net>
** 
** Started on  Thu May 21 17:18:39 2015 Hugo Bauer
** Last update Thu May 21 17:20:14 2015 Hugo Bauer
*/

#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>

int		is_exe(char *path)
{
  struct stat	s;

  if (access(path, F_OK | X_OK))
    return (0);
  if (stat(path, &s) == 0)
    if (s.st_mode & S_IFDIR)
      return (0);
  return (1);
}
