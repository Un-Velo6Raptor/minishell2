/*
** my_str_is_num.c for  in /home/januar_m/delivery/PSU/PSU_2016_minishell2/basics
** 
** Made by Martin Januario
** Login   <martin.januario@epitech.eu>
** 
** Started on  Sun Apr  9 02:38:48 2017 Martin Januario
** Last update Sun Apr  9 02:38:49 2017 Martin Januario
*/

#include	<stdlib.h>
#include	"my.h"

int		skip_neg(char *str)
{
  int		idx;

  idx = 0;
  while (str[idx] != '\0' && (str[idx] == '-' ||
			      str[idx] == '+'))
    idx++;
  return (idx);
}

int		my_str_is_num(char *str)
{
  int		idx;

  idx = skip_neg(str);
  if (str[idx] == '\0')
    return (84);
  while (str[idx] != '\0')
    {
      if (str[idx] < '0' || str[idx] > '9')
	return (84);
      idx++;
    }
  return (0);
}
