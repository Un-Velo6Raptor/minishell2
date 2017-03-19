/*
** free_list_order.c for  in /home/januar_m/delivery/PSU/PSU_2016_minishell2
** 
** Made by Martin Januario
** Login   <martin.januario@epitech.eu>
** 
** Started on  Wed Mar 15 19:29:55 2017 
** Last update Fri Mar 17 13:07:41 2017 
*/

#include	<stdlib.h>
#include	"my.h"

int		free_list_order(t_my_order *my_order)
{
  if (my_order == NULL)
    return (0);
  while (my_order->next != NULL)
    my_order = my_order->next;
  while (my_order->before != NULL)
    {
      free_tab(my_order->order);
      my_free(my_order->oper_b);
      my_order = my_order->before;
      if (my_order->next != NULL)
	free(my_order->next);
    }
  if (my_order != NULL)
    {
      free_tab(my_order->order);
      free(my_order);
    }
  return (0);
}
