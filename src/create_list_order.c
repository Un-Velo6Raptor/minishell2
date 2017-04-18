/*
** create_list_order.c for  in /home/januar_m/delivery/PSU/PSU_2016_minishell2/src
** 
** Made by Martin Januario
** Login   <martin.januario@epitech.eu>
** 
** Started on  Sun Apr  9 02:46:34 2017 Martin Januario
** Last update Tue Apr 18 12:27:40 2017 Martin Januario
*/

#include	<stdlib.h>
#include	"my.h"

int		fill_list_order(t_my_order *my_order,
				char **list_order, int *idx)
{
  while (my_order->next != NULL)
    my_order = my_order->next;
  if (my_order->before != NULL)
    my_order->oper_b = &my_order->before->oper_n[0];
  if (separator_or(list_order[*idx]) == 0 &&
      (my_order->order = my_str_to_wordtab(list_order[*idx])) == NULL)
    return (MALLOC_FAILED);
  if (separator_or(list_order[*idx]) == 0)
    (*idx)++;
  if (list_order[*idx] != NULL && separator_or(list_order[*idx]) != 0 &&
      (my_order->oper_n = my_strdup(list_order[*idx])) == NULL)
    return (MALLOC_FAILED);
  if (my_order->oper_n != NULL)
    (*idx)++;
  my_order->pipe[0] = -1;
  my_order->pipe[1] = -1;
  my_order->fd = -1;
  return (0);
}

int		add_list(t_my_order *my_order)
{
  t_my_order	*tmp;

  while (my_order->next != NULL)
    my_order = my_order->next;
  if ((tmp = ini_my_order()) == NULL)
    return (MALLOC_FAILED);
  tmp->before = my_order;
  my_order->next = tmp;
  return (0);
}

t_my_order	*create_list_order(char **list_order)
{
  t_my_order	*my_order;
  t_my_order	*beg;
  int		idx;

  idx = 0;
  beg = NULL;
  if ((my_order = ini_my_order()) == NULL)
    return (NULL);
  while (list_order[idx] != NULL)
    {
      if (idx == 0)
	beg = my_order;
      if (idx != 0 && add_list(my_order) == MALLOC_FAILED)
	return (NULL);
      if (fill_list_order(my_order, list_order, &idx) == MALLOC_FAILED)
	return (NULL);
    }
  return (beg);
}
