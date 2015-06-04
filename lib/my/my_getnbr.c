/*
** my_getnbr.c for my_get_nbr in /home/bauer_a/j04
** 
** Made by Hugo Bauer
** Login   <bauer_a@epitech.net>
** 
** Started on  Thu Oct  2 15:33:58 2014 Hugo Bauer
** Last update Thu Nov  6 09:42:04 2014 Hugo Bauer
*/

int	check(int nbr, int nbr_z)
{
  if (nbr < nbr_z)
    return (0);
  else
    return (1);
}

int	my_getnbr_2(char *str, int signe)
{
  int	p10;
  int	i;
  int	nbr;
  int	nbr_z;

  nbr = 0;
  i = 1;
  p10 = 1;
  str = str + 1;
  while (*str >= 48 && *str <= 57)
    {
      p10 = p10 * 10;
      str = str + 1;
      i = i + 1;
    }
  str = str - i;
  while (i > 0)
    {
      nbr_z = nbr;
      nbr = nbr + ((*str - 48) * p10);
      p10 = p10 / 10;
      str = str + 1;
      i = (i - 1) * check(nbr, nbr_z);
    }
  return (nbr * signe * check(nbr, nbr_z));
}

int	my_getnbr(char *str)
{
  int	signe;

  signe = 1;
  while (*str != '\0' && (*str < 48 || *str > 57))
    {
      if (*str == '-')
	signe = signe * -1;
      str = str + 1;
    }
  if (*str == '\0')
    return (0);
  return (my_getnbr_2(str, signe));
}
