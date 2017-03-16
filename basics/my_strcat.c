/*
** my_strcat.c for  in /home/januar_m/delivery/PSU/PSU_2016_tetris
** 
** Made by Martin Januario
** Login   <martin.januario@epitech.eu>
** 
** Started on  Mon Feb 27 16:39:37 2017 
** Last update Thu Mar 16 14:08:53 2017 
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
