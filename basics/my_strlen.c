/*
** my_strlen.c for  in /home/januar_m/delivery/PSU/PSU_2016_minishell2
** 
** Made by Martin Januario
** Login   <martin.januario@epitech.eu>
** 
** Started on  Tue Mar 14 12:55:52 2017 
** Last update Thu Mar 16 14:11:09 2017 
*/

#include	<stdlib.h>

int		my_strlen(char *str)
{
  int		idx;

  idx = 0;
  if (str == NULL)
    return (0);
  while (str[idx] != '\0')
    idx++;
  return (idx);
}
