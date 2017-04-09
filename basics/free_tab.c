/*
** free_tab.c for  in /home/januar_m/delivery/PSU/PSU_2016_minishell2/basics
** 
** Made by Martin Januario
** Login   <martin.januario@epitech.eu>
** 
** Started on  Sun Apr  9 02:40:56 2017 Martin Januario
** Last update Sun Apr  9 02:40:58 2017 Martin Januario
*/

#include	<stdlib.h>
#include	"my.h"

int		free_tab(char **tab)
{
  int		idx;

  idx = 0;
  if (tab == NULL)
    return (0);
  while (tab[idx] != NULL)
    {
      my_free(tab[idx]);
      idx++;
    }
  if (tab != NULL)
    free(tab);
  return (0);
}
