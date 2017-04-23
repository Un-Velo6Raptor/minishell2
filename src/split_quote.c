/*
** split_quote.c for  in /home/januar_m/delivery/PSU/PSU_2016_minishell2
** 
** Made by Martin Januario
** Login   <martin.januario@epitech.eu>
** 
** Started on  Fri Apr 21 11:01:23 2017 Martin Januario
** Last update Fri Apr 21 18:45:44 2017 Martin Januario
*/

#include	"my.h"

char		split_next(char tmp, int *idx, int *idx2)
{
  (*idx2)++;
  (*idx)++;
  return (tmp);
}

void		split_quote(char *str, char **tmp, int *cpt, int *idx)
{
  char		quote;
  int		idx2;

  idx2 = 0;
  while (str[*idx] != '\0' &&
	 separator_or(&str[*idx]) == 0)
    {
      if (str[*idx] == '"' || str[*idx] == '\'')
	{
	  quote = str[*idx];
	  tmp[*cpt][idx2] = quote;
	  (*idx)++;
	  while (str[*idx] != '\0' && quote != str[*idx])
	    tmp[*cpt][idx2 + 1] = split_next(str[*idx], idx, &idx2);
	  if (str[*idx] != '\0')
	    tmp[*cpt][idx2 + 1] = split_next(quote, idx, &idx2);
	}
      else
	{
	  tmp[*cpt][idx2] = str[*idx];
	  (*idx)++;
	}
      idx2++;
    }
  tmp[*cpt][idx2] = '\0';
}
