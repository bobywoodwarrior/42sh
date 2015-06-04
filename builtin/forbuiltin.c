/*
** forbuiltin.c for forbuiltin in /home/rouss_p/rendu/42
** 
** Made by pierre rousselle
** Login   <rouss_p@epitech.net>
** 
** Started on  Fri Apr 24 11:22:53 2015 pierre rousselle
** Last update Fri May 22 17:39:29 2015 pierre rousselle
*/

#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include "builtin.h"
#include "lib.h"

char	g_ref[8][2] = {{'a', '\a'},
		       {'b', '\b'},
		       {'e', ESCAPE},
		       {'f', '\f'},
		       {'n', '\n'},
		       {'r', '\r'},
		       {'t', '\t'},
		       {'v', '\v'}};

void	other_echo_case(char *str, int *i, char done)
{
  if (done == 1)
    return ;
  if (str[*i] == '0')
    my_putchar((char)my_getnbr_base(str + *i + 1, "01234567", i, 0), 1);
  else if (str[*i] == 'x')
    my_putchar((char)my_getnbr_base
	       (str + *i + 1, "0123456789abcdef", i, 0), 1);
  else
    {
      my_putchar('\\', 1);
      if (str[*i] != '\\')
	my_putchar(str[*i], 1);
    }
}

int	my_interpret(char *str, int i, int k, char done)
{
  while (str[i])
    {
      done = 0;
      if (str[i] == '\\')
	{
	  ++i;
	  k = 0;
	  while (k < 8 && done == 0)
	    {
	      if (str[i] == g_ref[k++][0])
		{
		  my_putchar(g_ref[k - 1][1], 1);
		  done = 1;
		}
	    }
	  if (str[i] == 'c')
            return (-1);
	  other_echo_case(str, &i, done);
	}
      else
	my_putchar(str[i], 1);
      if (str[i])
	++i;
    }
  return (0);
}

int	my_print(char *str, char inter, char noret, char *nextword)
{
  int	i;

  i = 0;
  if (!str)
    return (0);
  if (!inter)
    while (str[i])
      {
	write(1, str + i, 1);
	++i;
      }
  if (inter)
    if (my_interpret(str, 0, 0, 0) == -1)
      return (-1);
  if (nextword)
    my_putchar(' ', 1);
  if (!noret)
    my_putchar('\n', 1);
  return (0);
}

char	**my_epurtab(char **tab)
{
  int	i;
  int	j;
  char	**dupped;

  dupped = NULL;
  if (tab)
    {
      j = 0;
      i = 0;
      while (tab[i])
        if (tab[i++][0])
          ++j;
      if ((dupped = malloc((j + 1) * sizeof(char *))) == NULL)
        return (NULL);
      i = 0;
      j = 0;
      while (tab[i])
	{
	  if (tab[i][0])
	    dupped[j++] = tab[i];
	  ++i;
	}
      dupped[j] = NULL;
    }
  return (dupped);
}

char	**my_cattab(char **tab, char *new)
{
  int	i;
  char	**dupped;

  dupped = NULL;
  if (tab)
    {
      i = 0;
      while (tab[i])
        ++i;
      if ((dupped = malloc((i + 2) * sizeof(char *))) == NULL)
        return (NULL);
      i = 0;
      while (tab[i])
	{
	  dupped[i] = tab[i];
	  i++;
	}
      if ((dupped[i] = malloc(strlen(new) + 1)) == NULL
          || strcpy(dupped[i], new) == NULL)
        return (NULL);
      dupped[i + 1] = NULL;
    }
  else
    dupped = cattab_ext(new);
  return (dupped);
}
