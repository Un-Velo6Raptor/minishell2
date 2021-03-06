/*
** create_pipe.c for  in /home/januar_m/delivery/PSU/PSU_2016_minishell2
** 
** Made by Martin Januario
** Login   <martin.januario@epitech.eu>
** 
** Started on  Mon Apr  3 20:45:23 2017 Martin Januario
** Last update Thu Apr 27 17:02:53 2017 Martin Januario
*/

#include	<sys/types.h>
#include	<sys/stat.h>
#include	<sys/wait.h>
#include	<signal.h>
#include	<stdlib.h>
#include	<unistd.h>
#include	<fcntl.h>
#include	"my.h"

int		dup_pipe(t_my_order *my_order)
{
  if (my_order->before != NULL && my_strcmp(my_order->oper_b, "|") == 0 &&
      my_strcmp(my_order->before->oper_b, "<") != 0)
    dup2(my_order->before->pipe[0], 0);
  if (my_order->next != NULL && (my_strcmp(my_order->oper_n, "|") == 0 ||
				 my_strcmp(my_order->oper_n, "<") == 0))
    {
      dup2(my_order->pipe[1], 1);
      close(my_order->pipe[0]);
    }
  if (check_redir_right(my_order) == 1)
    if (right_pipe_redir(my_order) == 1)
      return (1);
  return (left_redir_pipe(my_order));
}

int		my_exec_pipe(t_needs *news, t_my_order *my_order)
{
  char		*exec_path;
  int		value_ret;

  if (dup_pipe(my_order) == 1)
    exit(1);
  if ((value_ret = check_builtins(news, my_order, 0)) != -1)
    exit(value_ret);
  if ((value_ret = make_exec_path(news, my_order, &exec_path)) > 0)
    return (value_ret);
  if (check_path(exec_path, my_order) == 1)
    exit(1);
  if (exec_path != NULL && execve(exec_path,
				  my_order->order, news->my_env) == -1)
    {
      my_puterror(exec_path);
      my_puterror(": Exec format error. Binary file not executable.");
      if (my_order->fd != -1)
	close(my_order->fd);
      exit(1);
    }
  return (0);
}

int		wait_son(int *son_uid,
			 t_my_order *beg, int cpt, int tmp)
{
  int		status[2];

  status[1] = 0;
  while (cpt >= 0)
    {
      if (waitpid(son_uid[cpt], &status[0], 0) == -1)
	kill(son_uid[cpt], 0);
      if (!WIFEXITED(status[0]))
	{
	  error_exec(status[0] % 255);
	  if (status[0] > 0 && status[0] < 30)
	    status[0] += 128;
	}
      if (status[0] != 0 && status[1] == 0)
	status[1] = status[0];
      close_broken(beg);
      beg = beg->before;
      cpt--;
    }
  free(son_uid);
  if (tmp == 0)
    return (status[1] % 255);
  return (my_puterror("Fail pipe.\n"));
}

void		big_father(t_my_order **my_order, int *idx,
			   t_my_order **beg)
{
  if ((*my_order)->pipe[1] != -1)
    close((*my_order)->pipe[1]);
  (*idx)++;
  if (check_redir_left(*my_order) == 1)
    *my_order = (*my_order)->next;
  else
    *beg = *my_order;
  if (check_redir_right(*my_order) == 1)
    *my_order = (*my_order)->next;
  *my_order = (*my_order)->next;
}

int		create_pipe(t_needs *news, t_my_order *my_order)
{
  t_my_order	*beg;
  int		*son_uid;
  int		idx;
  int		tmp;

  tmp = nb_pipe(my_order);
  beg = my_order;
  if ((son_uid = malloc(sizeof(int) * (tmp + 20))) == NULL)
    return (84);
  idx = 0;
  while (idx < tmp - 1 || (my_order != NULL &&
			   my_strcmp(my_order->oper_b, ";") != 0))
    {
      if (pipe(my_order->pipe) == -1)
	return (wait_son(son_uid, beg, idx - 1, 1));
      if ((son_uid[idx] = fork()) < 0)
	return (my_puterror("Fail fork.\n"));
      else if (son_uid[idx] == 0)
	exit(my_exec_pipe(news, my_order));
      else
	big_father(&my_order, &idx, &beg);
    }
  return (wait_son(son_uid, beg, idx - 1, 0));
}
