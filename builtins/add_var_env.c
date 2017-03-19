/*
** add_var_env.c for  in /home/januar_m/delivery/PSU/PSU_2016_minishell2
** 
** Made by Martin Januario
** Login   <martin.januario@epitech.eu>
** 
** Started on  Thu Mar 16 14:23:53 2017 
** Last update Sat Mar 18 20:52:34 2017 
*/

#include	<stdlib.h>
#include	"my.h"

char		*str_without_value(char *str)
{
  char		*tmp;
  int		idx;

  idx = 0;
  while (str[idx] != '\0' && str[idx] != '=')
    idx++;
  idx++;
  if ((tmp = malloc(sizeof(char) * (idx + 2))) == NULL)
    return (NULL);
  my_strncpy(tmp, str, idx);
  my_strcat(tmp, "*");
  return (tmp);
}

int		modif_var_env(t_needs *news, char *str, int pos)
{
  my_free(news->my_env[pos]);
  news->my_env[pos] = &str[0];
  return (0);
}

int		add_var_env_next(t_needs *news, char *str)
{
  char		**new_env;
  int		idx;

  if ((new_env = malloc(sizeof(char *) *
			(my_tablen(news->my_env) + 2))) == NULL)
    return (MALLOC_FAILED);
  idx = 0;
  while (news->my_env[idx] != NULL)
    {
      new_env[idx] = &news->my_env[idx][0];
      idx++;
    }
  new_env[idx] = &str[0];
  new_env[idx + 1] = NULL;
  if (news->my_env != NULL)
    free(news->my_env);
  news->my_env = new_env;
  return (0);
}

int		add_var_env(t_needs *news, char *str)
{
  char		*tmp;
  int		nb;

  if ((tmp = str_without_value(str)) == NULL)
    return (84);
  if ((nb = found_var(news->my_env, tmp)) != -1)
    modif_var_env(news, str, nb);
  else if (add_var_env_next(news, str) == MALLOC_FAILED)
    {
      my_free(tmp);
      return (84);
    }
  my_free(tmp);
  return (0);
}
