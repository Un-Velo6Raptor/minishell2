/*
** my_tablen.c for  in /home/januar_m/delivery/PSU/PSU_2016_minishell2/basics
** 
** Made by Martin Januario
** Login   <martin.januario@epitech.eu>
** 
** Started on  Sun Apr  9 02:24:20 2017 Martin Januario
** Last update Sun Apr  9 02:24:21 2017 Martin Januario
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
