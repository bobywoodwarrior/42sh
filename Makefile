##
## Makefile for 42sh in /home/bauer_a/rendu/PSU_2014_42sh
## 
## Made by Hugo Bauer
## Login   <bauer_a@epitech.net>
## 
## Started on  Mon Mar 23 17:00:04 2015 Hugo Bauer
## Last update Sat May 23 15:14:41 2015 Adrien Blanquer
##

SRC	= parsing/parsing_cmd.c \
	parsing/parsing_general.c \
	parsing/parsing_pipe.c \
	parsing/redirection.c \
	parsing/parsing_tilde.c \
	builtin/utils.c \
	builtin/top_builtin.c \
	builtin/forbuiltin.c \
	builtin/builtin.c \
	builtin/cd.c \
	builtin/getvar.c \
	prompt_read_termcaps/loop_read.c \
	prompt_read_termcaps/insert_list_double.c \
	prompt_read_termcaps/move.c \
	prompt_read_termcaps/init.c \
	prompt_read_termcaps/clear_line.c \
	prompt_read_termcaps/clean_screen.c \
	prompt_read_termcaps/prompt_dyn.c \
	prompt_read_termcaps/print_cursor.c \
	prompt_read_termcaps/gere_key.c \
	prompt_read_termcaps/modif_cmd.c \
	prompt_read_termcaps/last_word.c \
	auto_complete/auto_complete.c \
	auto_complete/functions_complete.c \
	alias/alias.c \
	alias/gnl.c \
	alias/pars_alias.c \
	alias/str_cat.c \
	alias/alias_etc.c \
	exe/redirection_right.c \
	exe/redirection_left.c \
	exe/exe_cmd.c \
	exe/pipe.c \
	exe/is_builtin.c \
	exe/default_path.c \
	lib/my/my_putchar.c \
	lib/my/get_next_line.c \
	lib/my/malloc_str.c \
	lib/my/my_putstr.c \
	lib/my/my_strcat.c \
	lib/my/my_getnbr.c \
	lib/my/my_put_nbr.c \
	lib/my/my_strncat.c \
	lib/my/my_strlen.c \
	lib/my/len_tab.c \
	lib/my/str_to_word_tab.c \
	lib/my/my_strcpy.c \
	lib/my/my_strcmp.c \
	lib/my/my_strncmp.c \
	lib/my/my_strcat_from.c \
	lib/my/my_strncpy.c \
	lib/my/my_strcpy_from.c \
	lib/my/my_strndup.c \
	lib/my/my_strdup.c \
	ps1/utils.c \
	ps1/tab_fonc.c \
	glob/glob.c \
	glob/stars.c \
	general/get_bin_path.c \
	general/segfault.c \
	general/make_env.c \
	general/is_exe.c \
	general/prompt.c \
	general/errors.c \
	general/sh.c \
	general/main.c

NAME	= 42sh

OBJ	= $(SRC:.c=.o)

CFLAGS	+= -Wall -Wextra
CFLAGS	+= -I include
CFLAGS	+= -I lib/my/include

CC	= gcc

all:		$(NAME)

$(NAME):	$(OBJ)
		$(CC) -o $(NAME) $(OBJ) $(LDFLAGS)

clean:
		rm -f $(OBJ)

fclean:		clean
		rm -f $(NAME)

re:		fclean all

.PHONY:		all clean fclean re
