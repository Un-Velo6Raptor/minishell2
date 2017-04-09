/*
** ini_needs.c for  in /home/januar_m/delivery/PSU/PSU_2016_minishell2/src
** 
** Made by Martin Januario
** Login   <martin.januario@epitech.eu>
** 
** Started on  Sun Apr  9 02:46:02 2017 Martin Januario
** Last update Sun Apr  9 02:46:03 2017 Martin Januario
*/

#include	<stdlib.h>
#include	<unistd.h>
#include	"my.h"

void		ini_path(t_needs *news)
{
  int		tmp;

  if ((tmp = found_var(news->my_env, "PATH=*")) != -1)
    news->path = my_strdup(&news->my_env[tmp][5]);
  else
    news->path = NULL;
}

void		ini_pwd(t_needs *news)
{
  news->pwd = getcwd(NULL, 0);
}

void		ini_oldpwd(t_needs *news)
{
  int		tmp;

  if ((tmp = found_var(news->my_env, "OLDPWD=*")) != -1)
    news->oldpwd = my_strdup(&news->my_env[tmp][7]);
  else
    news->oldpwd = getcwd(NULL, 0);
}

void		ini_home(t_needs *news)
{
  int		tmp;

  if ((tmp = found_var(news->my_env, "HOME=*")) != -1)
    news->home = my_strdup(&news->my_env[tmp][5]);
  else
    news->home = NULL;
}

int		ini_needs(t_needs *news)
{
  ini_path(news);
  ini_pwd(news);
  ini_oldpwd(news);
  ini_home(news);
  if (news->oldpwd == NULL || news->pwd == NULL)
    return (84);
  return (0);
}
