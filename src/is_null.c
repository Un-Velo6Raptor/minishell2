/*
** is_null.c for  in /home/januar_m/delivery/PSU/PSU_2016_minishell2
** 
** Made by Martin Januario
** Login   <martin.januario@epitech.eu>
** 
** Started on  Wed Apr 26 15:59:37 2017 Martin Januario
** Last update Wed Apr 26 15:59:58 2017 Martin Januario
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
