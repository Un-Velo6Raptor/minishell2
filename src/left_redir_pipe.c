/*
** left_redir_pipe.c for  in /home/januar_m/delivery/PSU/PSU_2016_minishell2
** 
** Made by Martin Januario
** Login   <martin.januario@epitech.eu>
** 
** Started on  Wed Apr 19 15:07:25 2017 Martin Januario
** Last update Wed Apr 26 23:26:18 2017 Martin Januario
*/

#include	<stdlib.h>
#include	<sys/types.h>
#include	<sys/stat.h>
#include	<signal.h>
#include	<unistd.h>
#include	<fcntl.h>
#include	"my.h"

int		left_redir_pipe(t_my_order *my_order)
{
  if (my_strcmp(my_order->oper_n, "<") == 0)
    {
      if (redir_error(my_order->next->order[0]) == 1)
	exit(1);
      my_order->fd = open(my_order->next->order[0], O_RDONLY);
      if (my_strcmp(my_order->oper_n, "<") == 0 && my_order->fd != -1)
	dup2(my_order->fd, 0);
    }
  if (my_strcmp(my_order->oper_b, "|") == 0 &&
      my_strcmp(my_order->before->oper_b, "<") == 0)
    dup2(my_order->before->before->pipe[0], 0);
  return (0);
}
