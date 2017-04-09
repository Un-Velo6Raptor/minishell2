/*
** my_strcpy.c for  in /home/januar_m/delivery/PSU/PSU_2016_minishell2/basics
** 
** Made by Martin Januario
** Login   <martin.januario@epitech.eu>
** 
** Started on  Sun Apr  9 02:40:31 2017 Martin Januario
** Last update Sun Apr  9 02:40:32 2017 Martin Januario
*/

#include	"my.h"

char		*my_strcpy(char *dest, char *src)
{
  int		idx;

  idx = 0;
  while (src[idx] != '\0')
    {
      dest[idx] = src[idx];
      idx++;
    }
  dest[idx] = '\0';
  return (dest);
}
