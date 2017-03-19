/*
** exec_the_order.c for  in /home/januar_m/delivery/PSU/PSU_2016_minishell2
** 
** Made by Martin Januario
** Login   <martin.januario@epitech.eu>
** 
** Started on  Wed Mar 15 21:05:39 2017 
** Last update Fri Mar 17 10:55:03 2017 
*/

#include	<stdlib.h>
#include	"my.h"

int		command_not_found(t_my_order *my_order)
{
  my_putstr(my_order->order[0]);
  my_putstr(": Command not found.\n");
  return (0);
}

int		check_builtins(t_needs *news, t_my_order *my_order)
{
  (void) news;
  if (my_order->order == NULL || my_order->order[0] == NULL ||
      my_strlen(my_order->order[0]) == 0)
    return (0);
  if (my_strcmp(my_order->order[0], "exit") == 0)
    return (my_exit(my_order));
  if (my_strcmp(my_order->order[0], "env") == 0)
    return (my_env(my_order, news));
  if (my_strcmp(my_order->order[0], "setenv") == 0)
    return (my_setenv(my_order, news));
  if (my_strcmp(my_order->order[0], "unsetenv") == 0)
    return (my_unsetenv(my_order, news));
  return (command_not_found(my_order));
}

int		exec_the_order(t_needs *news, t_my_order *my_order)
{
  while (my_order != NULL)
    {
      if (check_tild(news, my_order) == MALLOC_FAILED)
	return (84);
      if (check_builtins(news, my_order) == MALLOC_FAILED)
	return (84);
      my_order = my_order->next;
    }
  return (0);
}
