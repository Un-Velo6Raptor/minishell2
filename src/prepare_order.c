/*
** prepare_order.c for  in /home/januar_m/delivery/PSU/PSU_2016_minishell2/src
** 
** Made by Martin Januario
** Login   <martin.januario@epitech.eu>
** 
** Started on  Sun Apr  9 02:45:35 2017 Martin Januario
** Last update Sun Apr 23 15:05:00 2017 Martin Januario
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
  int		nb;
  int		idx_malloc;

  nb = 0;
  if ((idx_malloc = how_separate_order(str)) < 0)
    {
      my_putstr((idx_malloc == -2) ? "Unmatched '\"'.\n" : "Unmatched '''.\n");
      return (NULL);
    }
  nb = count_spe_char(str, '"') + count_spe_char(str, '\'') + 2;
  if (idx_malloc <= 0)
    idx_malloc = 1;
  if ((tmp = malloc(sizeof(char *) * ((idx_malloc * 3) * nb))) == NULL)
    return (NULL);
  return (tmp);
}

char		**split_order(char *str, int cpt, int i)
{
  char		**tmp;
  int		index;

  if ((tmp = ini_tmp_order(str)) == NULL)
    return (NULL);
  while (str[i] != '\0' && my_strlen(str) - 1 > i)
    {
      if ((tmp[cpt] = malloc(my_strlen(str) + 1)) == NULL)
	return (NULL);
      split_quote(str, tmp, &cpt, &i);
      if (str[i] != '\0')
	{
	  index = my_strlen(tmp[cpt]);
	  if ((tmp[cpt + ((index == 0) ? 0 : 1)] =
	       my_strndup(&str[i], 1 + separator_or(&str[i]) % 2)) == NULL)
	    return (NULL);
	  i += separator_or(&str[i]) % 2 + 1;
	  if (index != 0)
	    cpt++;
	}
      cpt++;
    }
  tmp[cpt] = NULL;
  return (tmp);
}

t_my_order	*prepare_order(char *str)
{
  t_my_order	*order;
  char		**tmp;

  if ((tmp = split_order(str, 0, 0)) == NULL)
    return (NULL);
  if ((order = create_list_order(tmp)) == NULL)
    {
      free_tab(tmp);
      return (NULL);
    }
  free_tab(tmp);
  return (order);
}
