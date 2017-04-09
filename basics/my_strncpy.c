/*
** my_strncpy.c for  in /home/januar_m/delivery/PSU/PSU_2016_minishell2/basics
** 
** Made by Martin Januario
** Login   <martin.januario@epitech.eu>
** 
** Started on  Sun Apr  9 02:24:12 2017 Martin Januario
** Last update Sun Apr  9 02:24:13 2017 Martin Januario
*/

#include	"my.h"

char		*my_strncpy(char *dest, char *src, int n)
{
  int		idx;

  idx = 0;
  if (n < 0)
    return (0);
  while (idx < n)
    {
      dest[idx] = src[idx];
      idx++;
    }
  dest[idx] = '\0';
  return (dest);
}
