/*
** check_all.c for  in /home/januar_m/delivery/PSU/PSU_2016_minishell2
** 
** Made by Martin Januario
** Login   <martin.januario@epitech.eu>
** 
** Started on  Tue Apr 25 20:21:30 2017 Martin Januario
** Last update Tue Apr 25 20:34:47 2017 Martin Januario
*/

#include	"my.h"

int		is_null(t_my_order *my_order)
{
  if (my_order == NULL || my_order->order == NULL ||
      my_strlen(my_order->order[0]) == 0)
      return (1);
  return (0);
}

int		check_redir_right(t_my_order *my_order)
{
  if (my_order == NULL)
    return (0);
  if (my_strcmp(my_order->oper_n, ">") == 0 ||
      my_strcmp(my_order->oper_n, ">>") == 0)
    return (1);
  return (0);
}

int		check_redir_left(t_my_order *my_order)
{
  if (my_order == NULL)
    return (0);
  if (my_strcmp(my_order->oper_n, "<") == 0 ||
      my_strcmp(my_order->oper_n, "<<") == 0)
    return (1);
  return (0);
}

int		check_pipe(t_my_order *my_order)
{
  if (my_order == NULL)
    return (0);
  if (my_strcmp(my_order->oper_n, "|") == 0)
    return (1);
  return (0);
}
