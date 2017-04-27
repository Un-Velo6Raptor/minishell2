/*
** is_a_redir.c for  in /home/januar_m/delivery/PSU/PSU_2016_minishell2
** 
** Made by Martin Januario
** Login   <martin.januario@epitech.eu>
** 
** Started on  Wed Apr 19 21:22:39 2017 Martin Januario
** Last update Wed Apr 26 19:59:17 2017 Martin Januario
*/

#include	<stdlib.h>
#include	"my.h"

int		is_a_redir(t_my_order *my_order)
{
  int		idx;
  int		redir;

  idx = 0;
  redir = 0;
  if (my_order->order != NULL &&
      (my_strcmp(my_order->order[0], "env") == 0 ||
       my_strcmp(my_order->order[0], "setenv") == 0))
    idx++;
  if (my_order->order != NULL &&
      my_strcmp(my_order->oper_n, ">") == 0)
    redir++;
  return ((redir != 0 && idx != 0) ? 1 : 0);
}

int		got_pipe(t_my_order *my_order)
{
  int		nb;

  nb = 0;
  while (my_order != NULL && my_strcmp(my_order->oper_n, ";") != 0)
    {
      if (my_strcmp(my_order->oper_n, "|") == 0)
	nb = 1;
      my_order = my_order->next;
    }
  return (nb);
}
