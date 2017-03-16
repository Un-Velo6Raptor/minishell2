/*
** my_tablen.c for  in /home/januar_m/delivery/PSU/PSU_2016_minishell2
** 
** Made by Martin Januario
** Login   <martin.januario@epitech.eu>
** 
** Started on  Tue Mar 14 13:16:41 2017 
** Last update Tue Mar 14 13:17:30 2017 
*/

#include	<stdlib.h>

int		my_tablen(char **tab)
{
  int		idx;

  idx = 0;
  if (tab == NULL)
    return (0);
  while (tab[idx] != NULL)
    idx++;
  return (idx);
}
