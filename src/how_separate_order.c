/*
** how_separate_order.c for  in /home/januar_m/delivery/PSU/PSU_2016_minishell2/src
** 
** Made by Martin Januario
** Login   <martin.januario@epitech.eu>
** 
** Started on  Sun Apr  9 02:45:13 2017 Martin Januario
** Last update Mon Apr 24 15:12:21 2017 Martin Januario
*/

#include	"my.h"

//Faire mes maccros
int		separator_or(char *str)
{
  if (my_strncmp(str, "|", 1) == 0)
    return (2);
  if (my_strncmp(str, ">>", 2) == 0)
    return (3);
  if (my_strncmp(str, ">", 1) == 0)
    return (4);
  if (my_strncmp(str, "<<", 2) == 0)
    return (5);
  if (my_strncmp(str, "<", 1) == 0)
    return (6);
  if (my_strncmp(str, ";", 1) == 0)
    return (8);
  return (0);
}

int		how_separate_order(char *str)
{
  char		tmp;
  int		idx;
  int		nb;

  idx = 0;
  nb = 1;
  while (str[idx] != '\0')
    {
      if (str[idx] == '\'' || str[idx] == '"')
	{
	  tmp = str[idx];
	  idx++;
	  while (str[idx] != '\0' && str[idx] != tmp)
	    idx++;
	  if (str[idx] == '\0')
	    return ((tmp == '\'') ? -1 : -2);
	}
      else if (separator_or(&str[idx]) != 0)
	{
	  idx += separator_or(&str[idx]) % 2;
	  nb += 2;
	}
      idx++;
    }
  return (nb);
}
