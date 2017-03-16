/*
** my_env.c for  in /home/januar_m/delivery/PSU/PSU_2016_minishell2
** 
** Made by Martin Januario
** Login   <martin.januario@epitech.eu>
** 
** Started on  Thu Mar 16 13:13:11 2017 
** Last update Thu Mar 16 13:25:49 2017 
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
