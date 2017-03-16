/*
** my_strdup.c for  in /home/januar_m/delivery/PSU/PSU_2016_tetris
** 
** Made by Martin Januario
** Login   <martin.januario@epitech.eu>
** 
** Started on  Mon Feb 27 14:44:41 2017 
** Last update Tue Mar 14 21:11:33 2017 
*/

#include	<stdlib.h>
#include	"my.h"

char	*my_strndup(char *src, int nb)
{
  char	*str;

  if (src == NULL)
    return (NULL);
  if ((str = malloc(sizeof(char) * (my_strlen(src) + 1))) == 0)
    return (NULL);
  my_strncpy(str, src, nb);
  return (str);
}
