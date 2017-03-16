/*
** disp_list_order.c for  in /home/januar_m/delivery/PSU/PSU_2016_minishell2
** 
** Made by Martin Januario
** Login   <martin.januario@epitech.eu>
** 
** Started on  Wed Mar 15 17:55:37 2017 
** Last update Wed Mar 15 18:37:39 2017 
*/

#include	<stdio.h>
#include	<stdlib.h>
#include	"my.h"

void		disp_list_order(t_my_order *my_order)
{
  while (my_order != NULL)
    {
      printf("---------------------\nOper before : %s\n", my_order->oper_b);
      printf("Oper next : %s\n", my_order->oper_n);
      printf("---- ORDER ----\n");
      disp_tab(my_order->order);
      my_order = my_order->next;
    }
}
