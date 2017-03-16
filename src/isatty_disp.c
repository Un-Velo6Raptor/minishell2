/*
** isatty_disp.c for  in /home/januar_m/delivery/PSU/PSU_2016_minishell2
** 
** Made by Martin Januario
** Login   <martin.januario@epitech.eu>
** 
** Started on  Tue Mar 14 16:03:45 2017 
** Last update Thu Mar 16 13:59:00 2017 
*/

#include	<stdlib.h>
#include	<unistd.h>
#include	"my.h"

void		isatty_disp(t_needs *news)
{
  if (isatty(0) == 1)
    {
      my_putstr("\033[31m");
      my_putstr(news->pwd);
      my_putstr(" --> ");
      my_putstr("\033[00m");
    }
}
