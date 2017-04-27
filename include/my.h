/*
** my.h for  in /home/januar_m/delivery/PSU/PSU_2016_minishell2/include
** 
** Made by Martin Januario
** Login   <martin.januario@epitech.eu>
** 
** Started on  Sun Apr  9 02:04:41 2017 Martin Januario
** Last update Wed Apr 26 22:47:21 2017 Martin Januario
*/

#ifndef MY_H_
# define MY_H_

# include		<stdio.h>
# include		"get_next_line.h"

# define		MALLOC_FAILED	84
# define		REDIR_LEFT	1
# define		REDIR_RIGHT	2
# define		PIPE		0

typedef struct		s_needs
{
  char			**my_env;
  char			*path;
  char			*pwd;
  char			*oldpwd;
  char			*home;
}			t_needs;

typedef struct		s_my_order
{
  struct s_my_order	*next;
  struct s_my_order	*before;
  char			*oper_b;
  char			*oper_n;
  char			**order;
  int			error;
  int			fd;
  int			pipe[2];
}			t_my_order;

/*
**			Prototypes of file's sources.
*/
int			ini_needs(t_needs *);
int			found_var(char **, char *);
void			isatty_disp(t_needs *);
t_my_order		*prepare_order(char *);
int			how_separate_order(char *);
int			separator_or();
t_my_order		*ini_my_order(void);
t_my_order		*create_list_order(char **);
int			exec_the_order(t_needs *, t_my_order *);
int			free_list_order(t_my_order *);
int			check_tild(t_needs *, t_my_order *);
int			update_pwd(t_needs *);
int			my_exec(t_needs *, t_my_order *, char *);
void			error_exec(int);
int			is_null(t_my_order *);
int			count_spe_char(char *, char);
int			make_exec_path(t_needs *, t_my_order *, char **);
int			command_not_found(t_my_order *);
int			create_pipe(t_needs *, t_my_order *);
int			check_builtins(t_needs *, t_my_order *, int);
void			save_pipe(int);
int			check_path(char *, t_my_order *);
int			got_pipe(t_my_order *);
int			nb_pipe(t_my_order *);
int			check_pipe_redir(t_my_order *);
int			my_order_for_redir(t_my_order *);
int			redir_error(char *);
int			left_redir_pipe(t_my_order *);
int			is_a_redir(t_my_order *);
void			split_quote(char *, char **, int *, int *);
char			split_next(char, int *, int *);
char			**make_double_redir_left(t_my_order *);

/*
**			Prototypes of file's basics.
*/
int			my_strlen(char *);
int			my_putstr(char *);
int			my_tablen(char **);
char			**my_tabdup(char **);
char			*my_strdup(char *);
char			*my_strndup(char *, int);
char			*my_strcpy(char *, char *);
void			disp_tab(char **);
int			free_tab(char **);
int			match(char *, char *);
int			my_str_is_num(char *);
int			my_str_is_alpha(char *);
int			my_car_is_alpha(char);
void			my_free(char *);
int			my_strncmp(char *, char *, int);
int			my_strcmp(char *, char *);
char			*my_strncpy(char *, char *, int);
char			**my_str_to_wordtab(char *);
void			disp_list_order(t_my_order *);
int			my_puterror(char *);
int			my_getnbr(char *);
char			*my_strcat(char *, char *);
int			without_space(char *);
int			check_pipe(t_my_order *);
int			check_redir_left(t_my_order *);
int			check_redir_right(t_my_order *);
int			is_null(t_my_order *);
void			disp_tab_fd(char **, int);

/*
**			Prototypes of file's builtins.
*/
int			my_exit(t_my_order *);
int			my_env(t_my_order *, t_needs *);
int			my_setenv(t_my_order *, t_needs *);
int			my_unsetenv(t_my_order *, t_needs *);
char			*make_var_env(char *, char *);
int			add_var_env(t_needs *, char *);
int			my_cd(t_my_order *, t_needs *);
int			go_to_last_dir(t_needs *);
int			check_access(char *, char *);

/*
**			Prototypes of file's get_next_line.
*/
char			*get_next_line(int, t_buffer *);
void			ini_gnl(t_buffer *);

#endif /* !MY_H_ */
