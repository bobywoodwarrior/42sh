/*
** lib.h for 42sh_lib in /home/bauer_a/rendu/PSU_2014_42sh/lib/my
** 
** Made by Hugo Bauer
** Login   <bauer_a@epitech.net>
** 
** Started on  Mon Apr 20 15:10:52 2015 Hugo Bauer
** Last update Fri May 22 17:35:38 2015 anthony geiger
*/

#ifndef LIB_H_
# define LIB_H_

char		*malloc_str(int);
char		*my_strcat(char *, char *);
char		*my_strncat(char *, char *, int);
char		*get_next_line(int);
char		*my_strcpy(char *, char *);
char		*my_strncpy(char *, char *, int);
char		*my_strcpy_from(char *, char *, int);
void		my_putchar(char, int fd);
void		my_putstr(char *, int);
void		my_put_nbr(int);
void		my_strcat_from(char *, char *, int);
int		my_getnbr(char *);
int		*my_strcmp(char *, char *);
int		my_strlen(char *);
int		len_tab(char **);
char		*my_strcpy(char *dest, char *src);
char		*my_strncpy(char *dest, char *src, int nb);
char		*my_strndup(char *src, int nb);
char		*my_strdup(char *src);
int		my_strncmp(char *a, char *b, int n);

#endif /* LIB_H_ */
