/*
** main.c for 42sh in /home/bauer_a/rendu/PSU_2014_42sh
** 
** Made by Hugo Bauer
** Login   <bauer_a@epitech.net>
** 
** Started on  Mon Apr 20 15:17:15 2015 Hugo Bauer
** Last update Sat May 23 17:48:03 2015 Hugo Bauer
*/

#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include "shell.h"
#include "ps1.h"
#include "lib.h"

void		signal_exit()
{
  my_putchar('\n', 1);
  pars_ps1(g_data->env);
}

void		signal_stop()
{
  my_putstr("\r", 1);
  pars_ps1(g_data->env);
  my_putstr("  \r", 1);
  pars_ps1(g_data->env);
}

int		main(int argc, char **argv, char **env)
{
  t_data	data;

  data.dynam_prompt = 0;
  data.alias = NULL;
  if (argc > 1 && !my_strcmp(argv[1], "--prompt-on"))
    data.dynam_prompt = 1;
  g_data = &data;
  data.return_exit = 0;
  if (signal(SIGINT, signal_exit) == SIG_ERR)
    return (-1);
  if (signal(SIGTSTP, signal_stop) == SIG_ERR)
    return (-1);
  data.env = make_env(env);
  if (pars_alias(&data) == -1)
    data.alias = NULL;
  data.return_exe = 0;
  if (sh(&data) == -1)
    return (data.return_exit);
  my_putchar('\n', 1);
  return (0);
}
