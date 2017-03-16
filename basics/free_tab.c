/*
** free_tab.c for  in /home/januar_m/delivery/PSU/PSU_2016_minishell2
** 
** Made by Martin Januario
** Login   <martin.januario@epitech.eu>
** 
** Started on  Tue Mar 14 13:22:43 2017 
** Last update Wed Mar 15 19:39:50 2017 
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
