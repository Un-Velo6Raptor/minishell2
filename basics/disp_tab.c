/*
** disp_tab.c for  in /home/januar_m/delivery/PSU/PSU_2016_minishell2
** 
** Made by Martin Januario
** Login   <martin.januario@epitech.eu>
** 
** Started on  Tue Mar 14 13:25:27 2017 
** Last update Tue Mar 14 13:26:40 2017 
*/

#include	<stdlib.h>
#include	"my.h"

void		disp_tab(char **tab)
{
  int		idx;

  idx = 0;
  while (tab != NULL && tab[idx] != NULL)
    {
      my_putstr(tab[idx]);
      my_putstr("\n");
      idx++;
    }
}
