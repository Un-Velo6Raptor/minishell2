/*
** my_getnbr.c for  in /home/januar_m/delivery/PSU/PSU_2016_tetris
** 
** Made by Martin Januario
** Login   <martin.januario@epitech.eu>
** 
** Started on  Mon Feb 27 21:54:55 2017 
** Last update Mon Feb 27 21:54:58 2017 
*/

#include	"my.h"

int		check_s(char *str)
{
  int		idx;
  int		cpt;

  idx = 0;
  cpt = 1;
  while (str[idx] != '\0' && (str[idx] < '0' || str[idx] > '9'))
    {
      if (str[idx] == '-')
	cpt = cpt * -1;
      idx++;
    }
  return (cpt);
}

int		start_idx(char *str)
{
  int		idx;

  idx = 0;
  while (str[idx] != '\0')
    {
      if (str[idx] != '-' && str[idx] != '+')
	return (idx);
      idx++;
    }
  return (0);
}

int		check_ovfl(long int nb, int cpt, int tmp)
{
  int		res;

  res = 0;
  if (cpt == 1)
    {
      nb = nb * tmp;
      if (nb > 2147483647)
	return (1);
      else if (nb < -2147483648)
	return (1);
      return (0);
    }
  if (cpt == 2)
    {
      nb = nb * tmp;
      res = nb;
      return (res);
    }
  return (0);
}

int		my_getnbr(char *str)
{
  int		idx;
  long int	result;

  result = 0;
  idx = start_idx(str);
  while (str[idx] != '\0')
    {
      if (str[idx] >= '0' && str[idx] <= '9')
	{
	  if (result == 0)
	    result = str[idx] - 48;
	  else
	    {
	      result = result * 10;
	      result = result + (str[idx] - 48);
	      if (result < 0 || check_ovfl(result, 1, check_s(str)) == 1)
		return (0);
	    }
	}
      else
	return (check_ovfl(result, 2, check_s(str)));
      idx++;
    }
  return (check_ovfl(result, 2, check_s(str)));
}
