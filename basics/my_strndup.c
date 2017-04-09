/*
** my_strndup.c for  in /home/januar_m/delivery/PSU/PSU_2016_minishell2/basics
** 
** Made by Martin Januario
** Login   <martin.januario@epitech.eu>
** 
** Started on  Sun Apr  9 02:38:59 2017 Martin Januario
** Last update Sun Apr  9 02:39:01 2017 Martin Januario
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
