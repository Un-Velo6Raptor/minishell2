/*
** how_separate_order.c for  in /home/januar_m/delivery/PSU/PSU_2016_minishell2
** 
** Made by Martin Januario
** Login   <martin.januario@epitech.eu>
** 
** Started on  Tue Mar 14 19:48:42 2017 
** Last update Wed Mar 15 14:22:03 2017 
*/

#include	"my.h"

int             separator_or(char *str)
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

int             how_separate_order(char *str)
{
  int           idx;
  int           nb;
  int           tmp;
  int           quote[2];

  idx = 0;
  quote[0] = 0;
  quote[1] = 0;
  nb = 1;
  while (str[idx] != '\0')
    {
      if (str[idx] == '\'')
        quote[0]++;
      if (str[idx] == '"')
        quote[1]++;
      if (quote[1] % 2 == 0 && quote[0] % 2 == 0 &&
          (tmp = separator_or(&str[idx])) != 0)
        {
          nb++;
          idx += ((tmp != 1) ? tmp : 0) % 2;
        }
      idx++;
    }
  return ((quote[1] % 2 != 0 || quote[0] % 2 != 0) ?
          ((quote[0] % 2 != 0) ? -1 : -2) : nb);
}
