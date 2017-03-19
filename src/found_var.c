/*
** found_var.c for  in /home/januar_m/delivery/PSU/PSU_2016_minishell2
** 
** Made by Martin Januario
** Login   <martin.januario@epitech.eu>
** 
** Started on  Tue Mar 14 14:18:49 2017 
** Last update Sun Mar 19 18:47:15 2017 
*/

#include	<stdlib.h>
#include	"my.h"

int		found_var(char **tab, char *str)
{
  int		idx;

  idx = 0;
  if (tab == NULL)
    return (-1);
  while (tab[idx] != NULL)
    {
      if (match(tab[idx], str) == 1)
	return (idx);
      idx++;
    }
  return (-1);
}
