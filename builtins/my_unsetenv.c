/*
** my_unsetenv.c for  in /home/januar_m/delivery/PSU/PSU_2016_minishell2/builtins
** 
** Made by Martin Januario
** Login   <martin.januario@epitech.eu>
** 
** Started on  Sun Apr  9 02:08:44 2017 Martin Januario
** Last update Sun Apr  9 02:08:45 2017 Martin Januario
*/

#include	<stdlib.h>
#include	"my.h"

int		remove_var_env(t_needs *news, int nb)
{
  char		**new_env;
  int		idx;
  int		cpt;

  idx = 0;
  cpt = 0;
  if ((new_env = malloc(sizeof(char *) * my_tablen(news->my_env))) == NULL)
    return (MALLOC_FAILED);
  while (news->my_env[idx] != NULL)
    {
      if (idx != nb)
	new_env[idx - cpt] = &news->my_env[idx][0];
      else
	{
	  my_free(news->my_env[idx]);
	  cpt = 1;
	}
      idx++;
    }
  new_env[idx - cpt] = NULL;
  if (news->my_env != NULL)
    free(news->my_env);
  news->my_env = new_env;
  return (0);
}

int		my_unsetenv(t_my_order *my_order, t_needs *news)
{
  char		*tmp;
  int		idx;
  int		nb;

  idx = 1;
  nb = 0;
  if (my_tablen(my_order->order) == 1)
    {
      my_order->error = 1;
      return (my_puterror("unsetenv: Too few arguments.\n"));
    }
  while (my_order->order[idx] != NULL)
    {
      if ((tmp = malloc(sizeof(char) *
			(my_strlen(my_order->order[idx]) + 3))) == NULL)
	return (MALLOC_FAILED);
      my_strcpy(tmp, my_order->order[idx]);
      my_strcat(tmp, "=*");
      if ((nb = found_var(news->my_env, tmp)) != -1 &&
	  remove_var_env(news, nb) == MALLOC_FAILED)
	return (MALLOC_FAILED);
      my_free(tmp);
      idx++;
    }
  return (0);
}
