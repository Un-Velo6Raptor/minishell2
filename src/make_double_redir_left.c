/*
** make_double_redir_left.c for  in /home/januar_m/delivery/PSU/PSU_2016_minishell2
** 
** Made by Martin Januario
** Login   <martin.januario@epitech.eu>
** 
** Started on  Tue Apr 25 21:09:55 2017 Martin Januario
** Last update Wed Apr 26 20:11:14 2017 Martin Januario
*/

#include	<sys/stat.h>
#include	<fcntl.h>
#include	<stdlib.h>
#include	<unistd.h>
#include	"get_next_line.h"
#include	"my.h"

int		add_str(char ***tab, char *str)
{
  char		**new_tab;
  int		idx;

  new_tab = malloc(sizeof(char *) * (my_tablen(*tab) + 3));
  if (new_tab == NULL)
    return (84);
  idx = 0;
  while (*tab != NULL && (*tab)[idx] != NULL)
    {
      new_tab[idx] = &(*tab)[idx][0];
      idx++;
    }
  if ((new_tab[idx] = my_strdup(str)) == NULL)
    return (84);
  new_tab[idx + 1] = NULL;
  *tab = new_tab;
  return (0);
}

char		**make_double_redir_left(t_my_order *my_order)
{
  t_buffer	buffer;
  char		**tab;
  char		*str;
  int		check;

  tab = NULL;
  ini_gnl(&buffer);
  check = 0;
  while (check == 0)
    {
      str = get_next_line(0, &buffer);
      if (str == NULL || my_strcmp(str, my_order->next->order[0]) == 0)
	check = 1;
      else if (add_str(&tab, str) == 84)
	check = -1;
    }
  if (check == -1)
    return (NULL);
  return (tab);
}
