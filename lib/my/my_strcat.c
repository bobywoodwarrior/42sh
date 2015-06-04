/*
** my_strcat.c for my_strcat in /home/bauer_a/j07
** 
** Made by Hugo Bauer
** Login   <bauer_a@epitech.net>
** 
** Started on  Tue Oct  7 09:25:10 2014 Hugo Bauer
** Last update Sat Apr 11 11:39:57 2015 Hugo Bauer
*/

char	*my_strcat(char *dest, char *src)
{
  int	i;
  int	j;

  i = 0;
  while (dest[i] != '\0')
    i++;
  j = 0;
  while (src[j] != '\0')
    {
      dest[i] = src[j];
      j++;
      i++;
    }
  dest[i] = '\0';
  return (dest);
}
