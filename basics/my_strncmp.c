/*
** my_strncmp.c for  in /home/januar_m/delivery/PSU/PSU_2016_minishell2/basics
** 
** Made by Martin Januario
** Login   <martin.januario@epitech.eu>
** 
** Started on  Sun Apr  9 02:41:26 2017 Martin Januario
** Last update Sun Apr  9 02:41:28 2017 Martin Januario
*/

#include	"my.h"

int		my_strncmp(char *s1, char *s2, int n)
{
  int		idx;

  idx = 0;
  while (s1[idx] != '\0' && s2[idx] != '\0' && idx < n)
    {
      if (s1[idx] != s2[idx])
	return (1);
      idx++;
    }
  if (n == idx)
    return (0);
  if (my_strlen(s1) != my_strlen(s2))
    return (1);
  return (0);
}
