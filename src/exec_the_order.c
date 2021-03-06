/*
** exec_the_order.c for  in /home/januar_m/delivery/PSU/PSU_2016_minishell2/src
** 
** Made by Martin Januario
** Login   <martin.januario@epitech.eu>
** 
** Started on  Sun Apr  9 02:45:52 2017 Martin Januario
** Last update Fri Apr 28 13:17:37 2017 Martin Januario
*/

#include	<stdlib.h>
#include	"my.h"

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
  if (is_null(my_order))
    return (0);
  if (my_strcmp(my_order->order[0], "exit") == 0)
    return (my_exit(my_order));
  if (my_strcmp(my_order->order[0], "env") == 0)
    return (my_env(my_order, news));
  if (my_strcmp(my_order->order[0], "setenv") == 0)
    return (my_setenv(my_order, news));
  return (check_builtins_next(news, my_order, opt));
}

void		pass_to_the_next_command(t_my_order **my_order)
{
  while ((*my_order)->next != NULL &&
	 my_strcmp((*my_order)->oper_n, ";") != 0)
    *my_order = (*my_order)->next;
  *my_order =(*my_order)->next;
}

int		exec_the_order(t_needs *news, t_my_order *my_order, char *tmp)
{
  int		nb;

  nb = 0;
  if (my_order_for_redir(my_order) == 84)
    return (84);
  if (check_pipe_redir(my_order) == 1)
    return (1);
  if (without_space(my_order->order[0]) == 0 && without_space(tmp) != 0 &&
      my_order->oper_b == NULL && my_order->oper_n == NULL)
    return (command_not_found(my_order));
  while (my_order != NULL)
    {
      if (check_tild(news, my_order) == MALLOC_FAILED)
	return (84);
      if ((my_order->next != NULL && my_strcmp(my_order->oper_n, "|") == 0) ||
	  is_a_redir(my_order) == 1 || (my_order->next != NULL &&
	   my_strcmp(my_order->next->oper_n, "|") == 0 &&
	   my_strcmp(my_order->oper_n, "<") == 0))
	nb = create_pipe(news, my_order);
      else if ((nb = check_builtins(news, my_order, 1)) == MALLOC_FAILED)
	return (84);
      pass_to_the_next_command(&my_order);
    }
  return (nb);
}
