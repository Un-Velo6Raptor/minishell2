/*
** my_strncmp.c for  in /home/januar_m/delivery/PSU/PSU_2016_minishell2
** 
** Made by Martin Januario
** Login   <martin.januario@epitech.eu>
** 
** Started on  Tue Mar 14 17:54:33 2017 
** Last update Tue Mar 14 17:59:13 2017 
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
