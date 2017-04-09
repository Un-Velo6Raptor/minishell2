/*
** my_strcat.c for  in /home/januar_m/delivery/PSU/PSU_2016_minishell2/basics
** 
** Made by Martin Januario
** Login   <martin.januario@epitech.eu>
** 
** Started on  Sun Apr  9 02:23:28 2017 Martin Januario
** Last update Sun Apr  9 02:23:40 2017 Martin Januario
*/

#include	"my.h"

char		*my_strcat(char *dest, char *src)
{
  int		dest_len;
  int		i;

  i = 0;
  dest_len = my_strlen(dest);
  while (src[i] != '\0')
    {
      dest[dest_len + i] = src[i];
      i++;
    }
  dest[dest_len + i] = '\0';
  return (dest);
}
