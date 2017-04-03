/*
** my_exec.c for  in /home/januar_m/delivery/PSU/PSU_2016_minishell2
** 
** Made by Martin Januario
** Login   <martin.januario@epitech.eu>
** 
** Started on  Mon Mar 27 14:01:03 2017 Martin Januario
** Last update Mon Apr  3 20:03:00 2017 Martin Januario
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
  else if (access(str, 0) == -1)
    {
      command_not_found(my_order);
      return (1);
    }
  else if (access(str, R_OK) == -1 ||
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
  if ((execve(exec_path, my_order->order, news->my_env)) == -1)
    {
      my_puterror(exec_path);
      my_puterror(": Exec format error. Binary file not executable.");
      exit(1);
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
      if (!WIFEXITED(status % 255))
        error_exec(status % 255);
      if (status > 0 && status < 30)
	status += 128;
      return ((status % 255));
    }
  else
    return (exec_this(news, my_order, exec_path));
}
