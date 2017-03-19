/*
** check_tild.c for  in /home/januar_m/delivery/PSU/PSU_2016_minishell2
** 
** Made by Martin Januario
** Login   <martin.januario@epitech.eu>
** 
** Started on  Fri Mar 17 10:55:47 2017 
** Last update Fri Mar 17 13:18:51 2017 
*/

#include	<stdlib.h>
#include	"my.h"

int		add_home_tild(t_needs *news, t_my_order *my_order,
			      int nb, int idx)
{
  char		*str;

  if (nb != -1)
    str = malloc(sizeof(char) *	(my_strlen(my_order->order[idx]) +
				 my_strlen(news->my_env[nb]) - 5));
  else
    str = malloc(sizeof(char) * (my_strlen(my_order->order[idx]) +
				 my_strlen(news->home)));
  if (str == NULL)
    return (MALLOC_FAILED);
  if (nb != -1)
    my_strcpy(str, &news->my_env[nb][5]);
  else
    my_strcpy(str, news->home);
  my_strcat(str, &my_order->order[idx][1]);
  my_free(my_order->order[idx]);
  my_order->order[idx] = &str[0];
  return (0);
}

int		check_tild(t_needs *news, t_my_order *my_order)
{
  int		idx;
  int		nb;

  idx = 0;
  nb = found_var(news->my_env, "HOME=*");
  if (nb == -1 && news->home == NULL)
    return (0);
  while (my_order->order[idx] != NULL)
    {
      if (my_order->order[idx][0] == '~' &&
	  add_home_tild(news, my_order, nb, idx) == MALLOC_FAILED)
	return (MALLOC_FAILED);
      idx++;
    }
  return (0);
}
