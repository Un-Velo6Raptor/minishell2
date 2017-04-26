/*
** my_exec.c for  in /home/januar_m/delivery/PSU/PSU_2016_minishell2/src
** 
** Made by Martin Januario
** Login   <martin.januario@epitech.eu>
** 
** Started on  Sun Apr  9 02:46:13 2017 Martin Januario
** Last update Wed Apr 26 14:55:20 2017 Martin Januario
*/

#include	<stdlib.h>
#include	<unistd.h>
#include        <signal.h>
#include        <sys/types.h>
#include        <sys/stat.h>
#include        <sys/wait.h>
#include	<fcntl.h>
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
  else if (access(str, X_OK) == -1 ||
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
  if ((my_strcmp(my_order->oper_n, "<") == 0 ||
       my_strcmp(my_order->oper_n, "<<") == 0) && my_order->fd != -1)
    dup2(my_order->fd, 0);
  if (my_strcmp(my_order->oper_n, ">") == 0 ||
      my_strcmp(my_order->oper_n, ">>") == 0)
    {
      if (my_order->fd == -1)
	exit(my_puterror("Can't open the file for redir.\n"));
      dup2(my_order->fd, 1);
    }
  if (my_order->next != NULL &&
      ((my_strcmp(my_order->oper_n, "<") == 0 ||
	my_strcmp(my_order->oper_n, "<<") == 0) &&
       (my_strcmp(my_order->next->oper_n, ">") == 0 ||
	my_strcmp(my_order->next->oper_n, ">>") == 0)))
    {
      if (my_order->next->fd == -1)
	exit(my_puterror("Can't open the file for redir.\n"));
      dup2(my_order->next->fd, 1);
    }
  if ((execve(exec_path, my_order->order, news->my_env)) == -1)
    {
      my_puterror(exec_path);
      my_puterror(": Exec format error. Binary file not executable.\n");
      close(my_order->fd);
      exit(1);
    }
  return (0);
}

int		open_redir(t_my_order *my_order)
{
  if ((check_redir_right(my_order) == 1 ||
       my_strcmp(my_order->oper_n, "<") == 0) &&
      redir_error(my_order->next->order[0]) == 1)
    return (1);
  if (my_strcmp(my_order->oper_n, "<<") == 0)
    make_double_redir_left(my_order);
  else if (my_strcmp(my_order->oper_n, "<") == 0)
    {
      my_order->fd = open(my_order->next->order[0], O_RDONLY);
      if (my_order->next != NULL &&
	  my_strcmp(my_order->next->oper_n, ">") == 0)
	my_order->next->fd = open(my_order->next->next->order[0],
				  O_CREAT | O_TRUNC | O_RDWR, 0644);
      if (my_order->next != NULL
	  && my_strcmp(my_order->next->oper_n, ">>") == 0)
	my_order->next->fd = open(my_order->next->next->order[0], O_CREAT |
				  O_APPEND | O_RDWR, 0644);
    }
  else if (my_strcmp(my_order->oper_n, ">") == 0)
    my_order->fd = open(my_order->next->order[0],
			O_CREAT | O_TRUNC | O_RDWR, 0644);
  else if (my_strcmp(my_order->oper_n, ">>") == 0)
    my_order->fd = open(my_order->next->order[0], O_CREAT |
			O_APPEND | O_RDWR, 0644);
  return (0);
}

int		my_exec(t_needs *news, t_my_order *my_order,
			char *exec_path)
{
  int		son_uid;
  int		status;

  son_uid = 0;
  status = 0;
  if (check_path(exec_path, my_order) == 1 || open_redir(my_order) == 1)
    return (1);
  if ((son_uid = fork()) == -1)
    return (my_puterror("Can't fork.\n"));
  else if (son_uid != 0)
    {
      if (waitpid(son_uid, &status, 0) == -1)
	kill(son_uid, 0);
      {
	if (!WIFEXITED(status))
	  error_exec(status % 255);
	if (status > 0 && status < 30)
	  status += 128;
      }
      if (my_order->pipe[1] != -1)
	close(my_order->pipe[1]);
      if (my_order->fd != -1)
	close(my_order->fd);
      return ((status % 255));
    }
  else
    return (exec_this(news, my_order, exec_path));
}
