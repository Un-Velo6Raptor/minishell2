/*
** my_env.c for  in /home/januar_m/delivery/PSU/PSU_2016_minishell2/builtins
** 
** Made by Martin Januario
** Login   <martin.januario@epitech.eu>
** 
** Started on  Sun Apr  9 02:09:42 2017 Martin Januario
** Last update Sun Apr  9 02:09:44 2017 Martin Januario
*/

#include	<stdlib.h>
#include	"my.h"

int		my_env(t_my_order *my_order, t_needs *news)
{
  if (my_tablen(my_order->order) != 1)
    {
      my_order->error = 1;
      return (my_puterror("env: Expression Syntax.\n"));
    }
  disp_tab(news->my_env);
  return (0);
}
