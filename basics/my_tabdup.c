/*
** my_tabdup.c for  in /home/januar_m/delivery/PSU/PSU_2016_minishell2/basics
** 
** Made by Martin Januario
** Login   <martin.januario@epitech.eu>
** 
** Started on  Sun Apr  9 02:41:37 2017 Martin Januario
** Last update Sun Apr  9 02:41:39 2017 Martin Januario
*/

#include	<stdlib.h>
#include	"my.h"

char		**my_tabdup(char **tab)
{
  char		**tmp;
  int		idx;

  idx = 0;
  if ((tmp = malloc(sizeof(char *) * (my_tablen(tab) + 1))) == NULL)
    return (NULL);
  while (tab[idx] != NULL)
    {
      if ((tmp[idx] = my_strdup(tab[idx])) == NULL)
	return (NULL);
      idx++;
    }
  tmp[idx] = NULL;
  return (tmp);
}
