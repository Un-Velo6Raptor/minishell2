/*
** my_order_for_redir.c for  in /home/januar_m/delivery/PSU/PSU_2016_minishell2
** 
** Made by Martin Januario
** Login   <martin.januario@epitech.eu>
** 
** Started on  Wed Apr  5 20:54:25 2017 Martin Januario
** Last update Wed Apr  5 21:38:23 2017 Martin Januario
*/

#include	<stdlib.h>
#include	"my.h"

int		copy_redir(char **tmp, t_my_order *my_order)
{
  int		idx;
  int		idx2;

  idx = 0;
  idx2 = 1;
 while (my_order->order[idx] != NULL)
    {
      tmp[idx] = &my_order->order[idx][0];
      idx++;
    }
  while (my_order->next->order[idx2] != NULL)
    {
      if ((tmp[idx] =
	   my_strdup(my_order->next->order[idx2])) == NULL)
	return (84);
      idx2++;
      idx++;
    }
  tmp[idx] = NULL;
  my_order->next->order[1] = NULL;
  free(my_order->order);
  my_order->order = tmp;
  return (0);
}

int		my_order_for_redir(t_my_order *my_order)
{
  char		**tmp;

  tmp = NULL;
  while (my_order->next != NULL)
    {
      if (my_strcmp(my_order->oper_n, ">") == 0 &&
	  my_tablen(my_order->next->order) > 1)
	{
	  if ((tmp = malloc(sizeof(char *) *
			    (my_tablen(my_order->order) +
			     my_tablen(my_order->next->order) +
			     2))) == NULL)
	    return (84);
	  copy_redir(tmp, my_order);	 
	}
      my_order = my_order->next;
    }
  return (0);
}
