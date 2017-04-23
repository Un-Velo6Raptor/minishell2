/*
** without_space.c for  in /home/januar_m/delivery/PSU/PSU_2016_minishell2
** 
** Made by Martin Januario
** Login   <martin.januario@epitech.eu>
** 
** Started on  Fri Apr 21 16:39:00 2017 Martin Januario
** Last update Fri Apr 21 16:42:58 2017 Martin Januario
*/

#include	"my.h"

int			without_space(char *str)
{
  int		idx;
  int		nb;

  idx = 0;
  nb = 0;
  if (str == NULL)
    return (0);
  while (str[idx] != '\0')
    {
      if (str[idx] != ' ' && str[idx] != '\t')
	nb++;
      idx++;
    }
  return (nb);
}
