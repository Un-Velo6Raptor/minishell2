/*
** found_var.c for  in /home/januar_m/delivery/PSU/PSU_2016_minishell2/src
** 
** Made by Martin Januario
** Login   <martin.januario@epitech.eu>
** 
** Started on  Sun Apr  9 02:46:43 2017 Martin Januario
** Last update Sun Apr  9 02:46:45 2017 Martin Januario
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
