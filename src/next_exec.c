/*
** next_exec.c for  in /home/januar_m/delivery/PSU/PSU_2016_minishell2
** 
** Made by Martin Januario
** Login   <martin.januario@epitech.eu>
** 
** Started on  Thu Apr 27 14:26:25 2017 Martin Januario
** Last update Thu Apr 27 17:05:24 2017 Martin Januario
*/

#include	<stdlib.h>
#include	<unistd.h>
#include	<sys/types.h>
#include	<fcntl.h>
#include	"my.h"

int		next_exec(t_my_order *my_order)
{
  char		**buffer;

  if (my_strcmp(my_order->oper_n, "<<") == 0)
    {
      if (pipe(my_order->pipe) == -1)
        return (1);
      buffer = make_double_redir_left(my_order);
      dup2(my_order->pipe[0], 0);
      disp_tab_fd(buffer, my_order->pipe[1]);
      free_tab(buffer);
      close(my_order->pipe[1]);
    }
  else if (check_redir_left(my_order) == 1 && my_order->fd != -1)
    dup2(my_order->fd, 0);
  if (my_order->next != NULL &&
      my_strcmp(my_order->next->oper_n, ">>") == 0)
    dup2(my_order->next->fd, 1);
  if (my_order->before != NULL &&
      my_strcmp(my_order->before->oper_b, "<<") == 0 &&
      check_redir_right(my_order->before) == 1)
    dup2(my_order->before->fd, 0);
  return (0);
}
