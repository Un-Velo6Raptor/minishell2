/*
** disp_tab.c for  in /home/januar_m/delivery/PSU/PSU_2016_minishell2/basics
** 
** Made by Martin Januario
** Login   <martin.januario@epitech.eu>
** 
** Started on  Sun Apr  9 02:40:01 2017 Martin Januario
** Last update Sun Apr  9 02:40:02 2017 Martin Januario
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
