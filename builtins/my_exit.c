/*
** my_exit.c for  in /home/januar_m/delivery/PSU/PSU_2016_minishell2/builtins
** 
** Made by Martin Januario
** Login   <martin.januario@epitech.eu>
** 
** Started on  Sun Apr  9 02:08:36 2017 Martin Januario
** Last update Sun Apr  9 02:08:37 2017 Martin Januario
*/

#include	<stdlib.h>
#include	"my.h"

void		exec_exit(int nb)
{
  my_putstr("exit\n");
  exit(nb);
}

int		my_exit(t_my_order *my_order)
{
  int		nb;

  nb = 0;
  if (my_tablen(my_order->order) == 1)
    exec_exit(0);
  if (my_tablen(my_order->order) != 2 ||
      my_str_is_num(my_order->order[1]) == 84)
    {
      my_order->error = 1;
      return (my_puterror("exit: Expression Syntax.\n"));
    }
  nb = my_getnbr(my_order->order[1]) % 256;
  exec_exit(nb);
  return (0);
}
