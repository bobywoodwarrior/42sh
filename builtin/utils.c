/*
** probably_useless.c for useless in /home/rouss_p/rendu/PSU_2014_42sh/builtin
** 
** Made by pierre rousselle
** Login   <rouss_p@epitech.net>
** 
** Started on  Mon May  4 16:19:00 2015 pierre rousselle
** Last update Fri May 22 17:40:17 2015 pierre rousselle
*/

#include <string.h>
#include <stdlib.h>

int		my_getnbr_base(char *str, char *base, int *offset, int i)
{
  unsigned int	k;
  int		nbr;
  int		imax;

  nbr = 0;
  if (strlen(base) == 8)
    imax = 3;
  else
    imax = 2;
  while (str[i] && i < imax)
    {
      k = 0;
      while (k < strlen(base))
        if (str[i] == base[k++])
          {
            nbr = (nbr * strlen(base)) + k - 1;
            break ;
          }
      if (k == strlen(base))
	break ;
      ++i;
    }
  *offset += i;
  return (nbr);
}

char    *get_env_value(char **env, char *key, int *offset)
{
  int   i;

  i = 0;
  while (env && env[i])
    {
      if (strncmp(env[i], key, strlen(key)) == 0 && env[i][strlen(key)] == '=')
        {
          if (offset != NULL)
            *offset = i;
          return (env[i] + strlen(key) + 1);
        }
      ++i;
    }
  return (NULL);
}

char    **cattab_ext(char *new)
{
  char  **dupped;

  if ((dupped = malloc(2 * sizeof(char *))) == NULL)
    return (NULL);
  dupped[0] = strdup(new);
  dupped[1] = NULL;
  return (dupped);
}
