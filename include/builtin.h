/*
** builtin.h for builtin in /home/rouss_p/rendu/PSU_2014_42sh/builtin
** 
** Made by pierre rousselle
** Login   <rouss_p@epitech.net>
** 
** Started on  Mon May  4 16:05:00 2015 pierre rousselle
** Last update Sat May 23 15:03:41 2015 pierre rousselle
*/

#ifndef BUILTIN_H_
# define BUILTIN_H_

# include "shell.h"

# define ESCAPE 27
# define FAILURE -2
# define NO_MATCH -1
# define SUCCESS 0
# define EXIT 1

typedef struct	s_bref
{
  char		*ref;
  int		(*builtin)(char **, t_data *);
}		t_bref;

int		my_redir_builtin(t_data *data, t_cmd *cmd);
char		**cattab_ext(char *new);
int		my_cd_error(char *str);
int		my_replace_key(char **expr, t_data *data);
char		*my_cstrconcat(char *s1, char *s2);
char		*get_env_value(char **env, char *key, int *offset);
int		my_print(char *str, char inter, char noret, char *nextword);
char		**my_epurtab(char **tab);
char		**my_cattab(char **tab, char *new);
int		my_getnbr_base(char *str, char *base, int *offset, int i);
int		my_cd(char **, t_data *);
int		my_exit(char **, t_data *);
int		my_env(char **, t_data *);
int		my_setenv(char **, t_data *);
int		my_unsetenv(char **, t_data *);
int		my_echo(char **, t_data *);

#endif /* !BUILTIN_H_ */
