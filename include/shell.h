/*
** shell.h for 42sh in /home/bauer_a/rendu/PSU_2014_42sh/include
** 
** Made by Hugo Bauer
** Login   <bauer_a@epitech.net>
** 
** Started on  Sat Mar 28 13:46:14 2015 Hugo Bauer
** Last update Sun May 24 17:29:13 2015 anthony geiger
*/

#ifndef SHELL_H_
# define SHELL_H_

# define READ_SIZE 512
# define RCNAME ".42rc"

typedef struct		s_alias
{
  char			*old;
  char			*new;
  struct s_alias	*next;
}			t_alias;

typedef struct		s_list_line
{
  char			*line;
  struct s_list_line	*next;
}			t_list_line;

typedef struct		s_list
{
  char			*file;
  int			double_redi;
  struct s_list		*next;
}			t_list;

typedef struct		s_cmd
{
  char			**tab;
  t_list		*redi_r;
  t_list		*redi_l;
  struct s_cmd		*next;
}			t_cmd;

typedef struct		s_cmds
{
  t_cmd			*cmd;
  char			sep;
  struct s_cmds		*next;
}			t_cmds;

typedef struct		s_stock
{
  char			*cmd;
  char			*c;
  int			pos;
}			t_stock;

typedef struct          s_history
{
  char			*data;
  struct s_history	*next;
  struct s_history      *prev;
}                       t_history;

typedef struct		s_data
{
  int			dynam_prompt;
  t_alias		*alias;
  t_cmds		*cmds;
  char			**env;
  char			*ps1;
  int			return_exe;
  int			return_exit;
  t_history		*list;
}			t_data;

t_data			*g_data;

t_cmd			*parsing_cmd(char *);
t_cmd			*parsing_pipe(char *);
t_cmds			*parsing_general(char *);
t_data			*check_recur(t_data *data, char *old, char *new);
t_data			*get_all_alias(t_data *data, char **bash, int x);
t_alias*		new_alias(t_alias *old, char *first, char *sec);
t_history		*insert_list_double(t_history *, char *);
int			pars_ps1(char **);
int			bashset(char *str, t_data *data);
int			segfault(int);
int			is_exe(char *path);
int			add_redi(char *, t_cmd *, int *);
int			error_syntax_error(int exit);
int			exe_cmd(t_data *, t_cmd *, int);
int			exe_pipe(t_data *, t_cmds *);
int			sh(t_data *);
int			redirection_right(t_list *);
int			redirection_left(t_list *);
int			is_redi(char);
int			builtin(t_data *data, char **cmd);
int			index_end_word(char *, int *);
int			is_stars(char *);
int			clean_screen(char *);
int			error_cmd_not_found(char *cmd, int exit);
int			if_stars(char **, char **, int, int);
int			pars_alias(t_data *data);
int			get_line_file();
int			is_slash(char *);
int			is_builtin(char *);
char			*epur_slash(char *);
char			*auto_complete(char *);
char			*malloc_str(int);
char			*loop(t_history *);
char			*get_cmd(t_history **);
char			*gnl(const int fd);
char			*concat_alias(char *, t_alias *);
char			*make_path(char *path, char *str);
char			*get_bin_path(t_data *data, char *bin);
char			*last_word(char *, int);
char			*my_strconcat(char *s1, char *s2);
char			*alias_finder(t_alias *s, char *alias);
char			*alias_find(t_alias *alias, char *to_find);
char			*end_find(char *new, char *prev, char *to_find);
char			*up(char *, t_history **, int *, char **);
char			*down(char *, t_history **, int *, char **);
char			*calc_new_str(char *, int, int);
char			*read_cmd();
char			*epure_str(char *);
char			**str_to_word_tab(char *, char *);
char			**parsing_globing(char **);
char			**return_globing(char *);
char			**make_env(char **);
char			**default_path();
char			**pars_tilde(t_data *, char **);
void			clean_line_prev(t_history *, char *, char *);
void			clean_line_next(t_history *, char *, char *);
void			clean(char *, int);
void			clean_line(void);
void			print_cursor_left(int);
void			print_cursor_right(int);
void			my_write_tab(char **);
void			gere_tab(t_stock *);
void			*gere_history(char *, char *, t_history *, t_stock *);
void			*init_stock(void);
void			*gere_char(t_stock *);
void			*gere_arrow(t_stock *);
void			*add_char(t_stock *);
void			*delete_char(t_stock *);
void			*delete_backward(t_stock *);

#endif /* !SHELL_H_ */
