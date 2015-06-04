/*
** my_strcpy.c for minishell1 in /home/blanqu_a/Workspace/rendu/PSU_2014_minishell1
** 
** Made by Adrien Blanquer
** Login   <blanqu_a@epitech.net>
** 
** Started on  Fri Jan  9 16:05:56 2015 Adrien Blanquer
** Last update Fri May 22 17:35:41 2015 anthony geiger
*/

char	*my_strcpy(char *dest, char *src)
{
  int	i;

  i = 0;
  while (src[i])
    {
      dest[i] = src[i];
      i++;
    }
  dest[i] = '\0';
  return (dest);
}
