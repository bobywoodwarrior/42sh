/*
** getvar.c for 42sh in /home/rouss_p/rendu/PSU_2014_42sh
** 
** Made by pierre rousselle
** Login   <rouss_p@epitech.net>
** 
** Started on  Mon May 18 14:01:13 2015 pierre rousselle
** Last update Fri May 22 18:53:47 2015 pierre rousselle
*/

#include <stdlib.h>
#include <lib.h>
#include "builtin.h"

void	delete_first_word(char **wtab)
{
  int	i;

  i = 0;
  if (wtab[i])
    while (wtab[i])
      {
	wtab[i] = wtab[i + 1];
	++i;
      }
}

int	my_replace_key(char **expr, t_data *data)
{
  int	i;
  char	*buffer;

  i = 0;
  if (!expr || !expr[0] || !data || !data->env)
    return (FAILURE);
  while (expr[i])
    {
      if (expr[i][0] == '$')
	{
	  if ((buffer = get_env_value(data->env, expr[i] + 1, NULL)) != NULL)
	    expr[i] = buffer;
	  else
	    delete_first_word(expr + i);
	}
      ++i;
    }
  return (SUCCESS);
}

char            *my_cstrconcat(char *s1, char *s2)
{
  char          *ret;
  int           i;
  int           j;

  if (s1 == NULL || s2 == NULL)
    return (NULL);
  i = 0;
  j = 0;
  if ((ret = malloc(sizeof(char) * (my_strlen(s1)
                                    + my_strlen(s2)) + 1)) == NULL)
    return (NULL);
  while (s1[i])
    ret[j++] = s1[i++];
  i = 0;
  while (s2[i])
    ret[j++] = s2[i++];
  ret[j] = '\0';
  return (ret);
}
