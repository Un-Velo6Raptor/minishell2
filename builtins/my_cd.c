/*
** my_cd.c for  in /home/januar_m/delivery/PSU/PSU_2016_minishell2/builtins
** 
** Made by Martin Januario
** Login   <martin.januario@epitech.eu>
** 
** Started on  Sun Apr  9 02:08:20 2017 Martin Januario
** Last update Sun Apr  9 02:08:21 2017 Martin Januario
*/

#include	<unistd.h>
#include	<stdlib.h>
#include	"my.h"

int		make_cd(t_needs *news, char *path, char *od, int opt)
{
  char		*tmp;
  char		*tmp2;

  if (check_access(path, (od == NULL) ? path : od) == 1 || chdir(path) == -1)
    return (1);
  my_free(news->oldpwd);
  if ((news->oldpwd = my_strdup(news->pwd)) == NULL)
    return (MALLOC_FAILED);
  my_free(news->pwd);
  if ((news->pwd = getcwd(NULL, 0)) == NULL)
    return (MALLOC_FAILED);
  if (opt == 1)
    my_free(path);
  if ((tmp = make_var_env("PWD", news->pwd)) == NULL)
    return (MALLOC_FAILED);
  if (add_var_env(news, tmp) == MALLOC_FAILED)
    return (MALLOC_FAILED);
  if (found_var(news->my_env, "OLDPWD=*") != -1)
    {
      if ((tmp2 = make_var_env("OLDPWD", news->oldpwd)) == NULL)
	return (MALLOC_FAILED);
      if (add_var_env(news, tmp2) == MALLOC_FAILED)
	return (MALLOC_FAILED);
    }
  return (0);
}

void		make_path_cd(char *path, t_needs *news,
			      t_my_order *my_order)
{
  my_strcpy(path, news->pwd);
  if (news->pwd[my_strlen(news->pwd) - 1] != '/' &&
      my_order->order[1][0] != '/')
    my_strcat(path, "/");
  if (news->pwd[my_strlen(news->pwd) - 1] == '/' &&
      my_order->order[1][0] == '/')
    my_strcat(path, &my_order->order[1][1]);
  else
    my_strcat(path, my_order->order[1]);
}

int		my_cd(t_my_order *my_order, t_needs *news)
{
  char		*path;

  if (update_pwd(news) == MALLOC_FAILED)
    return (MALLOC_FAILED);
  if (my_tablen(my_order->order) >= 3)
    return (my_puterror("cd: Too many arguments.\n"));
  if (my_tablen(my_order->order) == 1 && news->home == NULL)
    return (my_puterror("No var HOME.\n"));
  if (my_tablen(my_order->order) == 1)
    return (make_cd(news, news->home, my_order->order[1], 0));
  if (my_tablen(my_order->order) == 1 ||
      my_strcmp(my_order->order[1], "-") == 0)
    return (go_to_last_dir(news));
  if (my_order->order[1][0] == '/')
    return (make_cd(news, my_order->order[1], my_order->order[1], 0));
  if ((path = malloc(my_strlen(news->pwd) +
		     my_strlen(my_order->order[1]) + 3)) == NULL)
    return (MALLOC_FAILED);
  make_path_cd(path, news, my_order);
  return (make_cd(news, path, my_order->order[1], 1));
}
