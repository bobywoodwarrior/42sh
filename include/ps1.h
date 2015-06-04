/*
** ps1.h for ps1 in /home/geiger_a/PSU_2014_42sh/include
** 
** Made by anthony geiger
** Login   <geiger_a@epitech.net>
** 
** Started on  Thu May 21 16:21:10 2015 anthony geiger
** Last update Fri May 22 15:00:11 2015 Hugo Bauer
*/

#ifndef PS1_H_
# define PS1_H_

# define FORMAT_CHAR '%'
# define NAME_CHAR 'n'
# define HOST_CHAR 'j'
# define PWD_CHAR '~'
# define LAST_DIR_CHAR 'c'
# define TERM_CHAR 't'
# define BEEP_CHAR 'a'

typedef	struct		s_format
{
  char			format;
  void			(*ptr_tab)(char **env);
}			t_format;

void			case_name(char **env);
void			case_host(char **env);
void			case_pwd(char **env);
void			case_last_dir(char **env);
void			case_term(char **env);
void			case_beep(char **env);
int			pars_ps1(char **env);

#endif /* !PS1_H_ */
