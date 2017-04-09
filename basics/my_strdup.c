/*
** my_strdup.c for  in /home/januar_m/delivery/PSU/PSU_2016_minishell2/basics
** 
** Made by Martin Januario
** Login   <martin.januario@epitech.eu>
** 
** Started on  Sun Apr  9 02:41:14 2017 Martin Januario
** Last update Sun Apr  9 02:41:16 2017 Martin Januario
*/

#include	<stdlib.h>
#include	"my.h"

char	*my_strdup(char *src)
{
  char	*str;

  if (src == NULL)
    return (NULL);
  if ((str = malloc(sizeof(char) * my_strlen(src) + 1)) == 0)
    return (NULL);
  my_strcpy(str, src);
  return (str);
}
