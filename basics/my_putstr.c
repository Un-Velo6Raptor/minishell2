/*
** my_putstr.c for  in /home/januar_m/delivery/PSU/PSU_2016_minishell2/basics
** 
** Made by Martin Januario
** Login   <martin.januario@epitech.eu>
** 
** Started on  Sun Apr  9 02:41:05 2017 Martin Januario
** Last update Fri Apr 21 06:39:42 2017 Martin Januario
*/

#include	<unistd.h>
#include	"my.h"

int		my_putstr(char *str)
{
  if (str != NULL)
    write(1, str, my_strlen(str));
  return (0);
}

int		my_puterror(char *str)
{
  if (str != NULL)
    write(2, str, my_strlen(str));
  return (1);
}
