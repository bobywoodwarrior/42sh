/*
** my_strncpy.c for 42sh in /home/blanqu_a/Workspace/rendu/PSU_2014_42sh
** 
** Made by Adrien Blanquer
** Login   <blanqu_a@epitech.net>
** 
** Started on  Wed May 20 16:54:37 2015 Adrien Blanquer
** Last update Fri May 22 17:35:41 2015 anthony geiger
*/

char	*my_strncpy(char *dest, char *src, int nb)
{
  int	i;

  i = 0;
  while (src[i] && i < nb)
    {
      dest[i] = src[i];
      i++;
    }
  dest[i] = '\0';
  return (dest);
}
