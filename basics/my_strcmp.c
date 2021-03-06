/*
** my_strcmp.c for  in /home/januar_m/delivery/PSU/PSU_2016_minishell2/basics
** 
** Made by Martin Januario
** Login   <martin.januario@epitech.eu>
** 
** Started on  Sun Apr  9 02:25:15 2017 Martin Januario
** Last update Sun Apr  9 02:25:16 2017 Martin Januario
*/

#include	"my.h"

int		my_strcmp(char *s1, char *s2)
{
  int		idx;
  int		len1;
  int		len2;

  idx = 0;
  if (s1 == NULL && s2 == NULL)
    return (0);
  if (s1 == NULL || s2 == NULL)
    return (1);
  len1 = my_strlen(s1);
  len2 = my_strlen(s2);
  while (idx <= len1 && idx <= len2 && s1[idx] != '\0' && s2[idx] != '\0')
    {
      if (s1[idx] > s2[idx])
	return (1);
      if (s1[idx] < s2[idx])
	return (-1);
      idx++;
    }
  if (len1 > len2)
    return (1);
  if (len1 < len2)
    return (-1);
  return (0);
}
