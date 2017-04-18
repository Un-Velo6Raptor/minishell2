/*
** command_not_found.c for  in /home/januar_m/delivery/PSU/PSU_2016_minishell2
** 
** Made by Martin Januario
** Login   <martin.januario@epitech.eu>
** 
** Started on  Tue Apr 18 17:07:49 2017 Martin Januario
** Last update Tue Apr 18 17:08:07 2017 Martin Januario
*/

#include	"my.h"

int		command_not_found(t_my_order *my_order)
{
  my_puterror(my_order->order[0]);
  my_puterror(": Command not found.\n");
  return (1);
}
