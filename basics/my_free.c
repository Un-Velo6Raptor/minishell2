/*
** my_free.c for  in /home/januar_m/delivery/PSU/PSU_2016_minishell2/basics
** 
** Made by Martin Januario
** Login   <martin.januario@epitech.eu>
** 
** Started on  Sun Apr  9 02:25:01 2017 Martin Januario
** Last update Sun Apr  9 02:25:04 2017 Martin Januario
*/

#include	<stdlib.h>

void		my_free(char *str)
{
  if (str != NULL)
    free(str);
}
