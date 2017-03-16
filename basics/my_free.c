/*
** my_free.c for  in /home/januar_m/delivery/PSU/PSU_2016_minishell2
** 
** Made by Martin Januario
** Login   <martin.januario@epitech.eu>
** 
** Started on  Tue Mar 14 14:48:15 2017 
** Last update Tue Mar 14 14:48:44 2017 
*/

#include	<stdlib.h>

void		my_free(char *str)
{
  if (str != NULL)
    free(str);
}
