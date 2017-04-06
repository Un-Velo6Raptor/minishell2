/*
** create_pipe.c for  in /home/januar_m/delivery/PSU/PSU_2016_minishell2
** 
** Made by Martin Januario
** Login   <martin.januario@epitech.eu>
** 
** Started on  Mon Apr  3 20:45:23 2017 Martin Januario
** Last update Thu Apr  6 10:57:55 2017 Martin Januario
*/

#include	<sys/types.h>
#include	<sys/wait.h>
#include	<signal.h>
#include	<stdlib.h>
#include	<unistd.h>
#include	"my.h"

int		my_exec_pipe(t_needs *news, t_my_order *my_order)
{
  char		*exec_path;
  int		value_ret;

  if ((value_ret = check_builtins(news, my_order, 0)) != -1)
    exit(value_ret);
  if (my_order->before != NULL && my_strcmp(my_order->oper_b, "|") == 0)
    dup2(my_order->before->pipe[0], 0);
  if (my_order->next != NULL)
    {
      dup2(my_order->pipe[1], 1);
      close(my_order->pipe[0]);
    }
  if ((value_ret = make_exec_path(news, my_order, &exec_path)) > 0)
    return (value_ret);
  if (check_path(exec_path, my_order) == 1)
    exit(1);
  if (exec_path != NULL && execve(exec_path,
				  my_order->order, news->my_env) == -1)
    {
      my_puterror(exec_path);
      my_puterror(": Exec format error. Binary file not executable.");
      exit(1);
    }
  my_free(exec_path);
  return (0);
}

int		wait_son(int *son_uid, t_needs *news,
			 t_my_order *beg, int cpt)
{
  int		status;
  int		idx;

  idx = 0;
  son_uid[cpt] = -1;
  while (son_uid[idx] != -1)
    {
      status = 0;
      if (waitpid(son_uid[idx], &status, 0) == -1)
	kill(son_uid[idx], 0);
      if (!WIFEXITED(status % 255))
	{
	  error_exec(status % 255);
	  if (status > 0 && status < 30)
	    status += 128;
	}
      idx++;
    }
  if (son_uid != NULL)
    free(son_uid);
  if (beg != NULL && beg->order != NULL &&
      my_strcmp(beg->order[0], "cd") == 0)
    status = my_cd(beg, news);
  return (status % 255);
}

int		create_pipe(t_needs *news, t_my_order *my_order)
{
  t_my_order	*beg;
  int		*son_uid;
  int		idx;

  idx = 0;
  if ((son_uid = malloc(sizeof(int) * (nb_pipe(my_order)))) == NULL)
    return (84);
  while (my_order != NULL && (my_strcmp(my_order->oper_n, "|") == 0 ||
			      my_strcmp(my_order->oper_b, "|") == 0))
    {
      if (pipe(my_order->pipe) == -1)
	return (my_puterror("Fail pipe.\n"));
      if ((son_uid[idx] = fork()) < 0)
	return (my_puterror("Fail fork.\n"));
      else if (son_uid[idx] == 0)
	{
	  my_exec_pipe(news, my_order);
	  exit(0);
	}
      else
	{
	  close(my_order->pipe[1]);
	  beg = my_order;
	  idx++;
	  my_order = my_order->next;
	}
    }
  return (wait_son(son_uid, news, beg, idx));
}
