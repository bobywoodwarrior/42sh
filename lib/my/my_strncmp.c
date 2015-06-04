/*
** my_strncmp.c<2> for strncmp in /home/geiger_a/rendu/PSU_2014_42sh
** 
** Made by anthony geiger
** Login   <geiger_a@epitech.net>
** 
** Started on  Fri May 22 17:34:04 2015 anthony geiger
** Last update Fri May 22 17:35:15 2015 anthony geiger
*/

int	my_strncmp(char *a, char *b, int n)
{
  int	i;

  i = 0;
  while (a[i] && i != n)
    {
      if (a[i] != b[i])
	return (1);
      i++;
    }
  return (0);
}
