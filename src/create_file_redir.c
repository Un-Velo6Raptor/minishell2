/*
** create_file_redir.c for  in /home/januar_m/delivery/PSU/PSU_2016_minishell2
** 
** Made by Martin Januario
** Login   <martin.januario@epitech.eu>
** 
** Started on  Thu Apr 27 22:44:35 2017 Martin Januario
** Last update Thu Apr 27 22:46:25 2017 Martin Januario
*/

#include	<sys/stat.h>
#include	<unistd.h>
#include	<fcntl.h>
#include	"my.h"

void		create_file_redir(t_my_order *my_order)
{
  if (my_order->next != NULL &&
      my_strcmp(my_order->next->oper_n, ">") == 0)
    {
      my_order->next->fd = open(my_order->next->next->order[0],
				O_CREAT | O_TRUNC | O_RDWR, 0644);
      dup2(my_order->next->fd, 1);
    }
  if (my_order->next != NULL
      && my_strcmp(my_order->next->oper_n, ">>") == 0)
    {
      my_order->next->fd = open(my_order->next->next->order[0], O_CREAT |
				O_APPEND | O_RDWR, 0644);
      dup2(my_order->next->fd, 1);
    }
}
