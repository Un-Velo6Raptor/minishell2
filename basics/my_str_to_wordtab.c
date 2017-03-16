/*
** my_str_to_wordtab.c for  in /home/januar_m/delivery/PSU/PSU_2016_minishell1
** 
** Made by Martin Januario
** Login   <martin.januario@epitech.eu>
** 
** Started on  Wed Jan  4 20:41:11 2017 
** Last update Wed Mar 15 16:48:50 2017 
*/

#include	<stdlib.h>
#include	"my.h"

int		skip_space(char *str)
{
  int		idx;

  idx = 0;
  while (str[idx] != '\0' && (str[idx] == ' ' || str[idx] == '\t'))
    idx++;
  return (idx);
}

int		width_word(char *str, int cpt, int opt)
{
  int		quote;
  int		dquote;
  int		save;

  quote = 0;
  dquote = 0;
  save = cpt;
  while (str[cpt] != '\0' &&
	 ((str[cpt] != ' ' && str[cpt] != '\t') ||
	  (((dquote > 0 && dquote % 2 != 0) ||
			       (quote > 0 && quote % 2 != 0)) && opt == 0)))
    {
      if (str[cpt] == 34)
	dquote++;
      else if (str[cpt] == 39)
	quote++;
      cpt++;
    }
  if ((dquote % 2 != 0 || quote % 2 != 0) && str[cpt] == '\0')
    return (width_word(str, save + 1, 1));
  return (cpt - save);
}

char		*next_word(char *str, int *idx)
{
  char		*result;
  int		cpt;
  int		idx2;
  int		width;

  cpt = skip_space(str);
  width = width_word(str, cpt, 0);
  (*idx) += cpt + width;
  idx2 = 0;
  if ((result = malloc(sizeof(char) * (width + 1))) == NULL)
    return (NULL);
  if (str[cpt] == 34 || str[cpt] == 39)
    cpt++;
  if (cpt + width - 2 >= 0 && (str[cpt + width - 2] == 34 ||
			       str[cpt + width - 2] == 33))
    width -= 2;
  while (idx2 < width && str[cpt + idx2] != '\0')
    {
      result[idx2] = str[cpt + idx2];
      idx2++;
    }
  result[idx2] = '\0';
  return (result);
}

char		**add_words(char **tab, char *str, int *idx)
{
  char		**new_tab;
  int		cpt;

  cpt = 0;
  if ((new_tab = malloc(sizeof(char *) * (my_tablen(tab) + 2))) == NULL)
    return (NULL);
  while (tab[cpt] != NULL)
    {
      if ((new_tab[cpt] = my_strdup(tab[cpt])) == NULL)
	return (NULL);
      cpt++;
    }
  free_tab(tab);
  if ((new_tab[cpt] = next_word(str, idx)) == NULL)
    return (NULL);
  new_tab[cpt + 1] = NULL;
  return (new_tab);
}

char		**my_str_to_wordtab(char *str)
{
  char		**tab;
  int		idx;

  idx = 0;
  if ((tab = malloc(sizeof(char *) * 1)) == NULL)
    return (NULL);
  tab[0] = NULL;
  while (str[idx] != '\0' && str[idx + skip_space(&str[idx])] != '\0')
    if ((tab = add_words(tab, &str[idx], &idx)) == NULL)
      return (NULL);
  return (tab);
}
