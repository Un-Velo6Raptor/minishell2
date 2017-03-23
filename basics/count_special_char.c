/*
** count_special_char.c for  in /home/januar_m/delivery/PSU/PSU_2016_minishell2
** 
** Made by Martin Januario
** Login   <martin.januario@epitech.eu>
** 
** Started on  Thu Mar 23 01:12:50 2017 
** Last update Thu Mar 23 01:17:19 2017 
*/

#include	<stdlib.h>
#include	"my.h"

int		count_spe_char(char *str, char car)
{
  int		idx;
  int		result;

  idx = 0;
  result = 0;
  if (str == NULL)
    return (0);
  while (str[idx] != '\0')
    {
      if (str[idx] == car)
	result++;
      idx++;
    }
  return (result);
}
