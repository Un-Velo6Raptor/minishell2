/*
** check_pipe_redir.c for  in /home/januar_m/delivery/PSU/PSU_2016_minishell2
** 
** Made by Martin Januario
** Login   <martin.januario@epitech.eu>
** 
** Started on  Wed Apr  5 16:47:27 2017 Martin Januario
** Last update Tue Apr 25 20:43:57 2017 Martin Januario
*/

#include	"my.h"

int		order_null(t_my_order *my_order)
{
  if (my_order->order == NULL || my_order->order[0] == NULL)
    return (84);
  if (my_strlen(my_order->order[0]) == 0)
    return (84);
  return (0);
}

int		check_separator(t_my_order *my_order)
{
  if (my_order->oper_n == NULL)
    return (-1);
  if (my_strcmp(my_order->oper_n, ">") == 0 ||
      my_strcmp(my_order->oper_n, ">>") == 0)
    return (REDIR_RIGHT);
  if (my_strcmp(my_order->oper_n, "<") == 0 ||
      my_strcmp(my_order->oper_n, "<<") == 0)
    return (REDIR_LEFT);
  if (my_strcmp(my_order->oper_n, "|") == 0)
    return (PIPE);
  return (-1);
}

int		c_redir_left(t_my_order *my_order)
{
  if (is_null(my_order) == 1)
    return (my_puterror("Invalid null command.\n"));
  if (is_null(my_order->next) == 1)
    return (my_puterror("Missing name for redirect.\n"));
  if (check_redir_left(my_order->next) == 1)
    return (my_puterror("Ambiguous input redirect.\n"));  
  return (0);
}

int		c_redir_right(t_my_order *my_order)
{
  if (is_null(my_order) == 1)
    return (my_puterror("Invalid null command.\n"));
  if (is_null(my_order->next) == 1)
    return (my_puterror("Missing name for redirect.\n"));
  if (check_redir_right(my_order->next) == 1)
    return (my_puterror("Ambiguous output redirect.\n"));
  if (check_redir_left(my_order->next) == 1)
    return (my_puterror("Ambiguous output redirect.\n"));  
  return (0);
}

int		c_pipe(t_my_order *my_order)
{
  if (is_null(my_order) == 1 || is_null(my_order->next) == 1)
    return (my_puterror("Invalid null command.\n"));
  if (check_redir_right(my_order->before) == 1)
    return (my_puterror("Ambiguous output redirect.\n"));
  if (check_redir_left(my_order->next) == 1)
    return (my_puterror("Ambiguous input redirect.\n"));
  return (0);
}

int		check_pipe_redir(t_my_order *my_order)
{
  int		(*franklin[3])(t_my_order *) = {c_pipe, c_redir_left, c_redir_right};
  int		nb;

  while (my_order != NULL)
    {
      nb = check_separator(my_order);
      if (nb != -1 && franklin[nb](my_order) == 1)
	return (1);
      my_order = my_order->next;
    }
  return (0);
}
