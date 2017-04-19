/*
** prepare_order.c for  in /home/januar_m/delivery/PSU/PSU_2016_minishell2/src
** 
** Made by Martin Januario
** Login   <martin.januario@epitech.eu>
** 
** Started on  Sun Apr  9 02:45:35 2017 Martin Januario
** Last update Tue Apr 18 18:12:41 2017 Martin Januario
*/

#include	<stdlib.h>
#include	"my.h"

t_my_order	*ini_my_order(void)
{
  t_my_order	*my_order;

  if ((my_order = malloc(sizeof(t_my_order) * 1)) == NULL)
    return (NULL);
  my_order->next = NULL;
  my_order->before = NULL;
  my_order->oper_b = NULL;
  my_order->oper_n = NULL;
  my_order->order = NULL;
  my_order->error = 0;
  return (my_order);
}

int		size_separate(char *str)
{
  int		idx;
  int		tmp;
  int		quote[2];

  idx = 0;
  quote[0] = 0;
  quote[1] = 0;
  while (str[idx] != '\0')
    {
      if (str[idx] == '\'')
        quote[0]++;
      if (str[idx] == '"')
        quote[1]++;
      if (quote[1] % 2 == 0 && quote[0] % 2 == 0 &&
          (tmp = separator_or(&str[idx])) != 0)
	return (idx);
      idx++;
    }
  return (idx);
}

char		**ini_tmp_order(char *str)
{
  char		**tmp;
  int		idx_malloc;

  if ((idx_malloc = how_separate_order(str)) < 0)
    {
      my_putstr((idx_malloc == -1) ? "Unmatched \".\n" : "Unmatched '.\n");
      return (NULL);
    }
  if ((tmp = malloc(sizeof(char *) * ((idx_malloc * 3) + 1))) == NULL)
    return (NULL);
  return (tmp);
}

char		**split_order(char *str)
{
  char		**tmp;
  int		idx;
  int		cpt;
  int		last_pos;

  idx = 0;
  cpt = 0;
  last_pos = 0;
  if ((tmp = ini_tmp_order(str)) == NULL)
    return (NULL);
  while (str[idx] != '\0')
    {
      if (separator_or(&str[idx]) != 0)
	{
	  if ((tmp[cpt] = my_strndup(&str[last_pos], idx - last_pos)) == NULL)
	    return (NULL);
	  if ((tmp[cpt + 1] = my_strndup(&str[idx], 1 +
					 (separator_or(&str[idx]) % 2))) == NULL)
	    return (NULL);
	  idx += separator_or(&str[idx]) % 2 + 1;
	  cpt += 2;
	  last_pos = idx;
	}
      else
	idx++;
    }
  if (last_pos != idx)
    {
      tmp[cpt] = my_strndup(&str[last_pos], idx - last_pos);
      if (tmp[cpt] == NULL)
	return (NULL);
      tmp[cpt + 1] = NULL;
    }
  else
    tmp[cpt] = NULL;
  return (tmp);
}

t_my_order	*prepare_order(char *str)
{
  t_my_order	*order;
  char		**tmp;

  if ((tmp = split_order(str)) == NULL)
    return (NULL);
  if ((order = create_list_order(tmp)) == NULL)
    {
      free_tab(tmp);
      return (NULL);
    }
  free_tab(tmp);
  return (order);
}
