/*
** make_double_redir_left.c for  in /home/januar_m/delivery/PSU/PSU_2016_minishell2
** 
** Made by Martin Januario
** Login   <martin.januario@epitech.eu>
** 
** Started on  Tue Apr 25 21:09:55 2017 Martin Januario
** Last update Wed Apr 26 15:57:55 2017 Martin Januario
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

void		write_file_fd(char **tab, int fd_next)
{
  int		idx;

  idx = 0;
  while (tab != NULL && tab[idx] != NULL)
    {
      write(fd_next, tab[idx], my_strlen(tab[idx]));
      write(fd_next, "\n", 1);
      idx++;
    }
}

void		write_tab_fd(char **tab, int fd, t_my_order *my_order)
{
  int		idx;
  int		fd_next;

  idx = 0;
  fd_next = -1;
  while (tab != NULL && tab[idx] != NULL)
    {
      write(fd, tab[idx], my_strlen(tab[idx]));
      write(fd, "\n", 1);
      idx++;
    }
  if (my_order->next != NULL &&
      my_strcmp(my_order->next->oper_n, ">") == 0)
    fd_next = open(my_order->next->next->order[0],
		   O_CREAT | O_TRUNC | O_RDWR, 0644);
  if (my_order->next != NULL &&
      my_strcmp(my_order->next->oper_n, ">>") == 0)
    fd_next = open(my_order->next->next->order[0],
		   O_CREAT | O_TRUNC | O_RDWR, 0644);
  if (fd_next != -1)
    {
      write_file_fd(tab, fd_next);
      close(fd_next);
    }
}

int		make_double_redir_left(t_my_order *my_order)
{
  t_buffer	buffer;
  char		**tab;
  char		*str;
  int		fd;
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
  fd = open(".tmp", O_CREAT | O_TRUNC | O_RDWR, 0644);
  if (fd != -1)
    {
      write_tab_fd(tab, fd, my_order);
      close(fd);
    }
  my_order->fd = open(".tmp", O_RDONLY);
  return (0);
}
