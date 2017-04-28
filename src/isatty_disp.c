/*
** isatty_disp.c for  in /home/januar_m/delivery/PSU/PSU_2016_minishell2/src
** 
** Made by Martin Januario
** Login   <martin.januario@epitech.eu>
** 
** Started on  Sun Apr  9 02:46:54 2017 Martin Januario
** Last update Thu Apr 27 15:49:38 2017 Martin Januario
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
