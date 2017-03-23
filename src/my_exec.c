/*
** my_exec.c for  in /home/januar_m/delivery/PSU/PSU_2016_minishell2
** 
** Made by Martin Januario
** Login   <martin.januario@epitech.eu>
** 
** Started on  Wed Mar 22 16:18:55 2017 
** Last update Thu Mar 23 04:06:41 2017 
*/

#include	<stdlib.h>
#include	<unistd.h>
#include        <signal.h>
#include        <sys/types.h>
#include        <sys/stat.h>
#include        <sys/wait.h>
#include	"my.h"

int		check_path(char *str, t_my_order *my_order)
{
  struct stat	sb;

  if (str == NULL)
    {
      command_not_found(my_order);
      return (1);
    }
  if (access(str, 0) == -1)
    {
      command_not_found(my_order);
      return (1);
    }
  if (access(str, R_OK) == -1 ||
      (lstat(str, &sb) != -1 && S_ISDIR(sb.st_mode) != 0))
    {
      my_puterror(my_order->order[0]);
      my_puterror(": Permission denied.\n");
      return (1);
    }
  return (0);
}

int		exec_this(t_needs *news, t_my_order *my_order,
			  char *exec_path)
{
  struct stat	sb;

  if ((execve(exec_path, my_order->order, news->my_env)) == -1)
    {
      if (access(exec_path, X_OK) == 0)
        {
          my_puterror(exec_path);
          if (lstat(exec_path, &sb) != -1 &&
              !S_ISDIR(sb.st_mode) && !S_ISLNK(sb.st_mode))
            my_puterror(": Exec format error. Binary file not executable.\n");
          else
            my_puterror(": Permission denied.\n");
	}
      else
	command_not_found(my_order);
      return (1);
    }
  return (0);
}

int		my_exec(t_needs *news, t_my_order *my_order, char *exec_path)
{
  int		son_uid;
  int		status;

  son_uid = 0;
  status = 0;
  if (check_path(exec_path, my_order) == 1)
    return (1);
  if ((son_uid = fork()) == -1)
    return (my_puterror("Can't fork.\n"));
  else if (son_uid != 0)
    {
      if (waitpid(son_uid, &status, 0) == -1)
        kill(son_uid, 0);
      if (!WIFEXITED(status))
        error_exec(status);
      return (status);
    }
  else
    return (exec_this(news, my_order, exec_path));
}
