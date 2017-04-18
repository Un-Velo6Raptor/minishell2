/*
** disp_list_order.c for  in /home/januar_m/delivery/PSU/PSU_2016_minishell2
** 
** Made by Martin Januario
** Login   <martin.januario@epitech.eu>
** 
** Started on  Wed Mar 15 17:55:37 2017 
** Last update Fri Apr 14 15:27:12 2017 Martin Januario
*/

#include	<stdio.h>
#include	<stdlib.h>
#include	"my.h"

void		disp_list_order(t_my_order *my_order)
{
  while (my_order != NULL)
    {
      my_putstr("---------------------\nOper before : ");
      my_putstr(my_order->oper_b);
      my_putstr("\nOper next : ");
      my_putstr(my_order->oper_n);
      my_putstr("\n---- ORDER ----\n");
      disp_tab(my_order->order);
      my_order = my_order->next;
    }
  my_putstr("---- END ----\n");
}
