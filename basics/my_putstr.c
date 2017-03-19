/*
** my_putstr.c for  in /home/januar_m/delivery/PSU/PSU_2016_minishell2
** 
** Made by Martin Januario
** Login   <martin.januario@epitech.eu>
** 
** Started on  Tue Mar 14 12:56:39 2017 
** Last update Sun Mar 19 23:14:43 2017 
*/

#include	<unistd.h>
#include	"my.h"

int		my_putstr(char *str)
{
  write(1, str, my_strlen(str));
  return (0);
}

int		my_puterror(char *str)
{
  write(2, str, my_strlen(str));
  return (1);
}
