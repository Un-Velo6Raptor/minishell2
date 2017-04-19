/*
** nb_pipe.c for  in /home/januar_m/delivery/PSU/PSU_2016_minishell2
** 
** Made by Martin Januario
** Login   <martin.januario@epitech.eu>
** 
** Started on  Wed Apr  5 16:39:39 2017 Martin Januario
** Last update Wed Apr 19 17:18:18 2017 Martin Januario
*/

#include	<stdlib.h>
#include	"my.h"

int		nb_pipe(t_my_order *my_order)
{
  int		idx;

  idx = 0;
  while (my_order->next != NULL &&
	 my_strcmp(my_order->oper_n, "|") == 0)
    {
      my_order = my_order->next;
      idx++;
    }
  return (idx + 2);
}
