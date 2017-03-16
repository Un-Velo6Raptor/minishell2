/*
** my_str_is_alpha.c for  in /home/januar_m/delivery/PSU/PSU_2016_minishell2
** 
** Made by Martin Januario
** Login   <martin.januario@epitech.eu>
** 
** Started on  Thu Mar 16 13:44:20 2017 
** Last update Thu Mar 16 13:55:25 2017 
*/

#include	<stdlib.h>
#include	"my.h"

int		my_car_is_alpha(char car)
{
  if (car == '_' || (car >= 'a' && car <= 'z') ||
      (car >= 'A' && car <= 'Z'))
    return (0);
  return (84);
}

int		my_car_is_alphan(char car)
{
  if (car == '_' || (car >= 'a' && car <= 'z') ||
      (car >= 'A' && car <= 'Z') || (car >= '0' && car <= '9'))
    return (0);
  return (84);
}

int		my_str_is_alpha(char *str)
{
  int		idx;

  idx = 0;
  while (str[idx] != '\0')
    {
      if (my_car_is_alphan(str[idx]) == 84)
	return (84);
      idx++;
    }
  return (0);
}
