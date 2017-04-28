/*
** right_pipe_redir.c for  in /home/januar_m/delivery/PSU/PSU_2016_minishell2
** 
** Made by Martin Januario
** Login   <martin.januario@epitech.eu>
** 
** Started on  Thu Apr 27 15:20:37 2017 Martin Januario
** Last update Thu Apr 27 16:21:29 2017 Martin Januario
*/

#include	<fcntl.h>
#include	<stdlib.h>
#include	<sys/stat.h>
#include	<signal.h>
#include	<unistd.h>
#include	"my.h"

int		right_pipe_redir(t_my_order *my_order)
{
  if (redir_error(my_order->next->order[0], 0) == 1)
    return (1);
  if (my_strcmp(my_order->oper_n, ">") == 0)
    my_order->fd = open(my_order->next->order[0],
			O_CREAT | O_TRUNC | O_RDWR, 0644);
  else if (my_strcmp(my_order->oper_n, ">>") == 0)
    my_order->fd = open(my_order->next->order[0], O_CREAT |
			O_APPEND | O_RDWR, 0644);
  if (my_order->fd == -1)
    exit(1);
  dup2(my_order->fd, 1);
  return (0);
}
