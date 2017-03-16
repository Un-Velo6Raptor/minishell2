/*
** my_str_is_num.c for  in /home/januar_m/delivery/PSU/PSU_2016_tetris
** 
** Made by Martin Januario
** Login   <martin.januario@epitech.eu>
** 
** Started on  Thu Mar  2 19:23:51 2017 
** Last update Thu Mar 16 12:50:20 2017 
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
