/*
** insert_list_double.c for 42sh in /home/bauer_a/rendu/PSU_2014_42sh/prompt_read_termcaps
** 
** Made by Hugo Bauer
** Login   <bauer_a@epitech.net>
** 
** Started on  Mon May 11 15:20:38 2015 Hugo Bauer
** Last update Sat May 23 15:55:00 2015 Adrien Blanquer
*/

#include <stdlib.h>
#include "shell.h"

t_history	*insert_list_double(t_history *l, char *data)
{
  t_history	*new;

  if ((new = malloc(sizeof(t_history))) == NULL)
    return (NULL);
  new->data = data;
  new->next = NULL;
  new->prev = NULL;
  if (l == NULL)
    return (new);
  l->prev = new;
  new->next = l;
  return (new);
}
