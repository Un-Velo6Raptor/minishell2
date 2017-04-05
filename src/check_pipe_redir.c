
/*
** check_pipe_redir.c for  in /home/januar_m/delivery/PSU/PSU_2016_minishell2
** 
** Made by Martin Januario
** Login   <martin.januario@epitech.eu>
** 
** Started on  Wed Apr  5 16:47:27 2017 Martin Januario
** Last update Wed Apr  5 17:22:22 2017 Martin Januario
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

int		check_pipe_redir(t_my_order *my_order)
{
  while (my_order->next != NULL)
    {
      if (my_strcmp(my_order->oper_n, "|") == 0 &&
	  (order_null(my_order) == 84 ||
	   my_order->next == NULL || my_order->next->order == NULL ||
	   my_order->next->order[0] == NULL))
	return (my_puterror("Invalid null command.\n")); 
      if ((my_strcmp(my_order->oper_n, ">") == 0 ||
	   my_strcmp(my_order->oper_n, ">>") == 0) &&
	  (order_null(my_order) == 84 ||
	   my_order->next == NULL || my_order->next->order == NULL ||
	   my_order->next->order[0] == NULL))
	return (my_puterror("Missing name for redirect.\n"));
      if ((my_strcmp(my_order->oper_n, "<") == 0 ||
	   my_strcmp(my_order->oper_n, "<<") == 0) &&
	  (order_null(my_order) == 84 ||
	   my_order->next == NULL || my_order->next->order == NULL ||
	   my_order->next->order[0] == NULL))
	return (my_puterror("Missing name for redirect.\n"));
      my_order = my_order->next;
    }
  return (0);
}
