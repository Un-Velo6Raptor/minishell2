/*
** my_setenv.c for  in /home/januar_m/delivery/PSU/PSU_2016_minishell2
** 
** Made by Martin Januario
** Login   <martin.januario@epitech.eu>
** 
** Started on  Thu Mar 16 13:37:26 2017 
** Last update Thu Mar 16 14:10:05 2017 
*/

#include	<stdlib.h>
#include	"my.h"

int		my_setenv(t_my_order *my_order, t_needs *news)
{
  char		*str;

  if (my_tablen(my_order->order) == 1)
    return (my_env(my_order, news));
  if (my_tablen(my_order->order) > 3)
    {
      my_order->error = 1;
      return (my_puterror("setenv: Expression Syntax.\n"));
    }
  if (my_str_is_alpha(my_order->order[1]) == 84)
    {
      my_order->error = 1;
      my_puterror("setenv: Variable name must contain ");
      return (my_puterror("alphanumeric characters.\n"));
    }
  if (my_car_is_alpha(my_order->order[1][0]) == 84)
    {
      my_order->error = 1;
      my_puterror("setenv: Variable name ");
      return (my_puterror("must begin with a letter.\n"));
    }
  if ((str = make_var_env(my_order->order[1], my_order->order[2])) == NULL)
    return (84);
  printf("str: %s\n", str);
  return (0);
  //  return (add_var_env(news, str));
}