/*
** clear_line.c for prompt in /home/blanqu_a/Workspace/rendu/PSU_2014_42sh/prompt_read_termcaps
** 
** Made by Adrien Blanquer
** Login   <blanqu_a@epitech.net>
** 
** Started on  Mon May 18 15:47:20 2015 Adrien Blanquer
** Last update Sat May 23 16:57:13 2015 Adrien Blanquer
*/

#include <sys/ioctl.h>
#include <unistd.h>
#include "shell.h"
#include "lib.h"

void			clean_line()
{
  struct winsize	w;
  int			i;

  i = 0;
  if (ioctl(STDOUT_FILENO, TIOCGWINSZ, &w) != -1)
    {
      my_putchar('\r', 1);
      while (i++ < w.ws_col)
	write(1, " ", 1);
    }
}
