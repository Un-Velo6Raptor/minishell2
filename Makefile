##
## Makefile for  in /home/januar_m/delivery/PSU/PSU_2016_minishell2
## 
## Made by Martin Januario
## Login   <martin.januario@epitech.eu>
## 
## Started on  Wed Apr  5 16:47:48 2017 Martin Januario
## Last update Wed Apr 19 21:22:33 2017 Martin Januario
##

SRC	=	src/main.c			\
		src/ini_needs.c			\
		src/found_var.c			\
		src/prepare_order.c		\
		src/create_list_order.c		\
		src/how_separate_order.c	\
		src/free_list_order.c		\
		src/exec_the_order.c		\
		src/is_a_redir.c		\
		src/nb_pipe.c			\
		src/my_order_for_redir.c	\
		src/check_pipe_redir.c		\
		src/create_pipe.c		\
		src/redir_error.c		\
		src/command_not_found.c		\
		src/check_tild.c		\
		src/update_pwd.c		\
		src/my_exec.c			\
		src/error_exec.c		\
		src/left_redir_pipe.c		\
		src/make_exec_path.c		\
		src/isatty_disp.c

BASICS	=	basics/my_strlen.c		\
		basics/match.c			\
		basics/my_getnbr.c		\
		basics/my_tabdup.c		\
		basics/my_strdup.c		\
		basics/my_strcpy.c		\
		basics/my_strcat.c		\
		basics/my_strcmp.c		\
		basics/my_strncmp.c		\
		basics/my_str_to_wordtab.c	\
		basics/my_str_is_num.c		\
		basics/my_str_is_alpha.c	\
		basics/my_strndup.c		\
		basics/my_strncpy.c		\
		basics/disp_tab.c		\
		basics/free_tab.c		\
		basics/my_tablen.c		\
		basics/my_free.c		\
		basics/count_special_char.c	\
		basics/disp_list_order.c	\
		basics/my_putstr.c

BUILT	=	builtins/my_exit.c		\
		builtins/my_setenv.c		\
		builtins/make_var_env.c		\
		builtins/add_var_env.c		\
		builtins/my_unsetenv.c		\
		builtins/my_cd.c		\
		builtins/check_access.c		\
		builtins/go_to_last_dir.c	\
		builtins/my_env.c

GNL	=	gnl/ini_gnl.c			\
		gnl/get_next_line.c

OBJ	=	$(SRC:.c=.o)			\
		$(BASICS:.c=.o)			\
		$(BUILT:.c=.o)			\
		$(GNL:.c=.o)

CFLAGS	=	-g -Wall -Wextra -I include/

NAME	=	mysh

all:		$(NAME)

$(NAME):	$(OBJ)
		gcc -o $(NAME) $(OBJ)

clean:
		rm -f $(OBJ)

fclean:		clean
		rm -f $(NAME)

re:		fclean all
