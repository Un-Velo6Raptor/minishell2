/*
** exec_the_order.c for  in /home/januar_m/delivery/PSU/PSU_2016_minishell2
** 
** Made by Martin Januario
** Login   <martin.januario@epitech.eu>
** 
** Started on  Wed Mar 15 21:05:39 2017 
** Last update Thu Apr  6 11:00:03 2017 Martin Januario
*/

#include	<stdlib.h>
#include	"my.h"

int		command_not_found(t_my_order *my_order)
{
  my_puterror(my_order->order[0]);
  my_puterror(": Command not found.\n");
  return (1);
}

int		check_builtins_next(t_needs *news,
				    t_my_order *my_order, int opt)
{
  char		*exec_path;
  int		value_ret;

  exec_path = NULL;
  value_ret = 0;
  if (my_strcmp(my_order->order[0], "unsetenv") == 0)
    return (my_unsetenv(my_order, news));
  if (my_strcmp(my_order->order[0], "cd") == 0)
    return (my_cd(my_order, news));
  if (opt != 0)
    {
      if ((value_ret = make_exec_path(news, my_order, &exec_path)) > 0)
	return (value_ret);
      value_ret = my_exec(news, my_order, exec_path);
      my_free(exec_path);
      return (value_ret);
    }
  return (-1);
}

int		check_builtins(t_needs *news, t_my_order *my_order, int opt)
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
  return (check_builtins_next(news, my_order, opt));
}

int		exec_the_order(t_needs *news, t_my_order *my_order)
{
  int		nb;

  nb = 0;
  if (check_pipe_redir(my_order) == 1)
    return (1);
  if (my_order_for_redir(my_order) == 84)
    return (84);
  //  disp_list_order(my_order);
  while (my_order != NULL)
    {
      if (check_tild(news, my_order) == MALLOC_FAILED)
	return (84);
      if (my_order->next != NULL && my_strcmp(my_order->oper_n, "|") == 0)
	{
	  nb = create_pipe(news, my_order);
	  while (my_order->next != NULL &&
		 my_strcmp(my_order->oper_n, "|") == 0)
	    my_order = my_order->next;
	}
      else if ((nb = check_builtins(news, my_order, 1)) == MALLOC_FAILED)
	return (84);
      my_order = my_order->next;
    }
  return (nb);
}
