/*
** my_str_is_alpha.c for  in /home/januar_m/delivery/PSU/PSU_2016_minishell2/basics
** 
** Made by Martin Januario
** Login   <martin.januario@epitech.eu>
** 
** Started on  Sun Apr  9 02:23:56 2017 Martin Januario
** Last update Sun Apr  9 02:24:00 2017 Martin Januario
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
