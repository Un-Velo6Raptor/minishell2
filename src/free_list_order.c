/*
** free_list_order.c for  in /home/januar_m/delivery/PSU/PSU_2016_minishell2/src
** 
** Made by Martin Januario
** Login   <martin.januario@epitech.eu>
** 
** Started on  Sun Apr  9 02:47:35 2017 Martin Januario
** Last update Sun Apr  9 02:47:37 2017 Martin Januario
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
