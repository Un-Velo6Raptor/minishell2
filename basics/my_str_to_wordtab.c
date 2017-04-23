/*
** my_str_to_wordtab.c for  in /home/januar_m/delivery/PSU/PSU_2016_minishell2/basics
** 
** Made by Martin Januario
** Login   <martin.januario@epitech.eu>
** 
** Started on  Sun Apr  9 02:40:48 2017 Martin Januario
** Last update Fri Apr 21 18:38:24 2017 Martin Januario
*/

#include	<stdlib.h>
#include	"my.h"

int		count_word(char *str, int idx)
{
  char		tmp;
  int		nb;

  nb = 0;
  while (str[idx] != '\0')
    {
      while (str[idx] != '\0' && str[idx] != ' ' && str[idx] != '\t')
	{
	  if (str[idx] == '"' || str[idx] == '\'')
	    {
	      tmp = str[idx];
	      idx++;
	      while (str[idx] != '\0' && str[idx] != tmp)
		idx++;
	      if (str[idx] == '\0')
		return (0);
	    }
	  idx++;
	}
      nb++;
      if (str[idx] != '\0')
	idx++;
    }
  return (nb + 1);
}

char		skip_space(char *str, int *idx, int *cpt, int opt)
{
  if (opt == 1)
    {
      while (str[*idx] != '\0' && (str[*idx] == ' ' || str[*idx] == '\t'))
	(*idx)++;
      (*cpt)++;
    }
  else
    {
      while (str[*idx] != '\0' && (str[*idx] == ' ' || str[*idx] == '\t'))
	(*idx)++;
      *cpt = 0;
    }
  return ('A');
}

int		create_tab(char **tab, char *str, int cpt, int idx)
{
  char		tmp;
  int		idx2;

  while (str[idx] != '\0')
    {
      skip_space(str, &idx, &idx2, 0);
      if ((tab[cpt] = malloc(my_strlen(str) + 1)) == NULL)
	return (84);
      while (str[idx] != '\0' && str[idx] != ' ' && str[idx] != '\t')
	if (str[idx] == '"' || str[idx] == '\'')
	  {
	    tmp = str[idx++];
	    while (str[idx] != '\0' && str[idx] != tmp)
	      tab[cpt][idx2] = split_next(str[idx], &idx, &idx2);
	    if (str[idx] == '\0')
	      return (84);
	    idx++;
	  }
	else
	  tab[cpt][idx2] = split_next(str[idx], &idx, &idx2);
      skip_space(str, &idx, &cpt, 1);
      tab[cpt - 1][idx2] = '\0';
    }
  tab[cpt] = NULL;
  return (0);
}

char		**my_str_to_wordtab(char *str)
{
  char		**tab;
  int		nb;

  nb = count_word(str, 0);
  if (nb < 0)
    return (NULL);
  tab = malloc(sizeof(char *) * (nb + 1));
  if (tab == NULL)
    return (NULL);
  if (create_tab(tab, str, 0, 0) == 84)
    return (NULL);
  return (tab);
}
