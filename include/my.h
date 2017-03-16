/*
** my.h for  in /home/januar_m/delivery/PSU/PSU_2016_minishell2
** 
** Made by Martin Januario
** Login   <martin.januario@epitech.eu>
** 
** Started on  Tue Mar 14 12:57:32 2017 
** Last update Thu Mar 16 14:09:34 2017 
*/

#ifndef MY_H_
# define MY_H_

# include		"get_next_line.h"
# define		MALLOC_FAILED 84

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
}			t_my_order;

/*
**			Prototypes of file's sources.
*/
void			ini_needs(t_needs *);
int			found_var(char **, char *);
void			isatty_disp(t_needs *);
t_my_order		*prepare_order(char *);
int			how_separate_order(char *);
int			separator_or();
t_my_order		*ini_my_order(void);
t_my_order		*create_list_order(char **);
int			exec_the_order(t_needs *, t_my_order *);
int			free_list_order(t_my_order *);

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

/*
**			Prototypes of file's builtins.
*/
int			my_exit(t_my_order *);
int			my_env(t_my_order *, t_needs *);
int			my_setenv(t_my_order *, t_needs *);
char			*make_var_env(char *, char *);

/*
**			Prototypes of file's get_next_line.
*/
char			*get_next_line(int, t_buffer *);
void			ini_gnl(t_buffer *);

#endif /* !MY_H_ */
