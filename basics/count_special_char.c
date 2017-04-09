/*
** count_special_char.c for  in /home/januar_m/delivery/PSU/PSU_2016_minishell2/basics
** 
** Made by Martin Januario
** Login   <martin.januario@epitech.eu>
** 
** Started on  Sun Apr  9 02:13:14 2017 Martin Januario
** Last update Sun Apr  9 02:23:08 2017 Martin Januario
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
