/*
** go_to_last_dir.c for  in /home/januar_m/delivery/PSU/PSU_2016_minishell2/builtins
** 
** Made by Martin Januario
** Login   <martin.januario@epitech.eu>
** 
** Started on  Sun Apr  9 02:08:11 2017 Martin Januario
** Last update Sun Apr  9 02:08:12 2017 Martin Januario
*/

#include	<stdlib.h>
#include	<unistd.h>
#include	"my.h"

int		swap_pwd(t_needs *news)
{
  char		*tmp;

  tmp = news->pwd;
  news->pwd = news->oldpwd;
  news->oldpwd = tmp;
  return (0);
}

int		go_to_last_dir(t_needs *news)
{
  char		*tmp;
  char		*tmp2;

  if (news->oldpwd == NULL)
    return (my_puterror("No var OLDPWD.\n"));
  if (chdir(news->oldpwd) == -1)
    return (my_puterror("Can't return to the last directory.\n"));
  if ((tmp = make_var_env("PWD", news->oldpwd)) == NULL ||
      (tmp2 = make_var_env("OLDPWD", news->pwd)) == NULL)
    return (MALLOC_FAILED);
  if (add_var_env(news, tmp) == MALLOC_FAILED)
    return (MALLOC_FAILED);
  if (found_var(news->my_env, "OLDPWD=*") != -1)
    add_var_env(news, tmp2);
  return (swap_pwd(news));
}
